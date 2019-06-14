#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int n, q;
int A[20];
int M[200];

void store() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> M[i];
    }
}

bool find(int val, int i) {
    // if の条件を以下のように書いていた。
    // Aの要素はsortされているとは限らないので、これは早計
    // if (val - A[i] < 0 || i >= n) {
    if (i >= n) {
        return false;
    } else if (val - A[i] == 0) {
        return true;
    }

    return find(val - A[i], i + 1) || find(val, i + 1);
}

int main(){
    store();

    for (int i = 0; i < q; i++) {
        if (find(M[i], 0)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
