#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

/*Prototipi*/
int ottieni_da_file(float vett[MAX], char filename[]);
void ordina(float vett[MAX], int dim);
void stampa(float array[MAX], int dim);
void stampa_per_gruppi(float array[MAX], int riemp);

/*Programma*/
int main() 
{
    int dimensione;
    float vettore[MAX];
    char nomefile[MAX];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    dimensione = ottieni_da_file(vettore, nomefile);
    if(dimensione == -1)
    {
       printf("Errore nel caricamento del file!\n");
       return -1;
       system("PAUSE");
    }
    
    printf("\nIl file contiene il seguente vettore:\n");
    stampa(vettore, dimensione);
    
    ordina(vettore, dimensione);
    printf("\nVettore ordinato in base alle cifre decimali:\n");
    stampa(vettore, dimensione);
    printf("\n");
    system("PAUSE");
}

/*Funzioni*/
int ottieni_da_file(float vett[MAX], char filename[])
{
    FILE* f;
    int i = 0;
    int riemp = 0;
    
    f = fopen(filename, "r");
    if(f == NULL)
       return -1;
       
    while(fscanf(f, "%f", &vett[i]) != EOF)
    {
          i++;
          riemp++;
    }
    
    return riemp;
}

void ordina(float vett[MAX], int dim)
{
     int i, j;
     float temp;
     float num = 1.0000;
     float vett2[MAX];   
     
     for(i = 0; i < dim; i++)
     {
         vett2[i] = vett[i];
     }
     
     for(i = 0; i < dim; i++)
     {
         while(vett2[i] >= 1.00000){
               vett2[i] = vett2[i] - num;}
     }
     
     for(i = 0; i < dim; i++)
     {   
         for(j = dim-1; j > i; j--)
         {                   
             if(vett2[j] < vett2[j-1]) 
             {
                temp = vett2[j];
                vett2[j] = vett2[j-1];
                vett2[j-1] = temp;
                temp = vett[j];
                vett[j] = vett[j-1];
                vett[j-1] = temp;
             }
         }
     }
}

void stampa(float array[MAX], int riemp) 
{
     int i;
     for (i = 0; i < riemp; i++) 
     {
          printf("%.2f ", array[i]);
     }
}
