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

    int n;
    cin >> n;

    deque<int> deq;
    string str;
    int m;

    for(int i=0; i<n; i++){
        cin >> str;
        if(str=="insert"){
            cin >> m;
            deq.push_front(m);
        }else if(str=="deleteFirst"){
            deq.pop_front();
        }else if(str=="deleteLast"){
            deq.pop_back();
        }else if(str=="delete"){
            // 一番めんどくさい処理なので、最後に書いた
            cin >> m;
            deque<int>::iterator itr = deq.begin();
            while(itr != deq.end()){
                if(*itr==m){
                    deq.erase(itr);
                    break;
                }
                itr++;
            }

        }
    }

    
    //
    // while(!deq.empty()){
    //     cout << *deq.begin() << " ";
    //     deq.pop_front();
    // }

    int d_s = deq.size();
    for(int i=0; i<d_s; i++){
        if(i==d_s-1){
            cout << *deq.begin() << endl;
            break;
        }
        cout << *deq.begin() << " ";
        deq.pop_front();
    }


    return 0;
}
