#include <iostream>

using namespace std;

int n, W;

int main() {
    cin >> n >> W;
    int v[n];
    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }

    int dp[n+1][W+1];
    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }

    for (int i = 0; i <= n; i++) {
        for (int weight = 1; weight <= W+1; weight++) {
            if (w[i] < weight) {
                dp[i+1][weight] = max(v[i] + dp[i][weight-w[i]], dp[i][weight]);
            } else {
                dp[i+1][weight] = dp[i][weight];
            }
        }
    }

    // print dp
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= W+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    cout << dp[n][W+1] << endl;
    return 0;
}
