#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n[1000], i = 0, j = 0, k = 0;
	char pch[] = "10 12 2 3 4 5 32 4 54";
	char *teste = NULL;
	
	teste = strtok(pch, " ");
	while(teste != NULL)
	{
		j = sizeof(teste)/sizeof(char);
		n[k] = 0;
		for(i = 0; i < j; i++)
		{
			if(teste[i] == '\0') break;
			n[k] = n[k]*pow(10, i) + teste[i]-'0';
		}
		k++;
		teste = strtok(NULL, " ");
	}
	
	for(i = 0; i < k; i++)
		printf("%d\n", n[i]);
	
	return 0;
}
