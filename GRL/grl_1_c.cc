// 

// g++ -std=c++11 abc145_c.cc && ./a.out 
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
#define INT_MAX 2147483647
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int V_num, E_num, i, j, k, s, t, d;
    cin >> V_num >> E_num;

    int distance[V_num][V_num];

    rep(i, V_num) rep(j, V_num) { distance[i][j] = INT_MAX; }
    rep(i, E_num) {
        cin >> s >> t >> d;
        distance[s][t] = d;
    }

    rep(i, V_num) {
        distance[i][i] = 0;
    }

    rep(i, V_num) {
        int src = i;
        rep(j, V_num) {
            int dst = j;
            int dis = distance[src][dst];
            // src -> dst 間で直接つながるエッジがなくても、中継して繋がる可能性があるため、
            // 次の早期continueは
            // if (dis == INT_MAX) { continue; }
            rep(k, V_num) {
                if (distance[src][k] == INT_MAX) { continue; }
                if (distance[k][dst] == INT_MAX) { continue; }
                distance[src][dst] = min(distance[src][dst], distance[src][k] + distance[k][dst]);
            }
        }
    }

    rep(i, V_num) {
        if (distance[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, V_num) {
        rep(j, V_num) {
            int d = distance[i][j];
            if (j == V_num - 1) {
                if (d == INT_MAX) {
                    cout << "INF";
                } else {
                    cout << d;
                }
            } else {
                if (d == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << d << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
