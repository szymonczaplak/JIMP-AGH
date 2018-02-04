#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define Obwod 1
#define Pole 2
#define Figory 1
#define Temperatura 2
#define Katy 3
#define Kwadrat_Prostokat 1
#define Trojkat 2
#define Kolo 3

double input_double_nieujemna(char tekst[])
{
	double zmienna=0;
    do
    {  
      printf("%s", tekst);
      scanf(" %lf", &zmienna);
      while (getchar() != '\n');
    }while(zmienna<=0);
    return zmienna;
}

double input_double_dowolna(char tekst[])
{
	double zmienna =0;
    do
    {  
      printf("%s", tekst);
      scanf(" %lf", &zmienna);
      while (getchar() != '\n');
    }while(!zmienna);
    return zmienna;
}

int input_1_or_2_or_3(char tekst[])
{
	int zmienna=0;
    do
    {  
      printf("%s", tekst);
      scanf(" %d", &zmienna);
      while (getchar() != '\n');
    }while(zmienna!=1 && zmienna!=2 && zmienna!=3);
    return zmienna;
}

int obwod_czy_pole()
{
	int zmienna=0; 
	do
    {  
      printf("Obwod czy Pole?\nObwod - 1\nPole -2\n");
      scanf(" %d", &zmienna);
      while (getchar() != '\n');
    }while(zmienna!=Obwod && zmienna!=Pole);
    return zmienna;
}

void prostokat (int tryb)
{
    double bok1=input_double_nieujemna("Wpisz bok1:\n");
    double bok2=input_double_nieujemna("Wpisz bok2:\n");
                            
    switch(tryb)
    {
       case Obwod:
       {
          double wynik = 2*(bok1 + bok2);
          printf("\n\nSzukany obwod prostokata wynosi:\n%lf", wynik);
          break;
        }
                                    
       case Pole:
       {
          double wynik = bok1*bok2;
          printf("\n\nSzukane pole prostokata wynosi:\n%lf", wynik);
          break;
       }
    }
}

void trojkat (int tryb)
{
   double bok1=input_double_nieujemna("Prosze wprowadzic 1 bok trojkata:\n");
   double bok2=input_double_nieujemna("Prosze wprowadzic 2 bok trojkata:\n");
   double bok3=input_double_nieujemna("Prosze wprowadzic 3 bok trojkata:\n");
   
   if(bok1+bok2<=bok3 || bok3+bok1<=bok2 || bok2+bok3<=bok1)
   {
      printf("To nie jest trojkat\n");
      return;
   }
   else
   {
      switch(tryb)
      {
         case Obwod:
         {
            double wynik=bok1+bok2+bok3;
            printf("\n\n Szukany obwod trojkata wynosi:\n%lf", wynik);
            break;
         }
         case Pole:
         {
            double p;
            p=0.5*(bok1+bok2+bok3);
            double wynik =sqrt(p*(p-bok1)*(p-bok2)*(p-bok3));
            printf("\n\n Szukane pole trojkata wynosi:\n%lf", wynik);
            break;
         }
      }
   }
}


void kolo(int tryb)
{
   double promien=input_double_nieujemna("Prosze wprowadzic promien kola:\n");
   
   switch(tryb)
   {
      case Pole:
      {
         double wynik = M_PI*promien*promien;
         printf("\n\n Szukane pole kola wynosi:\n%lf", wynik);
         break;
      }
      case Obwod:
      {
         double wynik=2*M_PI*promien;
         printf("\n\n Szukany obwod kola wynosi:\n%lf", wynik);
         break;
      }
    }   
}


void CnaF()
{
   const int FwC = 33.8;
   double C=input_double_dowolna("Prosze wprowadzic ilosc stopni Celcjusza");
   double wynik = C*FwC;
   printf("\n\n%lf stopni Celciusza to:\n %lf stopni Farenheita:\n%lf", C ,wynik);
}

void katy()
{
   int const StopnieWPi = 180;
   double stopien=input_double_dowolna("Prosze wprowadzic ilosc stopni katowych:");
   double wynik = (M_PI/StopnieWPi)*stopien;
   printf("\n\n%lf stopni katowych to:\n %lf radianow", stopien, wynik);
}

int main ()
{
    printf("WITAJ W MOIM PROGRAMIE DROGI UZYTKOWNIKU\nPowiedz mi prosze co Ciebie interesuje :\n");
    int tryb=input_1_or_2_or_3("Aby uzyskac informacje o obwodach lub polach podstawowch figor wybierz 1.\nAby zamienic Celcjusze na Farenhajty wybierz 2\nAby zamienic stopnie na radiany wybierz 3.\n");
    
    switch(tryb)
    {
        case Figory:
            {
                int figora=input_1_or_2_or_3("\nKwadrat lub prostokat - 1\nTrojkat - 2\nKolo -3\n");
                switch(figora)
                    {
                        case Kwadrat_Prostokat: 
                        {
                           prostokat(obwod_czy_pole());
                           break;       
                        }
                        
                        case Trojkat:
                        {
                            trojkat(obwod_czy_pole());
                            break;
                        }
                        
                        case Kolo:
                        {
                            kolo(obwod_czy_pole());
                            break;
                        }
                   }    
                break;
          }
        case Temperatura:
        {
            CnaF();
            break;
        }
        case Katy:
        {
            katy();
            break;
        }
    }
return 0;
}



