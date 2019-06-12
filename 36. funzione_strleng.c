#include <stdio.h>
#define N 10

int strleng(char s[]);

int main ()
{
    char vett[N];

    printf("Inserisci una parola: ");
    scanf("%s", vett);

    printf("Questa parola contiene %d caratteri.", strleng(vett));
}
    
    
/*Quella che segue é la funzione che conta i caratteri contenuti in un vettore*/
int strleng(char s[])/*prototipo: la funzione si aspetta un vettore char e restituisce un intero*/
{
    int c = 0;
    
    while(s[c] != '\0'/*tappo*/)
         c++;
    
    return c;
}
