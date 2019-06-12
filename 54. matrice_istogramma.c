#define N 10
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica_matrice(int matr[][N], char nomefile[], int* colonne);
void stampa(int matr[][N], int righe, int colonne);
int media(int matr[][N],int righe,int colonne);
int output(int vet[], int matr[][N], int righe, int colonne, int media);
void istogramma(int vet[], int riemp);

/*Programma*/
int main()
{
    char nomefile[N];
    int dim_r, dim_c, matrice[N][N];
    int m;
    int dim_vett;
    int v[N*N];
    int i;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    dim_r = carica_matrice(matrice, nomefile, &dim_c);
    
    stampa(matrice, dim_r, dim_c);
    
    m = media(matrice, dim_r, dim_c);
    printf("La media della matrice e': %d\n\n", m);
    
    dim_vett = output(v, matrice, dim_r, dim_c, m);
    
    printf("Il vettore con gli elementi minori della media e' il seguente:\n");
    for(i = 0; i < dim_vett; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n\n");
    
    istogramma(v, dim_vett);
    
    system("PAUSE");
    return 0;
}

/*Funzioni*/
int carica_matrice(int matr[][N], char nomef[], int* colonne)
{
    FILE* file;
    int righe, col;
    int i, j;
    
    file = fopen(nomef, "r");
    
    if(file == NULL)
    {
       printf("Errore nel caricamento del file!");
       system("PAUSE");
       return -1;
    }
    
    fscanf(file, "%d %d", &righe, &col);
    
    for(i = 0; i < righe; i++)
        for(j = 0; j < col; j++)
            fscanf(file, "%d", &matr[i][j]);  
    
    fclose(file);
    
    *colonne = col;
    return righe;
}

void stampa(int matr[][N], int righe, int colonne)
{
    int i, j;
    
    for(i = 0; i < righe; i++)
    {
        for(j = 0; j < colonne; j++)
            printf("%d\t", matr[i][j]);
            printf("\n\n");
    }
}

int media(int matr[][N], int righe, int colonne)
{
    int i, j;
    int somma = 0;
    int med;
    
    for(i = 0; i < righe; i++)
       for(j = 0; j < colonne; j++)
       {
           somma = somma + matr[i][j];
       }

    med = somma / (righe * colonne);

    return med;
}

int output(int vet[], int matr[][N], int righe, int colonne, int media)
{
    int i, j, n;
    
    n = 0;
    
    for(i = 0; i < righe; i++)
       for(j = 0; j < colonne; j++)
       {
           if(matr[i][j] < media)
           {
              vet[n] = matr[i][j];     
              n++;                    
           }
       }
    
    return n;  
} 

void istogramma(int vet[],int dim)
{
    int i, j, max;

    max = vet[0];
    
    for(i = 0; i < dim; i++)
       if(vet[i] > max)
          max = vet[i];
    
    printf("\n\n*************************************************************************\n\n");
    printf("L'istogramma dei valori inferiori a quello della media e' il seguente:\n\n");
    
    for(j = max+1; j >= 0; j--)
    {
        for(i = 0; i < dim; i++)
        {
            if(j < vet[i])
               printf("#\t");
            else
               printf(" \t");
        }
        printf("\n");
    }
    for(i = 0; i < dim; i++)
        printf("%d\t",vet[i]);
        printf("\n\n");
} 
