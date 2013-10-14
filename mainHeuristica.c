/*
	Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"

int main(int argc, char* argv[])
{
	int numberTestCases = 0;
	FILE *finput, *foutput;
	input leitura;
	
	if(argc != 3)
	{
		printf("Informe somente o nome do arquivo de entrada seguido pelo arquivo de saida.\n");
		return 1;
	}
	
	finput = fopen(argv[1], "r");
	foutput = fopen(argv[2], "w");
	
	//numberTestCases = ReadNumberTestCases(finput);
	
	fclose(finput);
	fclose(foutput);
	return 0;
}
