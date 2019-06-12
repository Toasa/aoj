#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

bool linearSearch(int S[], int BANPEI, int t) {
    int j = 0;
    while (S[j] != t) {
        j++;
        if (S[j] == BANPEI) {
            return false;
        }
    }
    return true;
}

int main(){
    int n, q, c;
    cin >> n;
    int S[n+1];
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    // 番兵値
    int BANPEI = 10010;
    S[n] = BANPEI;

    cin >> q;
    int T[q];
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }

    // counter
    c = 0;
    for (int i = 0; i < q; i++) {
        bool found = linearSearch(S, BANPEI, T[i]);
        if (found) {
            c++;
        }
    }
    cout << c << endl;

    return 0;
}
