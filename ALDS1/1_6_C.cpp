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

typedef struct Card {
    int num;
    char suit;
} card;

int n;
card A[100000];
card B[100000];

card newCard(char suit, int num) {
    card c;
    c.num = num;
    c.suit = suit;
    return c; 
}

void swap(card *a, card *b) {
    card tmp = *a;
    *a = *b;
    *b = tmp;
}

// indexがi以下の要素はpivotより小さく、
// -----がiより大きい要素はpivotより大きくなるように並び替え
int partition(int l, int r) {
    int i = l - 1;
    int pivot = A[r].num;
    for (int j = l; j < r; j++) {
        if (A[j].num <= pivot) {
            i++;
            swap(A + i, A + j);
        }
    }
    swap(A + i + 1, A + r);
    return i + 1;
}

void quickSort(int l, int r) {
    if (l < r) {
        int m = partition(l, r);
        quickSort(l, m - 1);
        quickSort(m + 1, r);
    }
}

void merge(int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;

    card L[n1 + 1];
    card R[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = B[l + i];
    }
    L[n1] = newCard('X', 1000000001);

    for (int i = 0; i < n2; i++) {
        R[i] = B[m + i];
    }
    R[n2] = newCard('X', 1000000001);
    
    int l_i = 0;
    int r_i = 0;
    for (int i = l; i < r; i++) {
        if (L[l_i].num < R[r_i].num) {
            B[i] = L[l_i];
            l_i++;
        } else {
            B[i] = R[r_i];
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

void isStable() {
    for (int i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) {
            cout << "Not stable" << endl;
            return;
        }
    }
    cout << "Stable" << endl;
}

void printA() {
    cout << "quick sort" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i].suit << " " << A[i].num << endl;
    }
}

void printB() {
    cout << "merge sort" << endl;
    for (int i = 0; i < n; i++) {
        cout << B[i].suit << " " << B[i].num << endl;
    }
}

// 配列Aに対しquick sortを行い
// 配列Bに対しmerge sortを行う。
// merge sortは常にstableなため、quick sortのstable性を確かめるのに使う
int main(){
    cin >> n;

    char suit;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> suit >> num;
        card c = newCard(suit, num);
        A[i] = c;
        B[i] = c;
    }

    quickSort(0, n - 1);
    mergeSort(0, n);

    // isStable();
    printA();
    printB();

    return 0;
}