//
// Main.c
// Practica4
//
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include <time.h>
#include "ParallelMatrix.h"

int main(int argc, char** argv)
{
	//Variables a utilizar
    int numHilos;
    double tiempos[4][4];
    int x, r, c;
    int **MA, **MAA;
    int **MB, **MBB;
    int **MC, **MCC;
    int **MD, **MDD;
    int **ME, **MEE;
    int **MF, **MFF;
    int **res;
    struct timespec t0, t1;


	//Instrucciones para realizar la simulacion con 1, 2, 3 y 4 hilos disponibles para 4 nucleos.

	//Instrucciones para utilizar una cantidad de hilos.
	numHilos = 1;
	r = 0;
	c = 0;
	while(numHilos <= 4)
    {
        omp_set_num_threads(numHilos);

        //Instruccion para imprimir la cantidad de nucleos disponibles en la computadora
        printf("La cantidad de nucleos disponibles: %d\n", omp_get_num_procs());

        //y la cantidad maxima de hilos que se solicitaron.
        #pragma omp parallel
        printf("La cantidad maxima de hilos que se solicitaron: %d\n", omp_get_max_threads());

        /*Instrucciones para realizar la simulacion con matrices de
        10 x 20
        50 x 50
        200 x 100
        1000 x 1000
        1200 x 1200
        1920 x 1080.
        */

        //Funcion para inicializar las matrices.
        MA = Relleno(10, 20);
        MAA = Relleno(10, 20);
        MB = Relleno(50, 50);
        MBB = Relleno(50, 50);
        MC = Relleno(200, 100);
        MCC = Relleno(200, 100);
        MD = Relleno(1000, 1000);
        MDD = Relleno(1000, 1000);
        ME = Relleno(1200, 1200);
        MEE = Relleno(1200, 1200);
        MF = Relleno(1920, 1080);
        MFF = Relleno(1920, 1080);

        //Funcion para sumar las matrices de forma no paralela y toma de tiempo.
        if(clock_gettime(CLOCK_REALTIME,&t0) != 0)
        {
            printf("Error al llamar clock_gettime para t0\n");
            exit(EXIT_FAILURE);
        }

        res = Suma_No_Paralela(MA, MAA, 10, 20);
        res = Suma_No_Paralela(MB, MBB, 50, 50);
        res = Suma_No_Paralela(MC, MCC, 200, 100);
        res = Suma_No_Paralela(MD, MDD, 1000, 1000);
        res = Suma_No_Paralela(ME, MEE, 1200, 1200);
        res = Suma_No_Paralela(MF, MFF, 1920, 1080);

        if(clock_gettime(CLOCK_REALTIME, &t1) != 0)
        {
            printf("Error al llamar clock_gettime para t1\n");
            exit(EXIT_FAILURE);
        }
        tiempos[r][c] = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
        c++;

        //Funcion para sumar las matrices de forma paralela y toma de tiempo.

        if(clock_gettime(CLOCK_MONOTONIC,&t0) != 0)
        {
            printf("Error al llamar clock_gettime para t0\n");
            exit(EXIT_FAILURE);
        }

        res = Suma_Paralela(MA, MAA, 10, 20, numHilos);
        res = Suma_Paralela(MB, MBB, 50, 50, numHilos);
        res = Suma_Paralela(MC, MCC, 200, 100, numHilos);
        res = Suma_Paralela(MD, MDD, 1000, 1000, numHilos);
        res = Suma_Paralela(ME, MEE, 1200, 1200, numHilos);
        res = Suma_Paralela(MF, MFF, 1920, 1080, numHilos);

        if(clock_gettime(CLOCK_MONOTONIC, &t1) != 0)
        {
            printf("Error al llamar clock_gettime para t1\n");
            exit(EXIT_FAILURE);
        }
        tiempos[r][c] = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
        c++;

        //Funcion para obtener el valor maximo de forma no paralela y toma de tiempo.
        if(clock_gettime(CLOCK_REALTIME,&t0) != 0)
        {
            printf("Error al llamar clock_gettime para t0\n");
            exit(EXIT_FAILURE);
        }

        x=Maximo_No_Paralela(MA, 10, 20);
        x=Maximo_No_Paralela(MAA, 10, 20);
        x=Maximo_No_Paralela(MB, 50, 50);
        x=Maximo_No_Paralela(MBB, 50, 50);
        x=Maximo_No_Paralela(MC, 200, 100);
        x=Maximo_No_Paralela(MCC, 200, 100);
        x=Maximo_No_Paralela(MD, 1000, 1000);
        x=Maximo_No_Paralela(MDD, 1000, 1000);
        x=Maximo_No_Paralela(ME, 1200, 1200);
        x=Maximo_No_Paralela(MEE, 1200, 1200);
        x=Maximo_No_Paralela(MF, 1920, 1080);
        x=Maximo_No_Paralela(MFF, 1920, 1080);

        if(clock_gettime(CLOCK_REALTIME, &t1) != 0)
        {
            printf("Error al llamar clock_gettime para t1\n");
            exit(EXIT_FAILURE);
        }

        tiempos[r][c] = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
        c++;

        //Funcion para obtener el valor maximo de forma paralela y toma de tiempo.
        if(clock_gettime(CLOCK_REALTIME,&t0) != 0)
        {
            printf("Error al llamar clock_gettime para t0\n");
            exit(EXIT_FAILURE);
        }

        x=Maximo_Paralela(MA, 10, 20, numHilos);
        x=Maximo_Paralela(MAA, 10, 20, numHilos);
        x=Maximo_Paralela(MB, 50, 50, numHilos);
        x=Maximo_Paralela(MBB, 50, 50, numHilos);
        x=Maximo_Paralela(MC, 200, 100, numHilos);
        x=Maximo_Paralela(MCC, 200, 100, numHilos);
        x=Maximo_Paralela(MD, 1000, 1000, numHilos);
        x=Maximo_Paralela(MDD, 1000, 1000, numHilos);
        x=Maximo_Paralela(ME, 1200, 1200, numHilos);
        x=Maximo_Paralela(MEE, 1200, 1200, numHilos);
        x=Maximo_Paralela(MF, 1920, 1080, numHilos);
        x=Maximo_Paralela(MFF, 1920, 1080, numHilos);

        if(clock_gettime(CLOCK_REALTIME, &t1) != 0)
        {
            printf("Error al llamar clock_gettime para t1\n");
            exit(EXIT_FAILURE);
        }

        tiempos[r][c] = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
        c++;

        numHilos++;
        r++;
        c=0;
    }


	//Impresion de tabla de tiempos de TODA la simulacion.
    printf("1 Hilo\n");
	printf("La suma no paralela tardo: %lf segundos\n", tiempos[0][0]);
	printf("La suma paralela tardo: %lf segundos\n", tiempos[0][1]);
    printf("Valor maximo de forma no paralela: %lf segundos\n", tiempos[0][2]);
    printf("Valor maximo de forma paralela: %lf segundos\n", tiempos[0][3]);
    printf("2 Hilos\n");
	printf("La suma no paralela tardo: %lf segundos\n", tiempos[1][0]);
	printf("La suma paralela tardo: %lf segundos\n", tiempos[1][1]);
    printf("Valor maximo de forma no paralela: %lf segundos\n", tiempos[1][2]);
    printf("Valor maximo de forma paralela: %lf segundos\n", tiempos[1][3]);
    printf("3 Hilos\n");
	printf("La suma no paralela tardo: %lf segundos\n", tiempos[2][0]);
	printf("La suma paralela tardo: %lf segundos\n", tiempos[2][1]);
    printf("Valor maximo de forma no paralela: %lf segundos\n", tiempos[2][2]);
    printf("Valor maximo de forma paralela: %lf segundos\n", tiempos[2][3]);
    printf("4 Hilos\n");
	printf("La suma no paralela tardo: %lf segundos\n", tiempos[3][0]);
	printf("La suma paralela tardo: %lf segundos\n", tiempos[3][1]);
    printf("Valor maximo de forma no paralela: %lf segundos\n", tiempos[3][2]);
    printf("Valor maximo de forma paralela: %lf segundos\n", tiempos[3][3]);

	return EXIT_SUCCESS;
}
