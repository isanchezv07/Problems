#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string.h>
#include "stdio.h"
#define MAX 4
#define MIN 0

using namespace std;

const char FINCAD = char(0);
const int MAXCAD = 20;

const char SP = ' ';
char contrasena;
int i;
int contador=0;

typedef char TCadena[MAXCAD+1];
struct Persona_R
{
TCadena PASS;
};

void pausa();
void finalizar_programa();
void borrar_pantalla();
void Ingresar_PASS(Persona_R &p);
void confirmar_PASS(Persona_R &p);

void insertarPersonaTXT(TCadena nombreFichero, Persona_R p);
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p);
void verificar_existencia_fichero(TCadena nombreFichero);
void verificar_existencia_de_usuario(TCadena nombreFichero);
void verificar_contrasena(TCadena nombreFichero,Persona_R &password);

int main()
{
Persona_R p;;
Persona_R password;;
char opcion;
int num;
bool fin,encontrado;
TCadena nombre_usuario_registrado;
int opcion_menu;

cout << "\n	BIENVENIDOS AL SISTEMA DE LOGIN DE ISANCHEZV" << endl;
cout << "        »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»" << endl;
cout<< "«««««««««««««««««««««««««««««" << endl;
cout << "1. Ingresar como Usuario" << endl;
cout << "2. Registrarse" << endl;
cout << "3. Ingrersar como Visitante" << endl;
cout << "4. Salir del Programa." << endl;
cout << "««««««««««««««««««««««««««««" << endl;
cout << "-> Introduzca Opcion:  ";
cin >> opcion_menu;
if (opcion_menu==4) {finalizar_programa();}
if((opcion_menu<MIN)||(opcion_menu>MAX)){
try {        system("cls");
                 cout <<"\n\n\t | ESTA OPCION  ES INCORRECTA |\n";
                 cout <<"\n\n\t  ============================\n";
                 system("cls");
                 main();
    }
    catch(...)
	{cout << "\n UN ERROR HA OCURRIDO " << endl; } }

switch(opcion_menu)
{
case 1:
cout << "\nDigite su Nombre de Usuario:     ";
cin >> nombre_usuario_registrado;
verificar_existencia_fichero(nombre_usuario_registrado);

verificar_contrasena(nombre_usuario_registrado,password);
borrar_pantalla();main();
break;


case 2:
cout << "\nEscriba su Nuevo Nombre de Usuario:    ";
cin >> nombre_usuario_registrado;
verificar_existencia_de_usuario(nombre_usuario_registrado);
Ingresar_PASS(p);
insertarPersonaTXT(nombre_usuario_registrado,p);
borrar_pantalla();main();
break;

case 3:
cout << "\nHOLA VISITANTE \n";
borrar_pantalla();main();
break;
}
return 0;
}


void finalizar_programa()
{
borrar_pantalla();
printf("Se ha CERRADO el programa");
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
cout << "Escriba su Nuevo password:                 " ;
cin >> p.PASS;
cout<<"\nSE HA REGISTRADO CORRECTAMENTE"<<endl;
}
void confirmar_PASS(Persona_R &password)
{
cout << "Escriba su password:                 " ;
cin >> password.PASS;
}


void insertarPersonaTXT(TCadena nombreFichero, Persona_R p)
{
ofstream out;
out.open(nombreFichero,ios::app);

if (out.bad()){

out.open(nombreFichero);}
EscribePersonaFicheroTXT(out,p);
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
        cout<<"\nNombre de Usuario INCORRECTO.....INTENTELO DE NUEVO\n"<<endl; borrar_pantalla();main();
    }
    else
    {
        cout<<"\nNombre de Usuario CORRECTO\n"<<endl;
    }
}

void verificar_existencia_de_usuario(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout<<"\nNombre de Usuario DISPONIBLE\n"<<endl;
    }
    else
    {
    cout<<"\n Este Nombre de Usuario ya Existe.....INTENTELO DE NUEVO"<<endl; borrar_pantalla();main();
    }
}

void verificar_contrasena(TCadena nombreFichero,Persona_R &password)
{
string cadena;
string contrase;
cout << "Escriba su password:                 " ;
cin >> password.PASS;
ifstream fichero(nombreFichero,ios::in);

   while(!fichero.eof()) {
    fichero >> cadena;

  }
  if(cadena!=password.PASS){
  cout<<"\n Password es INCORRECTO.....INTENTELO DE NUEVO\n"<<endl;
  fichero.close();}

if(cadena==password.PASS){
cout<<"\n Su password es CORRECTA..!!! \n"<<endl;
cout<<"\n BIENVENIDO \n"<<endl;
}
}
//IsanchezV
