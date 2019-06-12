#include <stdio.h>

int main ()
{
    int num1;
    int num2;
    int somma;
    int scelta;
    int risultato;
    int resto;
    
    printf("/--------------------------------CALCOLATRICE--------------------------------/\nInserisci due numeri: ");
    scanf("%d%d", &num1, &num2);
    
    printf("Quale operazione desideri svolgere?\n1) Addizione\n2) Sottrazione\n3) Prodotto\n4) Divisione\nSeleziona l'operazione: ");
    scanf("%d", &scelta);
    
    while(scelta > 4 || scelta < 1)
    {
         printf("Non puoi scegliere altre operazioni. Inserisci un altro valore: ");
         scanf("%d", &scelta);
    }  
    
    switch(scelta)
    {
          case 1: risultato = num1 + num2;
                  break;
          case 2: risultato = num1 - num2;
                  break;
          case 3: risultato = num1 * num2;
                  break;
          case 4: {
                      if(num2 == 0)
                      {   printf("Divisione non possibile. Digitare un altro valore al posto dello 0: " );
                          scanf("%d", &num2);
                          risultato = num1 / num2;
                      }
                      else  
                      risultato = num1 / num2;
                  }
                  break;
    }                  
    printf("Il risultato dell'operazione e' %d", risultato);
}
