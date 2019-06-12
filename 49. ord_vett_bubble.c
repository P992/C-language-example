#define M 100
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica_vettore(int vett[]);
void ordina(int vett[], int dim_v);
void stampa(int vett[], int dim_v);

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
     int i, j, temp;
     
     for(i = 0; i < dim_v; i++)
     {
        for(j = dim_v-1; j > i; j--)
        {
            if(vett[j] < vett[j-1])
            { 
               temp = vett[j];
               vett[j] = vett[j-1];
               vett[j-1] = temp;  
            }
        }      
     }
} 

void stampa(int vett[], int dim_v)
{
     int i;
     
     printf("Hai ottenuto il seguente vettore ordinato:\n");
     for(i = 0; i < dim_v; i++)
     printf("%d ", vett[i]);
     
     printf("\n");
}
