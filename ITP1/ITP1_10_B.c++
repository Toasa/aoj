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

int main(){


    int a,b,c,C;
    double a_d, b_d, c_d;
    cin >> a >> b >> C;
    a_d = double(a);
    b_d = double(b);
    C = double(C);

    // change to radian
    double C_rad;
    C_rad = C/180.0 * M_PI;

    double S, L, h;

    h = b_d*sin(C_rad);
    S = a_d*h*0.5;
    c_d = sqrt(a_d*a_d + b_d*b_d - 2*a_d*b_d*cos(C_rad));
    L = a_d+b_d+c_d;

    cout << fixed;
    cout << setprecision(10) << S << endl;
    cout << setprecision(10) << L << endl;
    cout << setprecision(10) << h << endl;

    return 0;
}
