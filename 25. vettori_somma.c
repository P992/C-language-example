#include <stdio.h>

int main ()
{
    int vett[10];
    int dim_logica;
    int c;
    int somma;
    
    printf("Quanti elementi vuoi inserire? ");
    scanf("%d", &dim_logica);
    
    for(c = 0; c < dim_logica; c = c + 1)
       {
            printf("Inserisci l'elemento di indice %d: ", c);
            scanf("%d", &vett[c]);
       }
    
    somma = 0;
    for(c = 0; c < dim_logica; c = c + 1)
       somma = somma + vett[c];
       
    printf("La somma dei valori inseriti e' uguale a %d.", somma);            
}
