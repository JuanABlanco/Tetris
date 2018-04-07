#include "conio2.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

char tablero_[11][16] = {' '}; // Mantiene la información del tablero
char tablero_antes_pieza[11][16] = {' '};
char pieza_[2][2] = {0};
char tecla_pulsada = 0;
char nombre [20]="\0";
int score;
int acuf=0, auxg=0, c=10, lineac=0, dlinea=0;
char rsp;
double time_spent;
// Para conocer donde esta la pieza
int columna_base_pieza = 0;
int fila_base_pieza = 0;

// Inicio del juego 
void inicio ()
{
	printf ("\t\t  _______   _______   _______   ______     ___    _______    ____    ____     \n");
	printf ("\t\t |       | |       | |       | |    _ |   |   |  |       |  |____|  |    |    \n");
	printf ("\t\t |_     _| |    ___| |_     _| |   | ||   |   |  |  _____|   ____   |_    |   \n");
	printf ("\t\t   |   |   |   |___    |   |   |   |_||_  |   |  | |_____   |____|    |   |   \n");
	printf ("\t\t   |   |   |    ___|   |   |   |    __  | |   |  |_____  |            |   |   \n");
	printf ("\t\t   |   |   |   |___    |   |   |   |  | | |   |   _____| |           _|   |   \n");
	printf ("\t\t   |___|   |_______|   |___|   |___|  |_| |___|  |_______|          |____|    \n");
	printf ("\n\n\n\t\t\t\t presione cualquier tecla para continuar \n\n\n");

		system ("color 05");
		sleep (0.75);
		system ("color 50");
		sleep (0.75);
		system ("color 07");
		sleep (0.75);
		system ("color 05");
		sleep (0.75);
		system ("color 50");
		sleep (0.75);
		system ("color 07");
		sleep (0.75);
		system ("color 70");
		getch();
		system ("cls");

}
// menu de inicio
void menu ()
{
	char letra_p;
	printf ("\t\t\t\t   __   __  _______  __    _  __   __ \n");
	printf ("\t\t\t\t  |  |_|  ||       ||  |  | ||  | |  |\n");
	printf ("\t\t\t\t  |       ||    ___||   |_| ||  | |  |\n");
	printf ("\t\t\t\t  |       ||   |___ |       ||  |_|  |\n");
	printf ("\t\t\t\t  |       ||    ___||  _    ||       |\n");
	printf ("\t\t\t\t  | ||_|| ||   |___ | | |   ||       |\n");
	printf ("\t\t\t\t  |_|   |_||_______||_|  |__||_______|\n");
	printf ("\n\n");
	printf ("\t\t\t\t\t\t Inicio (I)\n");
	printf ("\n\n");
	printf ("\t\t\t\t\t\t Ayuda (A)\n");
	letra_p = _getch ();
	if (letra_p=='I' || letra_p=='i')
	{
		system ("cls");
		printf ("Ingrese nombre del jugador\n");
		scanf (" %s", &nombre);
		system ("cls");
	} else {
		if (letra_p=='A' || letra_p=='a')
		{
			system ("cls");
			printf ("\t\t\t\t Como se juega\n");
			printf ("-La mecanica del Tetris es muy sencilla. Desde la parte superior de la pantalla comienzan a caer piezas de diferentes formas, que deberas rotar y colocar en la parte baja de la pantalla con el objetivo de completar una linea sin huecos. Cuando la linea se completa, esta desaparece y hace que todas las piezas que se encuentran encima desciendan, liberando espacio. Si dejas huecos sin llenar, las piezas se amontonan y ocupan espacio en la pantalla,");
			printf (" dificultando cada vez más tu tarea. \n Mientras mas lineas completas, mas puntos haces. Sin embargo, la dificultad del juego es progresiva, ya que las piezas comienzan a caer con mas rapidez a medida que completes lineas. Cuando estas llenan la pantalla, el juego se termina.\n");
			printf ("Como comprobaras al jugar, estrategia, capacidad de ordenamiento y rapidez mental son los atributos mas importantes para convertirte en un buen jugador de Tetris\n");
			printf ("\t\t\t\t Movimientos\n");
			printf ("-Derecha= h\n-Izquierda=f\n-Giro=g\n-Pausa=p\n-Salir del juego=x\n");
			system ("pause"); 
			
			system ("cls");
			printf ("Ingrese nombre del jugador\n");
			scanf (" %s", &nombre);
			system ("cls");
		}
	}
	
}
//
void chao ()
{
	system ("cls");
	printf (" _______  _______  __   __  _______          _______  __   __  _______  ______    __  \n");
	printf ("|       ||   _   ||  |_|  ||       |        |       ||  | |  ||       ||    _ |  |  | \n");
	printf ("|    ___||  |_|  ||       ||    ___|        |   _   ||  |_|  ||    ___||   | ||  |  | \n");
	printf ("|   | __ |       ||       ||   |___         |  | |  ||       ||   |___ |   |_||_ |  | \n");
	printf ("|   ||  ||       ||       ||    ___|        |  |_|  ||       ||    ___||    __  ||__| \n");
	printf ("|   |_| ||   _   || ||_|| ||   |___  _____  |       | |     | |   |___ |   |  | | __  \n");
	printf ("|_______||__| |__||_|   |_||_______||_____| |_______|  |___|  |_______||___|  |_||__| \n");
	printf ("\n\n\n");
	printf ("                               ___    ____                                            \n");
	printf ("                              |   |  |    |                                           \n");
	printf ("                              |___| |    _|                                           \n");
	printf ("                               ___  |   |                                             \n");
	printf ("                              |   | |   |                                             \n");
	printf ("                              |___| |   |_                                            \n");
	printf ("                                     |____|                                           \n");	
}
//Pausar el juego
void pausa()
{
 int g = 1000;
 system("cls");
 printf("El juego esta pausado\nPulse cualquier tecla para quitar la pausa\n");

 while(tecla_pulsada == 'P')
 {
  if(kbhit()) 
   {
    tecla_pulsada = toupper(_getch());
   }
 }
}
//terminar el juego 
bool game_over()
{
	if(tecla_pulsada == 'X') {
		chao();
		tecla_pulsada = ' ';
		return true;
	}
	
	for (int j=1; j<15; j++)
	{
		auxg=0;
		for  (int i=10; i>3; i--)
		{
				
			if (tablero_[i][j]=='*')
			{
				auxg++;
				if (auxg==8)
				{
					chao ();
					return true;
				}
			}
	
		}
	}
	return false;
}
// Tiempo in-game 
void tiempo (time_t begin)
{
	time_t end = time(NULL);
    time_spent = difftime(end, begin);
}


