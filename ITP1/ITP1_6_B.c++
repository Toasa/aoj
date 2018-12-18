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
    int n;
    cin >> n;
    vector<int> s(13,0);
    vector<int> h(13,0);
    vector<int> c(13,0);
    vector<int> d(13,0);

    char str;
    int i;

    while(n>0){
        cin >> str >>i;
        switch (str) {
            case 'S':
                s[i-1] = i;
                break;
            case 'H':
                h[i-1] = i;
                break;
            case 'C':
                c[i-1] = i;
                break;
            case 'D':
                d[i-1] = i;
                break;
        }
        n -= 1;
    }
    for(int i=0; i<13; i++){
        if(s[i]==0){
            cout << "S" << " " << i+1 << endl;
        }
    }
    for(int i=0; i<13; i++){
        if(h[i]==0){
            cout << "H" << " " << i+1 << endl;
        }
    }
    for(int i=0; i<13; i++){
        if(c[i]==0){
            cout << "C" << " " << i+1 << endl;
        }
    }
    for(int i=0; i<13; i++){
        if(d[i]==0){
            cout << "D" << " " << i+1 << endl;
        }
    }


    return 0;
}
