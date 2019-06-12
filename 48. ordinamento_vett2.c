/*Dato un vettore da input il programma ordina gli elementi in maniera decrescente ed annulla i numeri pari*/

#define N 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Prototipi*/
int carica_vettore(int vett[]);
void ordina_vettore(int vett[], int vett2[], int dim);
void copia_vettori(int vett[], int vett2[], int dim);
int cercamax(int vett[], int inizio, int fine);
void annulla_pari(int vett[], int vett3[], int dim);
void stampa(int vett[], int dim);

/*Programma*/
int main()
{
    int v[N], v2[N], v3[N];
    int dimensione;
    
    dimensione = carica_vettore(v);
    ordina_vettore(v, v2, dimensione);
    annulla_pari(v2, v3, dimensione);
    
    printf("Ecco il vettore originale:\n");
    stampa(v, dimensione);
    printf("Ecco il vettore ordinato:\n");
    stampa(v2, dimensione);
    printf("Ecco il vettore ordinato senza numeri pari:\n");
    stampa(v3, dimensione);
    
    system("PAUSE");
}

/*Funzioni*/
int carica_vettore(int vett[])
{
    int i, dim;
    
    printf("Quanti valori vuoi inserire? ");
    scanf("%d", &dim);
    
    for(i = 0; i < dim; i++)
    {
        printf("Elemento %d: ", i+1);
        scanf("%d", &vett[i]);
    }
     
    return dim;
}

void ordina_vettore(int vett[], int vett2[], int dim)
{
     int i, indice_max;
     int temp;
     
     copia_vettori(vett, vett2, dim);
     
     for(i = 0; i < dim; i++)
     {
        indice_max = cercamax(vett2, i, dim);
        temp = vett2[i];
        vett2[i] = vett2[indice_max];
        vett2[indice_max] = temp;
     }     
}

int cercamax(int vett[], int inizio, int fine)
{
    int j, indice_max;
    
    indice_max = inizio;
    
    for(j = inizio+1; j < fine; j++)
    {
        if(vett[indice_max] < vett[j])
           indice_max = j;
    }
    
    return indice_max;
}

void copia_vettori(int vett[], int vett2[], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
        vett2[i] = vett[i];
}

void annulla_pari(int vett2[], int vett3[], int dim)
{
     int i;
     
     copia_vettori(vett2, vett3, dim);
     
     for(i = 0; i < dim; i++)
     {
        if(vett3[i] % 2 == 0)
           vett3[i] = 0;
     }
}

void stampa(int vett[], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
        printf("%d ", vett[i]);
        
     printf("\n");
}
