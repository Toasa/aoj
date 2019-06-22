#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int n;
int R[100];
int C[100];
// dp[i]: M0, M1,..., Miまでの連鎖行列積の最小値
long long dp[100];

void store() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> R[i] >> C[i];
    }
}

void init() {
    dp[0] = 0;
    dp[1] = R[0] * R[1] * C[1];
}

void calcDP() {
    for (int i = 2; i < n; i++) {
        long long n1 = dp[i - 1] + R[0] * R[i] * C[i];
        long long n2 = dp[i - 2] + R[0] * R[i - 1] * C[i] + R[i - 1] * R[i] * C[i];
        // cout << "n1: " << n1 << endl;
        // cout << "n2: " << n2 << endl;
        dp[i] = min(n1, n2);
    }
}

int main() {
    store();
    init();
    if (n > 1) {
        calcDP();
    }
    cout << dp[n - 1] << endl;

    return 0;
}