#define N 10
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica(int matr[][N], char filename[]);
void ordina(int matr[][N], int vett[], int dim);
int s(int matr[][N], int dim, int j);
int cercamin(int vett[], int inizio, int dim);
void stampa(int matr[][N], int dim);

/*Programma*/
int main ()
{
    int dimensione;
    int matrice[N][N], vettore[N];
    char nomefile[N];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    dimensione = carica(matrice, nomefile);
    
    if(dimensione == -1)
      printf("Errore nel caricamento del file!\n");
    
    ordina(matrice, vettore, dimensione);
    
    printf("\nEcco la matrice ordinata:\n");
    stampa(matrice, dimensione);
    
    system("PAUSE");
}

/*Funzioni*/
int carica(int matr[][N], char filename[])
{
    FILE* f;
    int dim;
    int i, j;
    
    f = fopen(filename, "r");
    
    if(f == NULL)
      return -1;
    
    fscanf(f, "%d", &dim);
    
    for(i = 0; i < dim; i++)
    {
       for(j = 0; j < dim; j++)
          fscanf(f, "%d", &matr[i][j]);
    }
    
    fclose(f);
    
    printf("Il file contiene la seguente matrice:\n");
    for(i = 0; i < dim; i++)
    {
       for(j = 0; j < dim; j++){
          printf("%d\t", matr[i][j]);
       }
       printf("\n");
    }
    return dim;
}

void ordina(int matr[][N], int vett[], int dim)
{
     int i, j, k;
     int somma;
     int temp;
     int indice_min;
     
     for(j = 0; j < dim; j++)
     {
         somma = s(matr, dim, j);
         vett[j] = somma;
     }
     
     for(j = 0; j < dim; j++)
     {
	     indice_min = cercamin(vett, j, dim);
         for(i = 0; i < dim; i++)
         {
             temp = matr[i][j];
             matr[i][j] = matr[i][indice_min];
             matr[i][indice_min] = temp;
         }
	     temp = vett[j];
         vett[j] = vett[indice_min];
         vett[indice_min] = temp;
     }
}

int s(int matr[][N], int dim, int j)
{
     int i;
     int somma = 0;
     
     for(i = 0; i < dim; i++)
         somma = somma + matr[i][j];
         
     return somma;
}

int cercamin(int vett[], int inizio, int dim)
{
    int ind_min = inizio;
    int n;
    
    for(n = inizio+1; n < dim; n++)
    {
        if(vett[n] < vett[ind_min])
           ind_min = n;
    }
    return ind_min;
}

void stampa(int matr[][N], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < dim; j++)
             printf("%d\t", matr[i][j]);
             printf("\n");
     }
}
