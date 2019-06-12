#define N 20
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica(char elenco[][N], char filename[]);
void estrai(char elenco[][N], char elenco2[][N], int dim);
void converti(char elenco[][N], int dim);
void inversa(char elenco[][N], char elenco2[][N], int dim);

/*Programma*/
int main ()
{
    char nomefile[N];
    char lista[N][N], lista2[N][N], lista3[N][N];
    int num_parole;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    num_parole = carica(lista, nomefile);
   
    if(num_parole == -1)
       printf("Errore nel caricamento del file!\n");
       
    estrai(lista, lista2, num_parole);
    converti(lista2, num_parole);
    inversa(lista2, lista3, num_parole);
    
    system("PAUSE");
}

/*Funzioni*/
int carica(char elenco[][N], char filename[])
{
     FILE* file;
     int dim, i;
     
     
     i = 0;
     
     file = fopen(filename, "r");
     
     if(file == NULL)
        return -1;
        
     fscanf(file, "%d", &dim);
     
     while(fscanf(file, "%s", elenco[i]) != EOF)
         i++;
         
     printf("Il file contiene il seguente elenco:\n");
     for (i = 0; i < dim; i++)
          printf("%s\n", elenco[i]);
          printf("\n");
     
     fclose(file);
     
     return dim;

}

void estrai(char elenco[][N], char elenco2[][N], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < 6; j++)
         {
             elenco2[i][j] = elenco[i][j];
         }
         elenco2[i][6] = '\0';
     }
     
     printf("Elenco contenente le prime 6 lettere di ogni parola:\n");
     for (i = 0; i < dim; i++)
         printf("%s\n", elenco2[i]);
         printf("\n");
}

void converti(char elenco[][N], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
        for(j = 0; j < 7; j++)
            if(elenco[i][j] >= 'A' && elenco[i][j] <= 'Z')
               elenco[i][j] = elenco[i][j] - 'A' + 'a';
     }
     
     printf("Elenco in minuscolo:\n");
     for (i = 0; i < dim; i++)
         printf("%s\n", elenco[i]);
         printf("\n");
}

void inversa(char elenco[][N], char elenco2[][N], int dim)
{
     int i, j, k;
     
     for(i = 0; i < dim; i++)
     {
        k = 0;
        
        for(j = 5; j >=0 ; j--)
        {
            elenco2[i][k] = elenco[i][j];
            elenco2[i][6] = '\0';
            k++;
        }    
     }
     
     printf("Elenco invertito:\n");
     for (i = 0; i < dim; i++)
         printf("%s\n", elenco2[i]);
}
