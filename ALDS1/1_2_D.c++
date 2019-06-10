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

vector<int> insertionSort(vector<int> A, int n, int g){
    for(int i=g; i<n; i++){
        int v = A[i];
        int j = i-g;
        int count;
        while(j>=0&&A[j]>v){
            A[j+g] = A[j];
            j=j-g;
            count++
        }
        A[j+g] = v;
    }

    return A;
}

vector<int> shellSort(vector<int> A, int n){
    int count =0;
    int m;
    G[] = {??????}
    for(int i=0; i<m; i++){
        insertionSort(A,n,G[i]);
    }
}

int main(){



    return 0;
}
