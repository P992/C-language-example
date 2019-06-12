/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 10 luglio 2007
   
Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di aprire un file di testo in cui sono riportati i valori di 
  una successione incognita f(n) per diversi valori di n. In particolare, su ogni 
  riga è riportata una coppia di numeri n e f(n) separati da uno spazio o un 
  carattere di tabulazione;
- carica in memoria tutti i dati presenti nel file di testo e visualizza a video
  un messaggio di conferma dell'avvenuto caricamento altrimenti visualizza un
  messaggio di errore; in caso di errore il programma termina;
- visualizza a video i valori caricati come riportato più in avanti nell'esempio;
- richiede all'utente di selezionare un valore intero n_utente compreso 
  nell'intervallo [n_min,n_max], dove n_min e n_max sono rispettivamente il 
  minimo ed il massimo tra i valori n caricati dal file; si richiede che il
  programma controlli che il valore selezionato dall'utente sia nell'intervallo
  definito e richieda all'utente di selezionare nuovamente il valore finchè non
  fornisca il valore corretto;
- calcola il valore della successione f in corrispondenza del valore di n 
  selezionato dall'utente. In particolare, nel caso in cui n è presente 
  nell'array asc, la funzione restituisce il valore corrispondente di f. 
  Se n non è presente, detto nprev e nsucc i valori immediatamente precedente e 
  successivo ad n la funzione restituisce la media tra f(nprev) e f(nsucc).
  
ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire al massimo 100 coppie di valori
  n,f(n)
- Il programma è in grado di calcolare il valore della successione f(n) solo per 
  valori di n interi
- Formato del file di input: ogni riga del file di input contiene una coppia di 
  valori n,f(n); i due valori sono separati da un carattere di spazio o di 
  tabulazione. Inoltre, le coppie di valori n,f(n) sono riportate nel file in
  ordine crescente rispetto ad n.
      
COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_valori
- calcola_f
- visualizza_valori

Per maggiore chiarezza al candidato è fornito il file di input di esempio 
"valori.txt".

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!

------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------
Digitare il nome del file di input: valori.txt

Sono state caricate le seguenti coppie di valori
    n    f(n)
    0   0.1982
    1   0.8415
    3   0.1411
    6   -0.2794
    8   0.0012
   11   1.0981
   14   1.9088
   19   2.8765
   23   2.9800
   30   4.0198
Selezionare il valore di n rispetto a cui calcolare f(n)
Digitare un valore intero compreso nell'intervallo [0,30]: 33
Valore di n esterno all'intervallo consentito


Selezionare il valore di n rispetto a cui calcolare f(n)
Digitare un valore intero compreso nell'intervallo [0,30]: 7
Il valore di f(7) e' -0.1391
Premere un tasto per continuare . . .
----------------  FINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA ---------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVAL 100

int carica_dati(char nf[], int ascisse[MAXVAL], float ordinate[MAXVAL]);
float calcola_f(int a, int ascisse[MAXVAL], float ordinate[MAXVAL], int r);                                                              
void visualizza_valori(int ascisse[MAXVAL], float ordinate[MAXVAL], int r);

int main()
{
    char nomefile[20];
    int num, controimmagini[MAXVAL], valore;
    float immagini[MAXVAL], imago;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    num = carica_dati(nomefile, controimmagini, immagini);
    if(num == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    visualizza_valori(controimmagini, immagini, num);
    
    while(valore < 0 || valore > 30)
    {
         printf("Selezionare il valore di n rispetto a cui calcolare f(n): ");
         scanf("%d", &valore);
    }
    
    imago = calcola_f(valore, controimmagini, immagini, num);
    printf("Il valore di f(%d) e' %.4f.\n", valore, imago);
    system("PAUSE");
}


/* La funzione riceve in ingresso la stringa nf con il nome del file da cui 
   caricare i dati relativi ad una serie di coppie di valori n,y in cui y 
   rappresenta il valore f(n) di una successione f in n. La funzione restituisce 
   un intero che è pari a 0 nel caso il file sia vuoto o se non riesce ad aprire 
   il file, altrimenti è un valore positivo pari al numero k di coppie di valori 
   caricati. I valori n vengono caricati nell'array asc, mentre i relativi 
   valori f(n) vengono caricati nell'array ord. 
   Le coppie di valori n,f(n) sono riportate nel file di input in ordine 
   crescente rispetto ad n. Inoltre, la funzione presuppone che il file di input
   sia ben formato e quindi tutte le coppie n,f(n) siano riportate in maniera
   corretta.                                                                  */
int carica_dati(char nf[], int ascisse[MAXVAL], float ordinate[MAXVAL])
{
    FILE* f;
    int i = 0;
    
    f = fopen(nf, "r");
    if(f == NULL)
       return 0;
    
    while(fscanf(f, "%d%f", &ascisse[i], &ordinate[i]) != EOF)
          i++; 
    
    fclose(f);
    
    return i;
}


/* La funzione calcola il valore della successione f in corrispondenza del
   valore passato attraverso il parametro n. In particolare, nel caso in cui n è 
   presente nell'array ascisse in posizione k, la funzione restituisce il valore 
   ordinate[k]. Se n non è presente, detto nprev e nsucc i valori immediatamente 
   precedente e successivo ad n nell'array ascisse la funzione restituisce la 
   media tra ordinate(nprev) e ordinate(nsucc).                               */
float calcola_f(int n, int ascisse[MAXVAL], float ordinate[MAXVAL], int r)
{
   int i, j;
   float imm = 0.0;
   int nprev, nsucc;
   
   for(i = 0; i < r; i++)
   {
       if(ascisse[i] == n)
          imm = ordinate[i];
   }
   
   if(imm == 0.0)
   {
      for(j = 0; j < r; j++)
      {
          if(ascisse[j] == n-1)
             nprev = j;
      }
      for(j = 0; j < r; j++)
      {
          if(ascisse[j] == n+1)
             nsucc = j;
      }
      imm = (ordinate[nprev]+ordinate[nsucc])/2;
   }
   return imm;                                                   
}


/* La funzione riceve come parametri due array, uno di interi, l'altro di float
   ed un intero che rappresenta il riempimento di entrambi gli array. La 
   funzione visualizza a video, una per ogni riga, le coppie di valori 
   ascisse[i] e ordinate[i] per i = 0, ..., r-1. Inoltre, sulla prima riga 
   vengono riportate le intestazioni delle due colonne e poi le coppie come 
   nell'esempio seguente:
       n    f(n)
       0   0.1982
       1   0.8415
     ...   ...                                                                */
void visualizza_valori(int ascisse[MAXVAL], float ordinate[MAXVAL], int r)
{
     int i;
     
     printf("n\tf(n)\n");
     for(i = 0; i < r; i++)
         printf("%d\t%9f\n", ascisse[i], ordinate[i]);
} 
