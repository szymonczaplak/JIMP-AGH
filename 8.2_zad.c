#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

enum ArgumentType {TYPE_CHAR =0, TYPE_CHAR_P =1, TYPE_INT =2, TYPE_DOUBLE =3}; 

void printArgumentInTheMiddle(void* argument, enum ArgumentType type, unsigned width);

void printInMiddleForCharPointer(void* argument, enum ArgumentType type, unsigned width, int linia)
{
    char argument_in_char = *(char*)argument;
    if(width <1)
    {
        return;
    }
    if(isprint(argument_in_char) == 0)
    {
        printf("\n");
        return;
    }
    for(int i =0; i<linia; i++)
    {
        printf(".");
    }
    printf("%c", argument_in_char);
    for (int i=0; i<(width-linia-1); i++)
    {
        printf(".");
    }
    printf("\n");
}

void printInMiddleForChar(void* argument, enum ArgumentType type, unsigned width, int linia)
{
    if(width <1)
    {
        return;
    }
    if(isprint(*(char*)argument) == 0)
    {
        printf("\n");
        return;
    }
    for( int i =0; i<linia; i++)
    {
        printf(".");
    }
    printf("%c", *(char*)argument);
    for (int i=0; i<(width-linia-1); i++)
    {
        printf(".");
    }
    printf("\n");
}

void printInMiddleForInt(void* argument, enum ArgumentType type, unsigned width)
{
    int linia = width - (log10(*(int*)argument)+1);
    if(linia <0)
    {
        int size = (int)(log10(*(int*)argument)+1);
        char char_number[size];
        sprintf(char_number, "%d", *(int*)argument);
        for (int i=0; i<width; i++)
        {
            printf("%c", char_number[i]);
        }
        printf("\n");
        return;
    }
    
    for( int i =0; i<linia/2; i++)
    {
        printf(".");
    }
    printf("%d", *(int*)argument);
    for (int i=0; i<(width-linia/2 -((log10(*(int*)argument)+1))); i++)
    {
        printf(".");
    }
    printf("\n");
}

void printInMiddleForDouble(void* argument, enum ArgumentType type, unsigned width)
{
    double arg_double = *(double*)argument;
    if(*(double*)argument == ceil(*(double*)argument))
    {
        int arg_int = (int)arg_double;
        printf("COS");
        printArgumentInTheMiddle(&arg_int, TYPE_INT, width);
        return;
    }
    int dlugosc=4;
    dlugosc += log10(*(double*)argument)+1;
    int linia = width - dlugosc;
    if(linia < 0)
    {
        char char_number[dlugosc];
        sprintf(char_number, "%lf", *(double*)argument);
        for (int i=0; i<width; i++)
        {
            printf("%c", char_number[i]);
        }
        printf("\n");
        return;
        return;
    }
    
    for( int i =0; i<linia/2; i++)
    {
        printf(".");
    }
    printf("%.3lf", *(double*)argument);
    for (int i=0; i<(width-linia/2 -dlugosc); i++)
    {
        printf(".");
    }
    printf("\n");
}

void printArgumentInTheMiddle(void* argument, enum ArgumentType type, unsigned width)
{
    int linia =0;
    if(NULL == argument)
    {
        printf("\n");
        return;
    }
    
    if(width% 2 == 0)
    {
        linia = width/2-1;
    }
    else
    {
        linia = width /2;
    }
    if(type==TYPE_CHAR_P)
    {
        printInMiddleForCharPointer(argument, type, width, linia);
    }
    else if(type == TYPE_CHAR)
    {
        printInMiddleForChar(argument, type, width, linia);
    }
        
    else if(type == TYPE_INT)
    {
        printInMiddleForInt(argument, type, width);
    }
    else
    {
        printInMiddleForDouble(argument, type, width);
    }
} 

int main(void)
{
    char arg ='l';
    printArgumentInTheMiddle(&arg, TYPE_CHAR, 7);
    
    char *chp =&arg;
    
    printArgumentInTheMiddle(chp, TYPE_CHAR_P, 4);

    int a = 1000;
    
    int *ip = &a;
    
    printArgumentInTheMiddle(ip, TYPE_INT, 2);
    
    double b=12.243254;
    double *bp = &b;
    
    printArgumentInTheMiddle(bp, TYPE_DOUBLE,7);
    
    
    return 0;
}
