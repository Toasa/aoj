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

bool sum_rec(int index, vector<int> &A, int sum, int expected) {
    if (sum > expected) { return false; }
    if (index == A.size()) {
        return (sum == expected);
    }
    int new_sum = sum + A[index];
    index++;
    return sum_rec(index, A, new_sum, expected) || sum_rec(index, A, sum, expected);
}

int main() {
    int n, q;
    int i, j;
    cin >> n;
    vector<int> A(n);
    rep(i, n) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cin >> q;
    int m[q];
    rep(i, q) (cin >> m[i]);
    rep(i, q) {
        int M = m[i];
        int sum = 0;
        int index = 0;
        if (sum_rec(index, A, sum, M)) {
            cout << "yes" << endl; 
        } else {
            cout << "no" << endl; 
        }
    }

    return 0;
}

// int n, q;
// int A[20];
// int M[200];

// void store() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> A[i];
//     }

//     cin >> q;
//     for (int i = 0; i < q; i++) {
//         cin >> M[i];
//     }
// }

// bool find(int val, int i) {
//     // if の条件を以下のように書いていた。
//     // Aの要素はsortされているとは限らないので、これは早計
//     // if (val - A[i] < 0 || i >= n) {
//     if (i >= n) {
//         return false;
//     } else if (val - A[i] == 0) {
//         return true;
//     }

//     return find(val - A[i], i + 1) || find(val, i + 1);
// }

// int main(){
//     store();

//     for (int i = 0; i < q; i++) {
//         if (find(M[i], 0)) {
//             cout << "yes" << endl;
//         } else {
//             cout << "no" << endl;
//         }
//     }

//     return 0;
// }
