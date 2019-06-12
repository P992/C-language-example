/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 29 GENNAIO 2008
   CORSI DI LAUREA IN INGEGNERIA ELETTRONICA E INGEGNERIA INFORMATICA

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- carica da un file di testo il cui nome è fornito interattivamente dall'utente
  una matrice quadrata di valori realinon negativi; il formato del file di input 
  è specificato nella sezione di ULTERIORI SPECIFICHE 
- inizializza un vettore ponendo nel generico elemento di posizione i il valore
  della somma di tutti gli elementi sulla riga i-esima della matrice 
- visualizza a video affiancati la matrice ed il vettore di cui ai passi 
  precedenti come riportato successivamente nell'esempio di esecuzione 


ULTERIORI SPECIFICHE
- il programma deve essere in grado di gestire vettori di massimo 10 elementi
- il programma deve essere in grado di gestire matrici di massimo 10 righe e 10
  colonne
- il file di input riporta nella prima posizione un valore intero che 
  corrisponde alle dimensioni della matrice quadrata seguito dai corrispondenti
  valori reali
       
COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_matrice
- somma_per_righe
- visualizza_matrice_e_vettore


ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------
Digitare il nome del file di input: matrice.txt
R0:     3.10    4.50    12.10   ->  19.70
R1:     0.00    1.30    2.10    ->  3.40
R2:     4.40    0.20    1.40    ->  6.00
Premere un tasto per continuare . . .
--------------- TERMINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA --------------------

NOTA: per maggiore chiarezza al candidato è fornito il file di input matrice.txt 
      a cui è riferito anche il precedente esempio di esecuzione.
*/


#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 10
#define MAXCAR_NOMEFILE 256

/* funzioni la cui implementazione è richiesta al candidato */
int carica_matrice(char nomefile[], double matrice[][MAXDIM], int *dim_logica);
void somma_per_righe(double matrice[][MAXDIM], int dim_logica, 
                                                        double vettore_somme[]);
void visualizza_matrice_e_vettore(double matrice[][MAXDIM], int dim_logica, 
                                                        double vettore_somme[]);



int main()
{
    char filename[MAXCAR_NOMEFILE];
    double matr[MAXDIM][MAXDIM];
    double vettore[MAXDIM];
    int dimensione;
    int carica;
    int i, j;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    carica = carica_matrice(filename, matr, &dimensione);
    if(carica == 1)
       printf("Errore nel caricamento del file!\n");
    else if(carica == 2)
       printf("Errore! La dimensione e' maggiore di quella supportata.\n");
    else if(carica == 3)
       printf("Errore! La matrice non puo' contenere valori negativi!\n");
    else if(carica == 4)
       printf("Errore! Il numero degli elementi presenti nel file e' insufficiente.\n");
    else if(carica == 0)
       printf("Caricamento effettuato.\n");
    
    somma_per_righe(matr, dimensione, vettore);
    printf("Matrice e somma degli elementi i-esimi:\n");
    visualizza_matrice_e_vettore(matr, dimensione, vettore);
    
    printf("\n");
    
    system("PAUSE");
}


/* La funzione carica dal file di testo il cui nome è passato attraverso il 
   parametro nomefile un matrice quadrata di valori reali non negativi. I valori 
   letti vengono utilizzati per inizializzare il parametro matrice; la funzione 
   legge dal file di testo anche la dimensione della matrice quadrata (numero di 
   righe e di colonne) inizializzando il parametro dim_logica. La funzione 
   restituisce 0 nel caso in cui il caricamento vada a buon fine oppure 
   restituisce i seguenti codici di errore nei seguenti casi:
   1 -> impossibile aprire il file
   2 -> valore della dimensione della matrice esterno all'intervallo [0,MAXDIM]
   3 -> presenza di valori negativi
   4 -> dati incompleti (non ci sono suffienti valori nel file per inizializzare
        la matrice)
   NB: Dettagli sul formato del file di input sono fornite nella sezione 
   precedente di ULTERIORI SPECIFICHE
*/
int carica_matrice(char nomefile[], double matrice[][MAXDIM], int *dim_logica)
{
    FILE* f;
    int elementi = 0;
    int i, j;
    int dim;
    
    f = fopen(nomefile, "r");
    if(f == NULL){
       return 1;}
       
    fscanf(f, "%d", dim_logica);
    
    if(*dim_logica <=0 || *dim_logica > MAXDIM){
       return 2;}
    
    for(i = 0; i < *dim_logica; i++)
    {
        for(j = 0; j < *dim_logica; j++)
        {
           fscanf(f, "%lf", &matrice[i][j]);
           elementi++;
           
           if(matrice[i][j] < 0.0)
              return 3;
        }
    }
    
    dim = *dim_logica;
    
    if(elementi < (dim*dim)){
       return 4;}

    return 0;
}
                                                          

/* Il sottoprogramma inizializza vettore_somme ponendo nel generico elemento di 
   posizione i il valore della somma di tutti gli elementi sulla riga i-esima di
   matrice. Il parametro dim_logica contiene la dimensione logica su righe e 
   colonne della matrice (e ovviamente anche di vettore_somme).
*/
void somma_per_righe(double matrice[][MAXDIM], int dim_logica, 
                                                        double vettore_somme[])
{
    int somma;
    int i, j;
    
    for(i = 0; i < dim_logica; i++)
    {
       vettore_somme[i] = 0.0; 
       for(j = 0; j < dim_logica; j++)
       {
           vettore_somme[i] = vettore_somme[i] + matrice[i][j];
       }
    }
}        

/* Il sottoprogramma visualizza a video il contenuto dei parametri matrice e 
   vettore_somme le cui dimensioni logiche (righe e colonne per la matrice) sono
   specificate attraverso il parametro dim_logica.
   La visualizzazione deve essere effettuata come indicato nell'esempio di 
   esecuzione precedentemente dettagliato.
*/                                                      
void visualizza_matrice_e_vettore(double matrice[][MAXDIM], int dim_logica, 
                                                        double vettore_somme[])
{
     int i, j;
     
     for(i = 0; i < dim_logica; i++)
     {
         for(j = 0; j < dim_logica; j++)
         {
             printf("%lf ", matrice[i][j]);
         }
         printf("----> %lf\n", vettore_somme[i]); 
     }
}

