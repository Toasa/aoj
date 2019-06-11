// shell sort

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int insertionSort(int *A, int n, int g){
    int cnt = 0;
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (v < A[j] && 0 <= j) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
    // cout << "cnt: " << cnt << endl;
    return cnt;
}

void shellSort(int *A, int n) {
    
    int m = (int)sqrt(n);
    cout << m << endl;

    // このG_iのチョイスは本を見た(p.77)
    int G[m];
    for (int i = 0; i < m; i++) {
        G[i] = 3 * i + 1;
    }

    for (int i = m - 1; 0 <= i; i--) {
        if (i == 0) {
            cout << G[i] << endl;
        } else {
            cout << G[i] << " ";
        }
    }

    // for (int i = 0; i < m - 1; i++) {
    //     if (n - i - 1 > 0) {
    //         G[i] = n - i - 1;
    //     } else {
    //         G[i] = n - i;
    //     }
    //     cout << G[i] << " ";
    // }
    // G[m - 1] = 1;
    // cout << G[m - 1] << endl;

    int cnt = 0;
    for (int i = m - 1; 0 <= i; i--) {
        cnt += insertionSort(A, n, G[i]);
    }
    cout << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    shellSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
    return 0;
}
