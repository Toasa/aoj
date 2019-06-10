#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int main(){

    // 反例
    // 10 4
    // 5
    // 3
    // 2
    // 1
    // 1
    // 6
    // 3
    // 4
    // 5
    // 7


    int n, k, tmp;
    cin >> n >> k;
    int sum=0;
    for(int i=0; i<n; i++){
        cin >> tmp;
        sum += tmp;
    }

    if(k==1){
        cout << sum << endl;
        return 0;
    }

    sum /= k;
    sum += 1;

    cout << sum << endl;

    return 0;
}
