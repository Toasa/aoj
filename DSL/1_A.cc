// 

// g++ -std=c++11 abc145_c.cc && ./a.out 
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
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

class Node {
public:
    int id;
    Node *parent;
    Node *child;
    
    Node(int id) {
        this->id = id;
        this->parent = nullptr;
        this->child = nullptr;
    }

    void printInfo() {
        cout << "id: " << this->id << endl;
    }

    void union_node(Node &another) {
        another.parent = this;
    }
};

int main() {
    int n, q, i, j, com, x, y;
    cin >> n >> q;

    Node nodes[n];

    int com_s[q];
    int x_s[q];
    int y_s[q];
    rep(i, q) {
        cin >> com_s[i] >> x_s[i] >> y_s[i];
    }

    // Node node1(30);
    // Node node2(40);

    // node1.union_node(node2);

    // node2.printInfo();
    // node2.parent->printInfo();

    return 0;
}
