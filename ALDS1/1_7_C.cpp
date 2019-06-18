// Tree Walk
// Binary trees are defined recursively. 
// A binary tree T is a structure defined on a finite set of nodes that either

// contains no nodes, or
// is composed of three disjoint sets of nodes:
// - a root node.
// - a binary tree called its left subtree.
// - a binary tree called its right subtree.
// Your task is to write a program which perform tree walks
// (systematically traverse all nodes in a tree) based on the following algorithms:

// Print the root, the left subtree and right subtree (preorder).
// Print the left subtree, the root and right subtree (inorder).
// Print the left subtree, right subtree and the root (postorder).
// Here, the given binary tree consists of n nodes and evey node has a unique ID from 0 to n-1.

// Input
// The first line of the input includes an integer n, the number of nodes of the tree.

// In the next n linen, the information of each node is given in the following format:

// id left right

// id is the node ID, left is ID of the left child and right is ID of the right child. 
// If the node does not have the left (right) child, the left(right) is indicated by -1

// Output
// In the 1st line, print "Preorder", and in the 2nd line print a list of node IDs obtained by the preorder tree walk.

// In the 3rd line, print "Inorder", and in the 4th line print a list of node IDs obtained by the inorder tree walk.

// In the 5th line, print "Postorder", and in the 6th line print a list of node IDs obtained by the postorder tree walk.

// Print a space character before each node ID.

// Constraints
// 1 ≤ n ≤ 25


#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

typedef struct NODE {
    int id;
    int left;
    int right;
    int parent;
    int deg; // the number of children
    char type;  // i | l | r もし r && i => rootと出力、rも同様
} Node;

int n;
int root;
Node nodes[25];
int parentOf[25];

int calcDeg(int l, int r) {
    int deg;
    if (l != -1 && r != -1) {
        deg = 2;
    } else if ((l != -1 && r == -1) || (l == -1 && r != -1)) {
        deg = 1;
    } else {
        deg = 0;
    }
    return deg;
}

void setType(int id, int deg) {
    // rootだけ後に再設定する
    if (deg > 0) {
        nodes[id].type = 'i';
    } else {
        nodes[id].type = 'l';
    }
}

Node newNode(int id, int l, int r) {
    Node node;
    node.id = id;
    node.left = l;
    node.right = r;

    parentOf[l] = id;
    parentOf[r] = id;

    int deg = calcDeg(l, r);
    setType(id, deg);
    node.deg = deg;

    return node;
}

void store() {
    int id, left, right;
    for (int i = 0; i < n; i++) {
        cin >> id >> left >> right;
        nodes[id] = newNode(id, left, right);
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        parentOf[i] = -1;
    }
}

void solveParent() {
    for (int i = 0; i < n; i++) {
        nodes[i].parent = parentOf[i];
    }
}

void searchRoot() {
    for (int i = 0; i < n; i++) {
        int p = nodes[i].parent;
        if (p == -1) {
            root = i;
            nodes[i].type = 'r';
            return;
        }
    }
}

// Print the root, the left subtree and right subtree (preorder).
// Print the left subtree, the root and right subtree (inorder).
// Print the left subtree, right subtree and the root (postorder).

void printId(int id) {
    cout << " " << id;
}

// countは改行print用
void walkPreorder(int id) {
    int l = nodes[id].left;
    int r = nodes[id].right;

    printId(id);
        
    if (l != -1) {
        walkPreorder(l);
    }
    if (r != -1) {
        walkPreorder(r);
    }
}

void walkInorder(int id) {
    int l = nodes[id].left;
    int r = nodes[id].right;
    
    if (l != -1) {
        walkInorder(l);
    }

    printId(id);

    if (r != -1) {
        walkInorder(r);
    }
}

void walkPostorder(int id) {
    int l = nodes[id].left;
    int r = nodes[id].right;
        
    if (l != -1) {
        walkPostorder(l);
    }
    if (r != -1) {
        walkPostorder(r);
    }

    printId(id);
}

void printPreorder() {
    cout << "Preorder" << endl;
    walkPreorder(root);
    cout << endl;
};

void printInorder() {
    cout << "Inorder" << endl;
    walkInorder(root);
    cout << endl;
};

void printPostorder() {
    cout << "Postorder" << endl;    
    walkPostorder(root);
    cout << endl;
};

int main () {    
    cin >> n;
    init();

    store();

    solveParent();
    searchRoot();

    printPreorder();
    printInorder();
    printPostorder();

    return 0;
}
