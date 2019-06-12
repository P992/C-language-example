/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 20 febbraio 2007
   
Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di aprire un file di testo contenente le registrazioni delle
  transazioni avvenute su un conto corrente bancario; il nome del file è fornito
  interattivamente dall'utente;
- carica in memoria tutti i dati presenti nel file di testo e li visualizza a 
  video secondo il formato di visualizzazione dell'esempio riportato 
  successivamente;
- consente all'utente di calcolare la somma di tutte le transazioni in ingresso 
  e la somma di tutte le transazioni in uscita avvenute successivamente ad una 
  data scelta dall'utente interattivamente;
- visualizza a video i valori calcolati al passo precedente

Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- CaricaDati
- VisualizzaDati
- CalcolaSomme

Al candidato è fornita anche la implementazione di una funzione che effettua il
confronto fra due date
- ConfrontaDate

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!

NOTE:
Il file di testo di input contiene le seguenti informazioni secondo la sintassi 
di seguito riportata:
- sulla prima riga sono riportati il nome ed il cognome dell'intestatario del 
  conto; sia il nome che il cognome non contengono separatori (il cognome 
  De Marco quindi sarà riportato nel file come DeMarco o De_Marco);
- sulla seconda riga è riportato l'ID del conto; l'ID è rappresentato mediante 
  una stringa numerica composta da 12 cifre (ad esempio un ID potrebbe essere 
  000128472910)
- sulla terza riga è riportato il saldo attuale del conto espresso in euro
- successivamente su ogni riga è riportata la registrazione di una transazione; 
  le registrazioni sono riportate nel file in ordine decrescente di data, per 
  cui è sempre verificata la condizione che la i-esima registrazione riportata 
  nel file è più recente della i+1-esima registrazione per ogni i; la 
  registrazione è composta dai seguenti campi:
                     anno mese giorno ora minuto importo
  dove i primi 5 campi fanno riferimento al momento in cui è stata effettuata, 
  mentre l'importo rappresenta la quantità di denaro oggetto della transazione; 
  se l'importo è negativo ovviamente si fa riferimento ad una "uscita" 
  altrimenti ad una "entrata".
Per maggiore chiarezza al candidato è fornito il file di input di esempio 
"dati.txt".

Il programma deve essere in grado di gestire fino a 1000 registrazioni.

Esempio.
Di seguito si riporta un esempio di esecuzione del programma con riferimento
al file "dati.txt" fornito al candidato.

                  ---> INIZIO ESEMPIO <---

Digitare il nome del file con il dettaglio delle transazioni: dati.txt
Caricamento avvenuto correttamente.
Il file di input contiene 6 registrazioni.

****** RIEPILOGO TRANSAZIONI CONTO CORRENTE BANCARIO ******
ID Conto Corrente:    000128472910
Intestatario:         Matteo DeMarco
Saldo attuale (euro): 5893.90

Registro delle transazioni effettuate
AAAA/MM/GG   hh:mm    Importo
2007/ 2/16   12:37    -231.80
2007/ 2/14   10:24      21.75
2007/ 2/ 7   14:23    1450.90
2007/ 1/30    9:12    -250.00 
2007/ 1/25   10: 7      33.40
2007/ 1/25    9:51    -250.00
************************************************************

Questo programma consente di calcolare la somma di tutte le transazioni in 
ingresso e la somma di tutte le transazioni in uscita avvenute successivamente 
ad una data da te scelta.
Selezionare una data:
Anno:   2007
Mese:   1
Giorno: 28
Ora:    8
Minuto: 0

La somma delle transazioni in uscita e': -481.80 euro
La somma delle transazioni in ingresso e': 1472.65 euro

                  ---> FINE ESEMPIO <---
*/ 

#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANS 1000
#define NUM_CAMPI_DATA 5
#define MAX_LUNGHEZZA 20

/* Prototipi delle funzioni da implementare da parte del candidato*/
int CaricaDati(char nomefile[], char nome[], char cognome[], char ID_conto[],
                    float *saldo, int data[][NUM_CAMPI_DATA], float importo[],
                    int dim_fisica);
                                                                
void VisualizzaDati(char nome[], char cognome[], char ID_conto[], float saldo,
                   int data[][NUM_CAMPI_DATA], float importo[], int dim_logica);
                                                                
void CalcolaSomme(int anno, int mese, int giorno, int ora, int minuto, 
                    int data[][NUM_CAMPI_DATA], float importo[], int dim_logica, 
                                     float *somma_entrate, float *somma_uscite);

/* Funzione già fornita al candidato: non deve essere modificata*/
int ConfrontaDate(int anno1, int mese1, int giorno1, int ora1, int minuto1,
                      int anno2, int mese2, int giorno2, int ora2, int minuto2);
                      
                      
int main()
{
    char filename[MAX_LUNGHEZZA], name[MAX_LUNGHEZZA], surname[MAX_LUNGHEZZA], ID[MAX_LUNGHEZZA];
    int transazioni, date[MAX_TRANS][NUM_CAMPI_DATA];
    float soldi, importi[MAX_TRANS];
    float entrate, uscite;
    int year, month, day, hour, minute;
    
    printf("Digitare il nome del file con il dettaglio delle transazioni: ");
    scanf("%s", filename);
    
    transazioni = CaricaDati(filename, name, surname, ID, &soldi, date, importi, NUM_CAMPI_DATA);
    if(transazioni == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;            
    }
    
    printf("\nIl file di input contiene %d transazioni.\n", transazioni);
    
    VisualizzaDati(name, surname, ID, soldi, date, importi, transazioni);
    
    printf("Selezionare una data:\n");
    printf("Anno: ");
    scanf("%d", &year);
    printf("Mese: ");
    scanf("%d", &month);
    printf("Giorno: ");
    scanf("%d", &day);
    printf("Ora: ");
    scanf("%d", &hour);
    printf("Minuto: ");
    scanf("%d", &minute);
    
    CalcolaSomme(year, month, day, hour, minute, date, importi, transazioni, &entrate, &uscite);
    printf("La somma delle transazioni in entrata e' %.2f\n", entrate);
    printf("La somma delle transazioni in uscita e' %.2f\n", uscite);
    
    system("PAUSE");
}


