#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 9; // Size of the sudoku

// Function to print the sudoku
void printSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed at a particular position in the sudoku
bool isValid(int sudoku[N][N], int row, int col, int num) {
    // Check if the number exists in the row
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == num) {
            return false;
        }
    }
    // Check if the number exists in the column
    for (int i = 0; i < N; i++) {
        if (sudoku[i][col] == num) {
            return false;
        }
    }
    // Check if the number exists in the 3x3 quadrant
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the sudoku using backtracking
bool solveSudoku(int sudoku[N][N]) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    // Find an empty position
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudoku[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }
    // If there are no more empty positions, the sudoku is solved
    if (isEmpty) {
        return true;
    }
    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isValid(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (solveSudoku(sudoku)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

// Function to generate a random sudoku
void generateSudoku(int sudoku[N][N]) {
    // Initialize the sudoku to zero
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sudoku[i][j] = 0;
        }
    }
    // Solve the empty sudoku
    solveSudoku(sudoku);
    // Remove random numbers to create the sudoku with holes
    srand(time(NULL));
    int numHoles = rand() % 40 + 20; // Random number of holes between 20 and 59
    for (int i = 0; i < numHoles; i++) {
        int row = rand() % 9;
        int col = rand() % 9;
        while (sudoku[row][col] == 0) {
            row = rand() % 9;
            col = rand() % 9;
        }
        sudoku[row][col] = 0;
    }
}

int main() {
    int sudoku[N][N];
    generateSudoku(sudoku);
    printSudoku(sudoku);
    return 0;
}

// Isanchezv
