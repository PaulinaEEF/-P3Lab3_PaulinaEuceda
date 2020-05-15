#include <iostream>
#include <cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cout;
using std::cin;
using std::endl;

void borrarMatriz(int , char**&);
char** crearMatriz(int, int);
void imprimirMatriz(int , int, char** matriz);
void llenarMatriz(int x, int y, char**& matriz);
char** simulacion(int, int, char**&);
char** ponerBorde(int, int, char**);
char** recursiva(int tamanoX, int tamanoY, char** matriz, int turnos);

int main(int argc, char** argv) {
	//vamo a darle
	int opcion;
	
	while(opcion != 4){
	
		cout<<"		Menu"<<endl
			<<"1.- Jugar con matriz random"<<endl
			<<"2.- Jugar con matriz predefinida"<<endl
			<<"3.- Salir"<<endl
			<<"Ingrese la opcion que desea: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:{
				int tamanoX, tamanoY, cantTurnos;
				cout << "Ingrese el tamano en x del tablero: ";
				cin >> tamanoX;
				cout << "Ingrese el tamano en y del tablero: ";
				cin >> tamanoY;
				cout << "Ingrese la cantidad de turnos por hacer: ";
				cin >> cantTurnos;
				
				while(tamanoX <= 3 || tamanoY <=3){
					cout << "Tamanos muy pequenos."<<endl;
					cout << "Ingrese el tamano en x del tablero: ";
					cin >> tamanoX;
					cout << "Ingrese el tamano en y del tablero: ";
					cin >> tamanoY;
				}
				
				
				char** matriz = NULL;//instancia
	
				matriz = crearMatriz(tamanoX, tamanoY);
				
				llenarMatriz(tamanoX, tamanoY, matriz);
				imprimirMatriz(tamanoX, tamanoY, matriz);
				
				//recursiva(tamanoX, tamanoY, matriz, cantTurnos);
				for(int i=0; i<cantTurnos; i++){
					cin.get();
					matriz = simulacion(tamanoX, tamanoY, matriz);
					
					imprimirMatriz(tamanoX, tamanoY, matriz);
						
				}
				
				borrarMatriz(tamanoX, matriz);
				
				break;
			}
			case 2:{
				int turnos;
				cout << "Ingrese la cantidad de turnos por hacer: ";
				cin >> turnos;
				
				int x = 22;
				int y = 22;
				char temp_mat [22][22] = {	
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ','*','*',' ',' ',' '},
				{' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ','*',' ','*',' ',' '},
				{' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
				};
				char ** mat = new char*[y];
				for(int i = 0; i < y ; i++){
					mat[i] = new char[x];
					for(int j = 0; j < x ; j++){
						mat[i][j] = temp_mat[i][j];
					}
				}
				
				for(int i=0; i<turnos; i++){
					cin.get();
					mat = simulacion(x, y, mat);
					
					imprimirMatriz(x, y, mat);
						
				}
				//conway(mat, x, y, turnos);
					
				break;
			}	
				
			case 3:{
				cout<<"Bye"<<endl;
				opcion = 4;
				break;
			}
		}
	}
	return 0;
}

char** recursiva(int tamanoX, int tamanoY, char** matriz, int turnos){
	if(turnos!=0){
		cin.get();
		matriz = simulacion(tamanoX, tamanoY, matriz);
	
		imprimirMatriz(tamanoX, tamanoY, matriz);
		turnos--;
		recursiva(tamanoX, tamanoY, matriz, turnos);
	}
	
}

