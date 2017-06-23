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
  Linklist *begin, *end;
  int i;
  begin = head;
  end = begin;
  for(i = 1; i<= n; i++) {
    end = end->next;
  }
  if(end == NULL)
    return head->next;
  else{
    while(end->next != NULL) {
      begin = begin->next;
      end = end->next;
    }
    begin->next = begin->next->next;
    return head;
  }
}

int main(void) {
  Linklist *p;
  p = create(1, 5);
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
