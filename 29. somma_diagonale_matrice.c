#include <stdio.h>
#define N 10

int main ()
{
    int mat[N][N];
    int riemp;
    long int somma;
    int i,j;
    
    do
    {
      printf("Inserisci la dimensione della matrice quadrata: ");
      scanf("%d", &riemp);
    }while(riemp < 1 || riemp > N);
    
    for(i = 0; i < riemp; i = i + 1)
    {
       for(j = 0; j < riemp; j = j + 1)
       {   
           printf("Inserisci l'elemento di indice [%d][%d]: ", i, j);
           scanf("%d", &mat[i][j]);
       }
    }

    somma = 0;
    for(i = 0; i < riemp; i = i + 1)
    {
       for(j = 0; j < riemp; j = j + 1)
       {   
          if(i == j)
          somma = somma + mat[i][j];
       }
    }
    
    printf("Il valore della traccia (diagonale principale) della matrice e' %ld", somma);
    
}
