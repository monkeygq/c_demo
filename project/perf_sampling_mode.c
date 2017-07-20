#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <linux/hw_breakpoint.h>
#include <asm/unistd.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <poll.h>

#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))
#define rmb() asm volatile("lock; addl $0,0(%%esp)" :: : "memory")

struct perf_record_sample {
  __u64 sample_id;
  __u64 id;
};

uint64_t page_size;
int main(int argc, char* argv[]) {
  struct perf_event_attr pea;
  int fd1;
  struct perf_event_mmap_page *mp;
  struct perf_event_header *peh;                                                                                    
  void *base;
  memset(&pea, 0, sizeof(struct perf_event_attr));
  pea.type = PERF_TYPE_HARDWARE;
  pea.size = sizeof(struct perf_event_attr);
  pea.config = PERF_COUNT_HW_INSTRUCTIONS;
  pea.disabled = 1;
  pea.sample_period = 1000;
  pea.sample_type = PERF_SAMPLE_IDENTIFIER | PERF_SAMPLE_ID;//PERF_SAMPLE_TID;//PERF_SAMPLE_TIME | PERF_SAMPLE_RAW;

  fd1 = syscall(__NR_perf_event_open, &pea, -1, 0, -1, 0);
  printf("fd1 = %d\n", fd1);
  page_size = sysconf(_SC_PAGE_SIZE);
  printf("page_size: %"PRIu64"\n", page_size);
  base = mmap(NULL, page_size * 3, PROT_READ|PROT_WRITE, MAP_SHARED, fd1, 0);
  //fcntl(fd1, F_SETFL, O_NONBLOCK);

  if(base == MAP_FAILED){
    printf("map failed\n");
    printf("%d\n", errno);
  }

  //ioctl(fd1, PERF_EVENT_IOC_RESET, 0);
  ioctl(fd1, PERF_EVENT_IOC_ENABLE, 0);

  struct pollfd pollfd[] = {{fd1, POLLIN | POLLHUP,0}};
  int ret;
  void *read_head = base, *read_tail;
  struct perf_record_sample *sample;
  //ret = poll(pollfd, 1, -1);
  //printf("ret = %d\n", ret);
  //printf("pollfd[0]->revents = %d\n", pollfd[0].revents);
  //printf("base = %p\n", base);
  
  sleep(1);

  while(1) {
    ret = poll(pollfd, 1, -1);
    if(ret == -1) {
      printf("failed start poll");
      continue;
    }
    read_tail = read_head;
    mp = (struct perf_event_mmap_page *)read_head;
    printf("mp: %p\n", mp);
    __u64 head = ACCESS_ONCE(mp->data_head);
    //rmb();
    printf("mp->version = %d\n", mp->version);
    printf("mp->data_head = %llu\n", head);
    printf("mp->data_tail = %llu\n", mp->data_tail);
    printf("mp->data_size = %llu\n", mp->data_size);
    printf("mp->data_offset = %llu\n", mp->data_offset);
    printf("mp->time_enabled = %llu\n", mp->time_enabled);
    //base += mp->data_offset;//sizeof(*mp);
    base = read_head + head;
    printf("%p\n", mp);
    printf("%p\n", base);
    printf("%p\n", read_tail + mp->data_offset + mp->data_size);
    read_tail += (mp->data_offset + mp->data_size);
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

    while(base <= read_tail) {
      printf("base: %p\n", base);
      peh = (struct perf_event_header *)base;
      printf("peh: %p\n", peh);
      printf("peh->type = %d\n", peh->type);
      printf("peh->misc = %d\n", peh->misc);
      printf("peh->size = %d\n", peh->size);
      if(peh->type != PERF_RECORD_SAMPLE)
        break;
      base += sizeof(peh);
      sample = (struct perf_record_sample *)base;
      printf("sample->sample_id = %llu\n", sample->sample_id);
      printf("sample->id = %llu\n", sample->id);
      base += sizeof(struct perf_record_sample);
    }
  }
  munmap(base, page_size * 3);
  close(fd1);
  return 0;
}










