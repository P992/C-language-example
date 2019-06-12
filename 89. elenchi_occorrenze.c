/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  16 febbraio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da due file di testo due elenchi di parole; una parola in 
*         questo contesto è definita come una sequenza continua di caratteri del 
*         codice ASCII che siano diversi dai seguenti caratteri separatori: 
*         ' '    ';'    ':'    '.'    ','    '\n'    '\t'
*       - visualizza a video entrambi gli elenchi di parole
*       - ordina i due elenchi in ordine alfabatico crescente
*       - visualizza a video entrambi gli elenchi ordinati di parole
*       - trasforma in minuscolo tutti i caratteri alfabetici presenti in ogni 
*         parola dei due elenchi; 
*       - calcola quante volte ogni parola del primo elenco appare nel secondo 
*         elenco e visualizza il risultato a video
*
*   Ulteriori specifiche:  
*       - i file contententi gli elenchi contengono sequenze di parole separate
*         da caratteri separatori; su una linea del file di input possono esser
*         presenti anche più parole; 
*       - la dimensione massima degli elenchi gestiti è pari a 100; inoltre la
*         massima lunghezza di una parola è di 30 caratteri
*       - oltre al main si scrivano funzioni per effettuare le operazioni di:
*          -> caricamento di un elenco di parole da file
*          -> visualizzazione elenco a video
*          -> ordinamento di un elenco di parole
*          -> trasformazione in minuscolo dei caratteri alfabetici delle parole 
*             di un elenco
*          -> conteggio e visualizzazione a video del numero di volte in cui 
*             ogni parola di un elenco appare in un altro elenco;
*
*    Altro:
*       - per maggiore chiarezza sono stati allegati al presente compito due 
*         file di input di esempio ("elenco1.txt" e "elenco2.txt")
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 30
#define MAXDIM 100

int carica(char nomefile[], char elenco[][MAXCAR]);
void ordina(char elenco[][MAXCAR], char ordinato[][MAXCAR], int dim);
int cerca_indice(char elenco[][MAXCAR], int inizio, int fine);
void trasforma(char elenco[][MAXCAR], int dim);
void occorrenze(char elenco[][MAXCAR], char elenco2[][MAXCAR], int dim, int dim2);
void visualizza_elenco(char elenco[][MAXCAR], int dim);

int main()
{
    char filename[MAXCAR], filename2[MAXCAR];
    int dim1, dim2;
    char elenco1[MAXDIM][MAXCAR], elenco2[MAXDIM][MAXCAR], elenco_ord[MAXDIM][MAXCAR], elenco_ord2[MAXDIM][MAXCAR];
    
    printf("Inserisci il nome del primo file da aprire: ");
    scanf("%s", filename);
    printf("Inserisci il nome del secondo file da aprire: ");
    scanf("%s", filename2);
    
    dim1 = carica(filename, elenco1);
    dim2 = carica(filename2, elenco2);
    
    printf("\nIl primo file contiene il seguente elenco:\n");
    visualizza_elenco(elenco1, dim1);
    
    printf("\nIl secondo file contiene il seguente elenco:\n");
    visualizza_elenco(elenco2, dim2);
    
    trasforma(elenco1, dim1);
    trasforma(elenco2, dim2);
    
    printf("\nPrimo elenco ordinato:\n");
    ordina(elenco1, elenco_ord, dim1);
    visualizza_elenco(elenco_ord, dim1);
    
    printf("\nSecondo elenco ordinato:\n");
    ordina(elenco2, elenco_ord2, dim2);
    visualizza_elenco(elenco_ord2, dim2);
    
    printf("\n");
    occorrenze(elenco_ord, elenco_ord2, dim1, dim2);
    
    system("PAUSE");
    return 0;
}

int carica(char nomefile[], char elenco[][MAXCAR])
{
    FILE* f;
    int i, j;
    
    f = fopen(nomefile, "r");
    
    i = 0;
    
    while(fscanf(f, "%c", &elenco[i][0]) != EOF)
    {
          if(elenco[i][0] != ' ' && elenco[i][0] != '\n' && elenco[i][0] != '\t' && elenco[i][0] != ';' && elenco[i][0] != ':' && elenco[i][0] != ',' && elenco[i][0] != '.')
          {
             j = 1;
          
             do
             {
               fscanf(f, "%c", &elenco[i][j]);
               j++;
             }while(elenco[i][j-1] != ' ' && elenco[i][j-1] != '\n' && elenco[i][j-1] != '\t' && elenco[i][j-1] != ';' && elenco[i][j-1] != ':' && elenco[i][j-1] != ',' && elenco[i][j-1] != '.');
             elenco[i][j-1] = '\0';
             i++;
          }
    }
    
    fclose(f);
    
    return i;
}

void ordina(char elenco[][MAXCAR], char ordinato[][MAXCAR], int dim)
{
     int i;
     int indice;
     char temp[MAXCAR];
     
     for(i = 0; i < dim; i++)
         strcpy(ordinato[i], elenco[i]);
         
     for(i = 0; i < dim; i++)
     {
         indice = cerca_indice(ordinato, i, dim);
         strcpy(temp, ordinato[i]);
         strcpy(ordinato[i], ordinato[indice]);
         strcpy(ordinato[indice], temp);  
     }
}

int cerca_indice(char elenco[][MAXCAR], int inizio, int fine)
{
    int ind;
    ind = inizio;
    int k;
    
    for(k = inizio+1; k < fine; k++)
        if(strcmp(elenco[k],elenco[ind])<0)
           ind = k;
           
    return ind;
}

void trasforma(char elenco[][MAXCAR], int dim)
{
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
        j = 0;
        while(elenco[i][j] != '\0')
        {
              if(elenco[i][j] >= 'A' && elenco[i][j] <= 'Z')
                 elenco[i][j] = elenco[i][j] - 'A' + 'a';
              j++;
        }
     }
}

void occorrenze(char elenco[][MAXCAR], char elenco2[][MAXCAR], int dim, int dim2)
{
    int i, j;
    int num;
    
    for(i = 0; i < dim; i++)
    {
        num = 0;
        for(j = 0; j < dim2; j++)
        {
            if(strcmp(elenco[i], elenco2[j]) == 0)
               num++;
        }
        
        if(num != 0)
           printf("La parola %s compare %d volte nel secondo elenco.\n", elenco[i], num);
    }
}

void visualizza_elenco(char elenco[][MAXCAR], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
         printf("%s\n", elenco[i]);
}
