/*
	Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bitmask.h"
#include "input.h"

int main(int argc, char* argv[])
{
	int i, numberTestCases = 0;
	bitmask set;
	input leitura;
	FILE *finput, *foutput;
	
	if(argc != 3)
	{
		printf("Informe somente o nome do arquivo de entrada seguido pelo arquivo de saida.\n");
		return 1;
	}
	
	finput = fopen(argv[1], "r");
	foutput = fopen(argv[2], "w");
	
	ReadTestCases(finput);
	
	//numberTestCases = ReadNumberTestCases(finput);
	
	//while(numberTestCases-- > 0)
	//{
	//	leitura = ReadTestCase(finput);
	//	PrintInput(&leitura);
		/*
		InitBitMask(&set, 20);
		
		for(i = 0; i < 20; i++)
		{
			PrintBitMask(set);
			AddBitMask(&set);
		}
		ClearBitMask(&set);
		*/
	//	ClearInput(&leitura);
	//}
	
	
	fclose(finput);
	fclose(foutput);
	return 0;
}
