#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int A[200000000];
int h; // 完全2分木は配列Aを用いて実現されている
       // 配列Aの[X, X, X, X, head, ?, ?, ?, ?]
       // ?は2分木に関係のない値、Xは2分木の要素。h = head

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

void insert(int key) {
    A[h] = key;
    h++;
    buildMaxHeap();
}

void extract() {    
    cout << A[0] << endl;
    A[0] = A[h - 1];
    // これ忘れてた;-)
    // ２分木の最後の値をrootに持ってきたので、heapサイズを一つ減らす
    h--;
    buildMaxHeap();
}

void readInst() {
    int key;
    string inst;
    do {
        cin >> inst;
        if (inst == "insert") {
            cin >> key;
            insert(key);
        } else if (inst == "extract") {
            extract();
        }
    } while (inst != "end");
}

// ティ.. TLE..
int main() {
    h = 0;
    readInst();

    return 0;
}