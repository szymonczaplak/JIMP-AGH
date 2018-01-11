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
    int liczba=input_d("Podaj liczbe z zakresu <1,9>. Bedzie ona oznaczac ciezsza kulke. Kazda inna bedzie takiej sameg wagi.\n");
    if(liczba>9)
    {
        liczba= liczba %9 +1;
        printf("Liczba wieksza niz 9\nZmieniam twoja liczbe na:\n%d\n\n", liczba);
    }
    else if(liczba<1)
    {
        liczba = abs(liczba)%9 +1;
        printf("Liczba mniejsza od 1\nZmieniam Twoja liczbe na\n%d\n\n", liczba);
    }
    return liczba;
}


int guess_which_ball_is_the_heaviest(int wagi_kulek[9])
{
    int wynik=-1;
    const int suma_0_1_2=wagi_kulek[0]+wagi_kulek[1]+wagi_kulek[2];
    const int suma_3_4_5=wagi_kulek[3]+wagi_kulek[4]+wagi_kulek[5];
    
    
    if(suma_0_1_2==suma_3_4_5)
    {
        if(wagi_kulek[6]==wagi_kulek[7])
        {
            wynik=8;
        }
        else if(wagi_kulek[6]>wagi_kulek[7])
        {
            wynik=6;
        }
        else
        {
            wynik=7;
        };
    }
    else if( suma_0_1_2>suma_3_4_5)
    {
        if(wagi_kulek[0]==wagi_kulek[1])
        {
            wynik=2;
        }
        else if(wagi_kulek[0]>wagi_kulek[1])
        {
            wynik=0;
        }
        else
        {
            wynik=1;
        }
    }
    else
    {
        if(wagi_kulek[3]==wagi_kulek[4])
        {
            wynik=5;
        }
        else if(wagi_kulek[3]>wagi_kulek[4])
        {
            wynik=3;
        }
        else
        {
            wynik=4;
        }
    }
    return wynik+1;
}



int main(void)
{
    int wagi_kulek[9]={1,1,1,1,1,1,1,1,1};
    
    int user_ball=get_number_from_user();
    
    wagi_kulek[user_ball-1]++;
    
    int wynik=guess_which_ball_is_the_heaviest(wagi_kulek);
    
    printf("\nNajciezsza kulka to\n%d", wynik);
    
    return 0;
}
