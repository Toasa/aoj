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
    int n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[i]: 0からi番目の要素までの、最長増加部分列の長さ
    // dp[i+1]
    int dp[100010] = {0}
    dp[0] = 0;

    return 0;
}
