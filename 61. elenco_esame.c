/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DELL'8 GENNAIO 2008
   CORSI DI LAUREA IN INGEGNERIA ELETTRONICA E INGEGNERIA INFORMATICA

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- carica da un file di testo il cui nome è fornito interattivamente dall'utente 
  un elenco di parole; maggiori dettagli sul formato del file sono riportati 
  nella sezione di ULTERIORI SPECIFICHE
- visualizza a video l'elenco di parole caricato da file
- ordina l'elenco di parole in maniera crescente rispetto al numero di caratteri
  di cui è costituita ogni parola impiegando l'algoritmo del Bubble Sort
- visualizza a video l'elenco di parole ordinato al passo precedente
- verifica la presenza nell'elenco della parola fornita interattivamente 
  dall'utente

ULTERIORI SPECIFICHE
- Il file di testo impiegato per l'input del programma contiene una sequenza di
  parole; le parole sono sequenze continue di caratteri alfabetici (maiuscoli 
  e/o minuscoli); le parole presenti nel file sono separate attraverso una
  sequenza di uno o più separatori appartenenti al seguente insieme:
           blank (spazio), tabulazione (\t), new-line (\n)
- Il programma deve essere in grado di gestire elenchi di non più di 30 parole
- Il programma deve essere in grado di gestire parole di non più di 25 caratteri
- Le condizioni di errore da individuare e gestire durante il caricamento da 
  file sono le seguenti:
     - apertura del file non riuscita

  

COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_elenco
- ordina_elenco
- ricerca_parola


ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------
Digitare il nome del file di input: testo.txt
E' stato caricato un elenco di 30 parole
Le parole caricate sono le seguenti: Bruxelles
avverte
la
Italia
sul
fronte
della
emergenza
rifiuti
Seguiamo
molto
da
vicino
la
situazione
in
Campania
e
nei
prossimi
giorni
valuteremo
se
prendere
nuove
decisioni
e
adottare
nuove
misure
Elenco ordinato: e
e
la
da
la
in
se
sul
nei
della
molto
nuove
nuove
Italia
fronte
vicino
giorni
misure
avverte
rifiuti
Seguiamo
Campania
prossimi
prendere
adottare
Bruxelles
emergenza
decisioni
situazione
valuteremo
Digitare una parola da ricercare nell'elenco: italia
La parola ricercata non e' in elenco
Premere un tasto per continuare . . .
--------------- TERMINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA --------------------


Altro:
- per maggiore chiarezza è stato allegato al presente compito il file di input 
  "testo.txt" cui si riferisce il precedente esempio di esecuzione del programma
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM_ELENCO 30
#define MAXDIM_PAROLA 25
#define MAXCAR_NOMEFILE 256

/* funzioni già fornite al candidato */
void visualizza_elenco(char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int num_parole);

/* funzioni la cui implementazione è richiesta al candidato */
int carica_elenco(FILE *f, char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int maxdim);
void ordina_elenco(char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int num_parole);
int ricerca_parola(char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int num_parole, 
                                                                 char parola[]);


int main()
{
    char parole[MAXDIM_ELENCO][MAXDIM_PAROLA];
    char nomefile[MAXCAR_NOMEFILE];
    FILE* file;
    int numero_parole;
    char parola_ricerca[MAXDIM_PAROLA];
    int risultato_ricerca;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    file = fopen(nomefile, "r");
    
    if(file == NULL)
       printf("Errore nel caricamento del file!");
    
    printf("\nE' stato caricato il seguente elenco:\n");
    numero_parole = carica_elenco(file, parole, MAXDIM_ELENCO);
    visualizza_elenco(parole, numero_parole);
    
    fclose(file);   
    
    printf("\nElenco ordinato:\n");
    ordina_elenco(parole, numero_parole);
    visualizza_elenco(parole, numero_parole);
    
    printf("\nInserisci una parola per verificarne la presenza all'interno del testo: ");
    scanf("%s", parola_ricerca);
    risultato_ricerca = ricerca_parola(parole, numero_parole, parola_ricerca);
    
    if(risultato_ricerca == -1)
       printf("La parola non e' presente nell'elenco.\n");
    else
       printf("La parola e' presente in posizione %d.\n", risultato_ricerca+1);
       
    system("PAUSE");
}




/* Il sottoprogramma visualizza a video, una per ogni riga, le parole presenti 
   nell'elenco passato mediante il parametro el ed il cui riempimento è 
   specificato attraverso il parametro num_parole
*/
void visualizza_elenco(char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int num_parole){
   int i;
   
   for(i=0; i<num_parole; i++)
      printf("%s\n", el[i]);
}

/* Il sottoprogramma legge da uno stream di testo aperto in lettura, il cui 
   handler è passato tramite il parametro f, un elenco di parole. Le parole 
   lette dal file vengono caricate nell'array di stringhe passato tramite il 
   parametro el. Il sottoprogramma riceve anche il parametro maxdim che 
   rappresenta la dimensione fisica sulle righe della matrice di caratteri el
   (da intendersi come la dimensione fisica dell'array di stringhe). Il 
   sottoprogramma deve terminare il caricamento al raggiungimento della fine del 
   file o quando sono state caricate maxdim parole.
   Il formato del file di input è conforme a quanto riportato in precedenza 
   nella sezione di ulteriori specifiche.
   La funzione restituisce il numero di parole lette dal file e caricate 
   nell'elenco.
   NB: non si richiede di gestire alcuna situazione di errore.
*/
int carica_elenco(FILE *f, char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int maxdim)
{
    int i = 0;
    
    while(fscanf(f, "%s", &el[i]) != EOF && i < MAXDIM_ELENCO)
    {
          i++;          
    }
    
    return i;
}
                                                          

/* Il sottoprogramma ordina l'elenco di parole ricevuto tramite il parametro el
   e la cui dimensione logica è fornita attraverso num_parole in maniera 
   crescente rispetto alla lunghezza, dove per lunghezza della parola si intende
   il numero di caratteri di cui essa è costituita. 
   L'algoritmo di ordinamento da impiegare è il Bubble Sort.
*/
void ordina_elenco(char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int num_parole)
{
     char temp[MAXDIM_PAROLA];
     int i, k;
     
     for(k = 0; k < num_parole; k++)
     {
        for(i = num_parole-1; i > k; i--)
        {
            if(strlen(el[i]) < strlen(el[i-1]))
            {
               strcpy(temp, el[i]);
               strcpy(el[i], el[i-1]);
               strcpy(el[i-1], temp);              
            }
        }
     }
}
                                                      
/* Il sottoprogramma verifica la presenza della stringa passata attraverso il
   parametro parola all'interno dell'array di stringhe passato attraverso il
   parametro el. Il parametro num_parole contiene la dimensione logica 
   dell'array di parole. Il sottoprogramma restituisce l'indice della posizione
   della parola nell'array se questa è presente altrimenti restituisce -1.
   La funzione deve implementare l'algoritmo di ricerca lineare.
   NB: la funzione effettua una ricerca case-sensitive (ad es. la parola "Ciao" 
   è diversa da "ciao").
*/                                                      
int ricerca_parola(char el[MAXDIM_ELENCO][MAXDIM_PAROLA], int num_parole, char parola[])
{
    int i = 0;
    
    while(i < num_parole && (strcmp(el[i],parola)!=0))
         i++;
    
    if(i < num_parole)
       return i;
    else  
       return -1;
}

