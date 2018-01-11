#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void* data, size_t sizeOfData)
{
	char *tablica = (char*)malloc(sizeOfData);
	memcpy( tablica, data, sizeOfData);
	int i=0;
	for (int i = 0; i< sizeOfData/sizeof(char); i++)
	{
		printf("%c\n", tablica[i]);
	}
	
	return 0;
}

int main (void)
{
	char bufor[20];
	for (int i =0; i<20; i++)
	{
		bufor[i]='2';
	}
	
	copyArgumentAndPrintCharByCharReturningSumOfArguments(bufor, sizeof(char)*20);
}
	
	
	
