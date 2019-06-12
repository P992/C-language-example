/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  16 febbraio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da un file di testo una matrice A di numeri reali; 
*       - visualizza a video la matrice caricata A;
*       - riordina gli elementi della matrice A in ordine crescente rispetto  
*         alla scansione per righe; in pratica dopo l'ordinamento i valori della 
*         matrice dovranno soddisfare la seguente condizione:
*         A[0][0]<A[0][1]<...<A[0][N-1]<A[1][0]<...<A[1][N-1]<...<A[M-1][N-1]
*       - visualizza nuovamente a video la matrice A;
*       - calcola la somma di tutti gli elementi delle righe di indice dispari 
*         (RD) e la somma di tutti gli elementi delle righe di indice pari (RP)
*       - crea una nuova matrice B con le stesse dimensioni della matrice A; 
*         gli elementi della matrice B sono ottenuti a partire dagli elementi
*         della matrice A:
*         -sommando RD agli elementi i cui indici di riga e colonna sono pari
*         -sommando RP agli elementi i cui indici di riga e colonna sono dispari
*         -sommando RP-RD agli elementi il cui indice di riga è dispari e 
*          l'indice di colonna è pari
*         -sommando RD-RP agli elementi il cui indice di riga è pari e l'indice 
*          di colonna è dispari
*       - visualizza a video la matrice B;
*
*
*   Ulteriori specifiche:  
*       - il caricamento della matrice deve essere effettuato chiedendo 
*         all'utente di indicare le dimensioni della matrice (numero di righe M 
*         e il numero di colonne N), quindi leggendo da un file, il cui nome è
*         anch'esso fornito dall'utente, M*N valori nel seguente ordine: 
*         A[0][0] A[0][1] ... A[0][N-1] A[1][0] ... A[1][N-1] ... A[M-1][N-1]
*         nel caso in cui il numero di valori presenti nel file sia minore di
*         M*N il programma termina dando una segnalazione di errore all'utente 
*       - la dimensione massima delle matrici gestite è pari a 100
*       - oltre al main si scrivano una funzione per ognuna delle seguenti 
*         operazioni da effettuare:
*          -> caricamento di una matrice da file
*          -> ordinamento crescente della matrice rispetto alla scansione per 
*             righe
*          -> calcolo di RD e RP
*          -> creazione della matrice B a partire dalla matrice A
*          -> visualizzazione a video di una matrice
*
*    Altro:
*       - per maggiore chiarezza è stato allegato al presente compito un file di 
*         input di esempio ("mat.txt")
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 30
#define MAXDIM 100

int carica(char nomefile[], int mat[][MAXDIM], int* col);
void ordina(int mat[][MAXDIM], int r, int c);
int somme(int mat[][MAXDIM], int r, int c, int* disp);
void nuova_matrice(int mat[][MAXDIM], int mat2[][MAXDIM], int r, int c, int pari, int dispari);
void visualizza_matrice(int matrice[][MAXDIM], int r, int c);
void stampa_su_file(char nomefile[], int matrice[][MAXDIM], int r, int c);

int main()
{
    char filename[MAXCAR], filename2[MAXCAR];
    int matrice[MAXDIM][MAXDIM], matrice2[MAXDIM][MAXDIM];
    int righe, colonne;
    int somma_pari, somma_dispari;
    int scelta;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    righe = carica(filename, matrice, &colonne);
    if(righe == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;      
    }
    else if(righe == -1)
    {
         printf("I valori sono insufficienti!\n");
         system("PAUSE");
         return -1;            
    }
    
    printf("Il file contiene la seguente matrice:\n");
    visualizza_matrice(matrice, righe, colonne);
    
    ordina(matrice, righe, colonne);
    printf("\nEcco la matrice ordinata (crescente per righe):\n");
    visualizza_matrice(matrice, righe, colonne);
    
    somma_pari = somme(matrice, righe, colonne, &somma_dispari);
    printf("\nSomma degli elementi di indice pari: %d\nSomma degli elementi di indice dispari: %d\n", somma_pari, somma_dispari);
    
    nuova_matrice(matrice, matrice2, righe, colonne, somma_pari, somma_dispari);
    printf("\nNuova matrice ottenuta\n");
    printf("- sommando RD agli elementi i cui indici di riga e colonna sono pari;\n");
    printf("- sommando RP agli elementi i cui indici di riga e colonna sono dispari;\n");
    printf("- sommando RP-RD agli elementi il cui indice di riga e' dispari e l'indice di colonna e' pari;\n");
    printf("- sommando RD-RP agli elementi il cui indice di riga e' pari e l'indice di colonna e' dispari.\n");
    visualizza_matrice(matrice2, righe, colonne);
    
    printf("\nVuoi salvare la matrice in un file? (SI = 0/NO = 1) ");
    scanf("%d", &scelta);
    if(scelta == 0)
    {
       printf("Inserisci il nome del file di output: ");
       scanf("%s", filename2);
       stampa_su_file(filename2, matrice2, righe, colonne);
    }
    
    system("PAUSE");
    return 0;
}

