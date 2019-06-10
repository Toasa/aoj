#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int Min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main(){
    int n;
    cin >> n;

    int v1, v2;
    cin >> v1 >> v2;
    int cost = v2 - v1;
    int min = Min(v1, v2);

    for (int i = 2; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < min) {
            min = tmp;
        } else {
            if (cost < tmp - min) {
                cost = tmp - min;
            }
        }
    }
    cout << cost << endl;
}
