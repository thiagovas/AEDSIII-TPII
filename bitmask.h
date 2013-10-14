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

/* Método para inicializar um bitmask com n posições e todas elas com 0. */
void InitBitMask(bitmask *obj, int n);

/* Método para limpar um bitmask, liberar a memória e zerar vaiáveis. */
void ClearBitMask(bitmask *obj);

/* Função que adiciona um no bitmask e retorna se o bitmask tem todas as posições setadas. */
int AddBitMask(bitmask *obj);

/* Função que retorna o número de bits  */
int BitCount(bitmask obj);

/* Função que retorna uma lista com os bits que estão setados. */
vector SettedBits(bitmask obj);

/* Retorna o valor de uma posição da máscara. */
int AtBitMask(bitmask obj, int index);

/* Função que seta o bit na posição index e retorna se o valor na posição index era 0. */
int SetBit(bitmask *obj, int index);

/* Método para imprimir o conteúdo do bitmask. */
void PrintBitMask(bitmask obj);

#endif
