/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  16 febbraio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da un file di testo un elenco di motociclette usate; per 
*         ogni motocicletta le informazioni sono: marca, modello, targa, prezzo, 
*         cilindrata, km percorsi; 
*       - visualizza a video l'elenco caricato; 
*       - ordina l'elenco secondo la seguente regola di ordinamento: i record
*         devono essere ordinati in ordine descrescente di prezzo ed a parità di
*         prezzo in ordine crescente di Km percorsi
*       - visualizza a video l'elenco ordinato;
*       - sposta in un nuovo elenco tutti i record dell'elenco di partenza il 
*         cui campo prezzo è compreso tra due valori selezionati dall'utente 
*       - visualizza a video il nuovo elenco generato e poi visualizza l'elenco 
*         di partenza dopo lo spostamento
*       - salva in due file diversi i due elenchi rispettando la sintassi del 
*         file riportata in basso nelle ulteriori specifiche
*
*   Ulteriori specifiche:  
*       - il file di testo contentente l'elenco è strutturato come segue:
*         la prima riga contiene un numero intero che rappresenta quanti record
*         sono presenti nell'elenco salvato su file;
*         su ogni riga c'è un record riportato secondo la seguente sintassi:
*         Campo_Marca-Campo_Modello-Campo_Targa-Campo_Prezzo-Campo_cilindarata-Campo_Km;
*         si ipotizzi che ogni riga del file contiene record validi (ovvero sono
*         presenti tutti i campi con i relativi separatori)
*       - la dimensione massima dell'elenco gestito è pari a 100
*       - oltre al main si scrivano funzioni per effettuare le operazioni di:
*          -> caricamento dell'elenco da file
*          -> ordinamento dell'elenco mediante algoritmo di bubble sort; i 
*             record devono essere ordinati in ordine descrescente di prezzo
*             ed a parità di prezzo in ordine crescente di Km percorsi
*          -> spostamento dei record in un nuovo elenco
*          -> visualizzazione a video dell'elenco
*          -> salvataggio elenco su file
*
*    Altro:
*       - per maggiore chiarezza è stato allegato al presente compito un file di 
*         input di esempio ("moto.txt")
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 30
#define MAXDIM 100

int carica(char filename[], char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[]);
void ordina(char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[], int dim);
void visualizza(char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[], int dim);
void stampa_su_file(char nomefile[], char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[], int dim);

int main()
{
    char nomefile[MAXCAR], nomefile2[MAXCAR];
    char marca[MAXDIM][MAXCAR], modello[MAXDIM][MAXCAR], targa[MAXDIM][MAXCAR];
    double prezzo[MAXDIM], cilindrata[MAXDIM], km[MAXDIM];
    int dimensione;
    int scelta;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    dimensione = carica(nomefile, marca, modello, targa, prezzo, cilindrata, km);
    if(dimensione == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;           
    }
    
    printf("\nIl file contiene il seguente elenco:\n");
    visualizza(marca, modello, targa, prezzo, cilindrata, km, dimensione);
    
    ordina(marca, modello, targa, prezzo, cilindrata, km, dimensione);
    printf("\nElenco ordinato in base al prezzo:\n");    
    visualizza(marca, modello, targa, prezzo, cilindrata, km, dimensione);
    
    printf("\nVuoi salvare l'elenco in un file? (SI = 1/NO = 0) ");
    scanf("%d", &scelta);
    if(scelta == 1)
    {
       printf("Inserisci il nome del file di output: ");
       scanf("%s", nomefile2);
       stampa_su_file(nomefile2, marca, modello, targa, prezzo, cilindrata, km, dimensione);
    }

    ordina(marca, modello, targa, cilindrata, prezzo, km, dimensione);      
    printf("\nElenco ordinato in base alla cilindrata:\n");    
    visualizza(marca, modello, targa, prezzo, cilindrata, km, dimensione);
    
    printf("\nVuoi salvare l'elenco nel file precedente? (SI = 1/NO = 0) ");
    scanf("%d", &scelta);
    if(scelta == 1)
    {
       printf("Inserisci il nome del file di output: ");
       scanf("%s", nomefile2);
       stampa_su_file(nomefile2, marca, modello, targa, prezzo, cilindrata, km, dimensione);
    }
      
    system("PAUSE");
    return 0;
}

int carica(char filename[], char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[])
{
    FILE* f;
    int i;
    int dim;
    
    f = fopen(filename, "r");
    if(f == NULL)
       return 0;
    
    fscanf(f, "%d", &dim);
    
    for(i = 0; i < dim; i++)
        fscanf(f, "%s %s %s %lf %lf %lf", &mar[i], &mod[i], &targ[i], &price[i], &cilindr[i], &kilometri[i]);

    fclose(f);
    
    return dim;
}

void ordina(char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[], int dim)
{
     int i, j;
     int ind_min;
     double temp;
     char temp2[MAXCAR];
     
     for(i = 0; i < dim; i++)
     {
         ind_min = cercamin(price, i, dim);
         temp = price[i];
         price[i] = price[ind_min];
         price[ind_min] = temp;
         temp = cilindr[i];
         cilindr[i] = cilindr[ind_min];
         cilindr[ind_min] = temp;
         temp = kilometri[i];
         kilometri[i] = kilometri[ind_min];
         kilometri[ind_min] = temp;
         strcpy(temp2, mar[i]);
         strcpy(mar[i], mar[ind_min]);
         strcpy(mar[ind_min], temp2);
         strcpy(temp2, mod[i]);
         strcpy(mod[i], mod[ind_min]);
         strcpy(mod[ind_min], temp2);
         strcpy(temp2, targ[i]);
         strcpy(targ[i], targ[ind_min]);
         strcpy(targ[ind_min], temp2);
     }
}

int cercamin(double vett[], int inizio, int fine)
{
    int indice_min;
    int k;
    indice_min = inizio;
    
    for(k = inizio+1; k < fine; k++)
        if(vett[k] < vett[indice_min])
           indice_min = k;
           
    return indice_min;
}
void visualizza(char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[], int dim)
{
     int i;
     
     printf("Marca\tModello\tTarga\t   Prezzo\t Cilindrata\t    Km\n");
     for(i = 0; i < dim; i++)
         printf("%s\t%s\t%s\t%9.2lf\t%9.2lf\t%9.2lf\n", mar[i], mod[i], targ[i], price[i], cilindr[i], kilometri[i]);
}

void stampa_su_file(char nomefile[], char mar[][MAXCAR], char mod[][MAXCAR], char targ[][MAXCAR], double price[], double cilindr[], double kilometri[], int dim)
{
     int i;
     FILE* f;
     
     f = fopen(nomefile, "a");
     
     fprintf(f, "Marca\tModello\tTarga\t   Prezzo\t Cilindrata\t    Km\n");
     for(i = 0; i < dim; i++)
         fprintf(f, "%s\t%s\t%s\t%9.2lf\t%9.2lf\t%9.2lf\n", mar[i], mod[i], targ[i], price[i], cilindr[i], kilometri[i]);
         
     fclose(f);
}
