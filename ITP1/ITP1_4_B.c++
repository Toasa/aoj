#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main(){

    double r;
    cin >> r;
    cout << fixed;
    cout << setprecision(15) << r*r*M_PI << endl;
    cout << setprecision(15) << 2*r*M_PI << endl;

    return 0;
}
