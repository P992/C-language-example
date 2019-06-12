/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  23 gennaio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da un file di testo un elenco di modelli di cellulari; per 
*         ogni modello di cellulare le informazioni sono: marca, modello e
*         prezzo 
*       - visualizza a video l'elenco caricato; 
*       - ordina l'elenco in base al prezzo;
*       - visualizza a video l'elenco ordinato;
*       - elimina record inconsistenti nell'elenco: due o più record sono da 
*         considerarsi inconsistenti se coincidono i campi marca e modello, 
*         mentre il prezzo è diverso; nel caso vengano individuati record 
*         inconsistenti il programma calcola la media di tutti i prezzi relativi 
*         ai record inconsistenti e conserva solo un record il cui prezzo è dato
*         dalla media calcolata
*       - visualizza a video l'elenco
*       - salva in un file l'elenco rispettando la sintassi del file riportata 
*         in basso nelle ulteriori specifiche
*
*   Ulteriori specifiche:  
*       - il file di testo contentente l'elenco è strutturato come segue:
*         la prima riga contiene un numero intero che rappresenta quanti record
*         sono presenti nell'elenco salvato su file;
*         su ogni riga c'è un record riportato secondo la seguente sintassi:
*         <Campo_Marca><Campo_Modello><Campo_Prezzo>
*       - la dimensione massima dell'elenco gestito è pari a 100
*       - oltre al main si scrivano funzioni per effettuare le operazioni di:
*          -> caricamento dell'elenco da file
*          -> ordinamento dell'elenco mediante algoritmo di selection sort
*          -> elimina i record inconsistenti nell'elenco
*          -> visualizzazione a video dell'elenco
*          -> salvataggio elenco su file
*
*    Altro:
*       - per maggiore chiarezza è stato allegato al presente compito un file di 
*         input di esempio ("cellulari.txt")
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 30
#define MAXDIM 100

int carica(char nomefile[], char elenco[][MAXCAR], char elenco2[][MAXCAR], double price[]);
void ordina(char elenco[][MAXCAR], int dim);
void ordina_prezzo(double price[], int dim);
void stampa(char elenco[][MAXCAR], char elenco2[][MAXCAR], double price[], int dim);
void stampa_file(char nomefile[], char elenco[][MAXCAR], char elenco2[][MAXCAR], double price[], int dim);

int main()
{
    char filename[MAXCAR], filename2[MAXCAR];
    char marca[MAXDIM][MAXCAR], modello[MAXDIM][MAXCAR];
    double prezzo[MAXDIM];
    int dimensione;
    int scelta;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    dimensione = carica(filename, marca, modello, prezzo);
    if(dimensione == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;           
    }
    
    printf("\nIl file contiene il seguente elenco:\n");
    stampa(marca, modello, prezzo, dimensione);
    
    ordina(marca, dimensione);
    printf("\nElenco ordinato in base alla marca:\n");
    stampa(marca, modello, prezzo, dimensione);
    printf("\nVuoi salvare l'elenco in un file di output? (SI = 0/NO = 1) ");
    scanf("%d", &scelta);
    if(scelta == 0)
    {
       printf("\nInserisci il nome del file: ");
       scanf("%s", filename2);
       stampa_file(filename2, marca, modello, prezzo, dimensione);      
    }

    ordina_prezzo(prezzo, dimensione);
    printf("\nElenco ordinato in base al prezzo:\n");   
    stampa(marca, modello, prezzo, dimensione);
    printf("\nVuoi salvare l'elenco su file? (SI = 0/NO = 1) ");
    scanf("%d", &scelta);
    if(scelta == 0)
       stampa_file(filename2, marca, modello, prezzo, dimensione);      
    
    system("PAUSE");
    return 0;
}

int carica(char nomefile[], char elenco[][MAXCAR], char elenco2[][MAXCAR], double price[])
{
    FILE* f;
    int dim;
    int i = 0;
    
    f = fopen(nomefile, "r");
    if(f == NULL)
       return 0;
       
    fscanf(f, "%d", &dim);
    
    while(fscanf(f, "%s %s %lf", &elenco[i], &elenco2[i], &price[i]) != EOF)
          i++;
        
    fclose(f);
    
    return dim;
}

void ordina(char elenco[][MAXCAR], int dim)
{
    int i, j;
    char temp[MAXCAR];
    
    for(i = 0; i < dim; i++)
    {
        for(j = dim-1; j > i ; j--)
        {
            if(strcmp(elenco[j], elenco[j-1]) < 0)
            {
               strcpy(temp, elenco[j]);
               strcpy(elenco[j], elenco[j-1]);
               strcpy(elenco[j-1], temp);                                  
            }
        }  
    }
}

void ordina_prezzo(double price[], int dim)
{
     int i, j;
     double temp;
     
     for(i = 0; i < dim; i++)
     {
         for(j = dim-1; j > i ; j--)
         {
             if(price[j] < price[j-1])
             {
                temp = price[j];
                price[j] = price[j-1];
                price[j-1] = temp;         
             }  
         }
     }
}

void stampa(char elenco[][MAXCAR], char elenco2[][MAXCAR], double price[], int dim)
{
     int i;
     
     printf("Marca\tModello\tPrezzo\n");
     for(i = 0; i < dim; i++)
        printf("%s\t%7s\t%6.2lf\n", elenco[i], elenco2[i], price[i]);
}

void stampa_file(char nomefile[], char elenco[][MAXCAR], char elenco2[][MAXCAR], double price[], int dim)
{
     FILE* f;
     int i;
     
     f = fopen(nomefile, "a");
     
     fprintf(f, "\nMarca\tModello\tPrezzo\n");
     for(i = 0; i < dim; i++)
        fprintf(f, "%s\t%7s\t%6.2lf\n", elenco[i], elenco2[i], price[i]);
     
     fclose(f);
}
