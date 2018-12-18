#include <cstdio>
#include <cstdlib>


using namespace std;

typedef struct Node {
  int val;
  Node *prev, *next;
} node;

node *nil;
void init() {
  nil = (node *)malloc(sizeof(node));
  nil -> next = NULL;
  nil -> prev = NULL;
}

node* make(int n) {
  node *p;
  p = (node *)malloc(sizeof(node));
  p -> val = n;
  return p;
}

void isrt(int n) {
  node* p = make(n);
  nil -> next -> prev = p;
  p -> next = nil->next;
  nil -> next = p;
  p -> prev = nil;
}

void dlet(int n) {
  node *p = make(n);
  p = nil->next;
  while (p->val != n) {
	p = p->next;
  }
  p->next->prev = p->prev;
  p->prev->next = p->next;
}

void disp() {
  node *p = (node *)malloc(sizeof(node));
  p = nil -> next;
  while (p != NULL) {
	printf("%d ->", p->val);
  }
}

int main() {
  init();
  isrt(1);
  isrt(2);
  isrt(5);

  //disp();

  return 0;
}
