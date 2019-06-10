#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;


int main(){

    int n,q;
    cin >> n >> q;

    queue<int> num_que;
    queue<string> str_que;

    int num;
    string str;

    for(int i=0; i<n; i++){
        cin >> str >> num;
        num_que.push(num);
        str_que.push(str);
    }

    int totalTime = 0;

    while(!num_que.empty()){
        str = str_que.front();
        num = num_que.front();
        if(num>q){
            num = num - q;
            num_que.pop();
            str_que.pop();
            num_que.push(num);
            str_que.push(str);
            totalTime += q;
        }else{
            totalTime += num;
            cout << str_que.front() << " " << totalTime << endl;
            str_que.pop();
            num_que.pop();
        }
    }


    return 0;
}
