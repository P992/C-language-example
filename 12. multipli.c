#include <stdio.h>

int main ()
{
    int x;
    int y;
    
    printf("Inserisci due numeri: ");
    scanf("%d%d", &x, &y);
    
    if(y == 0)
    printf("Non e' possibile dividere per 0.");

    if(x % y == 0)
      printf("Il numero %d e' multiplo di %d", x, y);
    else
      printf("Il numero %d non e' multiplo di %d", x, y);
      
}
