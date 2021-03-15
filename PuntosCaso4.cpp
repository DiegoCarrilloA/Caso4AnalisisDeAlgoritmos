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