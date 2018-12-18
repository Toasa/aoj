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

vector<int> rotate_x(vector<int> dice){
    int tmp1, tmp2, tmp3, tmp4;
    tmp1=dice[0]; tmp2=dice[1]; tmp3=dice[4]; tmp4=dice[5];
    dice[0]=tmp2; dice[1]=tmp4; dice[4]=tmp1; dice[5]=tmp3;
    return dice;
}

vector<int> rotate_y(vector<int> dice){
    int tmp1, tmp2, tmp3, tmp4;
    tmp1=dice[1]; tmp2=dice[2]; tmp3=dice[3]; tmp4=dice[4];
    dice[1]=tmp3; dice[2]=tmp1; dice[3]=tmp4; dice[4]=tmp2;
    return dice;
}

vector<int> rotate_z(vector<int> dice){
    int tmp1, tmp2, tmp3, tmp4;
    tmp1=dice[0]; tmp2=dice[2]; tmp3=dice[3]; tmp4=dice[5];
    dice[0]=tmp3; dice[2]=tmp1; dice[3]=tmp4; dice[5]=tmp2;
    return dice;
}

int getIndex(vector<int> dice, int n){
    int index;
    for(int i=0; i<6; i++){
        if(dice[i]==n){
            index = i;
            break;
        }
    }
    return index;
}

bool homDice(vector<int> dice1, vector<int> dice2){
    if(dice1[0]==dice2[0] && dice1[1]==dice2[1] && dice1[2]==dice2[2] && dice1[3]==dice2[3] && dice1[4]==dice2[4] && dice1[5]==dice2[5]){
        return true;
    }else{
        return false;
    }
}

int main(){

    vector<int> dice1(6);
    vector<int> dice2(6);
    for(int i=0; i<6; i++){
        cin >> dice1[i];
    }
    for(int i=0; i<6; i++){
        cin >> dice2[i];
    }

    vector<int> d1_dummy(6);
    vector<int> d2_dummy(6);
    d1_dummy = dice1;
    d2_dummy = dice2;
    sort(d1_dummy.begin(), d1_dummy.end());
    sort(d2_dummy.begin(), d2_dummy.end());
    if(d1_dummy != d2_dummy){
        cout << "No" << endl;
        return 0;
    }

    vector<int> d2_tmp(6);
    d2_tmp = dice2;

    // top面をあわせてy軸(1<=n<=4)回転
    // 計 6*4 = 24通りの総通りを試す
    // 1
    for(int i=0; i<4; i++){
        if(homDice(dice1, dice2)){
            cout << "Yes" << endl;
            return 0;
        }
        dice2 = rotate_y(dice2);
    }

    // 2
    dice2 = d2_tmp;
    dice2 = rotate_x(dice2);
    for(int i=0; i<4; i++){
        if(homDice(dice1, dice2)){
            cout << "Yes" << endl;
            return 0;
        }
        dice2 = rotate_y(dice2);
    }

    // 3
    dice2 = d2_tmp;
    dice2 = rotate_z(dice2);
    dice2 = rotate_z(dice2);
    dice2 = rotate_z(dice2);
    for(int i=0; i<4; i++){
        if(homDice(dice1, dice2)){
            cout << "Yes" << endl;
            return 0;
        }
        dice2 = rotate_y(dice2);
    }

    // 4
    dice2 = d2_tmp;
    dice2 = rotate_z(dice2);
    for(int i=0; i<4; i++){
        if(homDice(dice1, dice2)){
            cout << "Yes" << endl;
            return 0;
        }
        dice2 = rotate_y(dice2);
    }

    // 5
    dice2 = d2_tmp;
    dice2 = rotate_y(dice2);
    dice2 = rotate_z(dice2);
    for(int i=0; i<4; i++){
        if(homDice(dice1, dice2)){
            cout << "Yes" << endl;
            return 0;
        }
        dice2 = rotate_y(dice2);
    }

    // 6
    dice2 = d2_tmp;
    dice2 = rotate_x(dice2);
    dice2 = rotate_x(dice2);
    for(int i=0; i<4; i++){
        if(homDice(dice1, dice2)){
            cout << "Yes" << endl;
            return 0;
        }
        dice2 = rotate_y(dice2);
    }

    cout << "No" << endl;


    return 0;
}
