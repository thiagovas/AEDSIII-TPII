/*
	Feito por Thiago Vieira
*/

#ifndef _input_h
#define _input_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vector.h"

typedef struct{
	vector *obj; // Representação de um grafo como um vector de vectors.
	int numberNodes; // Número de vértices do grafo
} input;


/* Função que lê o número de casos de teste */
int ReadNumberTestCases();

/* Função que lê um caso de teste */
input ReadTestCase(FILE *stream);

/* Método que só dá um free na memória alocada para o input. */
void ClearInput(input *obj);

/* Função que lê uma linha de um caso de teste */
int* ReadLine(int numberNodes, FILE *stream);

/* Função que imprime o input lido */
void PrintInput(input *obj);

/* Função usada para ordenar os vetores pelo tamanho */
int compare(const void *a, const void *b);

/* Função que ordena os vectors do input pelo tamanho. */
void SortBySize(input *obj);

#endif
