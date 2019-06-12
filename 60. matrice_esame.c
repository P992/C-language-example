#define N 10
#include<stdio.h>
#include<stdlib.h>

/*Prototipi*/
int carica(int matr[][N], int matr2[][N], int* r1, int* r2, int* c1, char filename[]);
int elimina_min(int matr[][N], int righe, int colonne);
int cercamin(int matr[][N], int inizio, int fine, int riga);
void matrice_trasposta(int matr[][N], int matr2[][N], int righe, int colonne);
int elementi_uguali(int matr[][N], int matr2[][N], int righe, int colonne);
void stampa(int matr[][N], int righe, int colonne);

/*Programma*/
int main()
{
    int ri1, ri2, col1, col2;
    int matrice[N][N], matrice2[N][N], trasposta[N][N], trasposta2[N][N];
    char nomefile[N];
    int el_uguali;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    col2 = carica(matrice, matrice2, &ri1, &ri2, &col1, nomefile);
    
    if(col2 == -1)
       printf("Errore nel caricamento del file!\n");
    
    col1 = elimina_min(matrice, ri1, col1);
    col2 = elimina_min(matrice2, ri2, col2);
    
    printf("\nPrima matrice:\n");
    stampa(matrice, ri1, col1);
    printf("\nSeconda matrice:\n");    
    stampa(matrice2, ri2, col2);
    
    matrice_trasposta(matrice2, trasposta2, ri2, col2);
    el_uguali = elementi_uguali(matrice, trasposta2, ri1, col1);
    
    printf("Il numero di elementi uguali che occupano la stessa posizione nella matrice A e nella seconda matrice trasposta e' %d.\n", el_uguali);
    
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

int elimina_min(int matr[][N], int righe, int colonne)
{
     int i, j;
     int ind_min;
     int temp;
     
     for(i = 0; i < righe; i++)
     {
	    ind_min = cercamin(matr, 0, colonne, i);
            for(j = ind_min+1; j < colonne; j++)
            {
                temp = matr[i][j-1];
                matr[i][j-1] = matr[i][j];
                matr[i][j] = temp;
            }             
     }
     
     return (colonne-1);
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

void matrice_trasposta(int matr[][N], int matr2[][N], int righe, int colonne)
{
     int i, j;

     for(i = 0; i < righe; i++)
     {
         for(j = 0; j < colonne; j++)
         {
               matr2[j][i] = matr[i][j];
         }
     }
}

int elementi_uguali(int matr[][N], int matr2[][N], int righe, int colonne)
{
    int i, j, n;
    
    n = 0;
    
    for(i = 0; i < righe; i++)
    {
       for(j = 0; j < colonne; j++)
       {
           if(matr[i][j] == matr2[i][j])
           n++;
       }
    }
    
    return n;
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
