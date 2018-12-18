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

    int n;
    cin >> n;

    vector<int> r(n);

    for(int i=0; i<n; i++){
        cin >> r[i];
    }

    int maxv = -2000000000;
    int minv = r[0];

    for(int i=1; i<n; i++){
        maxv = max(maxv, r[i]-minv);
        minv = min(minv, r[i]);
    }

    cout << maxv << endl;

    return 0;



    // TLE
    // int max = r[1] - r[0];
    //
    // for(int i=0; i<n-1; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(max<r[j]-r[i]){
    //             max = r[j]-r[i];
    //         }
    //     }
    // }
    //
    // cout << max << endl;

}
