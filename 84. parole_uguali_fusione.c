/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  23 gennaio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da due file di testo due elenchi di parole; le 
*         eventuali righe vuote o che comunque non contengono caratteri 
*         alfabetici non devono essere caricate nell'elenco in memoria; inoltre,
*         all'atto del caricamento ogni carattere maiuscolo deve essere
*         convertito in minuscolo;
*       - visualizza a video i due elenchi caricati;
*       - ordina i due elenchi in ordine alfabatico crescente;
*       - calcola il numero di parole in comune ai due elenchi e visualizza a 
*         video il numero calcolato;
*       - crea un nuovo elenco ordinato costituito da tutte le parole presenti
*         in uno solo dei due elenchi precedenti (quindi le parole in comune ai
*         due precedenti elenchi non vengono inserite);
*       - visualizza a video il nuovo elenco generato
*       - salva in un file il nuovo elenco di parole creato rispettando la 
*         sintassi del file riportata in basso nelle ulteriori specifiche
*
*   Ulteriori specifiche:  
*       - i file contententi gli elenchi contengono una parola per ogni riga; 
*       - la dimensione massima degli elenchi gestiti è pari a 100; inoltre la
*         massima lunghezza di una parola è di 30 caratteri
*       - oltre al main si scrivano funzioni per effettuare le operazioni di:
*          -> caricamento di un elenco di parole da file
*          -> calcolo delle parole in comune nei due elenchi
*          -> ordinamento di un elenco di parole
*          -> fusione degli elenchi
*          -> salvataggio elenco su file
*
*    Altro:
*       - per maggiore chiarezza sono stati allegati al presente compito due 
*         file di input di esempio ("parole1.txt" e "parole2.txt")
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 30
#define MAXDIM 100

int carica_elenco(char filename[], char elenco[][MAXCAR]);
void ordina(char elenco[][MAXCAR], char ordinato[][MAXCAR], int dim);
int parole_comuni(char elenco[][MAXCAR], char elenco2[][MAXCAR], char super_elenco[][MAXCAR], int dim, int dim2, int* dim3);
void stampa_su_file(char filename[], char elenco[][MAXCAR], int dim);
void visualizza_elenco(char elenco[][MAXCAR], int dim);

int main()
{
    char lista[MAXDIM][MAXCAR], lista2[MAXDIM][MAXCAR], ordinata[MAXDIM][MAXCAR], ordinata2[MAXDIM][MAXCAR];
    char nomefile[MAXCAR], nomefile2[MAXCAR], nomefile3[MAXCAR];
    int dimensione, dimensione2, dim_super, comuni;
    char super[MAXDIM][MAXCAR];
    
    printf("Inserisci il nome del primo file da aprire: ");
    scanf("%s", nomefile);    
    dimensione = carica_elenco(nomefile, lista);
    if(dimensione == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;           
    }
    
    printf("\nIl file contiene il seguente elenco:\n");
    visualizza_elenco(lista, dimensione);
    
    printf("\nInserisci il nome del secondo file da aprire: ");
    scanf("%s", nomefile2);
    dimensione2 = carica_elenco(nomefile2, lista2);
    if(dimensione2 == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;           
    }
    
    printf("\nIl file contiene il seguente elenco:\n");
    visualizza_elenco(lista2, dimensione2);
    
    ordina(lista, ordinata, dimensione);
    ordina(lista2, ordinata2, dimensione2);
    
    printf("\n\nPrimo elenco ordinato:\n");
    visualizza_elenco(ordinata, dimensione);
    
    printf("\nSecondo elenco ordinato:\n");
    visualizza_elenco(ordinata2, dimensione2);
    
    comuni = parole_comuni(ordinata, ordinata2, super, dimensione, dimensione2, &dim_super);
    printf("\nGli elenchi hanno %d parole in comune.\n", comuni);
    
    printf("\nEcco l'elenco contenente le parole non in comune:\n");
    visualizza_elenco(super, dim_super);
    
    printf("Inserisci il nome del file di output: ");
    scanf("%s", nomefile3);
    
    stampa_su_file(nomefile3, super, dim_super);
    
    system("PAUSE");
    return 0;
}

int carica_elenco(char filename[], char elenco[][MAXCAR])
{
    FILE* f;
    int i = 0;
    int j;
    
    f = fopen(filename, "r");
    if(f == NULL)
       return -1;
    
    while(fscanf(f, "%s", &elenco[i]) != EOF)
    {
         for(j = 0; j < strlen(elenco[i]); j++)
         {
             if(elenco[i][j] >= 'a' && elenco[i][j] <= 'z')
                elenco[i][j] = elenco[i][j] - 'a' + 'A';     
         }  
         i++;
    }
    
    fclose(f);
    
    return i;
}

void ordina(char elenco[][MAXCAR], char ordinato[][MAXCAR], int dim)
{
     int i, j;
     char temp[MAXCAR];
     
     for(i = 0; i < dim; i++)
         strcpy(ordinato[i], elenco[i]);
     
     for(i = 0; i < dim; i++)
     {
         for(j = dim-1; j > i; j--)
            if(strcmp(ordinato[j], ordinato[j-1]) < 0)
            {
               strcpy(temp, ordinato[j]);
               strcpy(ordinato[j], ordinato[j-1]);
               strcpy(ordinato[j-1], temp);
            }
     } 
}

int parole_comuni(char elenco[][MAXCAR], char elenco2[][MAXCAR], char super_elenco[][MAXCAR], int dim, int dim2, int* dim3)
{
    int i, j;
    int k = 0;
    int num = 0;
    char comuni[MAXDIM][MAXCAR];
    
    for(i = 0; i < dim; i++)
    {
        j = 0;
        while(j < dim2 && strcmp(elenco[i], elenco2[j]) != 0)
        {
            j++;
        }
        if (j == dim2)
        {         
	       strcpy(super_elenco[num], elenco[i]);
               num++;
        }
        else
        {
               strcpy(comuni[k], elenco[i]);
               k++;
        }
    }
    
    for(i = 0; i < dim; i++)
    {
        j = 0;
        while(j < dim2 && strcmp(elenco2[i], elenco[j]) != 0)
        {
            j++;
        }
        if (j == dim2)
        {         
	       strcpy(super_elenco[num], elenco2[i]);
               num++;
        }
        else
        {
               strcpy(comuni[k], elenco2[i]);
               k++;
        }
    }
    
    *dim3 = num;
    return k;
}

void visualizza_elenco(char elenco[][MAXCAR], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
         printf("%s\n", elenco[i]);
}

void stampa_su_file(char filename[], char elenco[][MAXCAR], int dim)
{
    int i;
    FILE* f;
    
    f = fopen(filename, "w");
    
    fprintf(f, "Ecco l'elenco contenente le parole non comuni:\n");
    
    for(i = 0; i < dim; i++)
        fprintf(f, "%s\n", elenco[i]);
    
    fclose(f); 
}
