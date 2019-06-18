#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

typedef struct Node {
    int id;
    int depth;
    int parent;
    char type; // r | i | l
    vector <int> childs;
    int childs_num;
} node;

int n;
int root;
node nodes[100000];
int parentOf[100000];

node newNode(int id, char type, int childs_num, vector<int> childs) {
    node N;
    N.id = id;
    N.type = type;
    N.depth = 0;
    N.childs = childs;    
    N.childs_num = childs_num;
    if (parentOf[id] != -1) {
        N.parent = parentOf[id];
    } else {
        N.parent = -1;
    }
    return N;
}

void init() {
    root = -1;
    for (int i = 0; i < n; i++) {
        parentOf[i] = -1;
    }
}

void store() {
    int id, k;
    for (int i = 0; i < n; i++) {
        cin >> id >> k;
        char type;
        if (k == 0) {
            type = 'l';
        } else {
            type = 'i';
        }
        vector <int> childs(k);
        int ch;
        for (int j = 0; j < k; j++) {
            cin >> ch;

            childs[j] = ch;
            parentOf[ch] = id;
        }
        
        nodes[id] = newNode(id, type, k, childs);
    }
}

void searchRoot() {
    for (int i = 0; i < n; i++) {
        if (parentOf[i] == -1) {
            nodes[i].type = 'r';
            root = i;
            return;
        }
    }
}

void solveParent() {
    for (int p = 0; p < n; p++) {
        node N = nodes[p];
        vector <int> childs = N.childs;
        int c_n = N.childs_num;
        for (int j = 0; j < c_n; j++) {
            nodes[childs[j]].parent = p;
        }
    }
}

void calcDepth(int id, int d) {
    nodes[id].depth = d;
    int c_n = nodes[id].childs_num;

    for (int i = 0; i < c_n; i++) {
        calcDepth(nodes[id].childs[i], d + 1);
    }
}

string printType(int id) {
    char t = nodes[id].type;
    if (t == 'r') {
        return "root";
    } else if (t == 'i') {
        return "internal node";
    } else {
        return "leaf";
    }
}

void printChild(int id) {
    vector <int> childs = nodes[id].childs;
    int c_n = nodes[id].childs_num;
    cout << "[";
    for (int i = 0; i < c_n; i++) {
        if (i != c_n - 1) {
            cout << childs[i] << ", ";
        } else {
            cout << childs[i];
        }
    }
    cout << "]" << endl;
}

void printNode(int id) {
    cout << "node " << id << ": parent = " << nodes[id].parent;
    cout << ", depth = " << nodes[id].depth << ", " << printType(id);
    cout << ", ";
    printChild(id);
}

void printTree() {
    for (int i = 0; i < n; i++) {
        printNode(i);
    }
}

int main() {     
    cin >> n;
    init();
    store();

    searchRoot();
    solveParent();
    calcDepth(root, 0);

    printTree();

    return 0;
}
