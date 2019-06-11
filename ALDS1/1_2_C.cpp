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

void Swap(string *c1, string *c2) {
    string tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

// Compare Card
bool Less(string c1, string c2) {
    int n1 = c1[1] - '0';
    int n2 = c2[1] - '0';
    return n1 < n2;
}

int main(){
    int n;
    cin >> n;

    string A_B[n];
    string A_S[n];

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        A_B[i] = tmp;
        A_S[i] = tmp;
    }

    // Bubble sort
    // stable sort
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; i < j; j--) {
            if (Less(A_B[j], A_B[j - 1])) {
                Swap(A_B + j - 1, A_B + j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << A_B[i] << " ";
        } else {
            cout << A_B[i] << endl;
        }
    }
    cout << "Stable" << endl;

    // Selection sort
    // NOT necessary stable
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (Less(A_S[j], A_S[minj])) {
                minj = j;
            }
        }
        if (i != minj) {
            Swap(A_S + i, A_S + minj);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << A_S[i] << " ";
        } else {
            cout << A_S[i] << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        if (A_B[i] != A_S[i]) {
            cout << "Not stable" << endl;
            break;
        }
        if (i == n - 1) {
            cout << "Stable" << endl;
        }
    }

    return 0;
}
