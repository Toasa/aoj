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

int n, i, j, u, v, k;
bool is_connected[150][150];

// 最初に発見した時刻
int d[150];
// 隣接リストを調べ終えた時刻
int f[150];

void init() {
    rep(i, n + 1) rep(j, n + 1) is_connected[i][j] = false;
    rep(i, n + 1) {
        d[i] = 0;
        f[i] = 0;
    }
    d[1] = 1;
}

// must handle infinite loop
int walkDepthFirst(int src_id, int time) {
    d[src_id] = time;

    int dst_id;
    rep(dst_id, n + 1) {
        if (is_connected[src_id][dst_id]) {
            // 未訪問
            if (d[dst_id] == 0) {
                time = walkDepthFirst(dst_id, time + 1);
            }
        }
    }

    time++;
    f[src_id] = time;
    return time;
}

int main() {
    cin >> n;
    init();

    rep(i, n) {
        cin >> u >> k;
        rep(j, k) {
            cin >> v;
            is_connected[u][v] = true;
        }
    }

    int time = 1;
    int node = 1;

    time = walkDepthFirst(node, time);

    rep(i, n) {
        int cur_node = i + 1;
        if (d[cur_node] == 0) {
            time = walkDepthFirst(cur_node, time + 1);
        }
    }

    rep(i, n) {
        cout << i + 1 << " " << d[i + 1] << " " << f[i + 1] << endl;
    }

    return 0;
}