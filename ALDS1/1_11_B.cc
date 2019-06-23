#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int n, Time;

// d[i]: node iを最初に発見したときの時刻
int d[100];
// f[i]: iの隣接リストを調べ終えた完了時刻
int f[100];
vector <int> nodes[100];

int stack[100];
// 先頭の一つ上、空の箇所を指す
int stktop;

void init() {
    stktop = 0;
    Time = 1;
    for (int i = 0; i < 100; i++) {
        d[i] = 0;
        f[i] = 0;
        stack[i] = 0;
    }
}

void store() {
    cin >> n;

    int u, k;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        vector <int> v(k);
        for (int j = 0; j < k; j++) {
            int adj;
            cin >> adj;
            v[j] = adj - 1;
        }
        nodes[u - 1] = v;
    }
}

bool isVisited(int id) {
    return d[id] != 0;
}

int mustVisitNextNode(int id) {
    vector <int> nextNodes = nodes[id];
    for (int i = 0; i < nextNodes.size(); i++) {        
        if (!isVisited(nextNodes[i])) {
            return nextNodes[i];
        }
    }
    return -1;
}

bool exsistNotVisitNode() {
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
            return true;
        }
    }
    return false;
}

int shouldVisitFirstNode() {
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
            return i;
        }
    }
    return -1;
}

void push(int id) {
    d[id] = Time;
    Time++;
    stack[stktop] = id;
    stktop++;
}

int top() {
    if (stktop <= 0) {
        return -1;
    }
    return stack[stktop - 1];
}

int pop() {
    int id = stack[stktop - 1];
    f[id] = Time;
    Time++;
    stktop--;
    return id;
}

bool isEmpty() {
    return (stktop <= 0);
}

void dfs() {
    int node;

    while (exsistNotVisitNode()) {
        node = shouldVisitFirstNode();
        push(node);
        
        while (!isEmpty()) {
            node = top();
            int next = mustVisitNextNode(node);
            if (next != -1) {
                push(next);
            } else {
                pop();
            }
        }
    }
}

void printTimeStamp() {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    init();
    store();

    dfs();

    printTimeStamp();
    return 0;
}