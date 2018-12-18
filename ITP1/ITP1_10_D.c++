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

double dis_p(vector<int> x, vector<int>y, int p, int n){
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += pow(abs(x[i]-y[i]), p);
    }
    return pow(double(sum), 1.0/double(p));
}


int main(){


    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=0; i<n; i++){
        cin >> y[i];
    }

    double D_man, D_eu, D_3, D_che;

    D_man = dis_p(x,y,1,n);
    D_eu = dis_p(x,y,2,n);
    D_3 = dis_p(x,y,3,n);

    // D_che
    int tmp=0;
    for(int i=0; i<n; i++){
        if(abs(x[i]-y[i])>tmp){
            tmp = abs(x[i]-y[i]);
        }
    }
    D_che = double(tmp);

    cout << fixed;
    cout << setprecision(6) << D_man << endl;
    cout << setprecision(6) << D_eu << endl;
    cout << setprecision(6) << D_3 << endl;
    cout << setprecision(6) << D_che << endl;


    return 0;
}
