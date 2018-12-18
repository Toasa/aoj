#include <stdio.h>
#include <stdlib.h>

static int *c;

typedef struct NODE {
    int id;
    int parent;
    int depth;
    // type: r, i, l (root, internal node, leaf)
    char type;
    int child_num;
    struct NODE **childs;
} node;

void init(node *p) {
    p->parent = -1;
    p->depth = 0;
    p->type = 'r';
}

node *make_node(int id, int k, int *c) {
    node *p = malloc(sizeof(node));
    p->id = id;
    p->child_num = k;
    p->childs = malloc(sizeof(node) * k);
    for (int i = 0; i < k; i++) {
        node *q = malloc(sizeof(node));
        p->childs[i] = q;
        p->childs[i]->id = c[i];
    }

    return p;
}

void find_parent_depth_type(node *p, int n) {
    int depth = n;
    printf("%d's child num: %d\n",p->id, p->child_num);
    if (p->child_num != 0) {
        depth++;
        p->type = 'i';
        for (int i = 0; i < p->child_num; i++) {
            p->childs[i]->depth = depth;
            p->childs[i]->parent = p->id;
            find_parent_depth_type(p->childs[i], depth);
        }
    } else {
        p->type = 'l';
    }
}

char *det_type(char c) {
    if (c == 'r')
    return "root";
    else if (c == 'i')
    return "internal node";
    else if (c == 'l')
    return "leaf";

    return "error";
}

void print(node **nodes, int n) {
    for (int i = 0; i < n; i++) {
        node *p = nodes[i];
        printf("node %d: parent = %d, depth = %d, %s, ", p->id, p->parent, p->depth, det_type(p->type));
        printf("[");
        for (int j = 0; j < p->child_num; j++)
        printf((j != p->child_num - 1 ? "%d, " : "%d"), p->childs[j]->id);
        printf("]\n");
    }
}
//node 0: parent = -1, depth = 0, root, [1, 4, 10]

int main() {
    int n;
    scanf("%d", &n);
    node *nodes[n];

    for (int i = 0; i < n; i++) {
        // each node input
        int id, k;
        scanf("%d%d", &id, &k);

        int c[k];
        for (int j = 0; j < k; j++)
            scanf("%d", c + j);

        node *p = make_node(id, k, c);
        nodes[id] = p;
    }

    // child_solve
    for (int i = 0; i < n; i++) {
        if (nodes[i]->child_num != 0) {
            for (int j = 0; j < nodes[i]->child_num; j++) {
                nodes[i]->childs[j] = nodes[nodes[i]->childs[j]->id];
            }
        }
    }

    init(nodes[0]);

    find_parent_depth_type(nodes[0], 0);

    print(nodes, n);

}
