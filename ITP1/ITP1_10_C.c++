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
        int n;
        double m, alpha;
        cin >> n;
        if(n==0){
            break;
        }
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
        }

        double sum = 0;
        for(int i=0; i<n; i++){
            sum += s[i];
        }
        m = double(sum)/double(s.size());

        double sum_a=0;
        for(int i=0; i<n; i++){
            sum_a += (s[i]-m)*(s[i]-m);
        }
        alpha = sqrt(sum_a/double(n));

        cout << fixed;
        cout << setprecision(8) << alpha << endl;


    }


    return 0;
}
