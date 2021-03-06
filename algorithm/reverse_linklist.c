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

Linklist *change(Linklist *head, int m, int n) {
  Linklist *vhead, *realhead, *p, *q;
  int i;
  vhead = (Linklist *)malloc(sizeof(Linklist));
  vhead->num = 0;
  vhead->next = head;
  realhead = vhead;
  for(i = 1; i <= m - 1; i++) 
    realhead = realhead->next;
  p = realhead->next;
  q = p->next;
  for(i = 1; i <= n - m; i++) {
    p->next = q->next;
    q->next = realhead->next;
    realhead->next = q;
    q = p->next;
  }
  return vhead;
}

int main(void) {
  Linklist *head, *p;
  head = create(1, 6);
  head = change(head, 2, 3);
  p = head->next;
  free(head);
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
