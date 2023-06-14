#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item {
    string nombre;
    int cantidad;
};

const int MAX_ITEMS = 100;
Item inventario[MAX_ITEMS];
int totalItems = 0;

// Function to add an item to the inventory
void agregarItem() {
    if (totalItems < MAX_ITEMS) {
        cout << "Enter the name of the item: ";
        cin >> inventario[totalItems].nombre;
        cout << "Enter the quantity: ";
        cin >> inventario[totalItems].cantidad;
        totalItems++;
        cout << "Item added successfully." << endl;
    } else {
        cout << "The inventory is full. Cannot add more items." << endl;
    }
}

// Function to display the inventory
void mostrarInventario() {
    if (totalItems == 0) {
        cout << "The inventory is empty." << endl;
    } else {
        cout << "Inventory:" << endl;
        for (int i = 0; i < totalItems; i++) {
            cout << "- Name: " << inventario[i].nombre << ", Quantity: " << inventario[i].cantidad << endl;
        }
    }
}

// Function to remove an item from the inventory
void quitarItem() {
    if (totalItems == 0) {
        cout << "The inventory is empty." << endl;
    } else {
        cout << "Enter the name of the item you want to remove: ";
        string nombreItem;
        cin >> nombreItem;
        bool encontrado = false;
        for (int i = 0; i < totalItems; i++) {
            if (inventario[i].nombre == nombreItem) {
                encontrado = true;
                // Shift items to fill the gap
                for (int j = i; j < totalItems - 1; j++) {
                    inventario[j] = inventario[j + 1];
                }
                totalItems--;
                cout << "Item removed successfully." << endl;
                break;
            }
        }
        if (!encontrado) {
            cout << "The item was not found in the inventory." << endl;
        }
    }
}

// Function to save the inventory to a file
void guardarInventario() {
    ofstream archivo("inventario.txt");
    if (archivo.is_open()) {
        archivo << totalItems << endl;
        for (int i = 0; i < totalItems; i++) {
            archivo << inventario[i].nombre << " " << inventario[i].cantidad << endl;
        }
        archivo.close();
        cout << "Inventory saved successfully." << endl;
    } else {
        cout << "Unable to open the file to save the inventory." << endl;
    }
}

// Function to load the inventory from a file
void cargarInventario() {
    ifstream archivo("inventario.txt");
    if (archivo.is_open()) {
        archivo >> totalItems;
        for (int i = 0; i < totalItems; i++) {
            archivo >> inventario[i].nombre >> inventario[i].cantidad;
        }
        archivo.close();
        cout << "Inventory loaded successfully." << endl;
    } else {
        cout << "Creating initial inventory..." << endl;
        agregarItem();
        guardarInventario();
    }
}

int main() {
    cargarInventario();

    int opcion;
    while (true) {
        cout << "1. Add item" << endl;
        cout << "2. Show inventory" << endl;
        cout << "3. Remove item" << endl;
        cout << "4. Save inventory" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarItem();
                break;
            case 2:
                mostrarInventario();
                break;
            case 3:
                quitarItem();
                break;
            case 4:
                guardarInventario();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}
//Isanchezv
