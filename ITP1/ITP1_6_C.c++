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
    int n;
    cin >> n;
    vector<vector<int>> b1;
    b1 = vector<vector<int>>(3,vector<int>(10,0));
    vector<vector<int>> b2;
    b2 = vector<vector<int>>(3,vector<int>(10,0));
    vector<vector<int>> b3;
    b3 = vector<vector<int>>(3,vector<int>(10,0));
    vector<vector<int>> b4;
    b4 = vector<vector<int>>(3,vector<int>(10,0));


    int tmp_b, tmp_f, tmp_r, tmp_v;
    while(n > 0){
        cin >> tmp_b >> tmp_f >> tmp_r >> tmp_v;
        switch (tmp_b) {
            case 1:
                b1[tmp_f-1][tmp_r-1] += tmp_v;
                break;
            case 2:
                b2[tmp_f-1][tmp_r-1] += tmp_v;
                break;
            case 3:
                b3[tmp_f-1][tmp_r-1] += tmp_v;
                break;
            case 4:
                b4[tmp_f-1][tmp_r-1] += tmp_v;
                break;
        }
        n -= 1;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            if(j==9){
                cout << " " << b1[i][j] <<endl;
                break;
            }
            cout << " " << b1[i][j];
        }
    }

    cout << "####################" << endl;

    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            if(j==9){
                cout << " " << b2[i][j] <<endl;
                break;
            }
            cout << " " << b2[i][j];
        }
    }

    cout << "####################" << endl;

    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            if(j==9){
                cout << " " << b3[i][j] <<endl;
                break;
            }
            cout << " " << b3[i][j];
        }
    }

    cout << "####################" << endl;

    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            if(j==9){
                cout << " " << b4[i][j] <<endl;
                break;
            }
            cout << " " << b4[i][j];
        }
    }

    return 0;
}
