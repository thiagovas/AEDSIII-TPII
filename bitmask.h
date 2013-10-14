/*
	Feito por Thiago Vieira
*/

#ifndef _bitmask_h
#define _bitmask_h

#include "vector.h"

typedef struct{
	int *mask, size, numBits;
} bitmask;

/* Função que verifica se bitmask não é nulo e se mask não é nulo. */
int VerifyConsistency(bitmask *obj);

void InitBitMask(bitmask *obj, int n);

void ClearBitMask(bitmask *obj);

/* Função que adiciona um no bitmask e retorna se o bitmask tem todas as posições setadas. */
int AddBitMask(bitmask *obj);

/* Função que retorna o número de bits  */
int BitCount(bitmask obj);

/* Função que retorna uma lista com os bits que estão setados. */
vector SettedBits(bitmask obj);

/* Retorna o valor de uma posição da máscara. */
int AtBitMask(bitmask obj, int index);

void PrintBitMask(bitmask obj);

#endif
