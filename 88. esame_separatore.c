#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCAR 30
#define MAXDIM 100

int carica(char filename[], char elenco[][MAXCAR], char sep);
void inverti(char elenco[][MAXCAR], int dim);
void visualizza(char elenco[][MAXCAR], int dim);

int main()
{
    char nomefile[MAXCAR];
    char lista[MAXDIM][MAXCAR];
    int dimensione;
    char separatore;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    fflush(stdin);
    
    printf("Inserisci il separatore da escludere: ");
    scanf("%c", &separatore);  
    
    dimensione = carica(nomefile, lista, separatore);
    if(dimensione == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;           
    }
    
    printf("\nIl file contiene il seguente elenco:\n");
    visualizza(lista, dimensione);
    
    inverti(lista, dimensione);
    printf("\nElenco invertito:\n");
    visualizza(lista, dimensione);
    system("PAUSE");
}

int carica(char filename[], char elenco[][MAXCAR], char sep)
{
    FILE* f;
    int i, j;
    
    f = fopen(filename, "r");
    if(f == NULL)
       return 0;
    
    i = 0;
    while(fscanf(f, "%c", &elenco[i][0]) != EOF)
    {
          j = 1;
          do
          {
              fscanf(f, "%c", &elenco[i][j]);
              j++;          
          }while(elenco[i][j-1] != sep);
          elenco[i][j-1] = '\0';
          i++;
    }
      
    fclose(f);
    
    return i;
}

void inverti(char elenco[][MAXCAR], int dim)
{
     int i;
     char temp[MAXCAR];

     for(i = 0; i < (dim/2)-1; i++)
     {
        strcpy(temp, elenco[i]);
        strcpy(elenco[i], elenco[dim-1-i]);
        strcpy(elenco[dim-1-i], temp);
     }
}
void visualizza(char elenco[][MAXCAR], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
         printf("%s\n", elenco[i]);
}
