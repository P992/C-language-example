#include <stdio.h> /*Inserisce i dati dalla libreria per la funzione "printf"*/
#include <math.h> /*Inserisce i dati dalla libreria per la funzione radice quadrata "sqrt"*/

int main ()
{
    float a, b, c;
    float delta;
    float x1, x2;
    
    /*Acquisizione da tastiera di a, b e c*/
    printf("Inserisci i valori a, b e c: ");
    scanf("%f%f%f", &a, &b, &c);
    
    /*Calcolo del valore "delta"*/
    delta = b*b - 4*a*c;
    
    /*Se delta e' maggiore di 0, calcolare e stampare a video le due soluzioni x1 e x2*/
    if(delta>0)
    {
               x1 = (- b + sqrt(delta)) / (2 * a);
               x2 = (- b - sqrt(delta)) / (2 * a);
               printf("Due soluzioni reali e distinte:\n");
               printf("x1 = %f\n", x1);
               printf("x2 = %f\n", x2);
    }
    
    /*Se delta e' uguale a 0, ...*/
    if(delta == 0)
    {
             x1 = x2 = (-b/(2*a));
             printf("Due soluzioni reali e coincidenti:\n");
             printf("x1 = x2 = %f", x1);
    }
    
    /*Se delta e' minore di 0, ...*/
    if(delta < 0)
    {
             printf("Nessuna soluzione reale.");
    }
}