// Espacio del reloj y del puntaje
void marco (time_t begin)
{
	tiempo (begin);
	gotoxy (35,1);
	printf ("Tiempo en juego:");
	gotoxy (35,2);
	printf (" %.2lf ", time_spent);
	gotoxy (35,3);
	printf ("||||||");
	gotoxy (35,4);
	printf ("||||||");
	gotoxy (35,5);
	printf ("||||||");
	gotoxy (35,6);
	printf ("||||||");
	gotoxy (35,7);
	printf ("Player:");	
	gotoxy (35,8);
	printf (" %s", nombre);
	gotoxy (35,9);
	printf ("||||||");
	gotoxy (35,10);
	printf ("Puntaje:");
	gotoxy (35,11);
	printf (" %i", score);
	gotoxy (35,12);
	printf ("||||||");
}
// Sólo se ejecuta una vez
void inicializar_tablero(void) {
	for (int i=0; i < 12;i++)
	{
		for (int j=0; j<16; j++)
		{
			if (j==0 || j==15 || i==11 )
			{
				if(i > 3) tablero_ [i][j] = '|';	
			} else {
				tablero_ [i][j] = ' ';
			}
			
		}
	}
	// Asignar el contenido de tablero_antes_pieza
	for (int i=0; i < 12;i++)
	{
		for (int j=0; j<16; j++)
		{
			tablero_[i][j] = tablero_antes_pieza[i][j];	
		}
	}		
}

// 
void inicializar_tablero_antes_pieza(void){
	for (int i=0; i < 12;i++)
	{
		for (int j=0; j < 16; j++)
		{
			if (j==0 || j==15 || i==11 )
			{
				if(i > 3) tablero_antes_pieza [i][j] = '|';	
			} else {
				tablero_antes_pieza [i][j] = ' ';
			}
			
		}
	}			
}

// Imprime la pantalla completa usando la informacion que tiene el tablero_
void dibuja_tablero(time_t begin) {
	for (int i=0; i<12;i++)
	{
		for (int j=0; j<16; j++)
		{
			printf (" %c", tablero_ [i][j]);
		}
		printf ("\n");
	}
	marco (begin);
}
//Puntaje segun lineas realizadas
void scoref (int &linea)
{
	if (linea == 1)
	{
		score+=100;
		linea = 0;
	} else {
		if (linea == 2)
		{
			dlinea++;
			score+=400;
		} else {
			if (linea == 3)
			{
				score+=500;
				linea = 0;
			} else {
				if (linea == 4)
				{
					dlinea++;
					score+=1600;
					linea=0;
				}
			}
		}
	}
	
}
// Verificar lineas llenas
void limpiar (time_t begin, int &linea)
{
	for (int i=10; i>0; i--)
	{
		acuf=0;
		for (int j=1; j<15; j++)
		{
			if (tablero_ [i][j]== '*')
			{
				acuf++;
			}
		}
		if (acuf==14)
		{
			for (int y=1; y<15; y++)
			{
				tablero_[i][y]= tablero_[i-1][y];
				tablero_[i-1][y]=' ';
				tablero_antes_pieza[i][y]= tablero_antes_pieza[i-1][y];
				tablero_antes_pieza[i-1][y]=' ';
			}
			system ("cls");
			dibuja_tablero(begin);	
			linea ++;
			lineac+=linea;	
		}
		acuf=0;
	}
	scoref(linea);
	
}


