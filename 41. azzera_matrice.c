/*Data una matrice (da tastiera) ed un valore di input, il programma azzera tutti i valori della matrice maggiori del valore inserito e stampa la matrice.*/
#include <stdio.h>
#define N 10

/*prototipi*/
void carica(int m[][N], int righe, int colonne);
void azzera(int m[][N], int righe, int colonne, int x);
void stampa(int m[][N], int righe, int colonne);

/*programma*/
int main ()
{
    int matrice[N][N];
    int dim_i, dim_j;
    int c;
    
    printf("Inserisci il numero di righe della matrice: ");
    scanf("%d", &dim_i);
    printf("Inserisci il numero di colonne della matrice: ");
    scanf("%d", &dim_j);
    
    carica(matrice, dim_i, dim_j);
    azzera(matrice, dim_i, dim_j, c);
    stampa(matrice, dim_i, dim_j);
}

/*funzioni*/
void carica(int m[][N], int righe, int colonne)
{
     int i = 0, j = 0;
        
     for(i = 0; i < righe; i++)
     {
         for(j = 0; j < colonne; j++)
         {   
             printf("Inserisci il valore di indice [%d][%d]:\n", i, j);
             scanf("%d", &m[i][j]);
         }
     }    
}

void azzera(int m[][N], int righe, int colonne , int x)
{
     int i, j;
     
     printf("Inserisci un valore: ");
     scanf("%d", &x);
     
     for(i = 0; i < righe; i++)
     {
         for(j = 0; j < colonne; j++)
         {
             if(x < m[i][j])
                m[i][j] = 0;
         }
     }
}

void stampa(int m[][N], int righe, int colonne)
{
     int i, j;
     
     printf("Hai ottenuto la seguente matrice:\n");
     
     for(i = 0; i < righe; i++)
     {
         for(j = 0; j < colonne; j++)
         {
             printf("%d", m[i][j]);
         }
         printf("\n");
     }
} 

