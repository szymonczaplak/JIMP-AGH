#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Szymon Czaplak

void wypisz_tablice(int kolumny, int wiersze, long long tablica[kolumny][wiersze])
{
   for(int i=0; i<kolumny;i++)
   {
      for (int j=0; j<wiersze; j++)
      {
          printf("|  %lld  |",tablica[i][j]);
      };
      
      printf("\n");
   }
   printf("\n\n");
}


void losuj_tablice(int kolumny, int wiersze, long long tablica[kolumny][wiersze])
{
    for(int i=0;i<kolumny;i++)
    {
        for(int k=0; k<wiersze; k++)
        {
            tablica[i][k]=rand()%201 - 100;
        }
    }
}


void convert_to_3D(int kolumny, int wiersze, long long macierz_2d_1[kolumny][wiersze], long long macierz_2d_2[kolumny][wiersze], long long macierz_3d[3][3][2])
{
    for(int i=0; i<kolumny; i++)
    {
        for(int k=0; k<wiersze; k++)
        {
             macierz_3d[i][k][0] = macierz_2d_1[i][k];
             macierz_3d[i][k][1] = macierz_2d_2[i][k];
        }
    }
}


void mnozenie(int kolumny, int wiersze, long long macierz_3d[kolumny][wiersze][2])
{
    long long wynik[3][3];
    long long suma=0;
    for(int i=0; i<kolumny; i++)
    {
        for(int k=0; k<wiersze; k++)
        {
            suma=0;
            for(int c=0; c<3; c++)
            {
                suma += (macierz_3d[i][c][0] * macierz_3d[c][k][1]);
            }
            
            wynik[i][k]=suma;
            
        }
    }
    wypisz_tablice(3, 3, wynik);
}
            
            
            
int main(void)
{
    srand(time(NULL));
    
    long long macierz_2d_1[3][3] , macierz_2d_2[3][3];
    long long macierz_3d[3][3][2];
    
    losuj_tablice(3, 3, macierz_2d_1);
    losuj_tablice(3, 3, macierz_2d_2);
    
    printf("Macierz A:\n");
    wypisz_tablice(3, 3, macierz_2d_1);
    
    printf("Macierz B:\n");
    wypisz_tablice(3, 3, macierz_2d_2);
    
    printf("Wynik mnozenia AB to:\n");
    
    convert_to_3D(3, 3, macierz_2d_1, macierz_2d_2, macierz_3d);
    
    mnozenie(3, 3, macierz_3d);
    
    
    return 0;
}
    
    
