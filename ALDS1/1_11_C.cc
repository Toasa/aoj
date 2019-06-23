#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n;
vector <int> nodes[100];
queue <int> que;

bool visited[100];
int minDis[100];

void printMinDis();

void init() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        minDis[i] = -1;
    }
}

void store() {
    cin >> n;
    int u, k;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        vector <int> v(k);

        int id;
        for (int j = 0; j < k; j++) {
            cin >> id;
            v[j] = id - 1;
        }
        nodes[u - 1] = v;
    }
}

void enque(int id) {
    que.push(id);
    visited[id] = true;
}

int Deque() {
    int id = que.front();
    que.pop();
    return id;
}

vector <int> searchNonVisitedAdjs(int id) {
    vector <int> adjs;
    for (int i = 0; i < nodes[id].size(); i++) {
        int adj = nodes[id][i];
        if (!visited[adj]) {
            adjs.push_back(adj);
        }
    }
    return adjs;
}

void bfs() {
    enque(0);
    minDis[0] = 0;
    while (!que.empty()) {
        int node = Deque();
        vector <int> adjs = searchNonVisitedAdjs(node);
        for (int i = 0; i < adjs.size(); i++) {
            enque(adjs[i]);
            minDis[adjs[i]] = minDis[node] + 1;
        }
    }
}

void printMinDis() {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << minDis[i] << endl;
    }
}

int main() {
    store();
    init();
    bfs();
    printMinDis();

    return 0;
}