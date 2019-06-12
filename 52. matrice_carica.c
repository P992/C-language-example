#define N 10

/*Prototipi*/
int carica_matrice(int matrice[][N], int* righe);
void moltiplica(int matrice[][N], int righe, int colonne);
void stampa(int matrice[][N], int righe, int colonne);

/*Programma*/
int main()
{
    int matr[N][N];
    int dim_r, dim_c;
    
    dim_c = carica_matrice(matr, &dim_r);
    moltiplica(matr, dim_r, dim_c);
    stampa(matr, dim_r, dim_c);
    
    system("PAUSE");
}

/*Funzioni*/
int carica_matrice(int matrice[][N], int* righe)
{
    int colonne, r, i, j;
    
    printf("Inserisci il numero di righe della matrice: ");
    scanf("%d", &r);
    printf("Inserisci il numero di colonne della matrice: ");
    scanf("%d", &colonne);
    
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < colonne; j++)
        {
            printf("Inserisci l'elemento di indice [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    
    *righe = r;
    return colonne;
}

void moltiplica(int matrice[][N], int righe, int colonne)
{
     int i, j;
     
     for(i = 0; i < righe; i++)
     {
        for(j = 0; j < colonne; j++)
        {
            if(i == j)
              matrice[i][j] = matrice[i][j]*2;
        }
     }
}

void stampa(int matrice[][N], int righe, int colonne)
{
     int i, j;
     
     for(i = 0; i < righe; i++)
     {
         for(j = 0; j < colonne; j++)
            printf("%d ", matrice[i][j]);
            
         printf("\n");
     }
}
