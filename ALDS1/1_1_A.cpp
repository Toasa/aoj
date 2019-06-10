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
    vector<int> box(n);
    for(int i=0; i<n; i++){
        cin >> box[i];
    }

    // 初期の配列の状態を表示
    for(int h=0; h<n; h++){
        if(h==n-1){
            cout << box[h] << endl;
        }else{
            cout << box[h] << " ";
        }
    }

    // yaneurao ver.
    for(int i=1; i<n; i++){
        int tmp = box[i];
        if(box[i-1] > tmp){
            int j=i;
            do{
                box[j] = box[j-1];
                --j;
            }while(j>0 && box[j-1]>tmp);
            box[j] = tmp;
        }

        for(int h=0; h<n; h++){
            if(h==n-1){
                cout << box[h] << endl;
            }else{
                cout << box[h] << " ";
            }
        }

    }

    // for(int i=1; i<n; i++){
    //     int key = box[i];
    //     int j = i-1;
    //     while(j>=0 && box[j]>key){
    //         box[j+1] = box[j];
    //         j -= 1;
    //     }
    //     box[j+1] = key;
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
