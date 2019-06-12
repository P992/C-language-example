#include <stdio.h>

int main ()
{
    int num, cont;
    int fat;
    
    printf("Inserisci un numero: ");
    scanf("%d", &num);
    
    if(num < 0)
       printf("Non e' possibile calcolare il fattoriale di un numero negativo.");
    else
    {
       fat = 1;
       for(cont = 2; cont <= num; cont = cont + 1)
          fat = fat * cont;
       printf("Il fattoriale di %d e' %d", num, fat);
    }
}
