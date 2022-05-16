//
// ParallelMatrix.c
// Practica4
//
//

#include "ParallelMatrix.h"

//Definicion de funciones

int ** Suma_No_Paralela(int** MA, int** MB, int f, int c)
{
    int i,j,**matrix;
    matrix = (int**)malloc(f*sizeof(int*));
    for(i=0;i<f;i++)
    {
        matrix[i] = (int*)malloc(c*sizeof(int));
        for(j=0;j<c;j++)
        {
            matrix[i][j]= MA[i][j]+MB[i][j];
        }
    }

    return matrix;
}

int** Suma_Paralela(int** MA, int** MB, int f, int c, int numHilos)
{
    int i,j,**matrix;
    omp_set_num_threads(numHilos);
    #pragma omp parallel
    {
        matrix = (int**)malloc(f*sizeof(int*));
        for(i=0;i<f;i++)
        {
            matrix[i] = (int*)malloc(c*sizeof(int));
            for(j=0;j<c;j++)
            {
                matrix[i][j]= MA[i][j]+MB[i][j];
            }
        }
    }
     return matrix;
}

int Maximo_No_Paralela(int** MA, int f, int c)
{
    int mayor=0;

    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(MA[i][j] > mayor)
            {
                mayor = MA[i][j];
            }
        }
    }

    return mayor;
}

int Maximo_Paralela(int** MA, int f, int c, int numHilos)
{
    int mayor=0;
    omp_set_num_threads(numHilos);
    #pragma omp parallel
    {
        for(int i=0;i<f;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(MA[i][j] > mayor)
                {
                    mayor = MA[i][j];
                }
            }
        }
    }
    return mayor;
}

int** Relleno(int f, int c)
{
    int i,j,**matrix;
    matrix = (int**)malloc(f*sizeof(int*));
    for(i=0;i<f;i++)
    {
        matrix[i] = (int*)malloc(c*sizeof(int));
        for(j=0;j<c;j++)
        {
            matrix[i][j]=rand()%256;
        }
    }
  return matrix;
}
