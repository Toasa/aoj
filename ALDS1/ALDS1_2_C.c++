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

    int n;
    cin >> n;

    vector<string> cards(n);
    vector<string> cards_cpy(n);
    // stable性を判定するため(SelectionSortで必要)
    vector<char> chars(n);
    vector<char> chars_sorted(n);
    for(int i=0; i<n; i++){
        cin >> cards[i];
    }
    cards_cpy = cards;

    // BubbleSort
    for(int i=0; i<n; i++){
        for(int j=n-1; i+1<=j; j--){
            if(cards[j][1]-'0' < cards[j-1][1]-'0'){
                string tmp = cards[j];
                cards[j] = cards[j-1];
                cards[j-1] = tmp;
            }
        }
    }

    // bubblesortはstableであるため、そのときのalphabetの配列を取得し、
    // SelectionSortでのstable判定に用いる
    for(int i=0; i<n; i++){
        chars[i] = cards[i][0];
    }

    for(int i=0; i<n; i++){
        if(i==n-1){
            cout << cards[i] << endl;
            break;
        }
        cout << cards[i] << " ";
    }
    // BubbleSortはその機構上stable(inputされたalphabetのorderは保つ)
    cout << "Stable" << endl;


    cards = cards_cpy;
    // SelectionSort
    for(int i=0; i<n; i++){
        int mini = i;
        for(int j=i; j<n; j++){
            if(cards[j][1]-'0' < cards[mini][1]-'0'){
                mini = j;
            }
        }
        string tmp = cards[i];
        cards[i] = cards[mini];
        cards[mini] = tmp;
    }

    for(int i=0; i<n; i++){
        chars_sorted[i] = cards[i][0];
    }

    for(int i=0; i<n; i++){
        if(i==n-1){
            cout << cards[i] << endl;
            break;
        }
        cout << cards[i] << " ";
    }
    if(chars==chars_sorted){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

    return 0;
}
