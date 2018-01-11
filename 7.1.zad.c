#include <stdio.h>
#include <stdlib.h>

double srednia_wazona( int *poczatek, int *koniec)
{
	double suma = 0;
	int suma_wag=0;
	int index=0;
	while(poczatek+index != koniec)
	{
			suma += *(poczatek+index) * index;
			
			suma_wag += index;
			index ++;
	}
	
	return (suma / suma_wag);
}


int main(void)
{
	int tablica[9]={1,2,3,4,5,6,7,8,9};

	int *koniec = &tablica[8];
	int *poczatek = tablica;
	
	printf("Srednia wazona to: %lf ",srednia_wazona( poczatek, koniec));
}
