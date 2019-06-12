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

typedef struct proc {
    string name;
    int time;
} Proc;

Proc newProc(string n, int t) {
    Proc p = {n, t};
    return p;
}

int main(){
    int n,q;
    cin >> n >> q;

    queue<Proc> Q;

    for (int i = 0; i < n; i++) {
        string n;
        int t;
        cin >> n >> t;
        Q.push(newProc(n, t));
    }

    int all_time = 0;
    while (!Q.empty()) {
        Proc p = Q.front();
        if (p.time <= q) {
            all_time += p.time;
            cout << p.name << " " << all_time << endl;
            Q.pop();
        } else {
            all_time += q;
            Q.pop();
            p.time -= q;
            Q.push(p);
        }
    }

    return 0;
}
