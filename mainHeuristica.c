/*
	Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "bitmask.h"
#include "vector.h"

int main(int argc, char* argv[])
{
	int numberTestCases = 0, i = 0, j = 0, k = 0, cont, mudou;
	bitmask selected;
	FILE *finput, *foutput;
	input *leitura;
	vector listAdjacencia;
	
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
		SortBySize(&leitura[i]);
		InitBitMask(&selected, Size(leitura[i]));
		
		j = 0;
		cont = 0;
		while(BitCount(selected) != Size(leitura[i]))
		{
			listAdjacencia = listAdj(leitura[i], j);
			SetBit(&selected, j);
			mudou = 0;
			/* BEGIN Setar todos os adjacentes a j */
			for(k = 0; k < SizeVector(listAdjacencia); k++)
				if(SetBit(&selected, At(&listAdjacencia, k)))
					mudou = 1;
			
			//Só adiciono um à cont se o amigo j convida alguém que não tinha sido convidado antes.
			if(mudou)
				cont++;
			
			/* END Setar todos os adjacentes a j*/
			j++;
		}
		
		fprintf(foutput, "%d\n", cont);
		ClearBitMask(&selected);
	}
	
	fclose(finput);
	fclose(foutput);
	return 0;
}
