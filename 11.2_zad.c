#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
     
#define BUFSIZE 1024
	
void wyswietl_tablice (int rozmiar, int tablica[rozmiar])
{
	for(int i=0; i<rozmiar; i++)
	{
		printf("[ %2d ]", tablica[i]);
	}
	printf("\n\n");
}

	
void sortuj_tablice(int tablica[], int rozmiar)
{
	int schowek, zmiana;
	do
	{
		zmiana=0;
		for (int i=0; i<rozmiar-1; i++)
		{	
			if (tablica[i]>tablica[i+1])
			{
				zmiana++; 
				schowek=tablica[i];
				tablica[i]=tablica[i+1];
				tablica[i+1]=schowek;
			}
		}	
	}while(zmiana!=0);
}
     
int main (int argc, char **argv) {
	srand(time(NULL));
	if(argc != 2)
	{
		printf("Brak argumentow");
		return 1;
	}
		
	char *plik_zrodlo;
	plik_zrodlo = argv[1];
		
    FILE *f1 = fopen (plik_zrodlo, "r+w");
    if(f1 == NULL)
    {
		int err = errno;
		printf("Nie udalo sie otworzyc pliku");
		if(err == EACCES)
		{
			printf("Brak dostepu");
			return 1;
		}
	}
	
	char str[BUFSIZE];

	int i =0;
	int size = BUFSIZE;
	char* str2 = fgets(str, size, f1);
	
	/*for(int i=0; i<BUFSIZE; i++)
	{
		if()
		{
			licznik++;
		}

	}*/
	//printf("%d", licznik);
	int tab[BUFSIZE];
	int licznik = fscanf( f1, "%d", &tab);
    printf("%d", tab[1]);
    wyswietl_tablice(BUFSIZE, tab);
    
    fclose(f1);
    
    return 0;
    }

