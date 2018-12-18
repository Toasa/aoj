#include <stdio.h>
#include <stdlib.h>

typedef struct DLL {
  int val;
  struct DLL *next;
  struct DLL *prev;
} dll;

static dll *nil;

void init() {
  nil = malloc(sizeof(dll));
  nil->next = nil;
  nil->prev = nil;
}

void insert(int n) {
  dll *p = malloc(sizeof(dll));
  p->val = n;
  p->next = nil->next;
  nil->next = p;
  p->next->prev = p;
  p->prev = nil;
}

void delete(int n) {
  dll *p = malloc(sizeof(dll));
  p = nil->next;
  while (p->val != n) {
    p = p->next;
  }
  p->prev->next = p->next;
  p->next->prev = p->prev;
}

void deleteFirst() {
  nil->next = nil->next->next;
  nil->next->prev = nil;
}

void deleteLast() {
  nil->prev->prev->next = nil;
  nil->prev = nil->prev->prev;
}

void print() {
  dll *p = malloc(sizeof(dll));
  p = nil->next;
  while (p != nil) {
	if (p->next == nil)
	  printf("%d\n", p->val);
	else
	  printf("%d ", p->val);
    p = p->next;
  }
}

int main() {
  int count;
  scanf("%d", &count);

  init();
  char *inst;
  int val;

  for (int i = 0; i < count; i++) {
    scanf("%s", inst);
    if (inst[0] == 'i') {
	  scanf("%d", &val);
      insert(val);
    } else if (inst[6] == 'F') {
      deleteFirst();
    } else if (inst[6] == 'L') {
      deleteLast();
    } else {
	  scanf("%d", &val);
      delete(val);
    }
  }

  print();

}
