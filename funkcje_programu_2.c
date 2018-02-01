#include "funkcje_programu_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wczytanie_deklaracji(void)
{
   int zmienna=0;
   do
   {
      puts("Prosze wybrac dla gracza 1. (1=X;2=O)\n");
      scanf(" %d", &zmienna);
      while (getchar()!= '\n');
   }while(!(zmienna == 1 || zmienna == 2));
   return zmienna;
}

int wczytaj_symbol_gracza(void)
{
   int wybor = wczytanie_deklaracji();
   switch(wybor)
   {
      case 1:
         wybor = WARTOSC_X;
         break;
      case 2:
         wybor = WARTOSC_O;
         break;
   }
   return wybor;
}

void ruch_gracz_2(int wybor_gracza2, int tablica[3][3])
{
   gracz2();
   ruch(wybor_gracza2, tablica);
   wypisz_tablice(tablica);
   if (sprawdz_wygrana(tablica) == 1)
   {
      wypisz_tablice(tablica);
      exit(0);
   }
}

void gracz2 (void)
{
    puts("Kolej gracza 2\n");
}

int sprawdzam_poziom (int tryb, int tablica[3][3])
{
   int suma = 0;
   for(int a = 0; a < 3; a++)
   {
       suma = 0;
       for(int i = 0; i < 3; i++)
       {   
          suma += tablica[a][i];
       }
       if (suma == tryb)
       { 
          for(int j = 0; j < 3; j++)
          {
             if(tablica[a][j] == 0)
             {
 				tablica[a][j] = 1;
	 		}
          }
       return 1;
       }
	}
	return 0;   
}


int sprawdzam_pion(int tryb, int tablica[3][3])
{
   int suma = 0;
   for(int a = 0; a < 3; a++)  
   {
      suma = 0;
      for(int i = 0; i < 3; i++)
      {   
         suma += tablica[i][a];
      }
      if(suma == tryb)
      {
         for(int j = 0; j < 3; j++)
         {
            if(tablica[j][a] == 0)
            {
				tablica[j][a] = 1;
			}
         }
         return 1;
      }
   }
   return 0;
}


int sprawdzam_skosy (int tryb, int tablica[3][3])
{
   int suma = tablica[0][0]+tablica[1][1]+tablica[2][2];
   if(suma == tryb)
   {
      for(int c = 0; c < 3; c++)
      {
         if(tablica[c][c] == 0)
         {
		    tablica[c][c] = 1;
		 }
      }
      return 1;
   }

   suma = (tablica[0][2]+tablica[1][1]+tablica[2][0]);
   if(suma == tryb)
   {
      int e = 0;
      for (int d = 2; d > -1; d--)
      {
         if(tablica[e][d] == 0)
         {
            tablica[e][d] = 1;
         }
         e++;
      }
      return 1;
   }
   return 0;
}


int zagrozenie(int tryb, int tablica[3][3])
{
   return sprawdzam_pion(tryb,tablica) == 1 || sprawdzam_poziom(tryb,tablica) == 1 || sprawdzam_skosy(tryb,tablica) == 1;
}   


int poziom_trudnosci(void)
{
   int trudnosc_gry;
   do
   {
      puts("Wybierz poziom trudnosci\n1=szympans\n2=czlowiek\n3=zawodowiec");
      scanf("%d", &trudnosc_gry);
      while(getchar() != '\n');
   }while(trudnosc_gry != TRUDNOSC_SZYMPANS && trudnosc_gry != TRUDNOSC_CZLOWIEK && trudnosc_gry != TRUDNOSC_PRO);
   return trudnosc_gry;
}


void ruch_szympansa(int tablica[3][3])
{
   int wiersz,kolumna;
   int czy_gotowe = 0;
   do
   {
      wiersz = rand() % 3;
      kolumna = rand () % 3;
      if (tablica[wiersz][kolumna] == 0)
      {
         tablica[wiersz][kolumna]= WARTOSC_X;
         czy_gotowe = 1;
         return;
      }

   }while(czy_gotowe == 0);
}


void ruch_komputera(int tablica[3][3])
{
   if(zagrozenie(2,tablica) == 0)
   {
      if(zagrozenie(-2, tablica) == 0)
      {
         ruch_szympansa(tablica);
      }
   }
   wypisz_tablice(tablica);
   puts("\n");
   if(sprawdz_wygrana(tablica) == 1)
   {
      wypisz_tablice(tablica);
      puts("\n");
      exit(0);
   }
}


void ruch_pierwszy(int tablica[3][3])
{
   tablica[0][2] = WARTOSC_X;
   wypisz_tablice(tablica);
   puts("\n");
}


int ruch_drugi(int tablica[3][3])
{
   int scenariusz = 0;
   switch(tablica[1][1])
   {
      case WARTOSC_O:
      {
         scenariusz = 1;
         ruch_komputera(tablica);
         break;
         
      }
      case 0:
      {
         if(tablica[0][0] + tablica[2][2] == WARTOSC_O)
         { 
            scenariusz = 2;
            tablica[2][0] = WARTOSC_X;
            wypisz_tablice(tablica);
            puts("\n");
         }
         else if(tablica[1][0] + tablica[1][2] + tablica[2][1] == WARTOSC_O)
         {
            scenariusz = 3;
            tablica[0][0] = WARTOSC_X;
            wypisz_tablice(tablica);
            puts("\n");
         }
         else if(tablica[0][1] == WARTOSC_O)
         {
            scenariusz = 5;
            tablica[2][2] = WARTOSC_X;
            wypisz_tablice(tablica);
            puts("\n");
         }
         else
         {
            scenariusz = 4;
            ruch_komputera(tablica);
         }
         break;
      }
   }
   return scenariusz;
}


