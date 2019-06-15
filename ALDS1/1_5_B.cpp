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

int n, cnt;
int A[500000];

#define MAX 1000000001;

void merge(int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    L[n1] = MAX;

    for (int i = 0; i < n2; i++) {
        R[i] = A[m + i];
    }
    R[n2] = MAX;
    
    int l_i = 0;
    int r_i = 0;
    for (int i = l; i < r; i++) {
        cnt++;
        if (L[l_i] < R[r_i]) {
            A[i] = L[l_i];
            l_i++;
        } else {
            A[i] = R[r_i];
            r_i++;
        }
    }
}

void mergeSort(int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m, r);
        merge(l, m, r);
    }
}

void printA() {
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << A[i] << " ";
        } else {
            cout << A[i] << endl;
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cnt = 0;

    mergeSort(0, n);
    printA();
    cout << cnt << endl;

    return 0;
}