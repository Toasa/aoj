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

// Your task is to write a program of a simple dictionary which implements the following instructions:

// insert str: insert a string str in to the dictionary
// find str: if the distionary contains str, then print 'yes', otherwise print 'no'

// Input
// In the first line n, the number of instructions is given. 
// In the following n lines, n instructions are given in the above mentioned format.

// Output
// Print yes or no for each find instruction in a line.

// Constraints
// A string consists of 'A', 'C', 'G', or 'T'
// 1 ≤ length of a string ≤ 12
// n ≤ 1000000

typedef struct Node {
    string str;
    struct Node *next;
} node;

// A C G T
// 2 3 5 7
int Weight[12] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int calcHashVal(string str) {
    int val = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'A') {
            val += 2 * Weight[i];
        } else if (str[i] == 'C') {
            val += 3 * Weight[i];
        } else if (str[i] == 'G') {
            val += 5 * Weight[i];
        } else if (str[i] == 'T') {
            val += 7 * Weight[i];
        }
    }
    return val;
}

int main(){
    int n; 
    cin >> n;

    string inst, str;
    for (int i = 0; i < n; i++) {
        cin >> inst >> str;
        if (inst == "insert") {
            int hv = calcHashVal(str);
            cout << hv << endl;
        } else {
            
        }
    }

    return 0;
}
