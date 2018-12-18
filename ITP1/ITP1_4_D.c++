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

    long n, min, max, sum;
    sum=0;
    cin >> n;
    vector<long> ints(n);
    for(int i=0; i<n; i++){
        cin >> ints[i];
    }

    min = ints[0];
    max = ints[0];
    for(int i=0; i<n; i++){
        sum+=ints[i];
        if(max < ints[i]){
            max = ints[i];
        }
        if(min > ints[i]){
            min = ints[i];
        }
    }

    cout << min << " " << max << " " << sum << endl;

    return 0;
}
