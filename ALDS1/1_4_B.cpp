#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

void fillOutArr(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
}

bool binarySearch(int A[], int t, int min_i, int max_i) {
    if ((max_i - min_i == 1) && (A[max_i] != t && A[min_i] != t)) {
        return false;
    }

    int mid_i = (min_i + max_i) / 2;
    if (A[mid_i] == t || A[min_i] == t || A[max_i] == t) {
        return true;
    } else if (t < A[mid_i]) {
        return binarySearch(A, t, min_i, mid_i);
    } else {
        return binarySearch(A, t, mid_i, max_i);
    }
}

// 出力結果は正しい、だがWA.

int main(){
    int n, q, c;

    cin >> n;
    // asc sorted
    int S[n];
    fillOutArr(S, n);

    cin >> q;
    // diff elems
    int T[q];
    fillOutArr(T, q);

    for (int i = 0; i < q; i++) {
        bool found = binarySearch(S, T[i], 0, n);
        if (found) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}
