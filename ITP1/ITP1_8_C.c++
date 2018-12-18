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

    string str;
    vector<int> v(26,0);

    while(getline(cin, str)){
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        for(int i=0; i<str.length(); i++){
            if('a'<=str[i] && str[i]<='z'){
                v[str[i]-'a'] += 1;
            }
        }
    }

    for(int i=0; i<26; i++){
        cout << char(i+97) << " " << ":" << " " << v[i] << endl;
    }

    return 0;
}
