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

    while(true){
        string x;
        cin >> x;
        if(x=="0"){
            break;
        }
        int sum=0;
        for(int i=0; i<x.size(); i++){
            sum += (x[i] - '0');
        }
        cout << sum << endl;
    }


    return 0;
}
