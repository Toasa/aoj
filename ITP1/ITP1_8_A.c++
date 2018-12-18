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
    string str;
    getline(cin, str);
    for(int i=0; i<str.size(); i++){
        if('a'<=str[i] && str[i]<='z'){
            str[i] = toupper(str[i]);
        }else if('A'<=str[i] && str[i]<='Z'){
            str[i] = tolower(str[i]);
        }
    }

    cout << str << endl;

    return 0;
}
