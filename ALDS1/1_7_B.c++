#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

typedef struct NODE {
    int id;
    int left_id;
    int right_id;
    struct NODE *left;
    struct NODE *right;
    int parent;
    int sibling;
    int child_num;
    int depth;
    int height;
    string type;
} node;

int n;
int root_id;
node **nodes;
vector<int> same_height;

void gen_node(int id, int left_id, int right_id) {
    node *p = (node *)malloc(sizeof(node));
    p->id = id;
    p->left_id = left_id;
    p->right_id = right_id;

    nodes[id] = p;
}

void connect_parent_child() {
    node *p = (node *)malloc(sizeof(node));
    node *q = (node *)malloc(sizeof(node));
    for (int i = 0; i < n; i++) {
        p = nodes[i];
        int l = p->left_id;
        int r = p->right_id;
        int child_num = 0;
        if (l != -1) {
            child_num++;
            p->left = (node *)malloc(sizeof(node));
            q = nodes[l];
            p->left = q;
            q->parent = p->id;
            if (r != -1) {
                q->sibling = r;
            }
        }
        if (p->right_id != -1) {
            child_num++;
            p->right = (node *)malloc(sizeof(node));
            q = nodes[r];
            p->right = q;
            q->parent = p->id;
            if (l != -1) {
                q->sibling = l;
            }
        }
        p->child_num = child_num;
        if (p->child_num > 0) {
            p->type = "internal node";
        }
        if (p->child_num == 0) {
            p->type = "leaf";
            p->height = 0;
            same_height.push_back(p->id);
        }
    }
}

void find_root() {
    for (int i = 0; i < n; i++) {
        if (nodes[i]->parent == -1) {
            nodes[i]->type = "root";
            root_id = nodes[i]->id;
            return;
        }
    }
}

void calc_depth(int id, int d) {
    nodes[id]->depth = d;
    if (nodes[id]->left_id != -1) {
        calc_depth(nodes[id]->left_id, d+1);
    }
    if (nodes[id]->right_id != -1) {
        calc_depth(nodes[id]->right_id, d+1);
    }
}

vector<int> calc_height(vector<int> s_h, int h) {
    vector<int> next_height;
    for (int i = 0; i < s_h.size(); i++) {
        if (nodes[s_h[i]]->parent != -1) {
            nodes[nodes[s_h[i]]->parent]->height = h;
            next_height.push_back(nodes[s_h[i]]->parent);
        }
    }
    return next_height;
}

void print_tree() {
    for (int i = 0; i < n; i++) {
        cout << "node " << nodes[i]->id << ": parent = " << nodes[i]->parent <<
        ", sibling = " << nodes[i]->sibling << ", degree = " << nodes[i]->child_num <<
        ", depth = " << nodes[i]->depth << ", height = " << nodes[i]->height << ", " <<
        nodes[i]->type << endl;
    }
}

int main () {
    cin >> n;
    nodes = (node **)malloc(sizeof(node) * n);

    int id, left_id, right_id;
    for (int i = 0; i < n; i++) {
        cin >> id >> left_id >> right_id;
        gen_node(id, left_id, right_id);

        nodes[id]->parent = -1;
        nodes[id]->sibling = -1;
        nodes[id]->depth = -1;
        nodes[id]->height = -1;
    }

    connect_parent_child();

    find_root();

    nodes[root_id]->depth = 0;
    if (nodes[root_id]->left_id != -1) {
        calc_depth(nodes[root_id]->left->id, 1);
    }
    if (nodes[root_id]->right_id != -1) {
        calc_depth(nodes[root_id]->right->id, 1);
    }

    vector<int> next_height = same_height;

    int h = 1;
    while (next_height.size() > 0) {
        next_height = calc_height(next_height, h);
        h++;
    }

    print_tree();

    return 0;
}
