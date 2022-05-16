//
// ParallelMatrix.h
// Practica4
//
//

#pragma once

#ifndef ParallelMatrix_h
#define ParallelMatrix_h

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//Prototipos de funciones
int** Suma_No_Paralela(int** MA, int** MB, int f, int c);

int** Suma_Paralela(int** MA, int** MB, int f, int c, int numHilos);

int Maximo_No_Paralela(int** MA, int f, int c);

int Maximo_Paralela(int** MA, int f, int c, int numHilos);

int** Relleno(int f, int c);

int Hilos_Maximos(void);







#endif
