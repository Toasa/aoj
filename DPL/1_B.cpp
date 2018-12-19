#include <iostream>

using namespace std;

int main() {
    int N, W;
    int value[110];
    int weight[110];

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> value[i] >> weight[i];
    }

    int dp[110][10010];

    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i] < w) {
                dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i+1][w] = dp[i][w];
            }
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}
