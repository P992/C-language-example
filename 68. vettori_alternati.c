#define MAXDIM 10
#include <stdio.h>

/*Prototipi*/
int carica(int vett[], char filename[]);
void pari_dispari(int vett[], int vett2[], int vett3[], int dim, int dim2);
void matrice(int matr[][MAXDIM], int vett[], int vett2[], int dim);
void stampa(int matr[][MAXDIM], int dim);

/*Programma*/
int main()
{
    char nomefile[MAXDIM], nomefile2[MAXDIM];
    int vettore[MAXDIM], vettore2[MAXDIM], vettore3[MAXDIM];
    int dimensione, dimensione2;
    int matrix[MAXDIM][MAXDIM];
    
    printf("Inserisci il nome del primo file: ");
    scanf("%s", nomefile);
    dimensione = carica(vettore, nomefile);
    if(dimensione == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    printf("\nInserisci il nome del secondo file: ");
    scanf("%s", nomefile2);
    dimensione2 = carica(vettore2, nomefile2);
    if(dimensione2 == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    pari_dispari(vettore, vettore2, vettore3, dimensione, dimensione2);
    matrice(matrix, vettore, vettore2, dimensione);
    printf("\nHai ottenuto la seguente matrice:\n");
    stampa(matrix, dimensione);
    system("PAUSE");
}
/*Funzioni*/
int carica(int vett[], char filename[])
{
    FILE* f;
    int i = 0;
    int j;
    
    f = fopen(filename, "r");
    if(f == NULL)
       return -1;
       
    while(fscanf(f, "%d", &vett[i]) != EOF)
          i++;
    
    fclose(f);
    
    printf("Hai ottenuto il seguente vettore:\n");
    for(j = 0; j < i; j++)
        printf("%d ", vett[j]);
        printf("\n");
        
    return i; 
}

void pari_dispari(int vett[], int vett2[], int vett3[], int dim, int dim2)
{
    int i, j;
    
    j = 0;
    
    for(i = 0; i < dim; i++)
    {
        if(i % 2 == 0)
        {
           vett3[j] = vett[i];  
           j++;
        }
    }
    
    for(i = 0; i < dim2; i++)
    {
        if(i % 2 != 0)
        {
           vett3[j] = vett2[i];
           j++;  
        } 
    }
    
    printf("\nHai ottenuto il seguente vettore (indici combinati):\n");
    for(i = 0; i < dim; i++)
        printf("%d ", vett3[i]);
    
    printf("\n");
}

void matrice(int matr[][MAXDIM], int vett[], int vett2[], int dim)
{
     int i, j, k;
     
     for(i = 0; i < dim; i++)
     {  
        k = 0;
        for(j = 0; j < dim; j++)
        {
            matr[i][j] = vett[i]*vett2[k];
            k++;
        }  
     }    
}

void stampa(int matr[][MAXDIM], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < dim; j++)
         {
             printf("%d \t", matr[i][j]);  
         }
         printf("\n");
     }
}
