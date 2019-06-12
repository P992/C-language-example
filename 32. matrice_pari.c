#include <stdio.h>
#define N 10

int main ()
{
    int matr[N][N];
    int vett[N*N];
    int dim_r,dim_c;
    int i,j,v;
    
    do
    {
        printf("Inserisci il numero di righe della matrice: ");
        scanf("%d", &dim_r);
        printf("Inserisci il numero di colonne della matrice: ");
        scanf("%d", &dim_c);
    }while(dim_r < 1 || dim_c < 1 || dim_r > N || dim_c > N);
    
    for(i = 0; i < dim_r; i = i + 1)
    {  
        for(j = 0; j < dim_c; j = j + 1)
        {
           printf("Inserisci l'elemento di indice [%d][%d]: ", i, j);
           scanf("%d", &matr[i][j]);
        }
    }
    
    for(i = 0; i < dim_r; i = i + 1)
    {  
       for(j = 0; j < dim_c; j = j + 1)
        {
           if(matr[i][j] % 2 == 0)
           {
              vett[v] = matr[i][j];
              printf("%d ", vett[v]);
           }
        }
    }
}
