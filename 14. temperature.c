#include <stdio.h>

int main ()
{
    float C;
    float K;
    float F;
    
    printf("Inserisci il valore di una temperatura espressa in gradi Celsius: ");
    scanf("%f", &C); 
       
    K = C + 273.16;
    F = (9 / 5) * C + 32;
        
    if(C < - 273.16)
       printf("Non e' possibile scendere al di sotto dello zero assoluto!");
    else
       printf("Valore in gradi Kelvin: %f\nValore in gradi Fahrenheit: %f", K, F);

}
