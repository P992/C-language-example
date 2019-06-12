/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  23 gennaio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da due file di testo due matrici di numeri reali; 
*       - visualizza a video le matrici caricate;
*       - individua la dimensione L della più grande matrice quadrata che possa 
*         essere inclusa in entrambe le matrici caricate;
*       - visualizza a video il valore di L appena calcolato;
*       - traspone le matrici M1 ed M2; M1 e M2 sono le due matrici quadrate di 
*         dimensione L ottenute considerando le prime L righe ed L colonne delle 
*         due matrici caricate da file;
*       - calcola il prodotto matriciale tra M1 e M2, ottenendo in tal modo la 
*         matrice M3=M1*M2
*       - visualizza a video la matrice M3
*       - traspone la matrice M3
*       - visualizza a video la matrice M3 dopo la trasposizione
*       - salva in un file la matrice M3 rispettando la sintassi del file 
*         riportata in basso nelle ulteriori specifiche
*
*   Ulteriori specifiche:  
*       - i file contententi le matrici contengono 2+M*N valori; i primi due
*         valori sono interi e rappresentano rispettivamente il numero di righe
*         M ed il numero di colonne N della matrice; successivamente vi sono M*N
*         numeri reali che corrispondono ai valori della matrice; la sequenza di
*         valori è riportata nel file nel seguente ordine: 
*         A[0][0] A[0][1] ... A[0][N-1] A[1][0] ... A[1][N-1] ... A[M-1][N-1]
*       - la dimensione massima delle matrici gestite è pari a 100
*       - oltre al main si scrivano funzioni per effettuare le operazioni di:
*          -> caricamento di una matrice da file
*          -> trasposta di una matrice
*          -> prodotto matriciale
*          -> visualizzazione a video di una matrice
*          -> salvataggio matrice su file
*
*    Altro:
*       - per maggiore chiarezza sono stati allegati al presente compito due 
*         file di input di esempio ("mat1.txt" e "mat2.txt")
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 20
#define MAXDIM 100

int carica_matrice(char nomefile[], double m[][MAXDIM], int *r, int *c);
void trasp(double m[][MAXDIM], double trasp[][MAXDIM], int dim);
void prodotto(double m[][MAXDIM], double m2[][MAXDIM], double m3[][MAXDIM], int dim);
void visualizza_matrice(double m[][MAXDIM], int r, int c);

int main()
{
    double matrice[MAXDIM][MAXDIM], matrice2[MAXDIM][MAXDIM], trasposta[MAXDIM][MAXDIM], trasposta2[MAXDIM][MAXDIM], matrice_prodotto[MAXDIM][MAXDIM], prodotto_trasp[MAXDIM][MAXDIM];
    char filename[MAXCAR], filename2[MAXCAR];
    int righe1, colonne1, righe2, colonne2, dimensione;
    int carica;
    int max1, max2, L;
    
    printf("Inserisci il nome del primo file da aprire: ");
    scanf("%s", filename);
    carica = carica_matrice(filename, matrice, &righe1, &colonne1);
    if(carica == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    printf("\nIl primo file contiene la seguente matrice:\n");
    visualizza_matrice(matrice, righe1, colonne1);
    
    printf("\n\nInserisci il nome del secondo file: ");
    scanf("%s", filename2);
    carica = carica_matrice(filename2, matrice2, &righe2, &colonne2);
    if(carica == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    printf("\nIl secondo file contiene la seguente matrice:\n");
    visualizza_matrice(matrice2, righe2, colonne2);
    
    if(righe1 < colonne1)
       max1 = colonne1;
    else
       max1 = righe1;
       
    if(righe2 < colonne2)
       max2 = colonne2;
    else
       max2 = righe2;
       
    if(max1 < max2)
       L = max1-1;
    else
       L = max2-1;
       
    printf("\nLa dimensione della piu' grande matrice quadrata che puo' essere inclusa nelle due matrici caricate e' %d.\n", L);
    
    trasp(matrice, trasposta, L);
    printf("\nPrima matrice trasposta:\n");
    visualizza_matrice(trasposta, L, L);
    
    trasp(matrice2, trasposta2, L);
    printf("\n\nSeconda matrice trasposta:\n");
    visualizza_matrice(trasposta2, L, L);
    
    prodotto(trasposta, trasposta2, matrice_prodotto, L);
    printf("\nProdotto matriciale:\n");
    visualizza_matrice(matrice_prodotto, L, L);
    trasp(matrice_prodotto, prodotto_trasp, L);
    printf("\nTrasposta del prodotto:\n");
    visualizza_matrice(prodotto_trasp, L, L);
    
    system("PAUSE");
    return 0;
}

int carica_matrice(char nomefile[], double m[][MAXDIM], int *r, int *c)
{
     int i, j;
     
     FILE* f;
     int riga, colonna;
     
     f = fopen(nomefile, "r");
     if(f == NULL)
        return -1;
        
     fscanf(f, "%d%d", &riga, &colonna);
     
     for(i = 0; i < riga; i++)
     {
         for(j = 0; j < colonna; j++)
             fscanf(f, "%lf", &m[i][j]);
     }
     
     fclose(f);
     
     *r = riga;
     *c = colonna;
     
     return 0;
}

void trasp(double m[][MAXDIM], double trasp[][MAXDIM], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < dim; j++)
             trasp[j][i] = m[i][j]; 
     }
}

void prodotto(double m[][MAXDIM], double m2[][MAXDIM], double m3[][MAXDIM], int dim)
{
     int i, j, k;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < dim; j++)
         {
             for(k = 0; k < dim; k++)
                 m3[i][j] = m3[i][j] + m[i][k]*m2[k][j];
         }  
     }
}

void visualizza_matrice(double m[][MAXDIM], int r, int c)
{
     int i, j;
     
     for(i = 0; i < r; i++)
     {
         for(j = 0; j < c; j++)
         {
             printf("%6.2lf\t", m[i][j]);  
         }  
         printf("\n");
     }
}
