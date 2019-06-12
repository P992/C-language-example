#include <stdio.h>

int main ()
{
    int num, primo, i, j;
    
    printf("Inserisci un numero: ");
    scanf("%d", &num);
    
    if(num == 1)
      printf("I numeri primi minori o uguali a %d sono: 1", num);
    else if(num > 1)
    {
         printf("I numeri primi minori o uguali a %d sono: 1 2 ", num);
         for(i = 3; i <= num; i = i + 2)
         {
               j = 3;
               primo = 1;
               while(j <= (i / 2) && primo == 1)
               {    if(i % j == 0)
                       primo = 0;
                    j = j + 2;
               }
               if(primo == 1)
                  printf("%d ", i);
         }
    }
}
