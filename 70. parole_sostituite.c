/*******************************************************************************
*   Esame scritto di Fondamenti di Informatica
*   CdL in Ingegneria Elettronica e Ingegneria Informatica
*   Prova del: 9 gennaio 2007
*
*   Al candidato si richiede di implementare un programma che deve eseguire 
*   nell'ordine i seguenti passi:
*   - carica un elenco di parole da un file di testo il cui nome è fornito 
*     dall'utente interattivamente: tale elenco deve essere caricato in un 
*     array bidimensionale (matrice) di caratteri;
*   - visualizza a video l'elenco di parole caricate nella matrice;
*   - chiede interattivamente all'utente di fornire una stringa di caratteri 
*     (si ipotizzi che la stringa non contenga caratteri duplicati)
*   - sostituisce con '-' tutti i caratteri della matrice presenti nella stringa
*     digitata al passo precedente;
*   - visualizza a video l'elenco di parole modificate al passo precedente.
*
*   ESEMPIO:
*   Supponendo che il file di input contenga le seguenti parole:
*
*   Pippo
*   Pluto
*   Clarabella
*   Topolino
*   Minnie
*
*   e che la stringa letta da tastiera sia: Pan
*
*   allora, l'elenco di parole in memoria dopo la sostituzione dei caratteri 
*   sarà il seguente:
*
*   -ippo
*   -luto
*   Cl-r-bell-
*   Topoli-o
*   Mi--ie
*
*   Ulteriori specifiche:
*   MASSIMA LUNGHEZZA DELLE PAROLE (MAXLUNGPAROLA): 50 caratteri
*   NUMERO MASSIMO DI PAROLE DA CARICARE DA FILE (MAXNUMPAROLE): 100
*
*   Cosa è richiesto al candidato:
*   Si richiede di scrivere un programma completo che esegua quanto richiesto in
*   precedenza. Inoltre, il programma deve impiegare i seguenti sottoprogrammi 
*   di cui si riportano il prototipo ed una breve descrizione. Oltre al main, il 
*   candidato deve implementare tali sottoprogrammi senza modificare nè il 
*   prototipo, nè la funzionalità.
*
*   int CaricaVocabolario(char nomefile[], char elenco_parole[][MAXLUNGPAROLA],
*                                                               int max_parole);
*      La funzione carica da un file di testo il cui nome è passato mediante il 
*      parametro "nomefile" un elenco di parole nel parametro "elenco_parole"; 
*      la funzione presuppone che il file di input contenga una parola su ogni 
*      linea senza separatori o altri caratteri speciali ed inoltre le parole 
*      siano formate solo da caratteri alfabetici; la funzione quindi non deve 
*      gestire eventuali errori presenti nel file di input; la funzione inoltre 
*      restituisce -1 nel caso in cui non sia riuscita ad aprire il file, 
*      altrimenti il numero di parole lette; in ogni caso la funzione deve 
*      leggere al massimo "max_parole" parole dal file di input 
*
*   void VisualizzaParole(char elenco_parole[][MAXLUNGPAROLA], int num_parole);
*      La funzione visualizza a video l'elenco delle parole contenute nel 
*      parametro "elenco_parole"; il parametro "num_parole" rappresenta il 
*      riempimento per righe della matrice "elenco_parole" (ovvero quante parole 
*      ci sono nella matrice) 
*
*   void AnnullaCaratteri(char elenco_parole[][MAXLUNGPAROLA], int num_parole,
*                                       char stringa_caratteri_da_cancellare[]);
*     La funzione sostituisce con '-' tutti i caratteri della matrice 
*     "elenco_parole" presenti nel parametro "stringa_caratteri_da_cancellare";
*     il parametro num_parole contiene il numero di parole presenti in 
*     elenco_parole
*
*    Altro:
*       - per maggiore chiarezza è stato allegato al presente compito un file di
*         input di esempio ("parole.txt")
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLUNGPAROLA 50
#define MAXNUMPAROLE 100

int CaricaVocabolario(char nomefile[], char elenco_parole[][MAXLUNGPAROLA],
                                                                int max_parole);
void VisualizzaParole(char elenco_parole[][MAXLUNGPAROLA], int num_parole);
void AnnullaCaratteri(char elenco_parole[][MAXLUNGPAROLA], int num_parole,
                                        char stringa_caratteri_da_cancellare[]);



int main()
{
    char filename[100];
    char elenco[MAXNUMPAROLE][MAXLUNGPAROLA];
    int numero_parole;
    char stringa[MAXLUNGPAROLA];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    numero_parole = CaricaVocabolario(filename, elenco, MAXNUMPAROLE);
    printf("Il file contiene il seguente elenco:\n");
    VisualizzaParole(elenco, numero_parole);
    
    printf("\nInserisci una 'stringa' di lettere: ");
    scanf("%s", stringa);
    
    AnnullaCaratteri(elenco, numero_parole, stringa);
    
    printf("\nHai ottenuto il seguente elenco modificato:\n");
    VisualizzaParole(elenco, numero_parole);
    
    system("PAUSE");
}



int CaricaVocabolario(char nomefile[], char elenco_parole[][MAXLUNGPAROLA],
                                                                int max_parole)
{
    FILE* f;
    int i = 0;
    
    f = fopen(nomefile, "r");
    if(f == NULL)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    while(fscanf(f, "%s", &elenco_parole[i]) != EOF && i < max_parole)
          i++;
    
    fclose(f);
    
    return i;
}

void VisualizzaParole(char elenco_parole[][MAXLUNGPAROLA], int num_parole)
{
     int i;
     
     for(i = 0; i < num_parole; i++)
         printf("%s\n", elenco_parole[i]);
}

void AnnullaCaratteri(char elenco_parole[][MAXLUNGPAROLA], int num_parole, 
                                        char stringa_caratteri_da_cancellare[])
{
     int i, j, k;
     int num_stringa;
     
     num_stringa = strlen(stringa_caratteri_da_cancellare);
     
     for(i = 0; i < num_parole; i++)
     {
         for(j = 0; j < strlen(elenco_parole[i]);j++)
         {
             for(k = 0; k < num_stringa; k++)
             {
                 if(elenco_parole[i][j] == stringa_caratteri_da_cancellare[k])
                      elenco_parole[i][j] = '-';
             }
         }
     }
}
