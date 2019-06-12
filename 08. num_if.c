#include <stdio.h>

int main ()
{
    int num;
    
    /*Acquisizione del valore num da tastiera*/
    printf("Inserisci un valore: ");
    scanf("%d", &num);
    
    /*Se il valore e' maggiore di 100, scrivilo*/
    if(num > 100)
       printf("Il valore inserito e' %d", num);

}
