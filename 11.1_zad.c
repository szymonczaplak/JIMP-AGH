    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <errno.h>
    #include <time.h>
    #include <stdlib.h>
     
    #define BUFSIZE 1024
	
     
    int main (int argc, char **argv) {

		srand(time(NULL));
		if(argc != 3)
		{
			printf("Brak argumentow");
			return 1;
		}
		
		int ilosc_liczb = *argv[1] -48;
		printf("%d", ilosc_liczb);
		
		char *plik;
		plik = argv[2];
		
        FILE *f1 = fopen (plik, "w");
        if(f1 == NULL)
        {
			int err = errno;
			printf("Nie udalo sie otworzyc pliku");
			if(err == EACCES)
			{
				printf("Brak dostepu");
				return 0;
			}
		}
		
		for (int i =0; i<ilosc_liczb; i++)
		{
			int liczba = rand()%100;
			fprintf(f1, "%d \n", liczba);
		}
        
        fclose(f1);
     
        return(0);
    }

