/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 6 giugno 2007
   
Al candidato � richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di aprire un file di testo contenente una matrice di interi;
  tali valori rappresentano le distanze chilometriche tra un insieme di localit�
  anch'esse riportate nel file; il nome del file � fornito interattivamente 
  dall'utente; il formato del file di input � dettagliato pi� in avanti nella
  sezione "ULTERIORI SPECIFICHE"
- carica in memoria tutti i dati presenti nel file di testo e visualizza a video
  un messaggio di conferma dell'avvenuto caricamento altrimenti visualizza un
  messaggio di errore; in caso di errore il programma termina;
- visualizza in numero e i nomi delle localit� caricate;
- richiede all'utente di selezionare due localit� presenti nell'elenco e 
  visualizza a video la relativa distanza chilometrica; in caso di selezione 
  errata il programma fornisce un messaggio di errore e termina; si distinguono
  i seguenti due casi di errore:
  - se almeno una delle localit� selezionate dall'utente non � presente 
    nell'elenco il programma visualizza un messaggio di errore (non � richiesto 
    che il programma visualizzi quale delle due localit� non � presente in 
    elenco, ma � sufficiente che indichi solo che almeno una non � presente); 
  - se le due localit� selezionate coincidono il programma visualizza un 
    messaggio per segnalare tale scelta errata;
  
ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire al massimo 100 localit�
- Il numero massimo di caratteri di cui � composto il nome di una localit� deve
  essere al massimo pari a 30
- Formato del file di input:
  Il file di input contiene le distanze chilometriche relative ad un insieme di
  N localit�; il file � strutturato come di seguito riportato
  - sulla prima riga � riportato il valore di N (intero positivo) che 
    rappresenta il numero di localit� cui fanno riferimento i dati riportati
    di seguito;
  - sulla seconda riga � riportato un elenco di N localit�; le localit� sono 
    riportate in ordine alfabetico crescente e sono separate dal carattere
    di tabulazione (es. ancona     aosta     bari   ...); si ipotizzi che i nomi
    delle localit� contengano solo caratteri alfabetici minuscoli (es. laquila,
    laspezia, sanmartinodicastrozza, ...);
  - sulle righe successive � riportata una matrice simmetrica di dimensioni 
    N x N di valori interi; in particolare, il valore di posizione i,j della 
    matrice rappresenta la distanza tra le localit� di posizione i-esima e 
    j-esima dell'elenco di cui al punto precedente.
    
COSA E' RICHIESTO AL CANDIDATO
Al candidato � richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_distanze
- cerca_localita
- visualizza_elenco_localita

Per maggiore chiarezza al candidato � fornito il file di input di esempio 
"localita.txt".

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!

------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------
Digitare il nome del file di input: localita.txt

Il sistema consente di effettuare ricerche sulle seguenti 18 localita'
ancona
aosta
bari
bologna
campobasso
catanzaro
firenze
genova
laquila
milano
napoli
perugia
potenza
roma
torino
trento
trieste
venezia
Digitare il nome della prima localita': aosta
Digitare il nome della seconda localita': roma
La distanza tra le localita' selezionate e' 748Km
Premere un tasto per continuare . . .
----------------  FINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA ---------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 100
#define MAXCAR 30

int carica_distanze(char nomefile[], int distanze[MAXNUM][MAXNUM], 
                                          char elenco_localita[MAXNUM][MAXCAR]);
int cerca_localita(char elenco_localita[MAXNUM][MAXCAR], int n, 
                                                              char loc[MAXCAR]);                                                              
void visualizza_elenco_localita(char elenco_localita[MAXNUM][MAXCAR], int n);




int main()
{
    char filename[MAXCAR], localita[MAXNUM][MAXCAR];
    int distances[MAXNUM][MAXNUM];
    int num_loc, posizione1, posizione2;
    char loc1[MAXCAR], loc2[MAXCAR];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    num_loc = carica_distanze(filename, distances, localita);
    if(num_loc == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;         
    }
    
    printf("Il sistema consente di effettuare ricerche sulle seguenti %d localita':\n", num_loc);
    visualizza_elenco_localita(localita, num_loc);
    
    printf("Digitare il nome della prima localita': ");
    scanf("%s", loc1);
    
    posizione1 = cerca_localita(localita, num_loc, loc1);
    if(posizione1 == -1)
    {
       printf("Questa localita' non e' presente nell'elenco!\n");
       system("PAUSE");
       return -1;
    }
    
    printf("Digitare il nome della seconda localita': ");
    scanf("%s", loc2);
    
    posizione2 = cerca_localita(localita, num_loc, loc2);
    if(posizione2 == -1)
    {
       printf("Questa localita' non e' presente nell'elenco!\n");
       system("PAUSE");
       return -1;
    }
    
    printf("La distanza tra le due localita' e' pari a %d km.\n", distances[posizione1][posizione2]);
    system("PAUSE");
}



/* La funzione riceve in ingresso una stringa con il nome del file da cui 
   caricare i dati relativi alle distanze chilometriche tra localit�. La 
   funzione restituisce un intero che � pari a 0 nel caso il file sia vuoto o 
   se non riesce ad aprire il file, altrimenti � un valore positivo pari al 
   numero n di localit� gestite. Inoltre, la funzione modifica la matrice di
   interi inizializzandola con gli n x n valori letti dal file e che 
   rappresentano le distanze chilometriche; modifica, inoltre, anche l'elenco 
   delle localit� inserendo i nomi delle localit� lette dal file (i nomi delle
   localit� sono riportate nel file in ordine alfabetico crescente).          */
int carica_distanze(char nomefile[], int distanze[MAXNUM][MAXNUM], 
                                          char elenco_localita[MAXNUM][MAXCAR])
{
    FILE* f;
    int num, j;
    int i = 0;
        
    f = fopen(nomefile, "r");
    if(f == NULL)
       return 0;
       
    fscanf(f, "%d", &num);
    
    while(i < num)
    {
         fscanf(f, "%s", &elenco_localita[i]);
         i++;   
    }
    
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < num; j++)
            fscanf(f, "%d", &distanze[i][j]);  
    }
    
    fclose(f);
    
    return num;
}



/* La funzione implementa l'algoritmo di ricerca lineare: verifica se la stringa
   loc passata come parametro � presente nell'array di stringhe elenco_localita
   il cui riempimento � fornito attraverso il parametro n. La funzione 
   restituisce -1 se la ricerca ha esito negativo altrimenti restituisce la 
   posizione dell'elemento nell'array.                                        */
int cerca_localita(char elenco_localita[MAXNUM][MAXCAR], int n, 
                                                              char loc[MAXCAR])
{
   int i;
   
   for(i = 0; i < n; i++)
   {
      if(strcmp(elenco_localita[i], loc) == 0)
         return i;
   }
   
   return -1;
}



/* La funzione visualizza le localit� presenti nel parametro elenco_localita una
   per ogni riga. Il parametro n � il riempimento dell'array di stringhe
   elenco_localita.                                                           */
void visualizza_elenco_localita(char elenco_localita[MAXNUM][MAXCAR], int n)    
{
    int i;
    
    for(i = 0; i < n; i++)
       printf("%s\n", elenco_localita[i]);
} 
