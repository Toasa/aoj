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
    int n, x, count;

    while(true){
        cin >> n >> x;
        if(n==0 && x==0){
            break;
        }
        count = 0;
        for(int i=1; i<=n-2; i++){
            for(int j=i+1; j<=n-1; j++){
                for(int h=j+1; h<=n; h++){
                    if(i+j+h==x){
                        count += 1;
                    }
                }
            }
        }
        cout << count << endl;
    }





    return 0;
}
