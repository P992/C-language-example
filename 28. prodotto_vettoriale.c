#include <stdio.h>
#define N 10

int main ()
{
    int vett1[N];
    int vett2[N];
    int riemp;
    long int somma;
    int cont;
    
    do
    {
      printf("Quanti elementi vuoi inserire nei vettori? ");
      scanf("%d", &riemp);   
    }while(riemp < 1 || riemp > N);
    
    for(cont = 0; cont < riemp; cont = cont + 1)
    {
       printf("Inserisci il valore che occupa l'indice %d del primo vettore: ", cont);
       scanf("%d", &vett1[cont]);
       
       printf("Inserisci il valore che occupa l'indice %d del secondo vettore: ", cont);
       scanf("%d", &vett2[cont]);
    }
    
    somma = 0;
    for(cont = 0; cont < riemp; cont = cont + 1)
    {
       somma = somma + (vett1[cont]*vett2[cont]);
    }
    
    printf("Il prodotto scalare tra i due vettori e' %ld.", somma);
}
