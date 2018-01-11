#include <stdio.h>
#include <math.h>
#include <ctype.h>

//Szymon Czaplak

void ignore_rest_of_the_line_in_stdin(void)
{
    while (getchar() != '\n');
}

double delta (double a , double b, double c)
{
    return(b*b - 4*a*c);
}

double input_double(char tekst[])
{
    int czy_ok=0;
    double zmienna=0;
    do
    {
        printf("%s", tekst);
        
        if(scanf ("%lf", &zmienna) ==1)
        {
            czy_ok=1;
        }
        ignore_rest_of_the_line_in_stdin();
    }while(czy_ok !=1);
    return zmienna;
}

int input_int(char tekst[])
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

void if_a_is_zero(double b, double c)
{
    printf("To nie jest rownanie kwadratowe. Rozwiazanie to:\n");
    if(b==0 && c!=0)
    {
        printf("Rownanie sprzeczne.");
    }
    else if(b==0 && c==0)
    {
        printf("0=0");
    }
    else
    {
        double x1=-c/b;
        printf("To rownanie liniowe\nRozwiazanie to:\n%lf",x1);
    }
}

int czy_zespolone(void)
{
    int zespolone=0;
    do
    {
    zespolone=input_int("Czy interesuja Cie rozwiazania zespolone?\nTAK  - wybierz 1\nNIE  - wybierz 2\n");
    }while(zespolone!=1 && zespolone !=2);
    return zespolone;
}


void if_delta_is_positive(double a, double b, double c)
{
    double x1=(-b + sqrt(delta(a,b,c)))/(2*a);
    double x2=(-b - sqrt(delta(a,b,c)))/(2*a);
    printf("Rozwiazania to:\n%lf\n%lf\n", x1,  x2);
}


int main ()
{
    printf("Kalkulator pierwiastkow rownania\n"
    "a x^2 + b x + c = 0\n");
    double a=input_double("Podaj a:   a=");
    double b=input_double("Podaj b:   b=");
    double c=input_double("Podaj c:   c=");;
    
    if (a==0)
    {
        if_a_is_zero(b,c);
        return 0;
    }
    else if (delta(a,b,c)>=0)
    {
        if_delta_is_positive(a,b,c);
        return 0;   
    }
    else
    {
        printf("Delta jest ujemna. Brak rozwiazan rzeczywistych.\n");
        switch(czy_zespolone())
        {
            case 1:
            {   
                double x1=(-b)/(2*a);
                double x1_imaginary=(-sqrt(-delta(a,b,c)))/(2*a);
                double x2=x1;
                double x2_imaginary=-x1_imaginary;
                printf("\n\nTwoje rozwiazania to:\n x1= %lf+(%lf)i\n"
                "x2= %lf +(%lf)i\n",x1,x1_imaginary,x2,x2_imaginary);
                return 0;
                break;
            }
        case 2:
            {
                printf("Brak rozwiazan.");
                return 0;
            }
        }
    }
    return 1;
}
