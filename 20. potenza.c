#include <stdio.h>

int main ()
{
    int x, y;
    long potenza;
    int cont;
    
    printf("Inserisci la base: ");
    scanf("%d", &x);
    printf("Inserisci l'esponente: ");
    scanf("%d", &y);
    
    potenza = 1;
    
    for(cont = 1; cont <= y; cont = cont + 1)
    potenza = potenza * x;

    printf("x elevato ad y e' uguale a %ld", potenza);
    
}
