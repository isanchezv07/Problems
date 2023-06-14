#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string.h>
#include "stdio.h"
#define MAX 4
#define MIN 0

using namespace std;

const char FINCAD = char(0); // Constant character for the end of string
const int MAXCAD = 20; // Maximum length of a string

const char SP = ' '; // Constant character for a space
char contrasena;
int i;
int contador = 0;

typedef char TCadena[MAXCAD + 1]; // Type definition for a string with a maximum length

struct Persona_R
{
    TCadena PASS; // Structure representing a person with a password
};

void pausa(); // Function to pause the program
void finalizar_programa(); // Function to end the program
void borrar_pantalla(); // Function to clear the screen
void Ingresar_PASS(Persona_R &p); // Function to input a password
void confirmar_PASS(Persona_R &p); // Function to confirm a password

void insertarPersonaTXT(TCadena nombreFichero, Persona_R p); // Function to insert a person's data into a text file
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p); // Function to write a person's data into a text file
void verificar_existencia_fichero(TCadena nombreFichero); // Function to verify the existence of a file
void verificar_existencia_de_usuario(TCadena nombreFichero); // Function to verify the existence of a user
void verificar_contrasena(TCadena nombreFichero, Persona_R &password); // Function to verify a password

int main()
{
    Persona_R p; // Declare a Person object
    Persona_R password; // Declare a Person object to hold a password
    char opcion;
    int num;
    bool fin, encontrado;
    TCadena nombre_usuario_registrado; // String to hold the registered username
    int opcion_menu;

    cout << "\n\tWELCOME TO THE LOGIN SYSTEM BY ISANCHEZV" << endl;
    cout << "        --------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Log in as a User" << endl;
    cout << "2. Register" << endl;
    cout << "3. Log in as a Guest" << endl;
    cout << "4. Exit the Program." << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "-> Enter Option: ";
    cin >> opcion_menu;

    if (opcion_menu == 4)
    {
        finalizar_programa();
    }

    if ((opcion_menu < MIN) || (opcion_menu > MAX))
    {
        try
        {
            system("cls");
            cout << "\n\n\t | THIS OPTION IS INCORRECT |\n";
            cout << "\n\n\t  ============================\n";
            system("cls");
            main();
        }
        catch (...)
        {
            cout << "\n AN ERROR HAS OCCURRED " << endl;
        }
    }

    switch (opcion_menu)
    {
    case 1:
        cout << "\nEnter your Username: ";
        cin >> nombre_usuario_registrado;
        verificar_existencia_fichero(nombre_usuario_registrado);

        verificar_contrasena(nombre_usuario_registrado, password);
        borrar_pantalla();
        main();
        break;

    case 2:
        cout << "\nEnter your New Username: ";
        cin >> nombre_usuario_registrado;
        verificar_existencia_de_usuario(nombre_usuario_registrado);
        Ingresar_PASS(p);
        insertarPersonaTXT(nombre_usuario_registrado, p);
        borrar_pantalla();
        main();
        break;

    case 3:
        cout << "\nHELLO GUEST\n";
        borrar_pantalla();
        main();
        break;
    }
    return 0;
}

void finalizar_programa()
{
    borrar_pantalla();
    printf("The program has been CLOSED");
    exit(0);
}

void pausa()
{
    system("PAUSE");
}

void borrar_pantalla()
{
    system("CLS");
}

void Ingresar_PASS(Persona_R &p)
{
    cout << "Enter your New Password: ";
    cin >> p.PASS;
    cout << "\nREGISTRATION SUCCESSFUL" << endl;
}

void confirmar_PASS(Persona_R &password)
{
    cout << "Enter your Password: ";
    cin >> password.PASS;
}

void insertarPersonaTXT(TCadena nombreFichero, Persona_R p)
{
    ofstream out;
    out.open(nombreFichero, ios::app);

    if (out.bad())
    {
        out.open(nombreFichero);
    }

    EscribePersonaFicheroTXT(out, p);
    out.close();
}

void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p)
{
    fichero << p.PASS << SP;
}

void verificar_existencia_fichero(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout << "\nINCORRECT USERNAME.....PLEASE TRY AGAIN\n" << endl;
        borrar_pantalla();
        main();
    }
    else
    {
        cout << "\nCORRECT USERNAME\n" << endl;
    }
}

void verificar_existencia_de_usuario(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout << "\nAVAILABLE USERNAME\n" << endl;
    }
    else
    {
        cout << "\nThis Username already exists.....PLEASE TRY AGAIN\n" << endl;
        borrar_pantalla();
        main();
    }
}

void verificar_contrasena(TCadena nombreFichero, Persona_R &password)
{
    string cadena;
    string contrase;
    cout << "Enter your Password: ";
    cin >> password.PASS;
    ifstream fichero(nombreFichero, ios::in);

    while (!fichero.eof())
    {
        fichero >> cadena;
    }

    if (cadena != password.PASS)
    {
        cout << "\nIncorrect Password.....PLEASE TRY AGAIN\n" << endl;
        fichero.close();
    }

    if (cadena == password.PASS)
    {
        cout << "\nYour Password is CORRECT..!!!\n" << endl;
        cout << "\nWELCOME\n" << endl;
    }
}
//Isanchezv
