#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 9; // Tamaño del sudoku

// Función para imprimir el sudoku
void printSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para comprobar si un número se puede colocar en una posición determinada del sudoku
bool isValid(int sudoku[N][N], int row, int col, int num) {
    // Comprobar si el número está en la fila
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == num) {
            return false;
        }
    }
    // Comprobar si el número está en la columna
    for (int i = 0; i < N; i++) {
        if (sudoku[i][col] == num) {
            return false;
        }
    }
    // Comprobar si el número está en el cuadrante
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

// Función para resolver el sudoku mediante backtracking
bool solveSudoku(int sudoku[N][N]) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    // Buscar una posición vacía
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
    // Si no hay más posiciones vacías, el sudoku está resuelto
    if (isEmpty) {
        return true;
    }
    // Probar con números del 1 al 9
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

// Función para generar un sudoku aleatorio
void generateSudoku(int sudoku[N][N]) {
    // Inicializar el sudoku a cero
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sudoku[i][j] = 0;
        }
    }
    // Resolver el sudoku vacío
    solveSudoku(sudoku);
    // Quitar números aleatorios para crear el sudoku con huecos
    srand(time(NULL));
    int numHoles = rand() % 40 + 20; // Número aleatorio de huecos entre 20 y 59
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

//Isanchezv