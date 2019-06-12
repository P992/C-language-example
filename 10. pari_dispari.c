#include <stdio.h>

int main ()
{
    int num;
    
    /*Acquisizione del valore dalla tastiera*/
    printf("Inserisci un valore: ");
    scanf("%d", &num);
    
    /*Se il numero e' pari stampa "Il valore inserito e' pari". Se e' dispari stampa "Il valore inserito e' dispari".*/
    if(num%2 == 0)
       printf("Il valore inserito e' pari.");
    else
       printf("Il valore inserito e' dispari.");
       
}
