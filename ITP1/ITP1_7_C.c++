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
    int r,c;
    cin >> r >> c;
    vector<vector<int>> a;
    a = vector<vector<int>>(r+1,vector<int>(c+1,0));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            a[i][c] += a[i][j];
        }
    }

    for(int j=0; j<c; j++){
        for(int i=0; i<r; i++){
            a[r][j] += a[i][j];
        }
    }

    for(int i=0; i<r; i++){
        a[r][c] += a[i][c];
    }

    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            if(j==c){
                cout << a[i][c] << endl;
                break;
            }
            cout << a[i][j] << " ";
        }
    }

    return 0;
}
