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
vector <int> A(10000, 0);

// 1 ≤ n ≤ 2,000,000
// 0 ≤ A[i] ≤ 10,000

void printA() {
    int p_count = 0;
    for (int i = 0; i < 10000; i++) {
        if (A[i] != 0) {
            while (A[i] > 0) {
                if (p_count != n - 1) {
                    cout << i << " ";
                } else {
                    cout << i << endl;
                }
                p_count++;
                A[i]--;
            }
        }
    }
}

int main(){
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        A[num]++;        
    }

    printA();

    return 0;
}