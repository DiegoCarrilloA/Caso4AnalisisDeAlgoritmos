#include <iostream>
using namespace std;

void makePattern(int pWidth, int pHeight){
	/*			Caja A (Tamaño completo)
				_____________________________________
				|	  Tamaño total = pWidth;		|
				|___________________________________|
				 ___________________________________ 			 __
				|			|			|			|			|
				|			|			|			|			|
				|			|			|			|			|
				|___________________________________|			|
				|			|			| 			|			|Tamaño total = pHeight
				|			|		 	|			|			|
				|  			|		 	|			|			|
				|___________________________________|			|
				|			|			|			|			|
				|			|			|			|			|
				|			|			|			|			|
				|___________________________________|			|__

		Toma las dimensiones proporcionadas y las reduce  en un tercio para tener un espacio de trabajo más pequeño;
	*/

	int tirdWidth, tirdHeight;
	tirdWidth = pWidth/3;
	tirdHeight = pHeight/3;


	/* 	
			Caja B (Caja A reducida a tercios)
			_____________________________________
			|	  Tamaño total = tirdWidth;		|
			|___________________________________|
			 ___________________________________ 			 __
			|				  |					|			|
			|				  |					|			|
			|				  |					|			|
			|				  |					|			|
			|				  |		 			|			|Tamaño total = tirdHeigth
			|___________________________________|			|
			|  				  |	 				|			|
			|				  |					|			|
			|				  |					|			|
			|				  |					|			|
			|				  |					|			|
			|___________________________________|			|__

			
			Luego de reducirlo en tercios, se toma uno de estos y se divide en la mitad

	*/
	int halfTirdWi, halfTirdHe;
	halfTirdWi = tirdWidth/2;
	halfTirdHe = tirdHeight/2;

/*

El diseño se basa en 7 puntos básicos
Que serán la base para todos los demás
							Caja C (Caja B reducida a la mitad)
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
	int matriz[16] = {};
	//Recta 1
	matriz[0]= 0;
	matriz[1]= (int) (halfTirdWi/6);
	matriz[2]= halfTirdWi;
	matriz[3]=(int) (halfTirdHe/2);

	//Recta 2
	matriz[4] = (int)(halfTirdHe/6);
	matriz[5] = 0;
	matriz[6] = (int)(halfTirdWi/2);
	matriz[7] = halfTirdHe;

	//Recta 3
	matriz[8] = 0;
	matriz[9] = halfTirdHe ;
	matriz[10] = (int)((halfTirdWi/3)*2);
	matriz[11] = (int)((halfTirdHe/3)*2);

	//Recta 4
	matriz[12] = (int)((halfTirdWi/3)*2);
	matriz[13] = (int)((halfTirdHe/3)*2);
	matriz[14] = halfTirdWi;
	matriz[15] = 0;


/*
Con base a estas 4 rectas se puede producir todo el patrón

*/
	/*Para construir todo el patrón se necesitan 36 cajas C, o sea un tablero 6x6
	 	Y cada caja C consta de 4 rectas, que son 8 pares ordenados y estos a su vez 16 puntos
		Ese es el motivo del porque la matriz pointMatrix sea [6][6][16]

	*/

	int pointMatrix[6][6][16] = {};

	int increaseX, increaseY, pointX, pointY, pointX2, pointY2;
	increaseX = 0;
	increaseY = 0;

	/*
	Al incluir una caja C en el diseño existen 4 posibilidades
	- Que sea la misma posicion
	- Que sea una reflexion a la izquierda
	- Que sea una reflexión hacia abajo
	- Que sea una una doble reflexion hacia la izquierda y hacia abajo

	*/

	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			for(int k=0; k<16; k+=4){

				if(i%2==0 && j%2==0){
					//Que sea la misma posicion

					pointX = matriz[k];
					pointY = matriz[k+1];
					pointX2 = matriz[k+2];
					pointY2 = matriz[k+3];
				}

				else if(i%2==0 && j%2 != 0){
					//Que sea una reflexion a la izquierda

					pointX = halfTirdWi - matriz[k];
					pointY = matriz[k+1];
					pointX2 = halfTirdWi - matriz[k+2];
					pointY2 = matriz[k+3];

				}

				else if(i%2!=0 && j%2 != 0){
					//Que sea una una doble reflexion hacia la izquierda y hacia abajo

					pointX = halfTirdWi - matriz[k];
					pointY = halfTirdHe - matriz[k+1];
					pointX2 = halfTirdWi - matriz[k+2];
					pointY2 = halfTirdHe - matriz[k+3];
				}

				else if(i%2!=0 && j%2==0){
					//Que sea una reflexión hacia abajo

					pointX = matriz[k];
					pointY = halfTirdHe - matriz[k+1];
					pointX2 = matriz[k+2];
					pointY2 = halfTirdHe - matriz[k+3];
				}

				pointMatrix[i][j][k] = pointX + increaseX;
				pointMatrix[i][j][k+1] = pointY + increaseY;
				pointMatrix[i][j][k+2] = pointX2 + increaseX;
				pointMatrix[i][j][k+3] = pointY2 + increaseY;
				
			}
			increaseX += halfTirdWi;
		}
		increaseY += halfTirdHe;
		increaseX = 0;
	}



	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			for(int k=0; k<16; k+=4){
				printf("g.drawLine(%d,%d,%d,%d);\n",pointMatrix[i][j][k],pointMatrix[i][j][k+1],pointMatrix[i][j][k+2],pointMatrix[i][j][k+3]);
			}
		}
	}

}


int main(){

	makePattern(1000, 720);
	return 0;
}

