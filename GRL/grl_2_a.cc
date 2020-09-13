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
// #define INT_MAX 2147483647
using namespace std;
using ll = long long;
using P = pair<int,int>;

class Edge {
public:
    int weight;
    pair<int,int> vertexs;


    Edge(int weight, int src, int dst) {
        this->weight = weight;
        this->vertexs = make_pair(src, dst);
    }

    void info() {
        cout << "weight: " << this->weight << endl;
        cout << this->vertexs.first << " -> " << this->vertexs.second << endl;
    }

    bool operator< (const Edge &e1, const Edge &e2) {
        return e1.weight < e2.weight;
    };
};

// Kruskal's algorithm
int main() {
    Edge e = Edge(20, 0, 1);

    int V_num, E_num, i, j, s, t, w;
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    cin >> V_num >> E_num;

    int distance[V_num][V_num];
    rep(i, V_num) rep(j, V_num) distance[i][j] = -1;
    rep(i, E_num) {
        cin >> s >> t >> w;
        Edge e = Edge(s, t, w);
        Q.push(e);
        distance[s][t] = w;
    }

    return 0;
}
