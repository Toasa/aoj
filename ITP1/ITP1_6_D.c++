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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a;
    a = vector<vector<int>>(n,vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum += a[i][j] * b[j];
        }
        cout << sum << endl;
    }

    return 0;
}
