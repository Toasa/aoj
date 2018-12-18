#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

// void findStr(vector<string> strs, string str){
//     int size = strs.size();
//     if(size==0){
//         cout << "no" << endl;
//     }else{
//         for(int i=0; i<size; i++){
//             if(strs[i]==str){
//                 cout << "yes" << endl;
//                 break;
//             }else if(i==size-1 && strs[i]!=str){
//                 cout << "no" << endl;
//             }
//         }
//     }
// }

int main(){

    // TLE

    // int n;
    // cin >> n;
    //
    // vector<string> strs;
    //
    // string cmd;
    // string str;
    // for(int i=0; i<n; i++){
    //     cin >> cmd >> str;
    //     if(cmd=="insert"){
    //         strs.push_back(str);
    //     }else if(cmd=="find"){
    //         int size = strs.size();
    //         if(size==0){
    //             cout << "no" << endl;
    //         }else{
    //             for(int i=0; i<size; i++){
    //                 if(strs[i]==str){
    //                     cout << "yes" << endl;
    //                     break;
    //                 }else if(i==size-1 && strs[i]!=str){
    //                     cout << "no" << endl;
    //                 }
    //             }
    //         }
    //     }
    // }





    // TLE strの最初の文字を調べ、４種のvectorに格納

    // int n;
    // cin >> n;
    //
    // vector<string> strs_A;
    // vector<string> strs_C;
    // vector<string> strs_G;
    // vector<string> strs_T;
    //
    // string cmd;
    // string str;
    //
    // for(int i=0; i<n; i++){
    //     cin >> cmd >> str;
    //     if(cmd=="insert"){
    //         if(str[0]=='A'){
    //             strs_A.push_back(str);
    //         }else if(str[0]=='C'){
    //             strs_C.push_back(str);
    //         }else if(str[0]=='G'){
    //             strs_G.push_back(str);
    //         }else if(str[0]=='T'){
    //             strs_T.push_back(str);
    //         }
    //     }else if(cmd=="find"){
    //         if(str[0]=='A'){
    //             findStr(strs_A, str);
    //         }else if(str[0]=='C'){
    //             findStr(strs_C, str);
    //         }else if(str[0]=='G'){
    //             findStr(strs_G, str);
    //         }else if(str[0]=='T'){
    //             findStr(strs_T, str);
    //         }
    //     }
    // }

    set<string> str_set;
    int n;
    cin >> n;
    while(n--){
        string cmd, str;
        cin >> cmd >> str;
        if(cmd=="insert"){
            str_set.insert(str);
        }else if(cmd=="find"){
            bool result = (str_set.find(str) != str_set.end());
            if(result){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}
