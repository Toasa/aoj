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

typedef struct Point {
    float x;
    float y;
} point;

point newP(float x, float y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

point calc1(point p1, point p2) {
    point p;
    p.x = (p2.x + 2 * p1.x) / 3.0;
    p.y = (p2.y + 2 * p1.y) / 3.0;        
    return p;
}

point calc2(point p1, point p2) {
    point p;
    p.x = (3.0 * p2.x + 3.0 * p1.x - sqrt(3) * (p2.y - p1.y)) / 6.0;
    p.y = (3.0 * p2.y + 3.0 * p1.y + sqrt(3) * (p2.x - p1.x)) / 6.0;
    return p;
}

point calc3(point p1, point p2) {
    point p;
    p.x = (2 * p2.x + p1.x) / 3.0;
    p.y = (2 * p2.y + p1.y) / 3.0;
    return p;
}

void printP(point p) {
    cout << fixed;
    cout << setprecision(8) << p.x << " " << p.y << endl;
}

int n;

void rec(point head, point tail, int i) {
    if (i >= n) {
        return;
    }

    point p1 = calc1(head, tail);
    point p2 = calc2(head, tail);
    point p3 = calc3(head, tail);

    rec(head, p1, i + 1);
    printP(p1);
    rec(p1, p2, i + 1);
    printP(p2);
    rec(p2, p3, i + 1);
    printP(p3);
    rec(p3, tail, i + 1);
}

int main(){
    cin >> n;
    point head = newP(0.0, 0.0);
    point tail = newP(100.0, 0.0);

    printP(head);
    rec(head, tail, 0);
    printP(tail);
    
    return 0;
}