bool es_fila_tres_vacia(void) {
	int contador = 0;
	for(int col = 0; col < 3; col++){
		if(pieza_[2][col] == ' ') contador++;
	}
	if (contador == 3) {
		return true;
	}
	return false;
}

// Actualizar el tablero con la posicion de la pieza
void actualizar_tablero_con_pieza(void) {
	inicializar_tablero();
	for(int fil = 0; fil < 2; fil++){
		for(int col = 0; col < 2; col++){
			if(tablero_[fil+fila_base_pieza][col+columna_base_pieza] == ' '){
				tablero_[fil+fila_base_pieza][col+columna_base_pieza] = pieza_[fil][col];
			}
		}
	}
	
}

// Genera la columna inicial
int generar_columna_inicial_pieza(void) {
	srand(time(NULL));
	return rand()%11+2;	
}

// Generación de la pieza que va cayendo
void generar_pieza ()
{
	int aux3 = 0;
	srand(time(NULL));
	aux3 = rand()%4+1;
	
	switch (aux3)
	{
		// Palito acostado
		case 1:
			for (int i=0; i<2;i++)
			{
				for (int j=0; j<2; j++)
				{
					if ( (i==1 && j==0)||(i==1 && j==1))
					{
						pieza_ [i][j]= '*';
					} else {
						pieza_ [i][j]= ' ';
					}
				}
			}
			break;
		// Palito parado
		case 2:
			for (int i=0; i<2;i++)
			{
				for (int j=0; j<2; j++)
				{
					if ( (i==0 && j==0)||(i==1 && j==0))
					{
						pieza_ [i][j]= '*';
					} else {
						pieza_ [i][j]= ' ';
					}
				}
			}
			break;
		// Diagonal invertida
		case 3:
			for (int i=0; i<2;i++)
			{
				for (int j=0; j<2; j++)
				{
					if ( (i==0 && j==1)||(i==1 && j==0))
					{
						pieza_ [i][j]= '*';
					} else {
						pieza_ [i][j]= ' ';
					}
				}
			}
			
			break;
		// Diagonal
		case 4:
			for (int i=0; i<2;i++)
			{
				for (int j=0; j<2; j++)
				{
					if ( (i==0 && j==0)||(i==1 && j==1))
					{
						pieza_ [i][j]= '*';
					} else {
						pieza_ [i][j]= ' ';
					}
				}
			}
			break;
	}
	// Genera la columna inicial de arranque
	columna_base_pieza = generar_columna_inicial_pieza();
	fila_base_pieza = 0; // la pieza se encuentra por encima del tablero
}


void tablero_to_tablero_antes_pieza(void){
	for (int i=0; i < 12;i++)
	{
		for (int j=0; j<16; j++)
		{
			tablero_antes_pieza[i][j] = tablero_[i][j];	
		}
	}		
}

bool colision_(void) {
	bool colisiona = false;
	if(tecla_pulsada == 'X') {
		colisiona = true;
	} 
	else {		
		bool pos_izq = (pieza_[1][0] == '*');
		bool pos_der = (pieza_[1][1] == '*');
		bool pos_arriba = (pieza_[0][0] == '*');
		if(pos_izq && pos_der) {
			if(tablero_[fila_base_pieza+1][columna_base_pieza] != ' ') colisiona = true;
			if(tablero_[fila_base_pieza+1][columna_base_pieza+1] != ' ') colisiona = true;
		} 
		else if (pos_arriba && pos_izq){
			if(tablero_[fila_base_pieza+1][columna_base_pieza] != ' ') colisiona = true;
		}
		else if(pos_izq && (!pos_der)){
			if(tablero_[fila_base_pieza+1][columna_base_pieza] != ' ') colisiona = true;
			if(tablero_[fila_base_pieza][columna_base_pieza+1] != ' ') colisiona = true;	
		}else if((!pos_izq) && pos_der) {
			if(tablero_[fila_base_pieza][columna_base_pieza] != ' ') colisiona = true;
			if(tablero_[fila_base_pieza+1][columna_base_pieza+1] != ' ') colisiona = true;		
		}
	}
	return colisiona;
}

