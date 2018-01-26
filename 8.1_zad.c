#include <stdio.h>
#include <stdlib.h>

int wypelnij ( int tab[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Elemrnt %d \n: ", i); 
        if(scanf("%d", &tab[i]) == EOF)
        {
            return i;
        }
    }
}
        
int licz_sume(int tablica[],int rozmiar)
{
    int suma = 0;
    for(int i= 0; i< rozmiar; i++)
    {
        suma += tablica[i];
    }
    return suma;
}
        
double licz_srednia (double suma, int rozmiar)
{
    return(suma / rozmiar);
}

double licz_mediane(int tab[], int rozmiar)
{
    double mediana=0;
    if(rozmiar%2 == 0)
    {
        mediana = (tab[rozmiar/2] + tab[rozmiar/2 - 1])/2;
    }
    else
    {
        mediana = tab[(rozmiar-1)/2 +1];
    }
    return mediana;
}

int licz_dominante(int tab[], int rozmiar)
{
    int dominanta=0;
    for(int i =0; i<rozmiar; i++)
    {
        int licznik = 0;
        for(int k =0; k<rozmiar; k++)
        {
            if(tab[i] == tab[k])
            {
                licznik+=1;
            }
        }
        if(licznik > dominanta)
        {
            dominanta = i;
        }
    }
    return tab[dominanta];
}

int main(void)
{
    int size = 0;
    printf("Prosze liczbe elementow tablicy:\n");
    scanf("%d", &size);
    int* tab = (int*)malloc(sizeof(int)*size);
    if(NULL == tab)
    {
        printf("Nie powiodla sie alokacja pamieci");
        return 1;
    }
    size = wypelnij(tab, size);
    int suma = licz_sume(tab, size);    
    double srednia = licz_srednia(suma, size);
    
    double mediana = licz_mediane(tab, size);
    int dominanta = licz_dominante(tab, size);
    printf("Suma to: %d %o %x \nSrednia to: %lf \n Mediana to: %lf \nDominanta to: %d %o %x", suma, suma, suma, srednia, mediana, dominanta, dominanta, dominanta);
    
    free (tab);
    return 0;
}
