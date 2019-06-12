#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    int val;
} node;

// insert x
// delete x
// deleteFirst
// deleteLast


node* newNode(int val) {
    node *n = new(node);
    n->val = val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

// 7
// insert 1000000000
// insert 999999999
// deleteLast
// insert 1234566890
// insert 5
// deleteFirst
// insert 7
// delete 5

int main(){
    int num;
    cin >> num;

    // Doubly Linked List
    //  [] <-> [] <-> [] ... [] <-> []
    // head                        tail
    node *head = NULL;
    node *tail = NULL;
    string inst;
    int val;

    for (int i = 0; i < num; i++) {
        cin >> inst;
        if (inst == "insert") {
            cin >> val;
            node *n = newNode(val);

            if (head != NULL) {
                head->prev = n;
                n->next = head;
                head = n;
            } else {
                head = n;
                tail = n;
            }
        } else if (inst == "delete") {
            cin >> val;

            node *n = head;
            bool not_found = false;
            while (n->val != val) {                
                if (n == tail) {
                    not_found = true;
                    break;
                }
                n = n->next;
            }
            // 見つからなかった
            if (not_found) {
                continue;
            }

            if (n->prev != NULL && n->next != NULL) {
                n->prev->next = n->next;
                n->next->prev = n->prev;
            } else if (n->prev == NULL && n->next != NULL) {
                head = n->next;
                head->prev = NULL;
            } else if (n->prev != NULL && n->next == NULL) {
                tail = n->prev;
                tail->next = NULL;
            } else {
                head = NULL;
                tail = NULL;
            }
        } else if (inst == "deleteFirst") {
            if (head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            } else {
                head = NULL;
                tail = NULL;
            }
        } else if (inst == "deleteLast") {
            if (tail->prev != NULL) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                head = NULL;
                tail = NULL;
            }      
        }
    }

    for (node *n = head; ; n = n->next) {
        if (n == tail) {
            cout << n->val << endl;
            break;
        } else {
            cout << n->val << " ";
        }
    }

    return 0;
}
