/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 10 luglio 2007
   
Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di aprire un file di testo contenente una matrice di numeri
  reali; il nome del file è specificato dall'utente interattivamente; il formato 
  del file di input è dettagliato più in avanti nella sezione "ULTERIORI 
  SPECIFICHE";
- carica in memoria la matrice presente nel file di testo e visualizza a 
  video un messaggio di conferma dell'avvenuto caricamento altrimenti visualizza 
  un messaggio di errore; in caso di errore il programma termina;
- visualizza a video la matrice caricata da file;
- calcola e successivamente visualizza a video i valori minimo e massimo 
  presenti nella matrice.
  
ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire matrici la cui dimensione massima
  è 10 x 10
- Il file di input contiene nelle prime due posizioni due valori interi R,C che 
  rappresentano rispettivamente il numero di righe R e il numero di colonne C 
  della matrice; successivamente sono riportati tutti i valori della matrice
- la visualizzazione della matrice deve prevedere la stampa delle intestazioni 
  di riga e colonna ed i valori devono essere visualizzati con una sola cifra
  decimale (si veda l'esempio riportato più in avanti).


COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_matrice
- visualizza_matrice
- minmax_matrice

Per maggiore chiarezza al candidato è fornito il file di input di esempio 
"matrice.txt".

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!

------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------

Digitare il nome del file di input: matrice.txt
E' stata caricata una matrice di 3 righe e 4 colonne

          0     1     2     3
    0   2.1   4.1  -0.2  91.2
    1  23.1  34.3  -1.9   3.1
    2   9.1  34.1   0.1   5.3
Il valore minimo presente nella matrice e': -1.900000
Il valore massimo presente nella matrice e': 91.220000
Premere un tasto per continuare . . .

----------------  FINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA ---------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 10

int carica_matrice(char nf[], double m[MAXDIM][MAXDIM], int *r, int *c);
void minmax_matrice(double m[MAXDIM][MAXDIM], int r, int c, double *min, double *max);
void visualizza_matrice(double m[MAXDIM][MAXDIM], int r, int c);

int main()
{
    char nomefile[20];
    int carica;
    double matrice[MAXDIM][MAXDIM];
    int righe, colonne;
    double minim, maxim;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    carica = carica_matrice(nomefile, matrice, &righe, &colonne);
    if(carica == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;       
    }
    else if(carica == 1)
       printf("Caricamento avvenuto correttamente.\n\n");
       
    printf("E' stata caricata una matrice di %d righe e %d colonne:\n", righe, colonne);
    visualizza_matrice(matrice, righe, colonne);
    printf("\n");
    
    minmax_matrice(matrice, righe, colonne, &minim, &maxim);
    printf("Il valore minimo presente nella matrice e' %.2lf\n", minim);
    printf("Il valore massimo presente nella matrice e' %.2lf\n", maxim);
    printf("\n");
    
    system("PAUSE");
}


/* La funzione riceve in ingresso una stringa con il nome del file da cui 
   caricare la matrice. La funzione restituisce un intero che è pari ad 1 nel 
   caso in cui il caricamento sia andato a buon fine, altrimenti restituisce 0. 
   Il file di input contiene nelle prime due posizioni due valori interi che 
   rappresentano rispettivamente il numero di righe e il numero di colonne della 
   matrice; successivamente sono riportati tutti i valori della matrice.
   La funzione inizializza il parametro m con i valori della matrice letti da
   file; inoltre modifica anche i parametri r e c con il numero di righe e 
   colonne della matrice anch'essi letti da file. 
   La funzione presuppone che il file di input sia ben formato e quindi tutte le 
   informazioni siano riportate in maniera corretta.                          */
int carica_matrice(char nf[], double m[MAXDIM][MAXDIM], int *r, int *c)
{
    FILE* f;
    int riga, colonna;
    int i, j;
    
    f = fopen(nf, "r");
    if(f == NULL)
       return 0;
    
    fscanf(f, "%d%d", &riga, &colonna);
    
    for(i = 0; i < riga; i++)
    {
        for(j = 0; j < colonna; j++)
            fscanf(f, "%lf", &m[i][j]);  
    }
           
    fclose(f);
    
    *r = riga;
    *c = colonna;
    
    return 1;
}


/* La funzione riceve come parametri una matrice di double m, il relativo 
   riempimento sulle righe r e sulle colonne m. Calcola i valori minimo e 
   massimo presenti nella matrice e li restituisce attraverso i parametri di
   output min e max                                                           */
void minmax_matrice(double m[MAXDIM][MAXDIM], int r, int c, double *min, double *max)
{
     double minimo, massimo;
     int i, j;
     
     minimo = massimo = m[0][0];
     for(i = 0; i < r; i++)
     {
        for(j = 0; j < c; j++)
        {
            if(m[i][j] < minimo)
               minimo = m[i][j];  
            else if(m[i][j] > massimo)
               massimo = m[i][j];
        }   
     }
     
     *min = minimo;
     *max = massimo;
}


/* La funzione visualizza a video il contenuto della matrice di reali passata
   attraverso il parametro m, con il relativo riempimento per righe r e per 
   colonne c. La visualizzazione della matrice deve prevedere la stampa delle 
   intestazioni di riga e colonna ed i valori devono essere visualizzati con una 
   sola cifra decimale (si veda l'esempio riportato in precedenza)            */
void visualizza_matrice(double m[MAXDIM][MAXDIM], int r, int c)
{
     int i, j;
     
     printf("\t");
     for(j = 0; j < c; j++) 
         printf("%4d\t", j);
     
     printf("\n");    
     for(i = 0; i < r; i++)
     {
         printf("%d\t", i);
         for(j = 0; j < c; j++)
         {
             printf("%4.1lf\t", m[i][j]);   
         }
         printf("\n");
     }   
} 
