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

// dp[i]: s1とs2の先頭からi番目までの部分文字列に対し、最長共通部分列の長さ。0 <= i <= min(len(s1), len(s2))
// dp[0], ..., dp[min{len(s1), len(s2)}]
// dp[0], ..., dp[k-1]まで確定した場合、dp[k]は導出できるか？
// => 

int calcLongestCommonSubsequence(string s1, string s2) {
    // c1_prevは、s1とs2の最長共通部分列のs1の最後の文字
    char c1_prev, c2_prev;
    int ans;

    int min_len = min(s1.size(), s2.size());
    ans = (s1[0] == s2[0]) ? 1 : 0;

    c1_prev = s1[0];
    c2_prev = s2[0];

    for (int i = 1; i < min_len; i++) {
        if (s1[i] == s2[i]) {
            ans++;
            c1_prev = s1[i];
            c2_prev = s2[i];
        } else {
            if (s1[i] == s2[i - 1]) {
                ans++;
                c1_prev = s2[i - 1];
            } else if (s2[i] == s1[i - 1]) {
                ans++;
                c2_prev = s1[i - 1];
            } else if (s1[i] == c2_prev) {
                ans++;
                
            }
        }
    }

    return ans;
}

int main() {
    int i, j, q;
    cin >> q;
    string datasets[2 * q];
    for (i = 0; i < 2 * q; i += 2) {
        cin >> datasets[i];
        cin >> datasets[i + 1];
    }

    for (i = 0; i < q; i++) {
        cout << calcLongestCommonSubsequence(datasets[i], datasets[i + 1]) << endl;
    }

    return 0;
}
