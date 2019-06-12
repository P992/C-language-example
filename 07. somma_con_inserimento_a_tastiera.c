#include <stdio.h>

int main ()

{
    int x;
    int y;
    int somma;
    
    printf("Inserisci il valore di x: ");
    scanf("%d", &x);
    
    printf("Inserisci il valore di y: ");
    scanf("%d", &y);
    
    somma = x + y;
    printf("La somma dei valori inseriti e' %d", somma);
    
}
