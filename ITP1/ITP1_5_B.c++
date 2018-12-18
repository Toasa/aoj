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

    int h,w;

    while(true){
        cin >> h >> w;
        if(h==0 && w==0){
            break;
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                // 一行目 or 最終行のとき
                if(i==0 || i==h-1){
                    if(j==w-1){
                        cout << "#" << endl;
                        break;
                    }
                    cout << "#";
                }else{
                    if(j==0){
                        cout << "#";
                        continue;
                    }else if(j==w-1){
                        cout << "#" << endl;
                        continue;
                    }else{
                        cout << ".";
                    }
                }
            }
        }
        cout << "" << endl;
    }

    return 0;
}
