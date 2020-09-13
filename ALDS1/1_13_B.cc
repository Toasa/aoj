#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

typedef struct MOVE {
    int B[9];
    int n;
} Move;

queue<Move> que;

int goal;

int Hash(int B[9]) {
   return 0; 
}

void store() {
    int goalB[9];
    for (int i = 0; i < 9; i++) {
        cin >> goalB[i];
    }
    goal = Hash(goalB);
}

Move initMove() {
    Move m;
    for (int i = 1; i < 9; i++) {
        m.B[i - 1] = i;
    }
    m.B[8] = 0;
    m.n = 0;
    return m;
}

void pushLegalMoves(Move m) {
    
}

int solve() {
    Move m;
    int hashVal;
    while (!que.empty()) {
        m = que.pop();
        hashVal = Hash(m.B);
        if (hashVal == goal) {
            return m.n;
        } else {
            pushLegalMoves(m);
        }
    }
}

int main() {
    store();
    Move init = initMove();
    que.push(init);

    cout << solve() << endl;

    return 0;
}