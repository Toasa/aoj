#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int n;
int G[100][100];

void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            G[i][j] = 0;
        }
    }
}

void makeAdjMatrix() {
    int u, k, to;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> to;
            G[u - 1][to - 1] = 1;
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                cout << G[i][j];
            } else {
                cout << G[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    init();
    cin >> n;
    makeAdjMatrix();
    print();
    return 0;
}