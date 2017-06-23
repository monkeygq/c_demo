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

Linklist *swap(Linklist *head) {
  Linklist *new_head;
  if(head == NULL || head->next == NULL)
    return head;
  else {
    new_head = head->next;
    head->next = new_head->next;
    new_head->next = head;
    head->next = swap(head->next);
    return new_head;
  }
}

int main(void) {
  Linklist *p;
  p = create(1, 6);
  p = swap(p);
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
