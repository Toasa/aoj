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
    while(true){
        int h,w;
        cin >> h >> w;
        if(h==0 && w==0){
            break;
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;

    }
    return 0;
}
