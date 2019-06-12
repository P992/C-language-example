#define N 10
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica(char elenco[][N]);
int palindrome(char elenco[][N], char elenco2[][N], int dim);
void vocali(char elenco[][N], int dim_pal);
void stampa(char elenco[][N], int dim);

/*Programma*/
int main()
{
    int dimensione, numero_pal;
    FILE* file;
    char lista [N][N], lista2[N][N];
    
    dimensione = carica(lista);
    numero_pal = palindrome(lista, lista2, dimensione);
    vocali(lista2, numero_pal);
    stampa(lista2, numero_pal);

    system("PAUSE");
}

/*Funzioni*/
int carica(char elenco[][N])
{
     FILE* f;
     int dim, i;
     char nomefile[N];
     
     printf("Inserire il nome del file da aprire: ");
     scanf("%s", nomefile);
     
     f = fopen(nomefile, "r");
     
     if (f == NULL) 
         printf("Errore nell'apertura del file!");
     else
     {
         fscanf(f, "%d", &dim);
         
         i = 0;
         
         while (!feof(f))
         {
               fscanf(f, "%s", elenco[i]);
               i++;
         }
         fclose(f);
     }
    
     return dim;
}

int palindrome(char elenco[][N], char elenco2[][N], int dim)
{
     int i, j, pal, num_pal;
     
     num_pal = 0;
     
     for(i = 0; i < dim; i++)
     {
         pal = 0;
           
         for(j = 0; j < strlen(elenco[i]); j++) 
         {
            if(elenco[i][j] == elenco [i][strlen(elenco[i])-j-1])
               pal++;   
         }
         if(pal == strlen(elenco[i]))
         {
            strcpy(elenco2[num_pal], elenco[i]);
            num_pal++;
         }
     }
     
     return num_pal;
}

void vocali(char elenco[][N], int dim_pal)
{
     int i, j, k;
     char temp;
     
     for(i = 0; i < dim_pal; i++)
     {
        j = 0;
           while(elenco[i][j] != '\0')
           {
                 if(elenco[i][j] == 'a' || elenco[i][j] == 'e' || elenco[i][j] == 'i' || elenco[i][j] == 'o' || elenco[i][j] == 'u')
                    elenco[i][j] = ' ';
                    j++;
           }
     }
     
     i = 0;
     
     for(i = 0; i < dim_pal; i++)
     {
         for(k = strlen(elenco[i])-1; k >= 0; k--)
         {
             for(j = k; j< strlen(elenco[i]); j++)
             {
                if(elenco[i][j] == ' ')
                {
                   temp = elenco[i][j];
                   elenco[i][j] = elenco[i][j+1];
                   elenco[i][j+1] = temp;
                }              
             }
         }
     }
}

void stampa(char elenco[][N], int dim)
{
     int i,j, num_stampate;
     
     printf("Quante parole vuoi stampare? ");
     scanf("%d", &num_stampate);
     
     for(i = 0; i < num_stampate; i++)
        printf("%s\n", elenco[i]);
}