/* La funzione carica dal file di testo il cui nome è passato attraverso il 
   parametro nomefile il nome ed il cognome dell'intestatario di un conto 
   corrente bancario, l'ID del conto, ed una serie di registrazioni di 
   transazioni. Le registrazioni sono riportate una per ogni riga e sono 
   costituite dalla data (anno, mese, giorno, ora, minuto) e dall'importo;
   la funzione legge tutte le registrazioni fino a raggiungere la fine del file
   o la dimensione fisica dei parametri data e importo specificata attraverso
   il parametro dim_fisica. 
   La funzione restituisce -1 nel caso in cui si dovessero verificare errori di
   accesso al file, altrimenti il numero di registrazioni presenti nel file. 
   Si faccia riferimento alla sintassi del file descritta nella traccia per 
   ulteriori indicazioni. Si ipotizzi per semplicità che tutti i dati riportati
   nel file rispettino la sintassi.                                           */
int CaricaDati(char nomefile[], char nome[], char cognome[], char ID_conto[],
                   float *saldo, int data[][NUM_CAMPI_DATA], float importo[],
                   int dim_fisica)
{
    FILE* f;
    float euro;
    int i, j;
    
    f = fopen(nomefile, "r");
    if(f == NULL) 
       return -1;
    
    fscanf(f, "%s %s %s", nome, cognome, ID_conto);
    fscanf(f, "%f", &euro);
    
    i = 0;
    while(fscanf(f, "%d", &data[i][0]) != EOF)
    {
          for(j = 1; j < NUM_CAMPI_DATA; j++){
              fscanf(f, "%d", &data[i][j]);
          }
          
          fscanf(f, "%f", &importo[i]);
          
          i++;          
    }
    
    fclose(f);
    
    *saldo = euro;
    return i;
}



/* La funzione visualizza il dettaglio delle transazioni effettuate su un conto
   corrente bancario.
   La visualizzazione deve essere effettuata ESATTAMENTE come riportato 
   nell'esempio descritto nella traccia.                                      */                                                                
void VisualizzaDati(char nome[], char cognome[], char ID_conto[], float saldo,
                   int data[][NUM_CAMPI_DATA], float importo[], int dim_logica)
{
     int i, j;
     
     printf("\n****** RIEPILOGO TRANSAZIONI CONTO CORRENTE BANCARIO ******\n");
     printf("Conto corrente:\t%s\n", ID_conto);
     printf("Intestatario:\t%s %s\n", nome, cognome);
     printf("Saldo attuale (euro):\t%.2f\n\n", saldo);
     
     printf("Registro delle transazioni effettuate:\n");
     printf("AAAA/MM/GG\thh:mm\tImporto\n");
     for(i = 0; i < dim_logica; i++)
     {
         printf("%4d/%2d/%2d\t", data[i][0], data[i][1], data[i][2]);
         printf("%2d:%2d\t", data[i][3], data[i][4]);
         printf("%7.2f", importo[i]);
         printf("\n");
     }
     printf("***********************************************************\n\n");
}
                              
                              
/* La funzione calcola la somma di tutte le transazioni in ingresso e la somma 
   di tutte le transazioni in uscita avvenute successivamente alla data 
   specificata con i parametri anno,mese,giorno,ora,minuto                    */                                                                
void CalcolaSomme(int anno, int mese, int giorno, int ora, int minuto, 
                    int data[][NUM_CAMPI_DATA], float importo[], int dim_logica, 
                                     float *somma_entrate, float *somma_uscite)
{
     int i;
     float entrata = 0;
     float uscita = 0;
     int date;
     
     for(i = 0; (i<dim_logica) && ConfrontaDate(anno, mese, giorno, ora, minuto, data[i][0],
        data[i][1], data[i][2], data[i][3], data[i][4])<0; i++)
     {
        if(importo[i] < 0)
           uscita = uscita + importo[i];
        else
           entrata = entrata + importo[i];
     }
     
     *somma_entrate = entrata;
     *somma_uscite = uscita;
}
                                     
                                     

/* La funzione confronta due date specificate mediante le informazioni di anno,
   mese, giorno, ora, minuto. La funzione restituisce -1/0/1 se la prima data è 
   antecedente/uguale/successiva alla seconda data.
   La funzione è già fornita al candidato e non deve essere modificata        */
int ConfrontaDate(int anno1, int mese1, int giorno1, int ora1, int minuto1,
                      int anno2, int mese2, int giorno2, int ora2, int minuto2){
   if(anno1<anno2)
      return -1;
   else if(anno1>anno2)
      return 1;
   else if(mese1<mese2)
      return -1;
   else if(mese1>mese2)
      return 1;
   else if(giorno1<giorno2)
      return -1;
   else if(giorno1>giorno2)
      return 1;
   else if(ora1<ora2)
      return -1;
   else if(ora1>ora2)
      return 1;
   else if(minuto1<minuto2)
      return -1;
   else if(minuto1>minuto2)
      return 1;
   else
      return 0;
}
