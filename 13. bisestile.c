#include <stdio.h>

int main ()
{
    int anno;
    
    printf("Inserisci un anno: ");
    scanf("%d", &anno);
    
    if(anno <= 2010)
    if(anno % 4 == 0 && anno % 100 != 0 || anno % 400 == 0)
       printf("L'anno %d e' bisestile.", anno);
    else
       printf("L'anno %d non e' bisestile.", anno);
    
    if(anno > 2010)
       if(anno % 4 == 0 && anno % 100 != 0 || anno % 400 == 0)
          printf("L'anno %d sara' bisestile.", anno);
       else
          printf("L'anno %d non sara' bisestile.", anno);
}
