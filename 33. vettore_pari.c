#include <stdio.h>
#define N 10

int main ()
{
    int vett[N];
    int cont;
    int dim_vett;
    
    do
    {
        printf("Quanti elementi vuoi inserire nel vettore? ");
        scanf("%d", &dim_vett);
    }while(dim_vett < 1 || dim_vett > N);
    
    for(cont = 0; cont < dim_vett; cont = cont + 1)
    {
       printf("Inserisci l'elemento di indice %d: ", cont);
       scanf("%d", &vett[cont]);
    }
    
    for(cont = 0; cont < dim_vett; cont = cont + 1)
    {
       if(vett[cont] % 2 == 0)
       printf("%d ", vett[cont]);
    }
    
    for(cont = (dim_vett - 1); cont >= 0; cont = cont - 1)
       printf("%d ", vett[cont]);
}
