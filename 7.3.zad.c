#include <stdio.h>


void wyswietl_tablice_wsk (int *tablica[])
{
	for(int i=0; i<9; i++)
	{
		printf("[ %2d ]", *tablica[i]);
	}
	printf("\n\n");
}


void wyswietl_tablice (int tablica[])
{
	for(int i=0; i<9; i++)
	{
		printf("[ %2d ]", tablica[i]);
	}
	printf("\n\n");
}


void sortuj_tablice(int *tablica[])
{
	int * schowek, zmiana;
	do
	{
		zmiana=0;
		for (int i=0; i<9-1; i++)
		{	
			if (*tablica[i]>*tablica[i+1])
			{
				zmiana++; 
				schowek=tablica[i];
				tablica[i]=tablica[i+1];
				tablica[i+1]=schowek;
			}
		}	
	}while(zmiana!=0);
}

void przypisz( int *ptab[], int tab[])
{
	for(int i=0; i<9; i++)
	{
		ptab[i] = &tab[i];
	}
}

int main(void)
{
	int tab[9]={1,2,3,7,5,6,7,8,9};
	int *wtab[9];
	przypisz(wtab, tab);
	sortuj_tablice(wtab);
	wyswietl_tablice_wsk(wtab);
	wyswietl_tablice(tab);
}
