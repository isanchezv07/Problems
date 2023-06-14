#include <iostream>

using namespace std;

int P[9][9];
bool flag = false;

// Process input
void input() {
    char t;
    cout << "Enter a chessboard, empty with 0 for no value:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> t;
            P[i][j] = t - '0';
        }
    }
}

// Process output
void output() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (P[i][j]) {
                cout << P[i][j];
            } else {
                cout << " ";
            }

            if (j % 3 == 2)
                cout << "  ";
        }
        if (i % 3 == 2)
            cout << endl;
        cout << endl;
    }
}

// Check if placing a number at a specific position satisfies the conditions
bool check(int n, int num) {
    // Row
    for (int i = 0; i < 9; i++) {
        if (P[n / 9][i] == num) {
            return false;
        }
    }

    // Column
    for (int i = 0; i < 9; i++) {
        if (P[i][n % 9] == num) {
            return false;
        }
    }

    // Palace
    int x = n / 9 / 3 * 3;
    int y = n % 9 / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (P[x + i][y + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// [n/9][n%9]
void dfs(int n) {
    // Success
    if (n > 80) {
        flag = true;
        return;
    }

    int x = n / 9, y = n % 9;
    // Skip filled values
    if (P[x][y]) {
        dfs(n + 1);
        return;
    }
    // Traverse
    for (int i = 1; i <= 9; i++) {
        // Check if valid
        if (check(n, i)) {
            // Assign and recursively call
            P[x][y] = i;
            dfs(n + 1);
            // Check if complete on exit, terminate if complete
            if (flag) {
                return;
            }
            // Not complete, reset the position
            P[x][y] = 0;
        }
    }
}

int main() {
    input();
    cout << endl << endl;
    dfs(0);
    output();
    return 0;
}

// Isanchezv
