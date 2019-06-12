/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  23 gennaio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da un file di testo un elenco di modelli di autovetture; per 
*         ogni modello di autovettura le informazioni sono: marca, modello e
*         prezzo 
*       - visualizza a video l'elenco caricato; 
*       - ordina l'elenco in base alla marca e quindi al modello;
*       - visualizza a video l'elenco ordinato;
*       - elimina record duplicati nell'elenco: due o più record sono da 
*         considerarsi duplicati se coincidono tutti e tre i relativi campi; 
*         nel caso vengano rilevati dati duplicati il programma elimina tutte 
*         le copie del dato tranne una;
*       - visualizza a video l'elenco
*       - salva in un file l'elenco rispettando la sintassi del file riportata 
*         in basso nelle ulteriori specifiche
*
*   Ulteriori specifiche:  
*       - il file di testo contentente l'elenco è strutturato come segue:
*         la prima riga contiene un numero intero che rappresenta quanti record
*         sono presenti nell'elenco salvato su file;
*         su ogni riga c'è un record riportato secondo la seguente sintassi:
*         !Campo_Marca!Campo_Modello!Campo_Prezzo!
*       - la dimensione massima dell'elenco gestito è pari a 100
*       - oltre al main si scrivano funzioni per effettuare le operazioni di:
*          -> caricamento dell'elenco da file
*          -> ordinamento dell'elenco mediante algoritmo di bubble sort
*          -> elimina i record duplicati nell'elenco
*          -> visualizzazione a video dell'elenco
*          -> salvataggio elenco su file
*
*    Altro:
*       - per maggiore chiarezza è stato allegato al presente compito un file di 
*         input di esempio ("auto.txt")
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 20
#define MAXDIM 100

int carica_elenco(char nomefile[], char elenco[][MAXDIM]);
void ordina(char elenco[][MAXDIM], char elenco_ordinato[][MAXDIM], int dim);
int elimina_doppi(char elenco[][MAXDIM], char elenco_duplicati[][MAXDIM], int dim);
void visualizza_elenco(char elenco[][MAXDIM], int dim);
void stampa_su_file(char nomefile2[], char elenco[][MAXDIM], int dim);

int main()
{
    char filename[MAXCAR], filename2[MAXCAR];
    char lista[MAXDIM][MAXDIM], lista_ordinata[MAXDIM][MAXDIM], duplicati[MAXDIM][MAXDIM];
    int dim, dim2, dim3;
    int stampa;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    dim = carica_elenco(filename, lista);
    if(dim == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;    
    }
    
    printf("\nIl file contiene il seguente elenco:\n");
    visualizza_elenco(lista, dim);
    
    ordina(lista, lista_ordinata, dim);
    printf("\nEcco l'elenco ordinato:\n");
    visualizza_elenco(lista_ordinata, dim);
    
    dim2 = elimina_doppi(lista_ordinata, duplicati, dim);
    dim3 = dim - dim2;
    
    printf("\nSono stati eliminati %d report:\n", dim3);
    visualizza_elenco(duplicati, dim2);
    
    printf("\nInserisci il nome del file su cui salvare l'elenco: ");
    scanf("%s", filename2);
    
    stampa_su_file(filename2, duplicati, dim2);
    printf("Salvataggio avvenuto correttamente!\n\n");
       
    system("PAUSE");
    return 0;
}

int carica_elenco(char nomefile[], char elenco[][MAXDIM])
{
    FILE* f;
    int num;
    int i = 0;
        
    f = fopen(nomefile, "r");
    if(f == NULL)
       return 0;
       
    fscanf(f, "%d", &num);
    
    while(fscanf(f, "%s", &elenco[i]) != EOF)
          i++;
       
    fclose(f);
    
    return num;
}

void ordina(char elenco[][MAXDIM], char elenco_ordinato[MAXDIM][MAXDIM], int dim)
{
     int i, j;
     char temp[MAXDIM];
     
     for(i = 0; i < dim; i++)
         strcpy(elenco_ordinato[i], elenco[i]);
     
     for(i = 0; i < dim-1; i++)
     {
         for(j = dim-1; j > i; j--)
         {
             if(strcmp(elenco_ordinato[j], elenco_ordinato[j-1]) < 0)
             {
                strcpy(temp, elenco_ordinato[j]);
                strcpy(elenco_ordinato[j], elenco_ordinato[j-1]);
                strcpy(elenco_ordinato[j-1], temp);
             }
         }
     }
}

int elimina_doppi(char elenco[][MAXDIM], char elenco_duplicati[][MAXDIM], int dim)
{
    int i;
    int k = 0;
    
    for(i = 0; i < dim; i++)
    {
        if(strcmp(elenco[i], elenco[i+1]) != 0)  
        {
           strcpy(elenco_duplicati[k], elenco[i]);
           k++;            
        }
    }
    
    return k;
}

void visualizza_elenco(char elenco[][MAXDIM], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
         printf("%s\n", elenco[i]);
}

void stampa_su_file(char nomefile2[], char elenco[][MAXDIM], int dim)
{
     FILE* f;
     int i;
     
     f = fopen(nomefile2, "w");
        
     fprintf(f, "Sono presenti %d report:\n", dim);
     
     for(i = 0; i < dim; i++)
         fprintf(f, "%s\n", elenco[i]);
            
     fclose(f);
}
