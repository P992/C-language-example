#include <stdio.h>

int main ()
{
    int x;
    int y;
    
    printf("Inserisci un numero: ");
    scanf("%d", &x);
        
    y = - x;
      
    if(x >= 0)
       printf("Il valore assoluto del numero inserito e' %d", x);
    if(x < 0)
       printf("Il valore assoluto del numero inserito e' %d", y);
       
}
