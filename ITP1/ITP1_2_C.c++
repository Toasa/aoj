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

    int n1, n2, n3, tmp;
    cin >> n1 >> n2 >> n3;

    if(n2>n3){
        tmp = n2;
        n2 = n3;
        n3 = tmp;
    }

    if(n1>n2){
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    if(n2>n3){
        tmp = n2;
        n2 = n3;
        n3 = tmp;
    }


    cout << n1 << " " << n2 << " " << n3 << endl;

    return 0;
}