void ruch_trzeci(int scenariusz, int tablica [3][3])
{
   if(zagrozenie(2,tablica)==0)
   {
      if(zagrozenie(-2, tablica)==0)
      {
         switch(scenariusz)
         {
            case 1:
                  ruch_komputera(tablica);
                  break;
            case 4:
               ruch_komputera(tablica);
               break;
            case 2:
            {
               if(tablica[0][0] == WARTOSC_O)
               {
                  tablica[2][2] = WARTOSC_X;
               }
               else
               {
                  tablica[0][0] = WARTOSC_X;
               }
               break;
            }
            case 3:
            {
               tablica[1][1] = WARTOSC_X;
               break;
            }
            case 5:
            { 
               tablica[1][1] = WARTOSC_X;
               break;
            }
         }
         wypisz_tablice(tablica);
         puts("\n");
      }
   }
   wypisz_tablice(tablica);
   puts("\n");
   if (sprawdz_wygrana(tablica) == 1)
   {
      wypisz_tablice(tablica);
      puts("\n");
      exit(0);
   }
   
}


int strategiczny_ruch_komputera(int ktory, int scenariusz, int tablica[3][3])
{
   switch(ktory)
   {
      case 0:
         ruch_pierwszy(tablica);
         break;
      case 1:
         scenariusz = ruch_drugi(tablica);
         break;
      case 2:
         ruch_trzeci(scenariusz, tablica);
   }
   if(ktory > 2)
   {
      ruch_komputera(tablica);
   }
   return scenariusz;
}

void ruch_gracz_1(int wybor_gracza1, int tablica[3][3])
{
   gracz1();
   ruch(wybor_gracza1,tablica);
   wypisz_tablice(tablica);
   if (sprawdz_wygrana(tablica) == 1)
   {
      wypisz_tablice(tablica);
      exit(0);
   }
}

int czysc_tablice(int tablica[3][3])
{
   for(int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         tablica[i][j]=0;
      }
    }
    return 0;
}

void wypisz_tablice(int tablica[3][3])
{
   printf("     <1>    <2>    <3>\n");
   for(int i = 0; i < 3; i++)
   {
      printf("%d) ",i + 1);
      for (int j = 0; j < 3; j++)
      {
         
         switch( tablica[i][j])
         {
            case 0:
               printf("|     |");
               break;
            case WARTOSC_X:
               printf("|  X  |");
               break;
            case WARTOSC_O:
               printf("|  O  |");

          }

      }
      printf("\n");
   }
}

void gracz1 (void)
{
    puts("Kolej gracza 1\n");
}

int wczytaj_wspolrzedna(char tekst[])
{
   int zmienna=0;
   do
   {
      printf("Podaj %s:\n", tekst);   
      scanf("%d", &zmienna);
      while(getchar() != '\n');
      zmienna -= 1;
   }while(zmienna < 0 || zmienna > 2);
   return zmienna;
}

void ruch(int wybor, int  tablica[3][3])
{
   int kolumna = 0;
   int wiersz = 0;
   do
   {
      kolumna = wczytaj_wspolrzedna("kolumne");
      wiersz = wczytaj_wspolrzedna("wiersz");
   }while(tablica[wiersz][kolumna]);
   switch(wybor)
   {
      case 1:
         tablica[wiersz][kolumna] = WARTOSC_X;    
         break;
      case 2:
         tablica[wiersz][kolumna] = WARTOSC_O;    
      break;
   }

}

int werdykt_wygranej(int suma)
{
	switch(suma)
         {
            case 3*WARTOSC_X:
               puts("\n\n\nWygraly X\n\n");
               return 1;
            case 3*WARTOSC_O:
               puts("\n\n\nWygraly O\n\n");
               return 1;
         }
     return 0;
}

int sprawdz_wygrana (int tablica[3][3])
{
	int wyznacznik_wygranej = 0;
   int suma = 0;
   for(int a = 0; a < 3; a++)
      {
         for(int i = 0; i < 3; i++)
         {
            suma += tablica[a][i];
         }
         wyznacznik_wygranej += werdykt_wygranej(suma);
				
         suma = 0;
      }


   for(int a = 0; a < 3; a++)
   {
      for(int i = 0; i < 3; i++)
         {
            suma += tablica[i][a];
         }
      wyznacznik_wygranej += werdykt_wygranej(suma);
      suma = 0;
   }

   suma = tablica[0][0] + tablica[1][1] + tablica[2][2];
   wyznacznik_wygranej += werdykt_wygranej(suma);
   
   suma = tablica[0][2] + tablica[1][1] + tablica[2][0];
   wyznacznik_wygranej += werdykt_wygranej(suma);
	
	return (wyznacznik_wygranej >= 1);
}

int tryb_gry (void)
{
   int tryb;
   do
   {
      puts("Wybierz tryb gry:\n1=wersja dla 2 graczy\n2=wersja dla 1 gracza");
      scanf("%d", &tryb);
      while(getchar() != '\n');
   }while (!(tryb == 1 || tryb == 2));
   return tryb;
}














