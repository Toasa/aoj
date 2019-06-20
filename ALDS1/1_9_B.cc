#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int h;
int A[500000];

void store() {
    for (int i = 0; i < h; i++) {
        cin >> A[i];
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapfy(int i) {
    if (i >= h) {
        return;
    }
    int l_i = 2 * i + 1;
    int r_i = 2 * i + 2;
    int max_i = i;
    if (l_i < h && A[i] < A[l_i]) {
        max_i = l_i;
    }
    if (r_i < h && A[max_i] < A[r_i]) {
        max_i = r_i;
    }

    if (max_i != i) {
        swap(A + i, A + max_i);
        maxHeapfy(max_i);
    }
}

void buildMaxHeap() {
    for (int i = h / 2 - 1; 0 <= i; i--) {
        maxHeapfy(i);
    }
}

void printMaxHeap() {
    for (int i = 0; i < h; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}

int main() {
    cin >> h;
    store();
    buildMaxHeap();
    printMaxHeap();

    return 0;
}