int carica(char nomefile[], int mat[][MAXDIM], int* col)
{
    FILE* f;
    int r, c;
    int i, j;
    int num = 0;
    
    f = fopen(nomefile, "r");
    if(f == NULL)
       return 0;
    
    printf("Inserisci il numero di righe: ");
    scanf("%d", &r);
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &c);
    
    i = 0;
    while(fscanf(f, "%d", &mat[i][0]) != EOF)
    {
        for(j = 1; j < c; j++)
        {
            fscanf(f, "%d", &mat[i][j]);
            num++;   
        }
        i++;
    }
    
    fclose(f);
    
    *col = c;
    
    if(num < r*c)
       return -1;
    else
       return r;
}

void ordina(int mat[][MAXDIM], int r, int c)
{
     int i, j;
     int ind_min;
     int temp;
     
     for(i = 0; i < r; i++)
     {
         for(j = 0; j < c; j++)
         {
            ind_min = cercamin(mat[i], j, c);
            temp = mat[i][j];
            mat[i][j] = mat[i][ind_min];
            mat[i][ind_min] = temp;
         }
     }
}

int cercamin(int vett[], int inizio, int fine)
{
    int indice = inizio;
    int k;
    
    for(k = inizio+1; k < fine; k++)
    {
        if(vett[k] < vett[indice])
           indice = k;
    }
    
    return indice;
}

int somme(int mat[][MAXDIM], int r, int c, int* disp)
{
    int pari = 0;
    int dispari = 0;
    int i, j;
    
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(i % 2 == 0)
               pari = pari + mat[i][j];
            else
               dispari = dispari + mat[i][j];
        }  
    }
    
    *disp = dispari;
    return pari;
}

void nuova_matrice(int mat[][MAXDIM], int mat2[][MAXDIM], int r, int c, int pari, int dispari)
{
     int i, j;
     
     for(i = 0; i < r; i++)
     {
         for(j = 0; j < c; j++)
         {
             if(i % 2 == 0 && j % 2 == 0)
                mat2[i][j] = mat[i][j] + dispari;
             else if(i % 2 != 0 && j % 2 != 0)
                mat2[i][j] = mat[i][j] + pari;
             else if(i % 2 == 0 && j % 2 != 0)
                mat2[i][j] = mat[i][j] + (dispari - pari);
             else if(i % 2 != 0 && j % 2 == 0)
                mat2[i][j] = mat[i][j] + (pari - dispari);             
         }  
     }
}

void visualizza_matrice(int matrice[][MAXDIM], int r, int c)
{
     int i, j;
     
     for(i = 0; i < r; i++)
     {
         for(j = 0; j < c; j++)
         {
             printf("%5d\t", matrice[i][j]);
         }  
         printf("\n");
     } 
}

void stampa_su_file(char nomefile[], int matrice[][MAXDIM], int r, int c)
{
     FILE* f;
     int i, j;
     
     f = fopen(nomefile, "w");
     
     for(i = 0; i < r; i++)
     {
         for(j = 0; j < c; j++)
         {
             fprintf(f, "%5d\t", matrice[i][j]);
         }  
         fprintf(f, "\n");
     } 
     
     fclose(f);
}