char** simulacion(int x, int y, char**& matriz){
	char** matrizTrab = NULL;//instancia
	
	matrizTrab = crearMatriz(x, y);
	matrizTrab = ponerBorde(x, y, matrizTrab);
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			int con = 0;
			if(matriz[i][j] == '*'){//si la casilla tiene un asterisco
				if( (i+1)!=x && (i-1)!=-1 && (j+1)!=y && (j-1)!=-1){
					if( matriz[i+1][j]=='*'){
						con++;
					}
					if(matriz[i-1][j]=='*'){
						con++;
					}
					if(matriz[i][j+1]=='*'){
						con++;
					}
					if(matriz[i][j-1] =='*'){
						con++;
					}
					if(matriz[i-1][j-1] =='*'){
						con++;
					}
					if(matriz[i-1][j+1] =='*'){
						con++;
					}
					if(matriz[i+1][j-1] =='*'){
						con++;
					}
					if(matriz[i+1][j+1] =='*'){
						con++;
					}
				}else{
					if((i+1)==x){
						if((j-1)==-1){
							if(matriz[i-1][j]=='*'){
								con++;
							}
							if(matriz[i-1][j+1]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
						}else if((j+1)==y){
							if(matriz[i-1][j]=='*'){
								con++;
							}
							if(matriz[i][j-1]=='*'){
								con++;
							}
							if(matriz[i-1][j-1]=='*'){
								con++;
							}
						}else{
							if(matriz[i-1][j]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
							if(matriz[i][j-1] =='*'){
								con++;
							}
							if(matriz[i-1][j-1]=='*'){
								con++;
							}
							if(matriz[i-1][j+1]=='*'){
								con++;
							}
						}
					}else if((i-1)==-1){
						if((j-1)==-1){
							if(matriz[i+1][j]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
							if(matriz[i+1][j+1]=='*'){
								con++;
							}
						}else if((j+1)==y){
							if(matriz[i+1][j]=='*'){
								con++;
							}
							if(matriz[i][j-1]=='*'){
								con++;
							}
							if(matriz[i+1][j-1]=='*'){
								con++;
							}
						}else{
							if(matriz[i+1][j]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
							if(matriz[i][j-1] =='*'){
								con++;
							}
							if(matriz[i+1][j-1] =='*'){
								con++;
							}
							if(matriz[i+1][j+1] =='*'){
								con++;
							}
						}	
					}else if((j+1)==y){
						if(matriz[i+1][j]=='*'){
							con++;
						}
						if(matriz[i+1][j-1]=='*'){
							con++;
						}
						if(matriz[i-1][j]=='*'){
							con++;
						}
						if(matriz[i][j-1] =='*'){
							con++;
						}
						if(matriz[i-1][j-1] =='*'){
							con++;
						}
					}else if((j-1)==-1){
						if(matriz[i+1][j]=='*'){
							con++;
						}
						if(matriz[i+1][j+1]=='*'){
							con++;
						}
						if(matriz[i-1][j]=='*'){
							con++;
						}
						if(matriz[i-1][j+1]=='*'){
							con++;
						}
						if(matriz[i][j+1] =='*'){
							con++;
						}
					}
					
				}
				if(con == 2 || con == 3){
					matrizTrab[i][j]='*';
				}else if(con < 2 ){
					matrizTrab[i][j]=' ';
				}else if(con > 3 ){
					matrizTrab[i][j]=' ';
				}
			}
			
			else if(matriz[i][j] == ' '){//si la casilla tiene un espacio
				if( (i+1)!=x && (i-1)!=-1 && (j+1)!=y && (j-1)!=-1){
					if( matriz[i+1][j]=='*'){
						con++;
					}
					if(matriz[i-1][j]=='*'){
						con++;
					}
					if(matriz[i][j+1]=='*'){
						con++;
					}
					if(matriz[i][j-1] =='*'){
						con++;
					}
					if(matriz[i-1][j-1] =='*'){
						con++;
					}
					if(matriz[i-1][j+1] =='*'){
						con++;
					}
					if(matriz[i+1][j-1] =='*'){
						con++;
					}
					if(matriz[i+1][j+1] =='*'){
						con++;
					}
				}else{
					if((i+1)==x){
						if((j-1)==-1){
							if(matriz[i-1][j]=='*'){
								con++;
							}
							if(matriz[i-1][j+1]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
						}else if((j+1)==y){
							if(matriz[i-1][j]=='*'){
								con++;
							}
							if(matriz[i][j-1]=='*'){
								con++;
							}
							if(matriz[i-1][j-1]=='*'){
								con++;
							}
						}else{
							if(matriz[i-1][j]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
							if(matriz[i][j-1] =='*'){
								con++;
							}
							if(matriz[i-1][j-1]=='*'){
								con++;
							}
							if(matriz[i-1][j+1]=='*'){
								con++;
							}
						}
					}else if((i-1)==-1){
						if((j-1)==-1){
							if(matriz[i+1][j]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
							if(matriz[i+1][j+1]=='*'){
								con++;
							}
						}else if((j+1)==y){
							if(matriz[i+1][j]=='*'){
								con++;
							}
							if(matriz[i][j-1]=='*'){
								con++;
							}
							if(matriz[i+1][j-1]=='*'){
								con++;
							}
						}else{
							if(matriz[i+1][j]=='*'){
								con++;
							}
							if(matriz[i][j+1]=='*'){
								con++;
							}
							if(matriz[i][j-1] =='*'){
								con++;
							}
							if(matriz[i+1][j-1] =='*'){
								con++;
							}
							if(matriz[i+1][j+1] =='*'){
								con++;
							}
						}	
					}else if((j+1)==y){
						if(matriz[i+1][j]=='*'){
							con++;
						}
						if(matriz[i+1][j-1]=='*'){
							con++;
						}
						if(matriz[i-1][j]=='*'){
							con++;
						}
						if(matriz[i][j-1] =='*'){
							con++;
						}
						if(matriz[i-1][j-1] =='*'){
							con++;
						}
					}else if((j-1)==-1){
						if(matriz[i+1][j]=='*'){
							con++;
						}
						if(matriz[i+1][j+1]=='*'){
							con++;
						}
						if(matriz[i-1][j]=='*'){
							con++;
						}
						if(matriz[i-1][j+1]=='*'){
							con++;
						}
						if(matriz[i][j+1] =='*'){
							con++;
						}
					}
					
				}
				if(con == 3){
					matrizTrab[i][j]='*';
				}
			}
			
		}
	}
	borrarMatriz(x, matriz);
	return matrizTrab;
	
}

void llenarMatriz(int x, int y, char**& matriz){
	int numeroRandom;
	srand((unsigned)time(0));
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if((i==0) || ( j ==y-1) ||(i==x-1) || (j ==0)){
				matriz[i][j] = '#';	
			}else{
				numeroRandom = rand() % 2;
				if(numeroRandom == 1){
					matriz[i][j] = '*';	
				}else{
					matriz[i][j] = ' ';	
				}
			}
			
			
		}
	}
	
}

char** ponerBorde(int x, int y, char** matriz){
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if((i==0) || ( j ==y-1) ||(i==x-1) || (j ==0)){
				matriz[i][j] = '#';	
			}
		}
	}
	return matriz;
	
}



char** crearMatriz(int x, int y){
	
	char** matriz = NULL;//instancia
	
	matriz = new char*[y];
	
	for(int i = 0; i < x; i++){
		matriz[i] = new char[y];
	}
	
	return matriz;
}

void borrarMatriz(int size, char**& matriz){
	if(matriz != NULL){
	
		for(int i = 0; i < size; i++){
			delete[] matriz[i];
		}
		
		delete[]matriz;
		matriz = NULL;
	}
}

void imprimirMatriz(int x, int y, char** matriz){
	if(matriz != NULL){
	
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				cout << matriz[i][j];
			}
			cout << endl;
		}
	}
	
}
