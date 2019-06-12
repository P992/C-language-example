/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DELL'8 GENNAIO 2008
   CORSI DI LAUREA IN INGEGNERIA ELETTRONICA E INGEGNERIA INFORMATICA

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- carica da un file di testo il cui nome è fornito interattivamente dall'utente
  una matrice quadrata di valori reali; il formato del file di testo di input
  è specificato nella sezione di ULTERIORI SPECIFICHE
- nel caso in cui il caricamento non vada a buon fine il programma fornisce a 
  video una segnalazione di errore (le situazioni di errore da gestire sono
  specificate più avanti)
- visualizza a video la matrice caricata
- calcola il minimo ed il massimo tra gli elementi della matrice
- visualizza a video i due valori calcolati al passo precedente
- a seconda della scelta operata dall'utente interattivamente somma o sottrae a 
  tutti gli elementi della matrice la media tra il minimo ed il massimo della 
  matrice calcolati precedentemente; all'utente deve essere anche data la 
  possibilità di non effettuare alcuna delle precedenti operazioni di somma o
  sottrazione
- visualizza a video la matrice modificata al passo precedente, ovvero fornisce 
  un messaggio per indicare che la matrice non è stata modificata.
  

ULTERIORI SPECIFICHE
- Le informazioni nel file di testo impiegato come input per il programma sono 
  riportate in base alla seguente sintassi: 
            dimensione_matrice sequenza_valori
  dove:
       - dimensione_matrice è un valore intero che rappresenta il numero di 
         righe e di colonne della matrice quadrata
       - sequenza_valori è una sequenza di dimensione_matrice*dimensione_matrice
         valori reali che rappresentano gli elementi della matrice secondo una 
         scansione crescente per righe e crescente per colonne (quindi m[0][0],
         m[0][1], ..., m[0][dimensione_matrice-1], ...,
         m[dimensione_matrice-1][0], ..., 
         m[dimensione_matrice-1][dimensione_matrice-1]    
- Il programma deve essere in grado di gestire matrici quadrate con dimensione 
  fisica non superiore a 10x10
- Le condizioni di errore da individuare e gestire durante il caricamento da 
  file sono le seguenti:
     - apertura del file non riuscita
     - la dimensione della matrice presente nel file è maggiore minore/uguale di 
       zero o maggiore della dimensione massima gestibile dal programma
     - il numero di elementi presenti nel file è minore di 
       dimensione_matrice*dimensione_matrice (il significato di 
       dimensione_matrice è quello indicato al primo punto della presente 
       sezione)

  

COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_matrice_quadrata
- calcola_minmax_matrice
- somma_valore_matrice


ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


------------------  ESEMPIO 1 DI ESECUZIONE DEL PROGRAMMA ----------------------
Digitare il nome del file contenente la matrice quadrata di reali: dati1.txt
Caricamento di una matrice di dimensione 3
La matrice caricata da file e'
-3.90  4.62  2.78
 4.81 -0.93 -3.38
-0.67  1.29 -2.31
Il valore minimo della matrice e': -3.90
Il valore massimo della matrice e': 4.81
Aggiornamento della matrice
1. Somma il valore medio tra min e max a tutti gli elementi della matrice
2. Sottrai il valore medio tra min e max a tutti gli elementi della matrice
Il valore medio tra min e max e': 0.45
Selezionare 1, 2 per effettuare l'operazione altro valore per non modificare la
matrice: 1
La matrice modificata e'
-3.45  5.08  3.23
 5.26 -0.48 -2.92
-0.22  1.74 -1.86
Premere un tasto per continuare . . .
--------------- TERMINE ESEMPIO 1 DI ESECUZIONE DEL PROGRAMMA ------------------



------------------  ESEMPIO 2 DI ESECUZIONE DEL PROGRAMMA ----------------------
Digitare il nome del file contenente la matrice quadrata di reali: dati2.txt
Errore! File incompleto
Premere un tasto per continuare . . .
--------------- TERMINE ESEMPIO 2 DI ESECUZIONE DEL PROGRAMMA ------------------



------------------  ESEMPIO 3 DI ESECUZIONE DEL PROGRAMMA ----------------------
Digitare il nome del file contenente la matrice quadrata di reali: dati3.txt
Errore! Valore errato per la dimensione della matrice
Premere un tasto per continuare . . .
--------------- TERMINE ESEMPIO 3 DI ESECUZIONE DEL PROGRAMMA ------------------


Altro:
- per maggiore chiarezza sono stati allegati al presente compito i seguenti 
  file di input cui si riferiscono i precedenti esempi di esecuzione del 
  programma:
  - "dati1.txt" file corretto 
  - "dati2.txt" file con dati incompleti
  - "dati3.txt" file con matrice con dimensioni superiori alla dimensione 
                massima gestibile dal programma (10x10)
*/


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define MAXCAR_NOMEFILE 256

/* funzioni già fornite al candidato */
void visualizza_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col);

/* funzioni la cui implementazione è richiesta al candidato */
int carica_matrice_quadrata(FILE *f, double m[MAXSIZE][MAXSIZE], int maxdim);
                                                          
void calcola_minmax_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col, 
                                                      double *min, double *max);
                                                      
void somma_valore_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col, 
                                                double valore, int operazione);

