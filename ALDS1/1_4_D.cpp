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

int W[100000];
int n, k;

// 最大積載量がPのトラックk台に、いくつ荷物をつめるか？
int f(int P) {
    int count = 0;
    int pile_i = 0;
    for (int track = 0; track < k; track++) {
        int weight = 0;

        if (pile_i == n) {
            return count;
        }

        for (int i = pile_i; i < n; i++) {
            if (weight + W[i] <= P) {
                weight += W[i];
                // pile_i = i;
                count++;
            } else {
                weight = 0;
                pile_i = i;
                break;
            }            
        }
    }
    return count;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }

    cout << "----" << endl;
    cout << "P = 7: " << f(7) << endl;
    cout << "P = 8: " << f(8) << endl;
    cout << "P = 9: " << f(9) << endl;
    cout << "P = 10: " << f(10) << endl;
    cout << "P = 11: " << f(11) << endl;
    cout << "P = 12: " << f(12) << endl;
    cout << "P = 16: " << f(16) << endl;
    cout << "P = 20: " << f(20) << endl;
    cout << "P = 25: " << f(25) << endl;
    cout << "P = 28: " << f(28) << endl;

    return 0;
}
