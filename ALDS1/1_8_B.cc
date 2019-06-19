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

void find(int key) {
    Node *r = root;

    while (r) {
        if (r->key == key) {
            cout << "yes" << endl;
            return;
        }
        if (key < r->key) {
            r = r->left;
        } else {
            r = r->right;
        }
    }
    cout << "no" << endl;
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