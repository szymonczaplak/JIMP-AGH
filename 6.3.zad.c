#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void ignore_rest_of_the_line_in_stdin(void)
{
    while (getchar() != '\n');
}

int input_int(char tekst[])
{
    int zmienna=0;
    do
    {
        printf("%s", tekst);
        
        if(scanf ("%d", &zmienna) ==1)
        {
            break;
        }
        ignore_rest_of_the_line_in_stdin();
    }while(1);
    return zmienna;
}

void losuj_tablice (int tablica[], int rozmiar)
{
    for(int i=0; i<rozmiar; i++)
    {
        tablica[i]= rand() %20;
    }
}

void wyswietl_tablice (int rozmiar, int tablica[rozmiar])
{
    for(int i=0; i<rozmiar; i++)
    {
        printf("[ %2d ]", tablica[i]);
    }
    printf("\n\n");
}


double licz_srednia ( int tablica[], int rozmiar)
{
    double suma=0;
    for(int i=0; i<rozmiar; i++)
    {
        suma+=tablica[i];
    }

    return (suma / rozmiar);
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
    }while(zmiana0);
}

void kopiuj_tablice(int kopia[], int tablica[], int rozmiar)
{
    for(int i=0; i<rozmiar; i++)
    {
        kopia[i]=tablica[i];
    }
}

double mediana (int tablica[], int rozmiar)
{
    int posortowana[rozmiar];
    
    kopiuj_tablice(posortowana, tablica, rozmiar);
    
    sortuj_tablice(posortowana, rozmiar);
    
    int index = rozmiar/2;
    
    if(rozmiar%2 ==0)
    {
        return (posortowana[index] + posortowana[index-1])/2;
    }
    else
    {
        return (posortowana[index]);
    }

}
    
int minimalny (int tablica[], int rozmiar)
{
    int posortowana[rozmiar];
    
    kopiuj_tablice(posortowana, tablica, rozmiar);
    
    sortuj_tablice(posortowana, rozmiar);
    
    return posortowana[0];
}


int maxymalny (int tablica[], int rozmiar)
{
    int posortowana[rozmiar];
    
    kopiuj_tablice(posortowana, tablica, rozmiar);
    
    sortuj_tablice(posortowana, rozmiar);
    
    return posortowana[rozmiar-1];
}
    
int main(void)
{
    const int rozmiar=10;
    int tab[rozmiar];
    while (1)
    {
        int user_input=input_int("Aby wylosowac tablice 10 liczb wybierz 1\nAby wyswietlic tablice wybierz 2"
        "\nAby obliczyc srednia liczb z tablicy wybierz 3\nAby obliczyc mediane liczb wybierz 4"
        "\nAby obliczyc Max i Min element tablicy wybierz 5\nAby wyjsc wybierz 6\n\n") ;
        
        switch(user_input)
        {
            case 1:
                losuj_tablice(tab, rozmiar);
                break;
            case 2:
                wyswietl_tablice(rozmiar, tab);
                break;
            case 3:
                printf("Srednia liczb z tableli to: %lf\n\n", licz_srednia(tab, rozmiar));
                break;
            case 4:
                printf("Mediana z tablicy to: %lf\n\n", mediana(tab, rozmiar));
                break;
            case 5:
                printf("Maksymalny element tablicy to: %d\nMinimalny element tablicy to: %d\n\n", maxymalny(tab, rozmiar), minimalny(tab, rozmiar));
                break;
            case 6:
                return 0;
            default:
                printf("Wprowadzono zly numer\n\n");
        }
    }
    
    return 0;
}
