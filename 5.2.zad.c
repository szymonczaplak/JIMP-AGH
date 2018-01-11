#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Szymon Czaplak

void wypisz_tablice(int kolumny, int wiersze, int tablica[kolumny][wiersze])
{
   for(int i=0; i<kolumny;i++)
   {
      for (int j=0; j<wiersze; j++)
      {
          printf("|  %2d  |",tablica[i][j]);
      }

      printf("\n");
   }

}

void losuj_tablice(int wiersze, int kolumny, int tablica[kolumny][wiersze])
{
    for(int i=0;i<kolumny; i++)
    {
        for(int k=0; k<wiersze; k++)
        {
            tablica[i][k]=rand()%11;
        }
    }
}

int licz_wyznacznik(int tablica[3][3])
{
    return tablica[0][0]*tablica[1][1]*tablica[2][2] + tablica[0][1]*tablica[1][2]*tablica[2][0] + tablica[0][2]*tablica[1][0]*tablica[2][1] - tablica[0][2]*tablica[1][1]*tablica[2][0] - tablica[0][1]*tablica[1][0]*tablica[2][2] - tablica[0][0]*tablica[1][2]*tablica[2][1];
}

int main(void)
{
    srand(time(NULL));
    int tablica[3][3];;
    losuj_tablice(3, 3, tablica);
    int wyznacznik = licz_wyznacznik(tablica);
    wypisz_tablice(3, 3, tablica);
    printf("\nWyznacznik to:\n%d",wyznacznik);
}


