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

    // dp[i][w_i]: i番目までの商品で総重量 w_i 以下となるときの最大価値
    // dp[i+1][w_i]: max(dp[i][W - w_i] + v[i+1], dp[i][w_i])
    int dp[N+1][W+1];
    rep(i, N+1) rep(j, W+1) dp[i][j] = 0;

    for(i = 1; i <= N; i++) {
        int v_i = v[i-1];
        int w_i = w[i-1];

        // cout << i << "th: val: " << v_i << " wei: " << w_i << endl;

        for (int weight = 1; weight <= W; weight++) {
            if (w_i > weight) {
                dp[i][weight] = dp[i-1][weight];
            } else {
                dp[i][weight] = max(dp[i-1][weight-w_i] + v_i, dp[i-1][weight]);
            }
        }
    }

    // rep(i, N+1) {
    //     cout << i << "th: ";
    //     rep(j, W+1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[N][W] << endl;

    return 0;
}
