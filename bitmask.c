/*
	Feito por Thiago Vieira
*/

#include "bitmask.h"

/**/
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

void AddBitMask(bitmask *obj)
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
}

int BitCount(bitmask obj)
{
	return obj.numBits;
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
