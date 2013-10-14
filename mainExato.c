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

int main(int argc, char* argv[])
{
	int i, numberTestCases = 0, j, k, menor = INF;
	bitmask set, selected;
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
	
	leitura = ReadTestCases(finput, &numberTestCases);
	
	for(i = 0; i < numberTestCases; i++)
	{
		InitBitMask(&set, Size(leitura[i]));
		menor = Size(leitura[i]);
		
		while(!AddBitMask(&set))
		{
			possib = SettedBits(set); // Guardo em possib quais bits estão setados na máscara.
			InitBitMask(&selected, Size(leitura[i]));
			
			for(j = 0; j < SizeVector(possib); j++)
			{
				listAdjacencia = listAdj(leitura[i], At(&possib, j));
				SetBit(&selected, At(&possib, j));
				/* BEGIN Setar todos os adjacentes a j */
				for(k = 0; k < SizeVector(listAdjacencia); k++)
					SetBit(&selected, At(&listAdjacencia, k));
				/* END Setar todos os adjacentes a j*/
			}
			
			// Se todos os amigos foram selecionados, então essa é uma possivel solução
			if(BitCount(selected) == Size(leitura[i]))
				if(menor > BitCount(set))
					menor = BitCount(set);
			
			ClearVector(&possib);
			ClearBitMask(&selected);
		}
		fprintf(foutput, "%d\n", menor);
		ClearBitMask(&set);
	}
	
	for(i = 0; i < numberTestCases; i++)
		ClearInput(&leitura[i]);
	free(leitura);
	
	fclose(finput);
	fclose(foutput);
	return 0;
}
