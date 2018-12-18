#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>

using namespace std;


int main(){

    stack<string> stk;
    string str;
    while(cin >> str){
        if(str=="+" || str=="-" || str=="*"){
            int b = stoi(stk.top()); stk.pop();
            int a = stoi(stk.top()); stk.pop();
            if(str == "+"){
                stk.push(to_string(a+b));
            }else if(str=="-"){
                stk.push(to_string(a-b));
            }else if(str=="*"){
                stk.push(to_string(a*b));
            }
        }else{
            stk.push(str);
        }
        if(getchar()=='\n'){
            cout << stk.top() << endl;
            return 0;
        }
    }

    return 0;
}
