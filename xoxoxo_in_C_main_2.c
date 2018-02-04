#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funkcje_programu_2.h"

//Szymon Czaplak
//wersja aktualna w C


int main(void)
{
   time_t t;
   srand((unsigned) time(&t));
   puts("Witaj w grze w kolko i krzyzyk\nWybor miejsca na wstawienie znaku odbywa sie przez podanie 2 liczb.\n"
   "Pierwsza liczba odpowiada wspolrzednej pionowej(kolumna)\n"
   "Druga z nich odpowiada wspolrzednej poziomej(wiersz)");
   int tablica[3][3]; 
   czysc_tablice(tablica);
   switch (tryb_gry())
   {
      case 1:
      {
         wypisz_tablice(tablica);
         int wybor_gracza1;
         int wybor_gracza2;
         switch(wczytaj_symbol_gracza())
         {
            case WARTOSC_X:
               wybor_gracza1 = 1;
               wybor_gracza2 = 2;
               break;
            case WARTOSC_O:
               wybor_gracza1 = 2;
               wybor_gracza2 = 1;
               break;
         }
         for(int i = 0; i < 4; i++)
         {
            ruch_gracz_1(wybor_gracza1, tablica);
            ruch_gracz_2(wybor_gracza2, tablica);
         }
         ruch_gracz_1(wybor_gracza1, tablica);
         puts( "\n\nRemis\n\n");
         return 0;
       }
         case 2:
            switch(poziom_trudnosci ())
            {
               case TRUDNOSC_SZYMPANS:
               { 
                  puts("/n");
                  wypisz_tablice(tablica);
                  puts("Komputer - X, gracz - Y\n");
                  for(int i = 0; i < 4; i++)
                  {
                     ruch_szympansa (tablica);
                     wypisz_tablice(tablica);
                     puts("\n");
                     if (sprawdz_wygrana(tablica) == 1)
                     {
                        wypisz_tablice(tablica);
                        puts("\n");
                        return 0;
                     }
                     ruch_gracz_1(2, tablica);
                  }
                  ruch_gracz_1(2,tablica);
                  puts("\n\nRemis\n\n");
                  return 0;
               }
               case TRUDNOSC_CZLOWIEK:
               {
                  puts("\n");
                  wypisz_tablice(tablica);
                  puts("Komputer - X, gracz - O\n");
                  for(int i = 0; i < 4; i++)
                  {
                     ruch_komputera(tablica);
                     ruch_gracz_1(2, tablica);
                  }
                  ruch_komputera(tablica);
                  puts("\n\nRemis\n\n");
                  return 0;
               }
               case TRUDNOSC_PRO:
               {
                  puts("\n");
                  wypisz_tablice(tablica);
                  puts("Komputer - X, gracz - O\n");
                  int a = 0;
                  for(int i = 0; i < 4; i++)
                  {
                     a = strategiczny_ruch_komputera(i, a, tablica);
                     ruch_gracz_1(2, tablica);
                  }
                  strategiczny_ruch_komputera(8, 9, tablica);
                  puts("\nRemis\n");
                  return 0;
               }
            }    
        puts("\n\nRemis\n\n");
        return 0;
   }
}
