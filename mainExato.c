/*
	Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bitmask.h"

int main()
{
	int i;
	bitmask set;
	
	InitBitMask(&set, 20);
	
	for(i = 0; i < 20; i++)
	{
		PrintBitMask(set);
		AddBitMask(&set);
	}
	
	ClearBitMask(&set);
	return 0;
}
