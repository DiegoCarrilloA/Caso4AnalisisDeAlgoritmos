/**
 * Paso#1:
 *  se recive un NxM y se divide entre 3 para saber las dimensiones de las cajitas estrella
 * Paso#2:
 *  a cajita estrella se divide entre dos para sacar las dimensiones de las cajitas estrellas jr
 * Paso#3:
 *   
 *
 * 
 * 
 * **/
#include <iostream>
using namespace std;

void makePattern(int pWidth, int pHeight){
	//Toma las dimensiones proporcionadas y las reduce  en un tercio para tener un espacio de trabajo más pequeño;
	int tirdWidth, tirdHeight;
	tirdWidth = pWidth/3;
	tirdHeight = pHeight/3;

	//Se reducen otra vez estos nuevo tamaños
	int halfTirdWi, halfTirdHe;
	halfTirdWi = tirdWidth/2;
	halfTirdHe = tirdHeight/2;

/*

El diseño se basa en 7 puntos básicos
Que serán la base para todos los demás
								_____________________________________
								|	  Tamaño total = halfTirdWi;	|
								|___________________________________|


							   		↓ Punto B = (halfTirdHe/6,0)
				 				 ___._______________________________											___
								|									' Punto C = (halfTirdWi, 0)					|
 Punto A = (0, halfTirdWi/6) -->.									|											|
								|									|											|
								|									|											|
								|Punto D =((halfTirdWi/3)*2, 		|											| Tamaño total = halfTirdHe
								| ((halfTirdHe/3)*2) |				|											|
								|					 ↓				. <- Punto E = (halfTirdWi,(halfTirdHe/2));	|
								|  					 .				|											|
								|									|											|
								|									|											|
								|									|											|
								|									|											|
	 Punto F = (0, halfTirdHe)->.__________________.________________|											|____

												   ↑ Punto G = (halfTirdWi/2, halfTirdHe);


Con estos puntos podemos realizar 4 rectas que serán la base para el diseño.

Recta 1 = A-E;
Recta 2 = B-G;
Recta 3 = F-D;
Recta 4 = D-C;
*/

	int matriz[4][4] = {};
	//Recta 1
	matriz[0][0]= 0;
	matriz[0][1]= (int) (halfTirdWi/6);
	matriz[0][2]= halfTirdWi;
	matriz[0][3]=(int) (halfTirdHe/2);

	//Recta 2
	matriz[1][0] = (int)(halfTirdHe/6);
	matriz[1][1] = 0;
	matriz[1][2] = (int)(halfTirdWi/2);
	matriz[1][3] = halfTirdHe;

	//Recta 3
	matriz[2][0] = 0;
	matriz[2][1] = halfTirdHe ;
	matriz[2][2] = (int)((halfTirdWi/3)*2);
	matriz[2][3] = (int)((halfTirdHe/3)*2);

	//Recta 4
	matriz[3][0] = (int)((halfTirdWi/3)*2);
	matriz[3][1] = (int)((halfTirdHe/3)*2);
	matriz[3][2] = halfTirdWi;
	matriz[3][3] = 0;
	for(int i= 0; i<4; i++){
		printf("g.drawLine(%d,%d,%d,%d);\n", matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3]);
	}

}



void encuentraPuntos(int ancho, int largo){
    
    int matriz[9][4][7]; //en esta matriz se van a guardar los puntos para cada cajita
    int filas = 9;
    int columnas = 4;
    int puntosInternos = 7;


    int aumentaTamañoA = 0; //en esta variable se aumenta el tamaño de cada caja para sacar los puntos de la siguiente
    int aumentaTamañoL = 0;
    const int cajitaEstrellaA = ancho/3; //Se obrienen las dimensiones de una caja mas pequeña
    const int cajitaEstrellaL = largo/3;

    const int cajitaEstrellaJrA = cajitaEstrellaA/2;//Se obtienen las dimensiones aun mas pequeñas de un pedazo de la caja 
    const int cajitaEstrellaJrL = cajitaEstrellaL/2; //asi el problema se hacem as pequeño a la hora de reprtir el patrón

    const int partesPuntosA = cajitaEstrellaJrA/6; //esto se usa para calcular ciertos puntos
    const int partesPuntosL = cajitaEstrellaJrL/6; //esto se usa para calcular ciertos puntos


    for (int i = 0; i < filas; i++)
    {
        for (int i = 0; i < columnas; i++)
        {
            for (int i = 0; i < puntosInternos; i++)
            {
                
            }
            
            


            aumentaTamañoA+=cajitaEstrellaA;//despues de tener los puntos se pasa al aa siguiente cajita
        }
        aumentaTamañoL+=cajitaEstrellaL;//se pasa a la siguiente fila de cajitas

        
    }
    




    
};


int main (){



    return 0;
};
