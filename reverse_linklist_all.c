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

Linklist *change(Linklist *head) {
  Linklist *p, *prev = NULL;
  while(head != NULL) { 
    p = head->next;
    head->next = prev;
    prev = head;
    head = p;
  }
  return prev;
}

int main(void) {
  Linklist *head, *p;
  head = create(1, 5);
  p = change(head);
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