bool bloqueo_mover (void)
{
	bool bloqueo = false;
	bool posi_izq = (pieza_[1][0] == '*');
	bool posi_der = (pieza_[1][1] == '*');
	bool posi_arriba = (pieza_[0][0] == '*');
	// palito acostado
	if(posi_izq && posi_der) {
		if(tablero_[fila_base_pieza][columna_base_pieza-1] != ' ') bloqueo = true;
		if(tablero_[fila_base_pieza][columna_base_pieza+2] != ' ') bloqueo = true;
	} 
	// palito parado
	else if (posi_arriba && posi_izq){
		if(tablero_[fila_base_pieza][columna_base_pieza+1] != ' ') bloqueo = true;
		if(tablero_[fila_base_pieza][columna_base_pieza-1] != ' ') bloqueo = true;
	}
	// diagonal invertida
	else if(posi_izq && (!posi_der)){
		if(tablero_[fila_base_pieza][columna_base_pieza+1] != ' ') bloqueo = true;
		if(tablero_[fila_base_pieza-1][columna_base_pieza+2] != ' ') bloqueo = true;
	// diagonal normal	
	}else if((!posi_izq) && posi_der) {
		if(tablero_[fila_base_pieza-1][columna_base_pieza-1] != ' ') bloqueo = true;   
		if(tablero_[fila_base_pieza][columna_base_pieza+2] != ' ') bloqueo = true;   
	}
	return bloqueo;	
}


// Contiene el ciclo donde se esta ejecutando el juego
void ejecutar_pieza(time_t begin, int &linea) {
	generar_pieza();
	do {
		if(kbhit()) {
			tecla_pulsada = toupper(_getch()); // Obtiene siempre la mayuscula
			switch(tecla_pulsada) {
				case 'P' :
					pausa ();
					break;
				// Mueve la pieza a la izquierda
				case 'F' :
					if(!bloqueo_mover ())
					{
						columna_base_pieza--;					
					}
					break;									
				// Mueve la pieza a la derecha
				case 'H' : 
					if(!bloqueo_mover ())
					{
						columna_base_pieza++;	
					}
					break;
				// Hace Girar la pieza siempre en sentido del reloj
				case 'G' :
					// para pieza acostada 
					if (pieza_ [1][1] == '*' && pieza_[1][0] == '*') 
					{
						pieza_[1][1]=' ';
						pieza_[0][0]='*';
					} 
					else
					// para pieza parada 
					if (pieza_ [0][0]=='*' && pieza_[1][0]=='*')
					{
						pieza_[1][1]='*';
						pieza_[0][0]=' ';
					}
					else
					// para diagonal
					if (pieza_[0][0]=='*' && pieza_[1][1]=='*')
					{
						pieza_[1][1]=' ';
						pieza_[0][0]=' ';
						pieza_[1][0]='*';
						pieza_[0][1]='*';
					}
					else
					// para diagonal invertida
					if (pieza_[1][0]=='*' && pieza_[0][1]=='*')
					{
						pieza_[1][0]=' ';
						pieza_[0][1]=' ';
						pieza_[1][1]='*';
						pieza_[0][0]='*';
					}
					break;
			}
		}
		int auxv=1;
		int vel = 1;
		sleep(vel-auxv*(lineac*0.005));
		system("cls");
		actualizar_tablero_con_pieza();
		dibuja_tablero(begin);
		fila_base_pieza++;
	}while(!colision_()); 
	// actualizar el tablero_ con lo que tiene en ese momento
	tablero_to_tablero_antes_pieza();
	limpiar (begin, linea);
}

int main(int argc, char** argv) 
{
	int linea=0;
	inicio ();
	menu ();
	do
	{
		system ("cls");
		inicializar_tablero_antes_pieza();
		time_t begin = time(NULL);
		inicializar_tablero();
		dibuja_tablero(begin);
		marco (begin);
		fila_base_pieza = -3;
		do {
			// Ciclo de ejecución del juego
			ejecutar_pieza(begin, linea);	
		} while(!game_over());
		printf ("\n \t ¿Quiere volver a jugar?\n");
		scanf (" %c", &rsp);
	}while (toupper(rsp)  != 'N');
	printf(" Nombre: %s\n", nombre);
 	printf(" Puntaje obtenido: %i\n", score);
 	printf(" Lineas completadas: %i\n", lineac);
 	printf(" Tiempo de juego: %.2lf\n", time_spent);
 	printf(" Dobles lineas completadas: %i\n", dlinea);
	

	system("pause>null");
	return 0;
}
