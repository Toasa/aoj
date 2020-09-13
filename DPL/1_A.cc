// 

// g++ -std=c++11 abc145_c.cc && ./a.out 
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
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

int main() {
    int n, m, i, j;
    cin >> n >> m;
    int c[m];
    rep(i, m) {
        cin >> c[i];
    }

    // dp[i]: i円払う場合の、コインの最小枚数
    // dp[0],..., dp[k-1]が確定した状態で、dp[k]を導くことは可能か？
    // ＝＞　できる。以下の漸化式
    // dp[k] = min{dp[k-c0], dp[k-c1], ... , dp[k-cm]} + 1
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (i = 2; i <= n; i++) {

        int tmp_min = 2147483647;
        rep(j, m) {
            if (i >= c[j]) {
                if (dp[i - c[j]] < tmp_min) {
                    tmp_min = dp[i - c[j]];
                }
            }
        }
        dp[i] = tmp_min + 1;
    }

    cout << dp[n] << endl;

    return 0;
}
