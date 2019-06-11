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

using namespace std;

int Stoi(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        num = 10 * num + (s[i] - '0');
    }
    return num;
}

bool isOperator(char c) {
    return (c == '+') || (c == '-') || (c == '/') || (c == '*');
}

bool isNum(char c) {
    return '0' <= c && c <= '9';
}

int calc(char op, int n1, int n2) {
    if (op == '+') {
        return n1 + n2;
    } else if (op == '-') {
        return n1 - n2;
    } else if (op == '*') {
        return n1 * n2;
    } else {
        return n1 / n2;
    }
}

int main() {
    // このやり方だと、cin >> exp が、空白で読み込みをやめるためうまくいかない
    // 例えば, 1 2 + だと1までしか読み取らない
    string exp;
    cin >> exp;

    stack<int> stk;

    for (int head = 0; head < exp.size(); head++) {
        if (exp[head] == ' ') {
            continue;
        } else if (isOperator(exp[head])) {
            int n2 = stk.top();
            stk.pop();
            int n1 = stk.top();
            stk.pop();
            int res = calc(exp[head], n1, n2);
        } else {
            // number
            int tail = head;
            for (; isNum(exp[tail]); tail++) {
                if (exp.size() <= tail) {
                    break;
                }
            }
            int num = Stoi(exp.substr(head, tail - head));
            cout << num << endl;
            stk.push(num);
        }
    }

    int ans = stk.top();
    cout << ans << endl;

    return 0;
}
