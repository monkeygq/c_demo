#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (1024 * 1024)

struct item {
	struct item *next;
	unsigned long long arr[63];
};

int run() {
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

int main() {
	while(1) {
		run();
	}
}
