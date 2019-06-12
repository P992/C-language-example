#include <stdio.h>

int max(int a, int b);

int main ()
{
    int a, b;
    
    printf("Inserisci due valori: ");
    scanf("%d%d", &a, &b);
    
    printf("Il valore massimo e' %d", max(a,b));
}

int max(int a, int b)
{
    if(a>b)
    return a;
    else
    return b;
}

