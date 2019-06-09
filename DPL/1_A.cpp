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
    // m種類のコイン、n円支払う
    int n, m;
    cin >> n >> m;

    vector<int> dp(50001, 1 << 30);
    vector<int> c(m);

    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    // dp[i]: i円支払うときに必要な、最小のコイン枚数
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + c[j] > n) {
                break;
            }
            dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}
