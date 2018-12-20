#include <iostream>
#include <vector>
using namespace std;

typedef struct NODE {
    int id;
    int degree;
    int min_cost;
    bool done;
    vector<int> adj_n;
    vector<int> cost_to_n;
} node;

node **nodes;
int n;

node *gen_node(int id, int degree, vector<int> adj_n, vector<int> cost_to_n) {
    node *p = (node *)malloc(sizeof(node));
    p->id = id;
    p->degree = degree;
    if (id != 0) {
        p->min_cost = 100010;
    } else {
        p->min_cost = 0;
    }

    p->done = false;
    p->adj_n = adj_n;
    p->cost_to_n = cost_to_n;
    return p;
}

void solve() {
    for (int i = 0; i < n; i++) {
        node *src = (node *)malloc(sizeof(node));
        src = nodes[i];
        for (int j = 0; j < src->degree; j++) {
            node *dst = (node *)malloc(sizeof(node));
            dst = nodes[src->adj_n[j]];

            // 最小コストの更新
            //cout << "src: " << src->id << " dst: " << dst->id;
            //cout << " dst's min cost: " << dst->min_cost << " src's cost to dst: " << src->min_cost + src->cost_to_n[j] << endl;
            dst->min_cost = min(dst->min_cost, src->min_cost + src->cost_to_n[j]);

            // // dstの隣接nodeからsrcを消す処理
            // auto itr = find(dst->adj_n.begin(), dst->adj_n.end(), src->id);
            // int erase_index = itr - dst->adj_n.begin();
            // dst->degree--;
            // dst->adj_n.erase(dst->adj_n.begin() + erase_index);
            // dst->cost_to_n.erase(dst->cost_to_n.begin() + erase_index);
        }
    }
}

void print_node() {
    for (int i = 0; i < n; i++) {
        cout << nodes[i]->id << " " << nodes[i]->min_cost << endl;
    }
}

int main() {
    int u, k;
    cin >> n;

    nodes = (node **)malloc(sizeof(node) * n);

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        vector<int> adj_n;
        vector<int> cost_to_n;

        int node_tmp;
        int cost_tmp;
        for (int j = 0; j < k; j++) {
            cin >> node_tmp >> cost_tmp;
            adj_n.push_back(node_tmp);
            cost_to_n.push_back(cost_tmp);
        }
        node *p = gen_node(u, k, adj_n, cost_to_n);
        nodes[u] = p;
    }

    solve();
    solve();

    print_node();

    return 0;
}
