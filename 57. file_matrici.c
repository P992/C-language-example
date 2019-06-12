#define N 20
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica(char elenco[][N], char filename[]);
void estrai(char elenco[][N], char elenco2[][N], int dim);
void m(char elenco[][N], char elenco2[][N], int dim);
void scambia(char elenco[][N], int dim);

/*Programma*/
int main()
{
    char nomefile[N];
    char lista[N][N], lista2[N][N], lista3[N][N];
    int num_parole;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    num_parole = carica(lista, nomefile);
    
    if(num_parole == -1)
       printf("Errore nel caricamento del file!");
    
    estrai(lista, lista2, num_parole);
    m(lista2, lista3, num_parole);
    scambia(lista3, num_parole);
    
    system("PAUSE");
}

/*Funzioni*/
int carica(char elenco[][N], char filename[])
{
    FILE* f;
    int i = 0;
    int dim = 0;
    
    f = fopen(filename, "r");
    
    if(f == NULL)
       return -1;
    
    fscanf(f, "%d", &dim);
    
    while(fscanf(f, "%s", elenco[i]) != EOF)
          i++;
    
    fclose(f);
    
    printf("Il file contiene il seguente elenco:\n");
    for(i = 0; i < dim; i++)
       printf("%s\n", elenco[i]);
       printf("\n");
       
    return dim;
}

void estrai(char elenco[][N], char elenco2[][N], int dim)
{
     int i, j, k;
     
     for(i = 0; i < dim; i++)
     {
         k = 0;
         for(j = 0; j <= strlen(elenco[i]); j++)
         {
             if(j % 2 == 0)
             {
               elenco2[i][k] = elenco[i][j];
               k++;
             }
         }
         elenco[i][k] = '\0';
     }
     
     printf("Parole senza lettere di indice pari:\n");
     for(i = 0; i < dim; i++)
        printf("%s\n", elenco2[i]);
        printf("\n");
}

void m(char elenco[][N], char elenco2[][N], int dim)
{
     int i, j, k;
     
     for(i = 0; i < dim; i++)
     {
         k = 0;
         for(j = 0; j < strlen(elenco[i]); j++)
         {
            if(elenco[i][j] >= 'm')
            {
               elenco2[i][k] = elenco[i][j];  
               k++;
            }
         }   
         elenco2[i][k] = '\0';
     }
     
     printf("Parole contenenti lettere maggiori di 'm':\n");
     for(i = 0; i < dim; i++)
        printf("%s\n", elenco2[i]);
        printf("\n");
}

void scambia(char elenco[][N], int dim)
{
     int i, j, k;
     char temp;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < strlen(elenco[i]); j = j+2)
         {
             temp = elenco[i][j+1];
             elenco[i][j+1] = elenco[i][j];
             elenco[i][j] = temp;  
         }
     }
     
     printf("Elenco con lettere invertite:\n");
     for(i = 0; i < dim; i++)
        printf("%s\n", elenco[i]);
        printf("\n");
}
