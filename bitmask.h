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
void AddBitMask(bitmask *obj);
int BitCount(bitmask obj);
void PrintBitMask(bitmask obj);

#endif
