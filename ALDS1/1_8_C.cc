#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

typedef struct NODE {
    int key;
    struct NODE *right;
    struct NODE *left;
    struct NODE *parent;
} Node;

int m;
Node *root;

Node *newNode(int key) {
    Node *n = new Node;
    n->key = key;
    n->right = NULL;
    n->left = NULL;
    n->parent = NULL;
    return n;
}

void insert(int key) {
    Node *r = root;
    Node *n;

    while (r) {
        if (key < r->key) {
            if (r->left) {
                r = r->left;
            } else {
                n = newNode(key);
                r->left = n;
                n->parent = r;
                return;
            }
        } else {
            if (r->right) {
                r = r->right;
            } else {
                n = newNode(key);
                r->right = n;
                n->parent = r;
                return;
            }
        }
    }
}

Node *search(int key) {
    Node *r = root;

    while (r) {
        if (r->key == key) {
            return r;
        }
        if (key < r->key) {
            r = r->left;
        } else {
            r = r->right;
        }
    }
    return r;
}

void find(int key) {
    if (search(key)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int checkChildNum(Node *n) {
    int count = 0;
    if (n->left) {
        count++;
    }
    if (n->right) {
        count++;
    }
    return count;
}

char checkParentSide(Node *n) {
    Node *p = n->parent;
    if (p->left) {
        if (p->left->key == n->key) {
            return 'l';
        }
    }
        
    if (p->right) {
        if (p->right->key == n->key) {
            return 'r';
        }
    }

    return '\0';
}

// nの子供の数が0
void delete0(Node *n, char side) {
    if (side == 'l') {
        n->parent->left = NULL;
    } else {
        n->parent->right = NULL;
    }
}

// nの子供の数が1
void delete1(Node *n, char side) {
    if (n->left != NULL) {
        if (side == 'l') {
            n->parent->left = n->left;
            n->left->parent = n->parent;
        } else {
            n->parent->right = n->left;
            n->left->parent = n->parent;
        }
    } else {
        if (side == 'l') {
            n->parent->left = n->right;
            n->right->parent = n->parent;
        } else {
            n->parent->right = n->right;
            n->right->parent = n->parent;
        }
    }
}

Node *searchMinNode(Node *n) {
    while (n->left != NULL) {
        n = n->left;
    }
    return n;
}

// nの子供の数が2
void delete2(Node *n) {
    // min_nodeは定義上左の子を持たない
    Node *min_node = searchMinNode(n->right);
    n->key = min_node->key;

    int c_num = checkChildNum(n->right);
    char side = checkParentSide(n->right);

    if (c_num == 0) {
        delete0(n->right, side);
    } else if (c_num == 1) { 
        if (n->right->right != NULL) {
            n->right = n->right->right;
        } else {
            min_node->parent->left = min_node->right;
        }
    } else if (c_num == 2) {
        min_node->parent->left = min_node->right;
    }
}

// deleteはC++の予約語でした。。
void deleteN(int key) {
    Node *n = search(key);
    if (!n->parent) {
        cout << n->key << "is orphan" << endl;
        return;
    }

    // Node nはn->parentのleft or right?
    char side = checkParentSide(n);

    int c_num = checkChildNum(n);
    if (c_num == 0) {
        delete0(n, side);
    } else if (c_num == 1) { 
        delete1(n, side);
    } else if (c_num == 2) {
        delete2(n);
    }
}

void walkInOrder(Node *n) {
    if (n != NULL) {
        if (n->left != NULL) {
            walkInOrder(n->left);
        }
        cout << " " << n->key;
        if (n->right != NULL) {
            walkInOrder(n->right);
        }
    }
}

void printInOrder() {
    walkInOrder(root);
    cout << endl;
}

void walkPreOrder(Node *n) {
    if (n != NULL) {
        cout << " " << n->key;
        if (n->left != NULL) {
            walkPreOrder(n->left);
        }
        if (n->right != NULL) {
            walkPreOrder(n->right);
        }
    }
}

void printPreOrder() {
    walkPreOrder(root);
    cout << endl;
}

void printBinarySearchTree() {
    printInOrder();
    printPreOrder();
}

void makeRoot(string inst, int key) {
    if (inst != "insert") {
        cout << "error" << endl;
        return;
    }
    root = newNode(key);
}

void readInst() {
    int key;
    string inst;
    cin >> inst >> key;
    makeRoot(inst, key);

    for (int i = 1; i < m; i++) {
        cin >> inst;
        if (inst == "insert") {
            cin >> key;
            insert(key);
        } else if (inst == "print") {
            printBinarySearchTree();
        } else if (inst == "find") {
            cin >> key;
            find(key);
        } else if (inst == "delete") {
            cin >> key;
            deleteN(key);
        } else {
            cout << "invalid instruction" << endl;
            return;
        }
    }
}

int main() {
    cin >> m;
    readInst();

    return 0;
}