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





    // seq1内のかぶり数の削除

    // このかぶり削除にも問題がある
    // 15
    // 0 0 1 1 2 2 3 3 3 5 6 6 8 9 9 のとき

    // seq1はinputの段階で既にsort済
    vector<int>::iterator itr = seq1.begin();
    while(itr!=seq1.end()){
        if(*itr==*(itr+1)){
            // itr--;
            seq1.erase(itr);
            itr--;
        }
        itr++;
    }







    // seq1内整数の最大値、最小値の取得(Binary Searchに使用)
    vector<int>::iterator itr1_min = seq1.begin();
    vector<int>::iterator itr1_max = seq1.end();
    itr1_max--;
    int min_in_seq1 = *itr1_min;
    int max_in_seq1 = *itr1_max;

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

    int size1 = seq1.size()-1;
    // int size1 = seq1.size();
    int size2 = seq2.size();


    for(int i=0; i<size1+2; i++){
        cout << seq1[i] << endl;
    }








    // // すべてseq1のindex
    // int index = size1;
    // int index_max = size1;
    // int index_mid = size1/2;
    //
    // for(int i=0; i<size2; i++){
    //     int seq2_val = seq2[i];
    //     if(!(min_in_seq1<=seq2_val && seq2_val<=max_in_seq1)){
    //         continue;
    //     }
    //
    //     // min <= size2[i] <= maxのときのループ処理
    //     // seq2_valは固定
    //     index = index_mid;
    //
    //     while(true){
    //         if(seq2_val<seq1[index]){
    //             index /= 2;
    //             continue;
    //         }else if(seq1[index]<seq2_val){
    //
    //             index = index + (index_max-index)/2;
    //
    //             continue;
    //         }else{
    //             both_num += 1;
    //             break;
    //         }
    //     }
    // }
    //
    // cout << both_num << endl;

    return 0;
}
