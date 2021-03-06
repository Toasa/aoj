// 

// g++ -std=c++11 abc145_c.cc && ./a.out 
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int memo[50];
int n;

int fibo(int i) {
    if (memo[i] != 0) { return memo[i]; }

    int result = fibo(i - 1) + fibo(i - 2);
    memo[i] = result;
    return result;
}

int main() {
    int i;
    cin >> n;

    rep(i, n) memo[i] = 0;
    memo[0] = 1;
    memo[1] = 1;

    cout << fibo(n) << endl;

    return 0;
}
