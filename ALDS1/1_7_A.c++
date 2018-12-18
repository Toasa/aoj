#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

typedef struct node {
    int id;
    vector<int> child_id;
    int child_num;
    vector<struct node *> childs;
} Node;

int main() {
    int n;
    cin >> n;

    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    int k, id;

    for (int i = 0; i < n; i++) {
        Node *node = (Node *)malloc(sizeof(node));
        cin >> id >> k;
        node->id = id;
        node->child_num = k;

        node->child_id.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> node->child_id[j];
        }

        nodes[i] = node;
    }

    cout << "++++++" << endl;

    for (int i = 0; i < n; i++) {
        cout << nodes[i]->child_num << endl;
    }


    return 0;
}
