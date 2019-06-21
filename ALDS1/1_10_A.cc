#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int memo[45];

void init() {
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i < 45; i++) {
        memo[i] = -1;
    }
}

int fibo(int i) {
    if (memo[i] != -1) {
        return memo[i];
    }
    memo[i] = fibo(i - 1) + fibo(i - 2);
    return memo[i];
}

int main() {
    int n;
    cin >> n;
    init();
    cout << fibo(n) << endl;

    return 0;
}