#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (1024 * 1024 * 2)
int arr[MAX];

struct item {
	struct item *next;
	unsigned long long arr[63];
};

int run1() {
	struct item *p = (struct item *)malloc(sizeof(struct item) * MAX);
	struct item *head = p;
	int ran[MAX];
	int i, j, k;
	for(i = 0; i < MAX; i++) {
		ran[i] = i;
	}
	srand(time(NULL));
	for(i = MAX - 1; i >= 0; i--) {
		j = rand() % (i + 1);
		p->next = head + ran[j];
		if(p == p->next)
			p->next == NULL;
		else
			p = p->next;
		for(k = j; k < i; k++)
			ran[k] = ran[k + 1];
	}
	p = head;
	while(p != NULL)
		p = p->next;
	free(head);
	return 0;
}

int run2() {
	int i, j;
	for(i = 0; i < MAX; i++)
		arr[i] = 0;
	for(j = 2; j < MAX; j++) {
		for(i = 2; i < MAX; i += j)
			arr[i] = 1;
	}
	return 0;
}
int main() {
	run2();
}
