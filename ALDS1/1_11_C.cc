#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


bool is_connected[150][150];
int min_distance[150];

void init() {
    int i, j;

    rep(i, 150) {
        min_distance[i] = 150;
    }
    min_distance[0] = 0;
    min_distance[1] = 0;
    rep(i, 150) rep(j, 150) is_connected[i][j] = false;
}

void solveDepth(int src_id, int cur_depth) {
    int dst_id;
    rep(dst_id, 150) {
        if (is_connected[src_id][dst_id]) {
            if (cur_depth + 1 < min_distance[dst_id]) {
                min_distance[dst_id] = cur_depth + 1;
                solveDepth(dst_id, cur_depth + 1);
            }
        }
    }
}

int main() {
    int n, i, j, u, v, k;
    cin >> n;

    init();

    rep(i, n) {
        cin >> u >> k;
        rep(j, k) {
            cin >> v;
            is_connected[u][v] = true;
        }
    }

    solveDepth(1, 0);

    rep(i, n) {
        cout << i + 1 << " ";
        if (min_distance[i + 1] == 150) {
            cout << -1 << endl;
        } else {
            cout << min_distance[i + 1] << endl;
        }
        
    }

    return 0;
}