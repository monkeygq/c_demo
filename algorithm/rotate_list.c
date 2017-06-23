#include <stdio.h>
#include <malloc.h>  

typedef struct linklist Linklist;
struct linklist {
  int num;
  struct linklist *next;
};

Linklist *create(int num, int n) {
  Linklist *p;
  p = (Linklist *)malloc(sizeof(Linklist));
  p->num = num;
  if(num == n) {
    p->next = NULL;
    return p;
  }
  else
    p->next = create(num + 1, n);
  return p;
}

Linklist *change(Linklist *head, int n) {
  Linklist *prev, *realhead = head;
  int i, count = 1;
  if(head == NULL)
    return NULL;
  while(head->next != NULL) {
    count++;
    head = head->next;
  }
  head->next = realhead;
  for(i = 1; i <= (count - n % count); i++) {
    prev = realhead;
    realhead = realhead->next;
  }
  prev->next = NULL;
  return realhead;
}

int main(void) {
  Linklist *p;
  p = create(1, 1);
  p = change(p, 2);
  while(p != NULL) {
    Linklist *delete;
    printf("%d", p->num);
    delete = p;
    p = p->next;
    free(delete);
  }
  printf("\n");
  return 0;
}
