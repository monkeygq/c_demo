#include <stdio.h>
#include <malloc.h>  

typedef struct linklist Linklist;
struct linklist {
  int num;
  struct linklist *next;
};

Linklist *create(int num, int length, int* n) {
  Linklist *p;
  p = (Linklist *)malloc(sizeof(Linklist));
  p->num = n[num];
  if(num == length - 1) {
    p->next = NULL;
    return p;
  }
  else
    p->next = create(num + 1, length, n);
  return p;
}

Linklist *change(Linklist *head, int n) {
  Linklist *small, *big, *res, *prev;
  small = (Linklist *)malloc(sizeof(Linklist));
  small->next = head;
  res = small;
  big = head;
  prev = NULL;
  while(big != NULL) {
    if(big->num < n) {
      if(prev != NULL && prev != small) {
        prev->next = big->next;
        big->next = small->next;
        small->next = big;
        small = big;
        big = prev;
      }
      else
        small = big;
    }
    prev = big;
    big = big->next;
  }
  return res->next;
}

int main(void) {
  Linklist *p;
  int a[] = {1,4,3,2,5,2};
  p = create(0, sizeof(a) / sizeof(a[0]), a);
  p = change(p, 4);
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
