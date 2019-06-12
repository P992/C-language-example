#define N 20
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica(char elenco[][N], char filename[]);
int intervallo(char elenco[][N], char elenco2[][N], int dim);
void ordina(char elenco[][N], int dim);

/*Programma*/
int main()
{
    int num_parole, num2_parole;
    char lista[N][N], lista2[N][N];
    char nomefile[N];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    num_parole = carica(lista, nomefile);
    
    if(num_parole == -1)
       printf("Errore nel caricamento del file!\n");
    
    num2_parole = intervallo(lista, lista2, num_parole);
    ordina(lista2, num2_parole);
    
    system("PAUSE");
}

/*Funzioni*/
int carica(char elenco[][N], char filename[])
{
    FILE* f;
    int i, n, dim;
    
    f = fopen(filename, "r");
    
    if(f == NULL)
       return -1;
    
    n = 0;
    
    while(fscanf(f, "%s", elenco[i]) != EOF)
    {
          i++;
          n++;
    }
          
    printf("Il file contiene il seguente elenco:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", elenco[i]);
        printf("\n");
    return n;
}

int intervallo(char elenco[][N], char elenco2[][N], int dim)
{
    char estremo1, estremo2;
    int n2, i, k;
    
    fflush(stdin);
    printf("Inserisci il primo estremo per il nuovo intervallo (solo minuscole): ");
    scanf("%c", &estremo1);
    
    fflush(stdin);
    
    printf("Inserisci il secondo estremo per il nuovo intervallo (solo minuscole): ");
    scanf("%c", &estremo2);
    printf("\n");
    n2 = 0;
    k = 0;
    
    for(i = 0; i < dim; i++)
    {
        if(elenco[i][0] >= estremo1 && elenco[i][0] <= estremo2)
        {
           strcpy(elenco2[k], elenco[i]);
           n2++;
           k++;
        }
    }
    
    printf("Le parole contenute nell'intervallo scelto sono %d:\n", n2);
    for(i = 0; i < n2; i++)
        printf("%s\n", elenco2[i]);
        printf("\n");
    return n2;
}

void ordina(char elenco[][N], int dim)
{
     int i, j;
     char temp[N];
     
     for(i = 0; i < dim; i++)
     {
         for(j = dim-1; j > i; j--)
         {
             if(strcmp(elenco[j], elenco[j-1]) < 0)
             {
               strcpy(temp, elenco[j]);
               strcpy(elenco[j], elenco[j-1]);
               strcpy(elenco[j-1], temp);  
             }
         }
     }
     
    printf("Elenco ordinato lessicograficamente:\n");
    for(i = 0; i < dim; i++)
        printf("%s\n", elenco[i]);
}
