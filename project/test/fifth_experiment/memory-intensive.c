#define _GNU_SOURCE
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

struct read_format {
	uint64_t nr;
	uint64_t time_enabled;
	uint64_t time_running;
	struct {
		uint64_t value;
		uint64_t id;
	} values[];
};

#define MAX_MAX (1024 * 64)
#define MAX (1024 * 1)

int global[MAX];

struct item {
	struct item *next;
	unsigned long long arr[63];
};

struct item p[MAX];
struct item *head = p;
struct item first;

int run1() {
	struct item *p1;
		p1 = first.next;
		while(p1 != NULL) {
			p1 = p1->next;
		}
	return 0;
}

void init() {
	int ran[MAX];
	int i, j, k;
	struct item *p_init = &first;
	for(i = 0; i < MAX; i++) {
		ran[i] = i;
	}   
	for(i = MAX - 1; i >= 0; i--) {
		j = rand() % (i + 1); 
		global[i] = ran[j];
		for(k = j; k < i; k++)
			ran[k] = ran[k + 1]; 
	}   

	for(i = MAX - 1; i >= 0; i--) {
		p_init->next = head + global[i];
		p_init = p_init->next;
	}
	p_init->next = NULL;
}


int main(int argc, char* argv[]) {
	struct perf_event_attr pea;
	int fd1, fd2;
	uint64_t id1, id2;
	uint64_t val1, val2;
	char buf[4096];
	struct read_format* rf = (struct read_format*) buf;
	int i,j;
	void *base;

	memset(&pea, 0, sizeof(struct perf_event_attr));
	pea.type = PERF_TYPE_HARDWARE;
	pea.size = sizeof(struct perf_event_attr);
	pea.config = PERF_COUNT_HW_CACHE_REFERENCES;
	pea.disabled = 1;
	pea.exclude_kernel = 1;
	pea.exclude_hv = 1;
	pea.read_format = PERF_FORMAT_TOTAL_TIME_ENABLED | PERF_FORMAT_TOTAL_TIME_RUNNING | PERF_FORMAT_GROUP | PERF_FORMAT_ID;
	fd1 = syscall(__NR_perf_event_open, &pea, 0, -1, -1, 0);
	ioctl(fd1, PERF_EVENT_IOC_ID, &id1);

	memset(&pea, 0, sizeof(struct perf_event_attr));
	pea.type = PERF_TYPE_HARDWARE;
	pea.size = sizeof(struct perf_event_attr);
	pea.config = PERF_COUNT_HW_CACHE_MISSES;
	pea.disabled = 1;
	pea.exclude_kernel = 1;
	pea.exclude_hv = 1;
	pea.read_format = PERF_FORMAT_TOTAL_TIME_ENABLED | PERF_FORMAT_TOTAL_TIME_RUNNING | PERF_FORMAT_GROUP | PERF_FORMAT_ID;
	fd2 = syscall(__NR_perf_event_open, &pea, 0, -1, fd1 /*!!!*/, 0);
	ioctl(fd2, PERF_EVENT_IOC_ID, &id2);


	init();
	ioctl(fd1, PERF_EVENT_IOC_RESET, PERF_IOC_FLAG_GROUP);
	ioctl(fd1, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);
	run1();
	ioctl(fd1, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);


	read(fd1, buf, sizeof(buf));
	//printf("%"PRIu64"\n", rf->nr);
	//printf("%"PRIu64"\n", rf->time_enabled);
	//printf("%"PRIu64"\n", rf->time_running);
	for (i = 0; i < rf->nr; i++) {
		if (rf->values[i].id == id1) {
			val1 = rf->values[i].value;
		} else if (rf->values[i].id == id2) {
			val2 = rf->values[i].value;
		}
	}

	//printf("cache references: %"PRIu64"\n", val1);
	//printf("cache misses: %"PRIu64"\n", val2);
	//printf("cache misses rate: %f\n", val2 * 1.0 / val1);
	printf("%d %f\n", MAX / 1024 * 512, val2 * 1.0 / val1);

	return 0;
}
