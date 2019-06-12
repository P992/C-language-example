#define N 10
#include<stdio.h>
#include<stdlib.h>

/*Prototipi*/
int carica(int matr[][N], int matr2[][N], int* r1, int* r2, int* c1, char filename[]);
void elimina_min(int matr[][N], int righe, int colonne);
int cercamin(int matr[][N], int inizio, int fine, int riga);
void stampa(int matr[][N], int righe, int colonne);

/*Programma*/
int main()
{
    int ri1, ri2, col1, col2;
    int matrice[N][N], matrice2[N][N];
    char nomefile[N];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    col2 = carica(matrice, matrice2, &ri1, &ri2, &col1, nomefile);
    
    if(col2 == -1)
       printf("Errore nel caricamento del file!\n");
    
    elimina_min(matrice, ri1, col1);
    elimina_min(matrice2, ri2, col2);
    
    printf("\nPrima matrice ordinata:\n");
    stampa(matrice, ri1, col1);
    printf("\nSeconda matrice ordinata:\n");    
    stampa(matrice2, ri2, col2);
    
    system("PAUSE");
}
/*Funzioni*/
int carica(int matr[][N], int matr2[][N], int* r1, int* r2, int* c1, char filename[])
{
    FILE* f;
    int righe1, colonne1, righe2, colonne2, i, j;
    
    f = fopen(filename, "r");
    
    if(f == NULL)
       return -1;
       
    fscanf(f, "%d%d", &righe1, &colonne1);
    
    for(i = 0; i < righe1; i++)
    {
        for(j = 0; j < colonne1; j++)
           fscanf(f, "%d", &matr[i][j]);
    }    
    
    fscanf(f, "%d%d", &righe2, &colonne2);
    
    for(i = 0; i < righe2; i++)
    {
        for(j = 0; j < colonne2; j++)
           fscanf(f, "%d", &matr2[i][j]);
    }    
    
    fclose(f);
    
    *r1 = righe1;
    *c1 = colonne1;
    *r2 = righe2;
    return colonne2;
}

void elimina_min(int matr[][N], int righe, int colonne)
{
     int i, j;
     int temp, ind_min;
     
     for(i = 0; i < righe; i++)
     {
            for(j = 0; j < colonne; j++)
            {
                ind_min = cercamin(matr, j, colonne, i);
                temp = matr[i][j];
                matr[i][j] = matr[i][ind_min];
                matr[i][ind_min] = temp;
            }             
     }
}    

int cercamin(int matr[][N], int inizio, int fine, int riga)
{
    int k;
    int indice_min = inizio;
    
    for(k = inizio + 1; k < fine; k++)
    {
        if(matr[riga][k] < matr[riga][indice_min])
           indice_min = k;
    }
    
    return indice_min;
}

void stampa(int matr[][N], int righe, int colonne)
{
    int i, j;
    
    for(i = 0; i < righe; i++)
    {
        for(j = 0; j < colonne; j++)
           printf("%d\t", matr[i][j]);
           printf("\n");
    }    
}
