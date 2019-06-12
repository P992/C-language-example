#define N 10

/*Prototipi*/
int carica_elenco(char elenco [][N]);
void conversione(char elenco[][N], int dim);
void stampa(char elenco[][N], int dim);

/*Programma*/
int main()
{
    char parole[N][N];
    int dimensione;
    
    dimensione = carica_elenco(parole);
    conversione(parole, dimensione);
    stampa(parole, dimensione);
    
    system("PAUSE");
}

/*Funzioni*/
int carica_elenco(char elenco[][N])
{
    int dim, i;
    
    printf("Quante parole vuoi inserire? ");
    scanf("%d", &dim);
    
    for(i = 0; i < dim; i++)
       scanf("%s", elenco[i]);
       
    return dim;
}

void conversione(char elenco[][N], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
         j = 0;
         
         while(elenco[i][j] != '\0')
         {
               elenco[i][j] = elenco[i][j] - 'a' + 'A';
               j++;
         }
     }
}

void stampa(char elenco[][N], int dim)
{
     int i;
     
     printf("Elenco in maiuscolo:\n");
     
     for(i = 0; i < dim; i++)
        printf("%s\n", elenco[i]);
}
