/*
	Feito por Thiago Vieira
*/

#include "input.h"

/* Função que lê os casos de teste */
input* ReadTestCases(FILE *stream)
{
	int i, j, number = 0;
	input *retorno;
	vector line;
	
	fscanf(stream, "%d", &number);
	retorno = (input*)alloc(number, sizeof(input));
	
	while(number-- > 0)
	{
		fscanf(stream, "%d", &retorno[number].numberNodes);
		retorno[number].obj = (vector*)alloc(retorno[number].numberNodes, sizeof(vector));
		
		//Inicializar todos os vértices
		for(i = 0; i < retorno[number].numberNodes; i++)
			InitEmptyVector(&retorno[number].obj[i]);
		
		// Ler todas as linhas de um input
		for(i = 0; i < retorno[number].numberNodes; i++)
		{
			line = ReadLine(retorno[number].numberNodes, stream);
			
			if(Empty(&line))
			{
				i--;
				continue;
			}
			//PrintVector(line);
			EditItem(&line, 0, At(&line, 0)-1);
			//Ler todos os nodes de uma linha de um caso de teste
			for(j = 1; j < SizeVector(line); j++)
			{
				EditItem(&line, j, At(&line, j)-1);
				Push_back(&retorno[number].obj[At(&line, 0)], At(&line, j));
				Push_back(&retorno[number].obj[At(&line, j)], At(&line, 0));
			}
			ClearVector(&line);
		}
	}
	return retorno;
}

/* Função que lê uma string e retorna um vector de ints. */
vector ConvertStringToInt(char* string, int numberNodes)
{
	vector retorno;
	char *pch = NULL;
	int i = 0, k = 0, tam = 0;
	
	InitEmptyVector(&retorno);
	pch = strtok(string, " ");
	while(pch != NULL)
	{
		tam = sizeof(pch)/sizeof(char);
		Push_back(&retorno, 0);
		for(i = 0; i < tam; i++)
		{
			if(pch[i] == '\0' || pch[i] == 10) break;
			EditItem(&retorno, k, At(&retorno, k)*pow(10, i) + pch[i]-'0');
		}
		pch = strtok(NULL, " ");
		k++;
	}
	return retorno;
}

/* Função que lê uma linha de um caso de teste */
vector ReadLine(int numberNodes, FILE *stream)
{
	char *strInput = (char*)alloc(4*numberNodes, sizeof(char));
	char *pch = NULL;
	int i = 0, j = 0, k = 0, temp = 0;
	vector retorno;
	
	InitEmptyVector(&retorno);
	fgets(strInput, 4*numberNodes, stream);
	
	//Caso fgets ler algum lixo, ReadLine retorna NULL.
	if(strlen(strInput) < 2 && !isdigit(strInput[0]))
	{
		free(strInput);
		return retorno;
	}
	
	retorno = ConvertStringToInt(strInput, numberNodes);
	free(strInput);
	
	return retorno;
}

/* Função que imprime o input lido */
void PrintInput(input *obj)
{
	int i = 0;
	for(i = 0; i < obj->numberNodes; i++)
		PrintVector(obj->obj[i]);
}

/* Método que só dá um free na memória alocada para o input. */
void ClearInput(input *obj)
{
	int i = 0;
	for(i = 0; i < obj->numberNodes; i++)
		ClearVector(&obj->obj[i]);
	free(obj->obj);
	obj->obj = NULL;
	obj->numberNodes = 0;
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
