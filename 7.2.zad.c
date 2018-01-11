#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024


void extra_printf( char tekst[] )
{
	int i=0;
	while(i <= strlen(tekst))
	{
		if(tekst[i] == 37)
		{
			int zmienna=0;
			
			while(getchar() != '\n');
			
			scanf("%d", &zmienna);
			printf("\n%d\n", zmienna);
			
			if(i != strlen(tekst))
			{
				i++;
			}
		}
		else
		{
			printf("%c", tekst[i]);
		}
		i++;
	}
}


int main(void)
{
	char tekst[BUFSIZE];
	int ile = scanf("%1000[0-9a-zA-Z \%]", &tekst);
	for (int i = 0; i< ile; i++)
	{
		extra_printf(tekst);
	}
	return 0;
}
