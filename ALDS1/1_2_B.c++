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

    vector<int> data(n);
    for(int i=0; i<n; i++){
        cin >> data[i];
    }

    int swapCount=0;
    for(int i=0; i<n; i++){
        int mini = i;
        for(int j=i; j<n; j++){
            if(data[j]<data[mini]){
                mini = j;
            }
        }
        if(i != mini){
            int tmp = data[mini];
            data[mini] = data[i];
            data[i] = tmp;
            swapCount += 1;
        }
    }

    for(int i=0; i<n; i++){
        if(i==n-1){
            cout << data[i] << endl;
            break;
        }
        cout << data[i] << " ";
    }

    cout << swapCount << endl;

    return 0;
}
