// Insertion sort

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
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 6
    // 5 2 4 6 1 3
    // 2 5 4 6 1 3
    // 
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;

        while (0 <= j && v < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }








    // yaneurao ver.
    // for(int i=1; i<n; i++){
    //     int tmp = box[i];
    //     if(box[i-1] > tmp){
    //         int j=i;
    //         do{
    //             box[j] = box[j-1];
    //             --j;
    //         }while(j>0 && box[j-1]>tmp);
    //         box[j] = tmp;
    //     }

    //     for(int h=0; h<n; h++){
    //         if(h==n-1){
    //             cout << box[h] << endl;
    //         }else{
    //             cout << box[h] << " ";
    //         }
    //     }
    // }
    return 0;
}
