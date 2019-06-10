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

int main(){
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int swap_count = 0;
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            swap_count++;
            int tmp = A[i];
            A[i] = A[mini];
            A[mini] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    cout << swap_count << endl;

    return 0;
}
