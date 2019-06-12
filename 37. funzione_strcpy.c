#include <stdio.h>
#define N 10

void strcpy(char dest [], char src[]);

int main ()
{
    char vett[N];
    char vett2[N];
    
    printf("Inserisci una parola: ");
    scanf("%s", vett);
    
    strcpy(vett2, vett);
    
    printf("La parola inserita e': %s.", vett2);
    
}

/*Questa funzione copia una stringa*/
void strcpy(char dest [], char src[])    /*void sta ad indicare che la funzione non restituisce alcun valore*/
{
     int i = 0;
     while (src[i] != '\0')
     {
           dest[i] = src[i];
           i++;
     }
     dest[i] = '\0';
}
