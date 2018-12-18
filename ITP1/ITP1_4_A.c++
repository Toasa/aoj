#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    int a,b;
    double n;
    cin >> a >> b;
    cout << a/b << endl;
    cout << a - (a/b)*b << endl;
    cout << fixed;
    cout << setprecision(15) << double(a)/double(b) << endl;

    return 0;
}
