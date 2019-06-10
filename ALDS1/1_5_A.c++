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

int n, q;
vector<int> A(2000);

bool solve(int i, int v){
    if(v==0){
        return true;
    }
    if(i==n){
        return false;
    }
    bool res;
    if(A[i]<=v){
        res = solve(i+1, v) || solve(i+1, v-A[i]);
    }else{
        res = solve(i+1, v);
    }
    return res;
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    cin >> q;
    for(int i=0; i<q; i++){
        int M;
        cin >> M;
        if(solve(0, M)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

    return 0;
}
