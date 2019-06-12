#include <stdio.h>

int main ()
{
    printf("***QUESTO PROGRAMMA INCREMENTA IL VALORE INSERITO DI UN NUMERO***\n\n");
    
    int c;
    
    printf("Inserisci un valore: ");
    scanf("%d", &c);
    
    printf("... %d", incr(c)); 
}
         
int incr(int x)
{
    return x + 1;
}
