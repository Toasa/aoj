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

    int n, q;
    cin >> n;
    vector<int> seq1(n);
    for(int i=0; i<n; i++){
        cin >> seq1[i];
    }
    cin >> q;
    vector<int> seq2(q);
    for(int i=0; i<q; i++){
        cin >> seq2[i];
    }

    sort(seq1.begin(), seq1.end());
    // seq1内のかぶり数の削除
    vector<int>::iterator itr = seq1.begin();
    while(itr!=seq1.end()){
        if(*itr==*(itr+1)){
            seq1.erase(itr);
            itr--;
        }
        itr++;
    }


    sort(seq2.begin(), seq2.end());
    vector<int>::iterator itr2 = seq2.begin();
    while(itr2!=seq2.end()){
        if(*itr2==*(itr2+1)){
            seq2.erase(itr2);
                itr2--;
        }
        itr2++;
    }

    int both_num = 0;
    int size1 = seq1.size();
    int size2 = seq2.size();
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(seq1[i]==seq2[j]){
                both_num += 1;
                break;
            }
        }
    }

    cout << both_num << endl;

    return 0;
}
