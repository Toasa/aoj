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

    long a,b,gcd;
    cin >> a >> b;
    if(b>a){
        int tmp = b;
        b = a;
        a = tmp;
    }
    while(b!=0){
        int tmp2 = a;
        a = b;
        b = tmp2%b;
        // aとbの移り変わりを表示したいとき
        // cout << a << " " << b << endl;
    }

    cout << a << endl;

    return 0;
}
