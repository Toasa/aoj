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


    double x1, y1, x2, y2, dist;
    cin >> x1 >> y1 >> x2 >> y2;

    dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    cout << fixed;
    cout << setprecision(8) << dist << endl;

    return 0;
}
