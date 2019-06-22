#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int q;
string strs[310];
int memo[1010][1010];

void initMemo(int l1, int l2) {
    for (int i = 0; i <= l1; i++) {
        memo[0][i] = 0;
    }

    for (int i = 0; i <= l2; i++) {
        memo[i][0] = 0;
    }
}

void store() {
    cin >> q;
    for (int i = 0; i < 2 * q; i++) {
        cin >> strs[i];
    }
}

// Longest Common Subsequence
void LCS(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    initMemo(l1, l2);

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }            
        }
    }

    cout << memo[l1][l2] << endl;
}

void AllLCS() {
    for (int i = 0; i < 2 * q; i += 2) {
        LCS(strs[i], strs[i + 1]);
    }
}


int main() {
    store();
    AllLCS();

    return 0;
}