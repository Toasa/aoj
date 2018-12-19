#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int id;
    int parent;
    int depth;
    // type: r, i, l (root, internal node, leaf)
    char type;
    int child_num;
    struct NODE **childs;
} node;

static int *c;

// idがindexの親を登録する
int *parent_num;
node **nodes;
int root_id;

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
        parent_num[c[i]] = id;

        // この一行がないと、次の行がsegmentation fault
        p->childs[i] = malloc(sizeof(node));
        p->childs[i]->id = c[i];
    }
    return p;
}

void connect_parent_child(int n) {
    for (int i = 0; i < n; i++) {
        node *p = malloc(sizeof(node));
        p = nodes[i];
        if (parent_num[p->id] != -1) {
            if (p->child_num > 0) {
                p->type = 'i';
            } else {
                p->type = 'l';
            }
            p->parent = parent_num[p->id];
        } else {
            p->type = 'r';
            p->parent = parent_num[p->id];
            root_id = p->id;
        }
        for (int j = 0; j < p->child_num; j++) {
            int id = p->childs[j]->id;
            p->childs[j] = nodes[id];
        }
    }
}

// void find_parent_depth_type(node *p, int n) {
//     int depth = n;
//     printf("%d's child num: %d\n",p->id, p->child_num);
//     if (p->child_num != 0) {
//         depth++;
//         p->type = 'i';
//         for (int i = 0; i < p->child_num; i++) {
//             p->childs[i]->depth = depth;
//             p->childs[i]->parent = p->id;
//             find_parent_depth_type(p->childs[i], depth);
//         }
//     } else {
//         p->type = 'l';
//     }
// }

char *det_type(char c) {
    if (c == 'r')
        return "root";
    else if (c == 'i')
        return "internal node";
    else if (c == 'l')
        return "leaf";

    return "error";
}

//node 0: parent = -1, depth = 0, root, [1, 4, 10]
void print(int n) {
    for (int i = 0; i < n; i++) {
        node *p = nodes[i];
        printf("node %d: parent = %d, depth = %d, %s, ", p->id, p->parent, p->depth, det_type(p->type));
        printf("[");
        for (int j = 0; j < p->child_num; j++)
            printf((j != p->child_num - 1 ? "%d, " : "%d"), p->childs[j]->id);
        printf("]\n");
    }
}

void calc_depth(int id, int depth) {
    node *p = malloc(sizeof(node));
    p = nodes[id];
    p->depth = depth;
    if (p->child_num > 0) {
        for (int i = 0; i < p->child_num; i++) {
            calc_depth(p->childs[i]->id, depth+1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    nodes = malloc(sizeof(node) * n);
    parent_num = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        parent_num[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        // each node input
        int id, k;
        scanf("%d%d", &id, &k);

        int c[k];
        for (int j = 0; j < k; j++)
            scanf("%d", c + j);

        nodes[id] = make_node(id, k, c);
    }

    connect_parent_child(n);

    nodes[root_id]->depth = 0;
    for (int i = 0; i < nodes[root_id]->child_num; i++) {
        calc_depth(nodes[root_id]->childs[i]->id, 1);
    }

    print(n);
}
