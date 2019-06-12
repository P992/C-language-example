#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE *f;
    char vettore[100];
    int i=0;   
    
    f = fopen("stampa_video_file.txt", "r");
    
    if(f==NULL)
       printf("Errore nel caricamento del file.\n");
    else 
    {
       while((fscanf(f, "%c", &vettore[i])) != EOF)
       {
             printf("%c", vettore[i]);
             i++;
       }
             fclose(f);
    }
    
    system("PAUSE");
}

