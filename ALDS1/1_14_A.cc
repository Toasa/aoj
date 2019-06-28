#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

string T, P;
int lenP;

void store() {
    cin >> T >> P;
    lenP = P.length();
}

void solve() {
    for (int i = 0; i < T.length() - lenP + 1; i++) {
        if (T.substr(i, lenP) == P) {
            cout << i << endl;
        }
    }
}

int main() {
    store();
    if (T.length() < lenP) {
        return 0;
    }

    solve();

    return 0;
}