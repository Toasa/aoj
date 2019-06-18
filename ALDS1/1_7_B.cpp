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
    int sib;    // If two nodes have the same parent, they are siblings.
    int degree; // the number of children
    int depth;  // root is 0, children of root is 1, and so on...
    int height; // The height of a node in a tree is
                // the number of edges on the longest simple downward path from the node to a leaf.
    char type;  // i | l | r もし r && i => rootと出力、rも同様
} Node;

int n;
int root;
Node nodes[25];
int sibs[25];
int parentOf[25];
vector <int> leafs;

int storeSib(int l, int r) {
    int deg;
    if (l != -1 && r != -1) {
        sibs[l] = r;
        sibs[r] = l;
        deg = 2;
    } else if ((l != -1 && r == -1) || (l == -1 && r != -1)) {
        deg = 1;
    } else {
        deg = 0;
    }
    return deg;
}

Node newNode(int id, int l, int r) {
    Node node;
    node.id = id;
    node.left = l;
    node.right = r;
    // node.parent = -1;

    parentOf[l] = id;
    parentOf[r] = id;

    node.depth = 0;
    node.height = 0;

    node.sib = -1; // 後に更新する必要あり

    int deg = storeSib(l, r);
    node.degree = deg;

    if (deg > 0) {
        node.type = 'i'; // 後に更新する必要あり
    } else {
        node.type = 'l';
        leafs.push_back(id);
    }
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
        sibs[i] = -1;
        parentOf[i] = -1;
    }
}

string typeStr(char c) {
    if (c == 'i') {
        return "internal node";
    } else if (c == 'l') {
        return "leaf";
    } else if (c == 'r') {
        return "root";
    }
    return "";
}

void printBiTree() {
    // node id: parent = p , sibling = s , degree = deg, depth = dep, height = h, type
    for (int i = 0; i < n; i++) {
        Node node = nodes[i];
        cout << "node " << node.id;
        cout << ": parent = " << node.parent;
        cout << ", sibling = " << node.sib;
        cout << ", degree = " << node.degree;
        cout << ", depth = " << node.depth;
        cout << ", height = " << node.height;
        cout << ", " << typeStr(node.type) << endl;
    }    
}

void solveSibling() {
    for (int i = 0; i < n; i++) {
        if (sibs[i] != -1) {
            nodes[i].sib = sibs[i];
        }
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

void calcEachNodeHeight(int id, int h) {
    int p = nodes[id].parent;
    if (p != -1) {
        nodes[p].height = max(h, nodes[p].height);
        calcEachNodeHeight(p, h + 1);
    }
}

void calcHeight() {
    for (int i = 0; i < leafs.size(); i++) {
        int l = leafs[i];
        calcEachNodeHeight(l, 1);
    }
}

void calcDepth(int id, int d) {
    nodes[id].depth = d;
    if (nodes[id].degree > 0) {
        if (nodes[id].left != -1) {
            calcDepth(nodes[id].left, d + 1);
        }
        if (nodes[id].right != -1) {
            calcDepth(nodes[id].right, d + 1);
        }
    }
}

int main () {    
    cin >> n;
    init();

    store();

    solveSibling();
    solveParent();
    searchRoot();
    calcHeight();
    calcDepth(root, 0);

    printBiTree();
    return 0;
}
