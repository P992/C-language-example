#define M 100
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica_vettore(int vett[]);
void ordina(int vett[], int dim_v);
void stampa(int vett[], int dim_v);
int cercamin(int vett[], int inizio, int fine);

/*Programma*/
int main ()
{
    int dim, i;
    int v[M];
    
    dim = carica_vettore(v);
    ordina(v, dim);
    stampa(v, dim);
    
    system("PAUSE");
}

/*Funzioni*/
int carica_vettore(int vett[])
{
    int i, dim_v;
    
    printf("Quanti valori vuoi inserire? ");
    scanf("%d", &dim_v);
    
    for(i = 0; i < dim_v; i++)
    {
        printf("Elemento %d: ", i+1);
        scanf("%d", &vett[i]);
    }
    
    return dim_v;
}

void ordina(int vett[], int dim_v)
{
     int temp, i, ind_min;
     
     for(i = 0; i < dim_v; i++)
     {
         ind_min = cercamin(vett, i, dim_v);
         temp = vett[i];
         vett[i] = vett[ind_min];
         vett[ind_min] = temp;
     }
} 

int cercamin(int vett[], int inizio, int fine)
{
    int ind_min, j;
    
    ind_min = inizio;
    
    for(j = inizio+1; j < fine; j++)
    {
        if(vett[j] < vett[ind_min])
        ind_min = j;  
    }
    
    return ind_min;
}

void stampa(int vett[], int dim_v)
{
     int i;
     
     printf("Hai ottenuto il seguente vettore ordinato:\n");
     for(i = 0; i < dim_v; i++)
     printf("%d ", vett[i]);
     
     printf("\n");
}
