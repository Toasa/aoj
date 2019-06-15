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

int n;
int A[100000];

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// indexがi以下の要素はpivotより小さく、
// -----がiより大きい要素はpivotより大きくなるように並び替え
int partition(int l, int r) {
    int i = l - 1;
    int pivot = A[r];
    for (int j = l; j < r; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A + i, A + j);
        }
    }
    swap(A + i + 1, A + r);
    return i + 1;
}

void printA(int pivot_i) {
    for (int i = 0; i < n; i++) {
        if (i == pivot_i && i == n - 1) {
            cout << "[" << A[i] << "]" << endl;
        } else if (i == pivot_i) {
            cout << "[" << A[i] << "]" << " ";
        } else if (i == n - 1) {
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }        
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int pivot_i = partition(0, n - 1);

    printA(pivot_i);

    return 0;
}