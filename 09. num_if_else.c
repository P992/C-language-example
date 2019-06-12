#include <stdio.h>

int main ()
{
    int num;
    
    /*Acquisizione del valore dalla tastiera*/
    printf("Inserisci un valore: "),
    scanf("%d", &num);
    
    /*Se il numero e' compreso tra 30 e 50 (inclusi), scrivilo. In caso contrario, fai apparire il messaggio "Non e' possibile visualizzare questo valore".*/
    if(num>=30 && num<=50)
       printf("Il valore inserito e' %d", num);
    else
       printf("Non e' possibile visualizzare questo valore.");
       
}
