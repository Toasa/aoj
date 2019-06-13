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

// You are given n packages of wi kg from a belt conveyor in order (i=0,1,...n−1).
// You should load all packages onto k trucks which have the common maximum load P.
// Each truck can load consecutive packages (more than or equals to zero) 
// from the belt conveyor unless the total weights of the packages in the sequence 
// does not exceed the maximum load P.

// Write a program which reads n, k and wi, 
// and reports the minimum value of the maximum load P to load all packages from the belt conveyor.

// Input
// In the first line, two integers n and k are given separated by a space character. 
// In the following n lines, wi are given respectively.

// Output
// Print the minimum value of P in a line.

// Constraints
// 1≤n≤100,000
// 1≤k≤100,000
// 1≤wi≤10,000

int main(){

    // 反例
    // 10 4
    // 5
    // 3
    // 2
    // 1
    // 1
    // 6
    // 3
    // 4
    // 5
    // 7

    int n, k;
    cin >> n >> k;

    int W[n];
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }

    return 0;
}
