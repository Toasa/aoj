#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int k;
bool clear_flag;
char B[8][8];

void init() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            B[i][j] = '.';
        }
    }
    clear_flag = false;
}

void putFixedPieces() {
    cin >> k;

    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        B[r][c] = 'Q';
    }
}

void printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
}

bool isFilled(int row) {
    for (int col = 0; col < 8; col++) {
        if (B[row][col] == 'Q') {
            return true;
        }
    }
    return false;
}

bool conflict(int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (0 <= row - i) {
            if (B[row - i][col] == 'Q') {
                return true;
            }
        }
        if (row + i < 8) {
            if (B[row + i][col] == 'Q') {
                return true;
            }
        }
        if (0 <= col - i) {
            if (B[row][col - i] == 'Q') {
                return true;
            }
        }
        if (col + i < 8) {
            if (B[row][col + i] == 'Q') {
                return true;
            }
        }
        if (0 <= row - i && 0 <= col - i) {
            if (B[row - i][col - i] == 'Q') {
                return true;
            }
        }
        if (0 <= row - i && col + i < 8) {
            if (B[row - i][col + i] == 'Q') {
                return true;
            }
        }
        if (row + i < 8 && 0 <= col - i) {
            if (B[row + i][col - i] == 'Q') {
                return true;
            }
        }
        if (row + i < 8 && col + i < 8) {
            if (B[row + i][col + i] == 'Q') {
                return true;
            }
        }
    }
    return false;
}

bool isComplete() {
    int count = 0;
    for (int col = 0; col < 8; col++) {
        if (B[0][col] == 'Q') {
            count++;
        }
        if (B[1][col] == 'Q') {
            count++;
        }
        if (B[2][col] == 'Q') {
            count++;
        }
        if (B[3][col] == 'Q') {
            count++;
        }
        if (B[4][col] == 'Q') {
            count++;
        }
        if (B[5][col] == 'Q') {
            count++;
        }
        if (B[6][col] == 'Q') {
            count++;
        }
        if (B[7][col] == 'Q') {
            count++;
        }
    }

    return count == 8;
}

void solve(int row) {
    if (clear_flag) {
        return;
    }
    if (isComplete()) {
        printBoard();
        clear_flag = true;
        return;
    }
    while (isFilled(row)) {
        row++;
    }
    for (int col = 0; col < 8; col++) {
        if (!conflict(row, col)) {
            B[row][col] = 'Q';
            solve(row + 1);
            B[row][col] = '.';
        }
    }
}

int main() {
    init();
    putFixedPieces();
    solve(0);
    return 0;
}