#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int n, m, q;

// int FM[100000][100000];
int Q[10000][2];
char visited[100000];
map <int, vector <int> > adjs;

void store() {
    cin >> n >> m;
    
    int s, t;
    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        // FM[s][t] = 1;
        // FM[t][s] = 1;
        adjs[s].push_back(t);
        adjs[t].push_back(s);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s >> t;
        Q[i][0] = s;
        Q[i][1] = t;
    }
}

void clearVisitedArr() {
    for (int i = 0; i < n; i++) {
        visited[i] = '\0';
    }
}

bool reachable(int src, int dst) {
    if (src == dst) {
        return true;
    }
    vector <int> Adjs = adjs[src];
    for (int i = 0; i < Adjs.size(); i++) {
        int next = Adjs[i];
        if (visited[next]) {
            continue;
        }
        visited[next] = 1;
        if (reachable(next, dst)) {
            return true;
        }
    }
    return false;
}

void answer() {
    for (int i = 0; i < q; i++) {
        int src = Q[i][0];
        int dst = Q[i][1];
        visited[src] = 1;
        if (reachable(src, dst)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        clearVisitedArr();
    }
}

int main() {
    store();
    answer();

    return 0;
}