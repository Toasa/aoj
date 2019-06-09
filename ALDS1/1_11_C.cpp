#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

int n;

typedef struct NODE {
    int id;
    bool done;
    vector<int> adj_id;
} node;

node **nodes;

node *make_node(int id, vector<int> adj_id) {
    node *p = (node*)malloc(sizeof(node));
    p->id = id;
    p->adj_id = adj_id;
    p->done = false;
    return p;
}

int main() {
    cin >> n;
    nodes = (node**)malloc(sizeof(node) * n);

    for (int i = 0; i < n; i++) {
        int u, k;
        vector<int> adj_id;
        cin >> u >> k;
        int tmp;
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            adj_id.push_back(tmp);
        }
        nodes[u] = make_node(u, adj_id);
    }




}
