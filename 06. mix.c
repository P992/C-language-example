#include <stdio.h>

int main ()
{
    int operatore1;
    int operatore2;
    int somma;
    int operatore3;
    int operatore4;
    int differenza;
    int operatore5;
    int operatore6;
    int prodotto;
    int operatore7;
    int operatore8;
    int rapporto;
    
    operatore1 = 57;
    operatore2 = 106;
    operatore3 = 238;
    operatore4 = 554;
    operatore5 = 212;
    operatore6 = 2;
    operatore7 = 69;
    operatore8 = 5;
    
    somma = operatore1 + operatore2;
    differenza = operatore3 - operatore4;
    prodotto = operatore5 * operatore6;
    rapporto = operatore7 % operatore8;
    
        
    printf("La somma di %d e %d e' %d, la differenza tra %d e %d e' %d e il prodotto tra %d e %d e' %d. Ah! Il rapporto tra %d e %d ha resto pari a %d", operatore1, operatore2, somma, operatore3, operatore4, differenza, operatore5, operatore6, prodotto, operatore7, operatore8, rapporto);
    
}
