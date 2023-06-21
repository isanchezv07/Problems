#include <iostream>

using namespace std;

bool esPrimo(int numero) {
    if (numero < 2) {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

pair<int, int> obtenerNumerosPrimosSumaPar(int numeroPar) {
    if (numeroPar % 2 != 0) {
        return make_pair(-1, -1);
    }

    int limite = numeroPar / 2;
    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i) && esPrimo(numeroPar - i)) {
            return make_pair(i, numeroPar - i);
        }
    }

    return make_pair(-1, -1);
}

int main() {
    // Solicitar al usuario un número par
    int numeroPar;
    cout << "Ingresa un número par: ";
    cin >> numeroPar;

    // Obtener los números primos que suman el número par dado
    pair<int, int> numerosPrimos = obtenerNumerosPrimosSumaPar(numeroPar);

    if (numerosPrimos.first != -1 && numerosPrimos.second != -1) {
        cout << "Números primos que suman " << numeroPar << ": " << numerosPrimos.first << " y " << numerosPrimos.second << endl;
    } else {
        cout << "No se encontraron números primos que sumen " << numeroPar << endl;
    }

    return 0;
}
//Isanchezv
//Se ha descubierto que la suma de dos números primos siempre es un número par. 
