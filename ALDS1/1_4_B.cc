// 

// g++ -std=c++11 abc145_c.cc && ./a.out 
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
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

bool isContained(int needle, vector<int> &haystack, int min, int max) {
    int mid = (max + min) / 2;
    if (max - min <= 2) {
        return (needle == haystack[min]) || (needle == haystack[max]) || (needle == haystack[mid]);
    }

    if (needle < haystack[mid]) {
        return isContained(needle, haystack, min, mid);
    } else if (needle > haystack[mid]) {
        return isContained(needle, haystack, mid, max);
    } else {
        return true;
    }
}

int main() {
    int n, q, i, j;
    cin >> n;

    // 重複あり
    vector <int> S(n);
    rep(i, n) cin >> S[i];
    sort(S.begin(), S.end());

    cin >> q;
    // すべて異なる
    vector <int> T(q);
    rep(i, q) cin >> T[i];

    int count = 0;
    rep(i, q) {
        int t = T[i];
        if (isContained(t, S, 0, S.size() - 1)) {
            // for debug
            // cout << t << " is contained" << endl;

            count++;
        }
    }
    cout << count << endl;

    return 0;
}
