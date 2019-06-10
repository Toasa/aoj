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


// Write a program of the Bubble Sort algorithm which sorts a sequence A in ascending order.
// The algorithm should be based on the following pseudocode:

// BubbleSort(A)
// 1 for i = 0 to A.length-1
// 2     for j = A.length-1 downto i+1
// 3         if A[j] < A[j-1]
// 4             swap A[j] and A[j-1]
// Note that, indices for array elements are based on 0-origin.

// Your program should also print the number of swap operations defined in line 4 of the pseudocode.

int main(){

    int n;
    cin >> n;

    vector<int> data(n);
    for(int i=0; i<n; i++){
        cin >> data[i];
    }

    int swapCount=0;
    for(int i=0; i<n; i++){
        for(int j=n-1; i+1<=j; j--){
            if(data[j]<data[j-1]){
                swapCount += 1;
                int tmp = data[j-1];
                data[j-1] = data[j];
                data[j] = tmp;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(i==n-1){
            cout << data[i] << endl;
            break;
        }
        cout << data[i] << " ";
    }

    cout << swapCount << endl;

    return 0;
}
