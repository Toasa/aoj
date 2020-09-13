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

using namespace std;

int main() {
    int N, W, i, j;
    cin >> N >> W;
    int v[N];
    int w[N];
    rep(i, N) cin >> v[i] >> w[i];

    // dp[i][w_i]: i番目までの商品の中から、総重量が w_i 以下となるように選び取るときの価値の最大値
    // dp[i+1][w_i]: max(w[i])

    int dp[N+1][W+1];
    rep(i, N+1) rep(j, W+1) dp[i][j] = 0;

    rep(i, N) {
        int v_i = v[i];
        int w_i = w[i];

        for (int weight = 1; weight <= W; weight++) {
            for (int mul = 0; w_i * mul <= weight; mul++) {
                dp[i+1][weight] = max(dp[i][weight - (w_i * mul)] + v_i * mul, dp[i][weight]);
                // if (weight - (w_i * mul) >= 0) {
                //     dp[i+1][weight] = max(dp[i][weight - (w_i * mul)] + v_i * mul, dp[i][weight]);
                // } else {
                //     // dp[i+1][weight] = dp[i][weight];
                //     // break;
                // }
            }
            dp[i+1][weight] = max(dp[i+1][weight], dp[i][weight]);
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}
