#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void* data, size_t sizeOfData)
{
	char *tablica = (char*)malloc(sizeOfData);
	memcpy( tablica, data, sizeOfData);
	int i=0;
	long long suma = 0;
	for (int i = 0; i< sizeOfData/sizeof(char); i++)
	{
		printf("%X\n", tablica[i]);
		suma += tablica[i];
	}
	
	return suma;
}

int main (void)
{
	char bufor[20];
	for (int i =0; i<20; i++)
	{
		bufor[i]='z';
	}
	
	printf("\n\n%d\n ",copyArgumentAndPrintCharByCharReturningSumOfArguments(bufor, sizeof(char)*20));
}
	
	
	
