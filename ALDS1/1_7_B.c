#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int id;
  int parent;
  int sibling;
  int degree;
  int depth;
  int height;
  char type;
  char l_bit;
  char r_bit;
  struct NODE *right;
  struct NODE *left;
} node;

node *make_node(int id, int left, int right) {
  node *p = malloc(sizeof(node));
  p->id = id;
  p->degree = 0;
  p->left = malloc(sizeof(node));
  p->right = malloc(sizeof(node));
  p->left->id = left;
  p->left->l_bit = 1;
  p->right->id = right;
  p->right->r_bit = 1;
  if (left != -1)
    p->degree++;
  if (right != -1)
    p->degree++;

  return p;
}

void init(node *p) {
  p->depth = 0;
  p->parent = -1;
  p->sibling = -1;
  p->type = 'r';
}

void find_silb(node **tree, int n, int root_index) {
  for (int i = 0; i < n; i++) {
	node *p = tree[i];
	if (p->l_bit == 1)
	  p->sibling = tree[p->parent]->right->id;
	else if(p->r_bit == 1)
	  p->sibling = tree[p->parent]->left->id;
  }
}

void solve_depth(node *p, int depth) {
  depth++;
  if (p->left->id != -1) {
	p->left->depth = depth;
	solve_depth(p->left, depth);
  }
  if (p->right->id != -1) {
	p->right->depth = depth;
	solve_depth(p->right, depth);
  }
}

void solve_height(node *p) {
  int height = 0;
  while (p->left->id != -1 || p->right->id != -1) {
	if (p->left->id != -1) {
	  p = p->left;
	} else if (p->right->id != -1) {
	  p = p->right;
	}
	height++;
  }
  p->height = height;
}

int main() {
  int n;
  scanf("%d", &n);

  node *tree[n];

  int id;
  int right;
  int left;
  int root_index;

  // first index is assumed a root index
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &id, &left, &right);
	if (i == 0)
	  root_index = id;
    node *p = make_node(id, left, right);
	tree[id] = p;
  }

  // init root
  init(tree[root_index]);

  // solve child & parent
  for (int i = 0; i < n; i++) {
    int id_l = tree[i]->left->id;
    int id_r = tree[i]->right->id;
    if (id_l != -1)
      tree[i]->left = tree[id_l];
    if (id_r != -1)
      tree[i]->right = tree[id_r];
	tree[i]->left->parent = tree[i]->id;
	tree[i]->right->parent = tree[i]->id;
  }

  solve_depth(tree[root_index], 0);

  for (int i = 0; i < n; i++) {
	solve_height(tree[i]);
  }

  printf("%d\n", tree[0]->right->right->depth);

}