int main()
{
    char nomefile[MAXCAR_NOMEFILE];
    FILE* file;
    double matrice[MAXSIZE][MAXSIZE];
    int dimensione, scelta;
    double minimo, massimo, media;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    file = fopen(nomefile, "r");
    if(file == NULL)
       printf("Errore nel caricamento del file!\n");
    
    dimensione = carica_matrice_quadrata(file, matrice, MAXSIZE);
    if(dimensione == -2)
       printf("Errore! La dimensione specificata per la matrice e' minore di 0 o maggiore di quella supportata!\n");
    else if(dimensione == -3)
       printf("Errore! Il file contiene un numero di elementi insufficiente!\n");
    else    
       printf("\nIl file contiene la seguente matrice quadrata di dimensione %d:\n", dimensione);
       visualizza_matrice(matrice, dimensione, dimensione);
    
    fclose(file);
    
    calcola_minmax_matrice(matrice, dimensione, dimensione, &minimo, &massimo);
    printf("\nIl valore minimo e' %lf.\n", minimo);
    printf("Il valore massimo e' %lf.\n", massimo);
    
    media = (minimo + massimo)/2;
    printf("Il valor medio e' %lf.\n", media);
    
    printf("\nQuale operazione vuoi effettuare?\n");
    printf("1. Somma il valore medio tra min e max a tutti gli elementi della matrice.\n");
    printf("2. Sottrai il valore medio tra min e max a tutti gli elementi della matrice.\n");
    printf("Inserisci 1 per sommare, 2 per sottrarre o un altro valore per non modificare la matrice: ");
    scanf("%d", &scelta);
    
    somma_valore_matrice(matrice, dimensione, dimensione, media, scelta);
    if((scelta == 1) || (scelta == 2))
    {
       printf("\nMatrice modificata:\n");
       visualizza_matrice(matrice, dimensione, dimensione);
    }
    else
       printf("La matrice non e' stata modificata!\n");
    
    system("PAUSE");
}



/* Il sottoprogramma visualizza a video gli elementi della matrice passata 
   mediante il parametro m e le cui dimensioni per righe e per colonne sono
   specificate attraverso i parametri rig e col
*/
void visualizza_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col){
     int i, j;
     for(i=0; i<rig; i++){
        for(j=0; j<col; j++)
            printf("%5.2lf ",m[i][j]);
        printf("\n");
     }
}

/* La funzione legge da uno stream di testo aperto in lettura e ricevuto tramite
   il parametro f una matrice quadrata di valori reali. I valori letti dal file
   vengono caricati nella matrice passata tramite il parametro m. La funzione
   riceve anche il parametro maxdim che rappresenta la dimensione massima della 
   matrice. Il formato del file di input è conforme a quanto riportato in 
   precedenza nella sezione di ulteriori specifiche.
   La funzione restituisce:
   - -1 se la dimensione della matrice è maggiore di maxdim o minore/uguale di
     zero;
   - -2 se il numero di elementi presenti nel file è minore di 
     dimensione_matrice*dimensione_matrice (il significato di dimensione_matrice 
     è indicato nella sezione di ulteriori specifiche)
   - un intero compreso tra 1 e maxdim che rappresenta la dimensione della 
     matrice caricata se il caricamento va a buon fine
   NB: non si richiede di gestire altre situazioni di errore oltre quelle 
   precedentemente indicate
*/
int carica_matrice_quadrata(FILE *f, double m[MAXSIZE][MAXSIZE], int maxdim)
{
    int dim;
    int i, j, elementi;
    
    i = 0;
    
    elementi = 0;
    
    fscanf(f, "%d", &dim);
    
    if(dim <= 0 || dim > maxdim)
       return -2;
    
    while(i < dim && (!feof(f)))
    {
        j = 0;
        while(j < dim && (!feof(f)))
        {
            fscanf(f, "%lf", &m[i][j]);
            j++;
            elementi++;
        }
        i++;
    }
    
    if(elementi < (dim*dim))
       return -3;
        
    return dim;
}

/* Il sottoprogramma calcola il valore minimo ed il valore massimo tra gli 
   elementi della matrice passata tramite il parametro m e le cui dimensioni in
   termini di numero di righe e di colonne sono specificate mediante i parametri
   rig e col. I valori minimo e massimo sono restituiti attraverso i parametri 
   di output min e max. 
*/
void calcola_minmax_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col, 
                                                      double *min, double *max)
{ 
     int i, j;
     
     *min = m[0][0];
     *max = m[0][0];

     for(i = 0; i < rig; i++)
     {
         for(j = 0; j < col; j++)
         {
             if(m[i][j] < *min)
               *min = m[i][j];
             else if(m[i][j] > *max)
               *max = m[i][j]; 
         }
     }
}

/* Il sottoprogramma modifica ogni valore della matrice passata attraverso il
   parametro m sommando o sottraendo il reale passato tramite il parametro 
   valore. Il sottoprogramma effettua la somma se il parametro operazione 
   corrisponde al valore intero 1 ovvero effettua la differenza nel caso in cui 
   operazione sia uguale al valore intero 2. Nel caso in cui venga passato un 
   valore diverso il sottoprogramma non modifica la matrice.
   I parametri rig e col rappresentano le dimensioni della matrice in termini di
   righe e di colonne.
*/                                                      
void somma_valore_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col, 
                                                double valore, int operazione)
{
     int i, j;
     
     for(i = 0; i < rig; i++)
     {
         for(j = 0; j < col; j++)
         {
             if(operazione == 1)
                m[i][j] = m[i][j] + valore;
             else if(operazione == 2)
                m[i][j] = m[i][j] - valore;
         }  
     }
}
