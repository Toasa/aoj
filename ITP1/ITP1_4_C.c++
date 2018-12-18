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

    int a,b;
    char op;

    while(true){
        cin >> a >> op >> b;
        if(op=='?'){
            break;
        }
        if(op=='+'){
            cout << a+b << endl;
        }else if(op=='-'){
            cout << a-b << endl;
        }else if(op=='*'){
            cout << a*b << endl;
        }else if(op=='/'){
            cout << a/b << endl;            }
        }

    return 0;
}
