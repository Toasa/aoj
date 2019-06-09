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
    // n種類の品物、容量Wのナップサック
    int n, W;
    cin >> n >> W;

    int v[n];
    int w[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }

    vector< vector<int> > dp = vector< vector<int> >(101, vector<int>(10001, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (w[i] <= j) {
                // dp[i+1][j-w[i]]のi+1を忘れていた
                dp[i+1][j] = max(dp[i+1][j-w[i]] + v[i], dp[i][j]);
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}
