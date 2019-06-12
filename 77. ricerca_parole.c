/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 6 giugno 2007
   
Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di aprire un file di testo contenente un elenco ordinato di 
  parole; il nome del file è fornito interattivamente dall'utente; il formato 
  del file di input è dettagliato più in avanti nella sezione "ULTERIORI 
  SPECIFICHE";
- carica in memoria tutte le parole presenti nel file di testo e visualizza a 
  video un messaggio di conferma dell'avvenuto caricamento altrimenti visualizza 
  un messaggio di errore; in caso di errore il programma termina;
- visualizza il numero di parole caricate nonchè l'elenco delle parole;
- consente all'utente di effettuare la ricerca di una parola nell'elenco e di 
  visualizzare il risultato della ricerca.
  
ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire al massimo 500 parole
- Il numero massimo di caratteri di cui è composta una parola è pari a 25
- Formato del file di input:
  Il file di input contiene una sequenza di parole; il file è strutturato come 
  di seguito riportato
  - su ogni riga del file è riportata una parola
  - le parole sono riportate in ordine alfabetico crescente; 
  - le parole sono costituite solo da caratteri alfabetici minuscoli;
    
COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_parole
- visualizza_elenco_parole
- ricerca_parola

NB: La funzione ricerca_parola deve implementare l'algoritmo di ricerca 
    dicotomica.

Per maggiore chiarezza al candidato è fornito il file di input di esempio 
"parole.txt".

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!

------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------
Digitare il nome del file di input: parole.txt

Sono state caricate le seguenti 15 parole
abbaino
arrivederci
cane
ciao
cattolicesimo
femmina
ferrari
luca
milano
musulmano
neonato
pilota
prova
religione
salute

Digitare una parola da ricercare nell'elenco: prova

La parola prova e' presente nell'elenco

Premere un tasto per continuare . . .
----------------  FINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA ---------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 500
#define MAXCAR 25

int carica_parole(char nomefile[], char elenco_parole[MAXNUM][MAXCAR]);
int ricerca_parola(char elenco_parole[MAXNUM][MAXCAR], int n, 
                                                           char parola[MAXCAR]);
void visualizza_elenco_parole(char elenco_parole[MAXNUM][MAXCAR], int n);

int main()
{
    char filename[MAXCAR], elenco[MAXNUM][MAXCAR], word[MAXCAR];
    int num_parole, posizione;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    num_parole = carica_parole(filename, elenco);
    if(num_parole == 0)
    {
       printf("Errore nell'apertura del file!\n");
       system("PAUSE");
       return -1;           
    }
    else
       printf("Caricamento effettuato correttamente!\n");
       
    visualizza_elenco_parole(elenco, num_parole);
    
    printf("Digitare una parola da ricercare nell'elenco: ");
    scanf("%s", word);
    posizione = ricerca_parola(elenco, num_parole, word);
    if(posizione == -1)
       printf("La parola non e' presente in elenco.\n");          
    else 
       printf("\nLa parola e' presente in elenco in posizione %d.\n", posizione+1);
       
    system("PAUSE");
}


/* La funzione riceve in ingresso una stringa con il nome del file da cui 
   caricare l'elenco di parole. La funzione restituisce un intero che è pari a 0 
   nel caso il file sia vuoto o se non riesce ad aprire il file, altrimenti è un 
   valore positivo pari al numero n di parole caricate. Inoltre, la funzione 
   inizializza il parametro elenco_parole con le parole lette dal file. 
   La funzione carica le prime 500 parole presenti nel file; se il file contiene 
   meno di 500 parole la funzione si arresta al raggiungimento della fine del
   file.                                                                      */
int carica_parole(char nomefile[], char elenco_parole[MAXNUM][MAXCAR])
{
    FILE* f;
    int i = 0;
    
    f = fopen(nomefile, "r");
    if(f == NULL)
       return 0;
       
    while(i < MAXNUM && (fscanf(f, "%s", &elenco_parole[i]) != EOF))
          i++;
       
    fclose(f);
    
    return i;
}

/* La funzione implementa l'algoritmo di ricerca dicotomica: verifica se la 
   stringa parola passata come parametro è presente nell'array di stringhe 
   elenco_parole il cui riempimento è fornito attraverso il parametro n. La 
   funzione restituisce -1 se la ricerca ha esito negativo altrimenti 
   restituisce la posizione dell'elemento nell'array.                         */
int ricerca_parola(char elenco_parole[MAXNUM][MAXCAR], int n, 
                                                           char parola[MAXCAR])
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        if(strcmp(elenco_parole[i], parola) == 0)
           return i;  
    }
    
    return -1;
}

/* La funzione visualizza le parole presenti nel parametro elenco_parole una
   accanto all'altra separate solo dal carattere di spazio. Il parametro n è il 
   riempimento dell'array di stringhe elenco_parole.                          */
void visualizza_elenco_parole(char elenco_parole[MAXNUM][MAXCAR], int n)
{
     int i;
     
     printf("\nSono state caricate le seguenti %d parole:\n", n);
     for(i = 0; i < n; i++)
         printf("%s\n", elenco_parole[i]);
         
     printf("\n");
} 
