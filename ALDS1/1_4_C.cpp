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

typedef struct Node {
    string str;
    struct Node *next;
} node;

// A C G T
// 2 3 5 7
int Weight[12] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

node *HashMap[3000];

node *newNode(string str) {
    node *n = new(node);
    n->str = str;
    n->next = NULL;
    return n;
}

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

void Insert(string str, int hv) {
    node *n = newNode(str);
    if (HashMap[hv] == NULL) {
        HashMap[hv] = n;
    } else {
        node *head = HashMap[hv];
        HashMap[hv] = n;
        n->next = head;
    }
}

void Find(string str, int hv) {
    node *n = HashMap[hv];
    while (n != NULL) {
        if (n->str == str) {
            cout << "yes" << endl;
            return;
        }
        n = n->next;
    }
    cout << "no" << endl;
}

// Memory Limit Exceeded :-(
int main(){
    int n; 
    cin >> n;

    string insts[n];
    string strs[n];
    for (int i = 0; i < n; i++) {
        cin >> insts[i] >> strs[i];
    }

    string inst, str;
    for (int i = 0; i < n; i++) {
        inst = insts[i];
        str = strs[i];

        int hv = calcHashVal(str);

        if (inst == "insert") {
            Insert(str, hv);
        } else {
            Find(str, hv);
        }
    }

    return 0;
}
