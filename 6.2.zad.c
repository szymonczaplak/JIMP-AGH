#include <stdio.h>
#include <time.h>

int days_in_month(int month, int year)
{
    if(month == 0 || month== 2 || month ==4 || month == 6 || month == 7 || month ==9 || month ==11)
    {
      return 31;
      }
    else if(month ==2)
    {
        if((year%4 == 0 && year % 100 != 0) || year %400 ==0)
        {
           return 29;
        }
        else
        {
           return 28;
        }
    }
    else
    {
        return 30;
    } 
}

int actual_month()
{
	time_t rawtime;
    time (&rawtime);
    struct tm *tm_struct = localtime(&rawtime);
    return tm_struct -> tm_mon;
}

int actual_year()
{
	time_t rawtime;
    time (&rawtime);
    struct tm *tm_struct = localtime(&rawtime);
    return tm_struct -> tm_year;
}


int main ()
{
    int month = actual_month();
    int year = actual_year();
    int number_of_days = days_in_month(month, year); 
    
    for(int i=0; i<number_of_days; i++)
    {
        printf("%2d  ", i+1);
        if( (i+1)%7 ==0 )
        {
            printf("\n");
        }
    }
       
    return 0;
}
