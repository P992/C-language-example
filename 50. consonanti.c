/*Dato un elenco di stringhe il programma crea un vettore con le parole ed il numero di consonanti*/

#define N 10
#include <stdio.h>
#include <stdlib.h>

/*Prototipi*/
int carica_elenco(char elenco[][N]);
void consonanti(char elenco[][N], int vett[], int dim);
void stampa(char elenco[][N], int v[], int dim);

/*Programma*/

int main()
{
    char lista[N][N];
    int v[N];
    int dimensione, num_cons;
    
    printf("**Questo programma calcola il numero di consonanti presenti nelle parole inserite da input**\n"); 
    
    dimensione = carica_elenco(lista);
    consonanti(lista, v, dimensione);
    stampa(lista, v, dimensione);      
    
    system("PAUSE");
}

/*Funzioni*/
int carica_elenco(char elenco[][N])
{
    int i, dim;
    
    printf("Quante parole vuoi inserire? ");
    scanf("%d", &dim);
    
    for(i = 0; i < dim; i++)
       scanf("%s", elenco[i]);
    
    return dim;
}

void consonanti(char elenco[][N], int vett[], int dim)
{
     int i,j, cons;
     
     for(i = 0; i < dim; i++)
     {
        j = 0;
        cons = 0;
        
        while(elenco[i][j] != '\0')
        {
              if(elenco[i][j] != 'a' && elenco [i][j] != 'e' && elenco [i][j] != 'i' && elenco [i][j] != 'o' && elenco [i][j] != 'u'){
                cons++;
              }
              j++;
        }    
        vett[i] = cons;
     }
}

void stampa(char elenco[][N], int vett[], int dim)
{
    int i;
    
    printf("PAROLA/CONSONANTI\n");
    
    for(i = 0; i < dim; i++)
       printf("%s /%d\n", elenco[i], vett[i]);
}
