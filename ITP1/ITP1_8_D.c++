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

string EnqDeq_str(string s){
    char tmp;
    tmp = s[0];
    for(int i=0; i<s.size()-1; i++){
        s[i] = s[i+1];
    }
    s[s.size()-1] = tmp;
    return s;
}

string getSubStr(string s, int i, int j){
    vector<string> tmp(j-i+1);
    for(int h=0; h<j-i+1; h++){
        tmp[h] = s[i+h];
    }
    string subStr;
    for(int h=0; h<j-i+1; h++){
        subStr += tmp[h];
    }
    return subStr;
}

int main(){

    string s, p;
    cin >> s;
    cin >> p;

    for(int i=0; i<s.size(); i++){
        if(p==getSubStr(s,0,p.size()-1)){
            cout << "Yes" << endl;
            return 0;
        }
        s = EnqDeq_str(s);
    }

    cout << "No" << endl;

    return 0;
}
