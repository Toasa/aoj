// 

// g++ -std=c++11 abc145_c.cc && ./a.out 
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

class Item {
public:
    int weight;
    int value;

    bool operator<(const Item &another) const {
        return this->weight < another.weight;
    }
};

Item init(int value, int weight) {
    Item item = Item{ weight, value};
    return item;
}

int main() {
    int N, W, i, j, v, w, tmp;
    cin >> N >> W;
    Item items[N];

    rep(i, N) {
        cin >> v >> w;
        items[i] = init(v, w);
    }

    // 重さを昇順にソート
    sort(items, items + N);

    // dp[weight]: weight以下で最大の価値
    // 最終的な答えは dp[N]
    int dp[N+1];
    dp[0] = 0;

    rep(i, N) {
        cout << "val: " << items[i].value << " wei: " << items[i].weight << endl;
    }

    // cout << dp[N] << endl;

    return 0;
}
