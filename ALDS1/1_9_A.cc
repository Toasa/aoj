#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int h;
int nodes[250];

void store() {
    for (int i = 0; i < h; i++) {
        cin >> nodes[i];
    }
}

void printKey(int i) {
    cout << ": key = " << nodes[i] << ", ";
}

void printParent(int i) {
    if (i == 0) {
        return;
    }
    cout << "parent key = " << nodes[(i - 1) / 2] << ", ";
}

void printLeft(int i) {
    if (2 * i + 1 < h) {
        cout << "left key = " << nodes[2 * i + 1] << ", ";
    }    
}

void printRight(int i) {
    if (2 * i + 2 < h) {
        cout << "right key = " << nodes[2 * i + 2] << ", ";
    }    
}

void printNode() {
    for (int i = 0; i < h; i++) {
        cout << "node " << i + 1;
        printKey(i);
        printParent(i);
        printLeft(i);
        printRight(i);
        cout << endl;
    }
}

int main() {
    cin >> h;
    store();
    printNode();

    return 0;
}