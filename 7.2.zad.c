#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define BUFSIZE 1024

void ExtraPrint (const char* tekst, ...)
{
	int length = strlen(tekst);
	va_list args;
	va_start(args, tekst);
	int *one_arg;
	
	for (int i=0; i< length; i++)
	{
		if (tekst[i+1] == 'd' && tekst[i] == '%')
		{
			one_arg = va_arg(args, int*);
			
			scanf("%d", one_arg);
			i++;
		}
		else
		{
			printf("%c", tekst[i]);
		}
	}
	va_end(args);
}

int main(void)
{
	int wartosci[3];
	
	ExtraPrint("Bok 1:%d\nBok 2: %d\nBok 3: %d\n", &wartosci[0], &wartosci[1], &wartosci[2]);
	
	return 0;
}
