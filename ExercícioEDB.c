#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define teste1 22

#include "ExercícioEDB.h"

int main(){

    int *vetR = NULL, *vetQ = NULL, i;
    float tempo_total, sumTimeR = 0, sumTimeQ = 0;

    LARGE_INTEGER inicio, fim, freq;

    vetQ = criarVetor(vetQ,teste1);
	vetR = criarVetor(vetR,teste1);

	QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&inicio);
    Radix(vetR,teste1);
    QueryPerformanceCounter(&fim);
    tempo_total = (float)(fim.QuadPart - inicio.QuadPart)/freq.QuadPart;

	printf("Tempo Medio de execucao (Radix): %f",tempo_total);
}
