/*
	Feito por Thiago Vieira
*/

#include "bitmask.h"

/* Função que verifica se bitmask não é nulo e se mask não é nulo. */
int VerifyConsistency(bitmask *obj)
{
	if(obj == NULL) return 0;
	if(obj->mask == NULL) return 0;
	return 1;
}

void InitBitMask(bitmask *obj, int n)
{
	int i = 0;
	if(!VerifyConsistency(obj)) return;
	obj->mask = (int*)alloc(n, sizeof(int));
	obj->size = n;
	obj->numBits = 0;
	
	for(i = 0; i < n; i++) obj->mask[i] = 0;
}

void ClearBitMask(bitmask *obj)
{
	if(!VerifyConsistency(obj)) return;
	free(obj->mask);
	obj->size = 0;
}

/* Função que adiciona um no bitmask e retorna se o bitmask tem todas as posições setadas. */
int AddBitMask(bitmask *obj)
{
	if(!VerifyConsistency(obj)) return;
	
	int i = 0;
	int surplus = 1;
	
	for(i = obj->size-1; i >= 0; i--)
		if(surplus+obj->mask[i] == 2)
		{
			if(obj->mask[i]) obj->numBits -= 1;
			obj->mask[i] = 0;
		}
		else
		{
			if(!obj->mask[i]) obj->numBits +=1 ;
			obj->mask[i] = 1;
			break;
		}
	
	return obj->numBits == obj->size;
}

/* Função que retorna o número de bits  */
int BitCount(bitmask obj)
{
	return obj.numBits;
}

/* Função que retorna uma lista com os bits que estão setados. */
vector SettedBits(bitmask obj)
{
	int i = 0;
	vector retorno;
	
	InitEmptyVector(&retorno);
	for(i = 0; i < obj.size; i++)
		if(obj.mask[i])
			Push_back(&retorno, i);
	
	return retorno;
}

/* Procedimento que seta o bit na posição index */
void SetBit(bitmask *obj, int index)
{
	obj->numBits += (obj->mask[index] == 0 ? 1 : 0);
	obj->mask[index] = 1;
}

/* Retorna o valor de uma posição da máscara. */
int AtBitMask(bitmask obj, int index)
{
	return obj.mask[index];
}

void PrintBitMask(bitmask obj)
{
	int i = 0;
	if(obj.size == 0) return;
	
	printf("%d: %d", obj.numBits, obj.mask[0]);
	for(i = 1; i < obj.size; i++)
		printf(" %d", obj.mask[i]);
	printf("\n");
}
