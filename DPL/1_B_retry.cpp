#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n+1, 0);
    vector<int> w(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    // dp[i][j]: おもりがi以下のとき、j番目までの品物を考えたときの、価値の最大値
    vector< vector<int> > dp = vector< vector<int> >(W+1, vector<int>(n+1, 0));

    for (int j = 0; j <= n; j++) {
        for (int i = 1; i <= W; i++) {
            if (w[j] <= i) {
                dp[i][j+1] = max(dp[i-w[j]][j] + v[i], dp[i][j]);
            } else {
                dp[i][j+1] = dp[i][j];
            }
        }
    }

    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[W-1][n] << endl;

    return 0;
}
