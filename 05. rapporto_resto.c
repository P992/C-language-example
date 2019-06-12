#include <stdio.h>

int main ()
{
    int operatore1;
    int operatore2;
    int rapporto;
    
    operatore1 = 520;
    operatore2 = 3;
    rapporto = operatore1 % operatore2;
    
    printf("Il rapporto tra %d e %d ha resto %d", operatore1, operatore2, rapporto);
    
}
