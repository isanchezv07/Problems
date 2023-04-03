#include <iostream>

using namespace std;

int P[9][9];
bool flag = false;

// Entrada de proceso 
void input(){
	char t;
	cout << "Introduzca un tablero de ajedrez, vacío con 0 para no hay valor \n";
	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 9; j ++){
			cin >> t;
			P[i][j] = t - '0';
		}
	}
}

// Salida del proceso 
void output(){
	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 9; j ++){
			
			if(P[i][j]){
				cout << P[i][j];	
			}else{
				cout << " ";
			}
			
			if(j%3 == 2) cout << "  ";
		}
		if(i%3 == 2) cout << endl;
		cout << endl;
	}
	
}

// Determinar si se colocará cumple con las condiciones 
bool check(int n, int num){
	
	// Fila  
	for(int i = 0; i < 9; i ++){
		if(P[n/9][i] == num){
			return false;
		}
	} 
	
	// columna 
	for(int i = 0; i < 9; i ++){
		if(P[i][n%9] == num){
			return false;
		}
	} 
	
	// Palacio
    int x = n / 9 / 3 * 3;
    int y = n % 9 / 3 * 3;
    for(int i = 0; i < 3; i ++){
    	for(int j = 0; j < 3; j ++){
    		if(P[x+i][y+j] == num){
    			return false;
    		}
    	}
    } 
    
    return true;
}

// [n/9][n%9]
void dfs(int n){
	
	// éxito 
	if(n > 80){
		flag = true;
		return;
	}
	
	int x = n/9, y = n%9;
	// salto de valor 
	if(P[x][y]){
		dfs(n+1);
		return;
	}
	// Atravesar 
	for(int i = 1; i <= 9; i ++){
		// juez 
		if(check(n, i)){
			// Asignación de éxito del juicio 
			P[x][y] = i;
			dfs(n+1);
			// Juzgar si está completo al salir, salir cuando esté completo 
			if(flag){
				return;
			}
			// no completado reinicia el tablero 
			P[x][y] = 0;
		}
	}
}

int main(){
	input();
	cout << endl << endl; 
	dfs(0);
	output();
	return 0;
} 

//Isanchezv 