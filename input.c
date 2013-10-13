/*
	Feito por Thiago Vieira
*/

#include "input.h"

/* Função que lê o número de casos de teste */
int ReadNumberTestCases(FILE *stream)
{
	int number;
	fscanf(stream, "%d", &number);
	return number;
}

/* Função que lê um caso de teste */
input ReadTestCase(FILE *stream)
{
	int i, j;
	input retorno;
	int *line = NULL;
	
	
	fscanf(stream, "%d", &retorno.numberNodes);
	retorno.obj = (vector*)alloc(retorno.numberNodes, sizeof(vector));
	
	//Inicializar todos os vértices
	for(i = 0; i < retorno.numberNodes; i++)
		InitEmptyVector(&retorno.obj[i]);
	
	// Ler todas as linhas de um input
	for(i = 0; i < retorno.numberNodes; i++)
	{
		line = ReadLine(retorno.numberNodes, stream);
		line[0] -= 1;
		//Ler todos os nodes de uma linha de um caso de teste
		for(j = 1; j < sizeof(line)/sizeof(line[0]); j++)
		{
			line[j] -= 1;
			Push_back(&retorno.obj[line[0]], line[j]);
			Push_back(&retorno.obj[line[j]], line[0]);
		}
		
		free(line);
	}
	return retorno;
}

/* Método que só dá um free na memória alocada para o input. */
void ClearInput(input *obj)
{
	free(obj->obj);
}

/* Função que lê uma linha de um caso de teste */
int* ReadLine(int numberNodes, FILE *stream)
{
	char *strInput = (char*)alloc(2*numberNodes, sizeof(char));
	char *pch = NULL;
	int i = 0, *line = (int*)alloc(numberNodes, sizeof(int)), j = 0, k = 0, temp = 0;
	fgets(strInput, 2*numberNodes, stream);
	
	for(i = 0; i < 2*numberNodes; i++)
	{
		if(strInput[i] == '\0') break; // Se for fim de linha, o loop é interrompido.
		if(strInput[i] == 32)
		{
			line[k++] = temp;
			j = 0, temp = 0;
			continue;
		}
		else if(strInput[i] < 48 || strInput[i] > 57)
		{
			continue;
		}
		
		temp = pow(10, j)*temp + (strInput[i]-'0');
		j++;
	}
	if(temp != 0)
		line[k] = temp;

	free(strInput);
	
	return line;
}

/* Função que imprime o input lido */
void PrintInput(input *obj)
{
	int i = 0;
	for(i = 0; i < obj->numberNodes; i++)
	{
		PrintVector(obj->obj[i]);
		printf("\n");
	}
}

/* Função usada para ordenar os vetores pelo tamanho */
int compare(const void *a, const void *b)
{
	return SizeVector(*(vector*)a) > SizeVector(*(vector*)b);
}

/* Função que ordena os vectors do input pelo tamanho. */
void SortBySize(input *obj)
{
	qsort(obj->obj, obj->numberNodes, sizeof(vector), compare);
}
