#include <stdio.h>
#include <stdlib.h>

//Szymon Czaplak

void ignore_rest_of_the_line_in_stdin(void)
{
    while (getchar() != '\n');
}

int input_d(char tekst[])
{
    int czy_ok=0;
    int zmienna=0;
    do
    {
        printf("%s", tekst);
        
        if(scanf ("%d", &zmienna) ==1)
        {
            czy_ok=1;
        }
        ignore_rest_of_the_line_in_stdin();
    }while(czy_ok !=1);
    return zmienna;
}

int get_number_from_user(void)
{
    int liczba=input_d("Podaj liczbe z zakresu <1,10>\n");
    if(liczba>10)
    {
        liczba= liczba %10 +1;
        printf("Liczba wieksza od 10\nZmieniam Twoja liczbe na:\n%d\n\n", liczba);
    }
    else if(liczba<1)
    {
        liczba = (-liczba) % 10 +1;
        printf("Liczba mniejsza od 1\nZmieniam Twoja liczbe na\n%d\n\n", liczba);
    }
    return liczba;
}

int guess_number(int number)
{
    int wynik=0;
    if(number<6)
    {
        if(number<3)
        {
            if(number<2)
            {
                wynik=1;
            }
            else
            {
                wynik=2;
            }
        }
        else if(number>3)
        {
            if (number<5)
            {
                wynik=4;
            }
            else
            {
                wynik=5;
            }
        }
        else
        {
            wynik=3;
        };
    }
    else
    {
        if(number<8)
        {
            if(number<7)
            {
                wynik=6;
            }
            else
            {
                wynik=7;
            }
        }
        else if(number>8)
        {
            if(number<10)
            {
                wynik=9;
            }
            else
            {
                wynik=10;
            }
        }
        else
        {
            wynik=8;
        };
    }
    return wynik;
}

int main(void)
{
    int user_number = get_number_from_user();
    int wynik=guess_number(user_number);
    printf("\nTwoj numer to:\n%d", wynik);
    return 0;
}

    
    
    
    
    
    
    
