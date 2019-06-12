/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  16 febbraio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da un file di testo una matrice A di numeri interi, secondo
*         una scansione a spirale in senso orario partendo dall'elemento A[0][0]
*         la matrice A deve essere una matrice quadrata di dimensione N; il 
*         valore di N deve essere fornito dall'utente da tastiera;
*       - visualizza a video la matrice caricata A;
*       - ordina in maniera decrescente ogni riga della matrice;
*       - visualizza a video la matrice A ordinata per righe;
*       - effettuando una scansione della matrice per colonne conta quante 
*         coppie di elementi adiacenti soddisfano il seguente criterio di 
*         ordinamento: A[i][j]<A[i][j+1]
*         la scansione per colonne è effettuata visitando gli elementi della 
*         matrice nel seguente ordine:
*         A[0][0]-A[1][0]-...-A[N-1][0]-A[0][1]-...-A[N-1][1]<...<A[N-1][N-1]
*         nella scansione della matrice la generica coppia A[N-1][i] - A[0][i+1]
*         non è da considerarsi come una coppia di valori adiacenti
*       - visualizza a video il valore calcolato
*       - somma a tutti gli elementi della diagonale secondaria della matrice A
*         il valore visualizzato al passo precedente
*       - visualizza a video la matrice A;
*
*
*   Ulteriori specifiche:  
*       - il caricamento della matrice deve essere effettuato chiedendo 
*         all'utente di indicare le dimensioni della matrice (numero di righe N 
*         e il numero di colonne N), quindi leggendo da un file, il cui nome è
*         anch'esso fornito dall'utente, N*N valori nel seguente ordine: 
*         A[0][0] A[0][1] ... A[0][N-1] A[1][N-1] ... A[N-1][N-1] A[N-1][N-2]...
*         secondo una scansione a spirale in senso orario;
*         nel caso in cui il numero di valori presenti nel file sia minore di
*         N*N il programma termina dando una segnalazione di errore all'utente 
*       - la dimensione massima delle matrici gestite è pari a 100
*       - oltre al main si scrivano una funzione per ognuna delle seguenti 
*         operazioni da effettuare:
*          -> caricamento di una matrice da file
*          -> ordinamento decrescente delle righe di una matrice 
*          -> calcolo del numero di coppie che soddisfano il criterio di 
*             ordinamento secondo una scansione per colonne
*          -> somma di un valore agli elementi della diagonale secondaria di una 
*             matrice
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

int carica(char filename[], int mat[][MAXDIM], int dim);
void ordina(int mat[][MAXDIM], int dim);
int adiacenti(int mat[][MAXDIM], int dim);
void somma(int mat[][MAXDIM], int dim, int num);
void visualizza(int mat[][MAXDIM], int dim);

int main()
{
    char nomefile[MAXCAR];
    int matrice[MAXDIM][MAXDIM];
    int dimensione;
    int car, coppie;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    printf("Inserisci la dimensione della matrice quadrata: ");
    scanf("%d", &dimensione);
    
    car = carica(nomefile, matrice, dimensione);
    if(car == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;    
    }
    
    printf("\nIl file contiene la seguente matrice:\n");
    visualizza(matrice, dimensione);
    
    ordina(matrice, dimensione);
    printf("\nMatrice ordinata per righe in maniera decrescente:\n");
    visualizza(matrice, dimensione);
    
    coppie = adiacenti(matrice, dimensione);
    printf("\nGli elementi che soddisfano il criterio di ordinamento sono %d.\n", coppie);
    
    somma(matrice, dimensione, coppie);
    printf("\nMatrice rielaborata:\n");
    visualizza(matrice, dimensione);
        
    system("PAUSE");
    return 0;
}

int carica(char filename[], int mat[][MAXDIM], int dim)
{
     FILE* f;
     int righe = 0;
     int colonne = 0;
     int i, j;  
        
     f = fopen(filename, "r");
     if(f == NULL)
        return -1;
        
     while(dim > 0)
     {
     for(i = righe, j = colonne; j < dim; j++)
         fscanf(f, "%d", &mat[i][j]);
     for(i = righe+1, j = dim-1; i < dim; i++)
         fscanf(f, "%d", &mat[i][j]);
     for(i = dim-1, j = dim-2; j >= colonne; j--)
         fscanf(f, "%d", &mat[i][j]);
     for(i = dim-2, j = colonne; i > righe; i--)
         fscanf(f, "%d", &mat[i][j]);
         
     righe++;
     colonne++;
     dim--;
     }   
     
     return 0;
}

void ordina(int mat[][MAXDIM], int dim)
{
     int i, j;
     int temp;
     int ind_max;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < dim; j++)
         {
             ind_max = cercamax(mat[i], j, dim);
             temp = mat[i][ind_max];
             mat[i][ind_max] = mat[i][j];
             mat[i][j] = temp;
         }
     }
}

int cercamax(int vett[], int inizio, int fine)
{
    int k;
    int indice_max = inizio;
    
    for(k = inizio+1; k < fine; k++)
        if(vett[k] > vett[indice_max])
           indice_max = k;
           
    return indice_max;
}

int adiacenti(int mat[][MAXDIM], int dim)
{
    int i, j;
    int num = 0;
    
    for(j = 0; j < dim; j++)
    {
        for(i = 0; i < dim; i++)
        {
            if(mat[i][j] < mat[i+1][j])
               num++;
        }
    }
    
    return num;
}

void somma(int mat[][MAXDIM], int dim, int num)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < dim; j++)
             if(j == dim-1-i)
                mat[i][j] = mat[i][j] + num;
     }
}

void visualizza(int mat[][MAXDIM], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {   
         for(j = 0; j < dim; j++)
         {
             printf("%2d\t", mat[i][j]); 
         }
         printf("\n");
     }
}
