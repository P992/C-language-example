#include <string.h>
#include <stdio.h>
#define N 100

int compare(char v[], char v1[]);

int main ()
{
    char vett[N];
    char vett2[N];
    
    printf("Inserisci una parola: ");
    scanf("%s", vett);
    printf("Inserisci un'altra parola: ");
    scanf("%s", vett2);
      
    switch(compare(vett, vett2))
    {
           case 1: printf("Prima parola > Seconda Parola");
                   break;
           case -1: printf("Prima parola < Seconda Parola");
                   break;
    }
}

int compare(char v[], char v1[])
{
    int a, b, i;
    a = strlen(v);
    b = strlen(v1);
    
    if(a>b)
       return 1;
    if(a<b)
       return -1;
    if(a==b)
    {
       i = 0;
       while(v[i] == v1[i] && i < a)
            {
            i++;
            }
            return v[i]-v1[i];        
    }
}
