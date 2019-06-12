#include <stdio.h>

int main ()
{
         int a, b, min, max, r;
         
         r = 1;
         
         printf("Inserisci il primo valore: ");
         scanf("%d", &a);
         
         printf("Inserisci il secondo valore: ");
         scanf("%d", &b);
         
         if (a < b)
         {
               min = a;
               max = b;
         }
         else
         {
               min = b;
               max = a;
         }
         
         if (min == 0)
           printf("Il M.C.D. e' %d", max);
         else
         {   while(r > 0)
             {    r = max%min;
                  max = min;
                  min = r;
             }
         printf("Il M.C.D. e' %d", max);
         }
}
