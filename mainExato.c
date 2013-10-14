/*
	Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bitmask.h"
#include "input.h"
#include "vector.h"

#define INF 2147000000

/* Método para inicializar o vetor usado no union-find */
void InitUnionFind(int *f);

/* Método que faz union entre a e b */
void Union(int *f, int a, int b);
int Find(int *f, int a);

/* Função que verifica se  */
int isSolution(int *f);


int main(int argc, char* argv[])
{
	int i, numberTestCases = 0, j, *f, k, menor = INF;
	bitmask set;
	input *leitura;
	vector possib, listAdjacencia;
	FILE *finput, *foutput;
	
	if(argc != 3)
	{
		printf("Informe somente o nome do arquivo de entrada seguido pelo arquivo de saida.\n");
		return 1;
	}
	
	finput = fopen(argv[1], "r");
	foutput = fopen(argv[2], "w");
	
	leitura = ReadTestCases(finput);
	numberTestCases = sizeof(leitura)/sizeof(input);
	
	for(i = 0; i < numberTestCases; i++)
	{
		InitBitMask(&set, Size(leitura[i]));
		menor = INF;
		f = (int*)alloc(Size(leitura[i]), sizeof(int));
		
		while(!AddBitMask(&set))
		{
			
			possib = SettedBits(set);
			InitUnionFind(f);
			for(j = 1; j < SizeVector(possib); j++)
			{
				listAdjacencia = listAdj(leitura[i], j);
				
				/* BEGIN Unir todos os adjacentes a j */
				for(k = 0; k < SizeVector(listAdjacencia); k++)
					Union(f, At(&possib, j), At(&listAdjacencia, k));
				/* END Unir todos os adjacentes a j*/
				
				Union(f, At(&possib, j-1), At(&possib, j));
			}
			
			if(isSolution(f))
				if(menor < BitCount(set))
					menor = BitCount(set);
			
			ClearVector(&possib);
		}
		printf("%d\n", menor);
		free(f);
		f = NULL;
		ClearBitMask(&set);
	}
	
	for(i = 0; i < numberTestCases; i++)
		ClearInput(&leitura[i]);
	free(leitura);
	
	fclose(finput);
	fclose(foutput);
	return 0;
}

void InitUnionFind(int *f)
{
	int i = 0;
	for(i = 0; i < sizeof(f)/sizeof(int); i++)
		f[i] = i;
}

void Union(int *f, int a, int b)
{	f[Find(f, a)] = Find(f, b); }

int Find(int *f, int a)
{	return f[a] == a ? a : (f[a] = Find(f, f[a])); }

int isSolution(int *f)
{
	int i = 0, resp = 1;
	for(i = 1; i < sizeof(f)/sizeof(int); i++)
		if(f[i] != f[i-1])
		{
			resp = 0;
			break;
		}
	return resp;
}

