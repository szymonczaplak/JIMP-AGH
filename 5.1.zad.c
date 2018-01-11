#include <stdio.h>

//Szymon Czpaplak

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


int input_hours(void)
{
    int zmienna;
    do
    {
        zmienna = input_int("Prosze wprowadzic liczbe godzin:\n");
    }while(!(zmienna<25 && zmienna>-1));
    return zmienna;
}

int input_minutes_or_seconds(char tekst[])
{
    int zmienna;
    do
    {
        zmienna = input_int(tekst);
    }while (!(zmienna>-1 && zmienna < 60));
    return zmienna;
}

int time_to_seconds(int const godzina[3])
{
    int const liczba_s_w_h = 3600;
    int const liczba_s_w_min = 60;
    return godzina[0] * liczba_s_w_h + godzina[1] * liczba_s_w_min + godzina[2];
}

int compare_time(int const godzina1[3] , int const godzina2[3])
{
    int const wartosc_godziny_1_w_s = time_to_seconds(godzina1);
    int const wartosc_godziny_2_w_s = time_to_seconds(godzina2);
    
    if(wartosc_godziny_1_w_s == wartosc_godziny_2_w_s)
    {
        return 0;
    }
    else if(wartosc_godziny_1_w_s > wartosc_godziny_2_w_s)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
}

void conclusion(int const godzina1[3], int const godzina2[3])
{
    switch(compare_time(godzina1, godzina2))
    {
        case 1:
            puts("Pierwsza godzina jest pozniejsza");
            break;
        case 0:
            puts("Godziny sa sobie rowne");
            break;
        case -1:
            puts("Druga godzina jest pozniejsza");
            break;
    }
}


int main(void)
{
    int godzina1[3];
    int godzina2[3];
    
    godzina1[0] = input_hours();
    godzina1[1] = input_minutes_or_seconds("Prosze wpisac liczbe minut:\n");
    godzina1[2] = input_minutes_or_seconds("Prosze wpisac liczbe sekund:\n");
    
    printf("\n\n");
    
    godzina2[0] = input_hours();
    godzina2[1] = input_minutes_or_seconds("Prosze wpisac liczbe minut:\n");
    godzina2[2] = input_minutes_or_seconds("Prosze wpisac liczbe sekund:\n");
    
    conclusion(godzina1, godzina2);

    return 0;
}
