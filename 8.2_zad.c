#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

enum ArgumentType { charr =0, p_to_char =1, integer =2, lf =3}; 

void printArgumentInTheMiddle(void* argument, enum ArgumentType type, unsigned width)
{
	int linia =0;
	if(NULL == argument)
	{
		printf("\n");
		return;
	}
	if(width% 2 == 0)
	{
		linia = width/2-1;
	}
	else
	{
		linia = width /2;
	}
	if(type==1)
	{
		if(width <1)
		{
			return;
		}
		if(isprint(*(char*)argument) == 0)
		{
			printf("\n");
			return;
		}
		for( int i =0; i<linia; i++)
		{
			printf(".");
		}
		printf("%c", *(char*)argument);
		for (int i=0; i<(width-linia-1); i++)
		{
			printf(".");
		}
		printf("\n");
	}
	else if(type == 0)
	{
		if(width <1)
		{
			return;
		}
		if(isprint(*(char*)argument) == 0)
		{
			printf("\n");
			return;
		}
		for( int i =0; i<linia; i++)
		{
			printf(".");
		}
		printf("%c", *(char*)argument);
		for (int i=0; i<(width-linia-1); i++)
		{
			printf(".");
		}
		printf("\n");
	}
		
	else if(type == 2)
	{
		
		linia = width - (log10(*(int*)argument)+1);
		if(linia <0)
		{
			char char_number[(int)(log10(*(int*)argument)+1)];
			sprintf(char_number, "%d", *(int*)argument);
			for (int i=0; i<width; i++)
			{
				printf("%c", char_number[i]);
			}
			printf("\n");
			return;
		}
		
		for( int i =0; i<linia/2; i++)
		{
			printf(".");
		}
		printf("%d", *(int*)argument);
		for (int i=0; i<(width-linia/2 -((log10(*(int*)argument)+1))); i++)
		{
			printf(".");
		}
		printf("\n");
	}
	else
	{
		double arg_double = *(double*)argument;
		if(  *(double*)argument == ceil(*(double*)argument ))
		{
			int arg_int = (int)arg_double;
			printf("COS");
			printArgumentInTheMiddle(&arg_int, integer, width);
			return;
		}
		int dlugosc=4;
		dlugosc += log10(*(double*)argument)+1;
		linia = width - dlugosc;
		if(linia < 0)
		{
			char char_number[dlugosc];
			sprintf(char_number, "%lf", *(double*)argument);
			for (int i=0; i<width; i++)
			{
				printf("%c", char_number[i]);
			}
			printf("\n");
			return;
			return;
		}
		
		for( int i =0; i<linia/2; i++)
		{
			printf(".");
		}
		printf("%.3lf", *(double*)argument);
		for (int i=0; i<(width-linia/2 -dlugosc); i++)
		{
			printf(".");
		}
		printf("\n");
	}
} 

int main(void)
{
	char arg ='l';
	printArgumentInTheMiddle(&arg, charr, 7);
	
	char *chp =&arg;
	
	printArgumentInTheMiddle(chp, p_to_char, 4);

	int a = 1000;
	
	int *ip = &a;
	
	printArgumentInTheMiddle(ip, integer, 2);
	
	double b=12.243254;
	double *bp = &b;
	
	printArgumentInTheMiddle(bp, lf,7);
	
	
	return 0;
}
