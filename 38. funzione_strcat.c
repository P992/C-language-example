#include <stdio.h>
#define N 10

void unisci(char dest[], char src[]);

int main ()
{
    char v[N];
    char v2[N];
    
    printf("Inserisci una parola: ");
    scanf("%s", v);
    printf("Inserisci un'altra parola: ");
    scanf("%s", v2);
    
    unisci(v, v2);
    
    printf("Hai ottenuto %s.", v);
}

/*Questa funzione concatena due stringhe*/
void unisci(char dest[], char src[])
{
     int i = 0, h = 0;
     
     while(dest[i] != '\0')
          i++;
     while(src[h] != '\0')
     {
           dest[i] = src[h];
           i++;
           h++;
     }
     dest[i] = '\0';
}
