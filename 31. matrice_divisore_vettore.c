#include <stdio.h>
#define N 10

int main ()
{
    int mat[N][N];
    int vet[N*N];
    int dim_r;
    int dim_c;
    int i,j,v;
    int num;
    
    do
    {
        printf("Inserisci il numero di righe della matrice: ");
        scanf("%d", &dim_r);
        printf("Inserisci il numero di colonne della matrice: ");
        scanf("%d", &dim_c);
    }while(dim_r < 1 || dim_r < 1 || dim_c > N || dim_r > N);
    
    for(i = 0; i < dim_r; i = i + 1)
    {
       for(j = 0; j < dim_c; j = j + 1)
       {   
           printf("Inserisci l'elemento di indice [%d][%d]: ", i, j);
           scanf("%d", &mat[i][j]);
       }
    }
    
    printf("Inserire un numero: ");
    scanf("%d", &num);
    
    for(i = 0; i < dim_r; i = i + 1)
    {  
        for(j = 0; j < dim_c; j = j + 1)
        if(mat[i][j] % num == 0)
        {  
           vet[v] = mat[i][j];
           printf("%d ", vet[v]);
        }
    }
}
