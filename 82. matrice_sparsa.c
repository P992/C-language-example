/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 18 settembre 2007

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di fornire interattivamente una matrice quadrata di interi;
  all'utente viene richiesto di fornire la dimensione della matrice e tutti e 
  soli i valori non nulli presenti nella matrice; i restanti valori della 
  matrice sono posti a 0;
- visualizza a video la matrice in forma di una immagine; in particolare in 
  corrispondenza di ogni valore nullo viene visualizzato il carattere '-',
  mentre per ogni valore non nullo viene visualizzato il carattere '+';
- salva la matrice su file come una matrice sparsa; in pratica vengono salvati
  solo i valori non nulli. Per ogni valore da salvare nel file viene salvata
  una terna di valori costituita nell'ordine dall'indice di riga, dall'indice di 
  colonna e dal valore dell'elemento della matrice.

ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire matrici quadrate con dimensione 
  fisica non superiore a 25x25

COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_matrice_quadrata
- salva_matrice_quadrata_sparsa
- visualizza_immagine_da_matrice

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------

Digitare la dimensione della matrice quadrata [0,25]: 15
Digitare quanti valori non nulli devono essere inseriti: 3
Inserimento di un valore della matrice non nullo
Digitare il numero di riga [0,14]: 1
Digitare il numero di colonna [0,14]: 2
Digitare il valore dell'elemento di posizione 1,2 della matrice: 5
Inserimento di un valore della matrice non nullo
Digitare il numero di riga [0,14]: 4
Digitare il numero di colonna [0,14]: 4
Digitare il valore dell'elemento di posizione 4,4 della matrice: 10
Inserimento di un valore della matrice non nullo
Digitare il numero di riga [0,14]: 0
Digitare il numero di colonna [0,14]: 8
Digitare il valore dell'elemento di posizione 0,8 della matrice: -5
--------+------
--+------------
---------------
---------------
----+----------
---------------
---------------
---------------
---------------
---------------
---------------
---------------
---------------
---------------
---------------
Digitare il nome del file su cui salvare la matrice sparsa: out.txt
Premere un tasto per continuare . . .

--------------- TERMINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA --------------------

NOTA:
Il contenuto del file out.txt generato al termine della esecuzione riportata 
nell'esempio precedente sarà il seguente:
0 8 -5
1 2 5
4 4 10

*/


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 25
#define MAXCAR 30

/* funzioni già fornite al candidato */
int valore_in_intervallo(int min, int max, int valore);

/* funzioni la cui implementazione è richiesta al candidato */
int carica_matrice_quadrata(int m[MAXSIZE][MAXSIZE]);
void salva_matrice_quadrata_sparsa(FILE *f, int m[MAXSIZE][MAXSIZE], int riemp);
void visualizza_immagine_da_matrice(int m[MAXSIZE][MAXSIZE], int riemp);


int main()
{
    int matrice[MAXSIZE][MAXSIZE];
    int dimensione;
    char nomefile[MAXCAR];
    FILE* file;
    
    dimensione = carica_matrice_quadrata(matrice);
    if(dimensione == -1)
    { 
       printf("Errore! Hai inserito una dimensione non supportata.\n");
       system("PAUSE");
       return -1;
    }  
    
    visualizza_immagine_da_matrice(matrice, dimensione);
    
    printf("Digitare il nome del file su cui si desidera salvare la matrice sparsa: ");
    scanf("%s", nomefile);
    
    file = fopen(nomefile, "w");
    salva_matrice_quadrata_sparsa(file, matrice, dimensione);
    fclose(file);
    
    system("PAUSE");
}



/* La funzione restituisce 1 se val è nell'intervallo [min, max], 0 altrimenti.
   La funzione non controlla che sia verificata la condizione min<=max.
*/
int valore_in_intervallo(int min, int max, int val){
    if((val>=min)&&(val<=max))
       return 1;
    else
       return 0;
}



/* La funzione carica una matrice quadrata di valori forniti interattivamente 
   dall'utente. All'utente viene richiesto di fornire nell'ordine:
      - la dimensione (numero di righe e di colonne) della matrice
      - il numero di elementi non nulli che presenti nella matrice
      - gli elementi non nulli della matrice; tali valori sono forniti mediante
        una terna costituita dall'indice di riga, dall'indice di colonna e dal
        relativo valore dell'elemento
   La funzione verifica che i valori digitati dall'utente per la dimensione 
   della matrice, per l'indice di riga e per l'indice di colonna siano
   all'interno degli intervalli consentiti. (NB: Per effettuare tali controlli
   si usi la funzione valore_in_intervallo di cui è già fornito il codice)
   I restanti valori della matrice sono posti a 0.
   La funzione restituisce la dimensione della matrice.
*/
int carica_matrice_quadrata(int m[MAXSIZE][MAXSIZE])
{
    int dim, num;
    int controllo;
    int riga, colonna, k, i, j;
    
    printf("Inserisci le dimensioni della matrice [0,25]: ");
    scanf("%d", &dim);
    controllo = valore_in_intervallo(0, 25, dim);
    if(controllo == 0)
       return -1;
    
    for(i = 0; i < dim; i++)
    {
        for(j = 0; j < dim; j++)
           m[i][j] = 0;
    }
    
    printf("Quanti elementi non nulli vuoi inserire nella matrice? ");
    scanf("%d", &num);
    
    for(k = 0; k < num; k++)
    {
        printf("Digitare il numero di riga [0,%d]: ", dim-1);
        scanf("%d", &riga);
        controllo = valore_in_intervallo(0, dim-1, riga);
        if(controllo == 0)
           return -1;
        printf("Digitare il numero di colonna [0,%d]: ", dim-1);
        scanf("%d", &colonna);
        controllo = valore_in_intervallo(0, dim-1, colonna);
        if(controllo == 0)
           return -1;
              
        printf("Digitare il valore di indice[%d,%d]: ", riga, colonna);
        scanf("%d", &m[riga][colonna]);
    }
    
    return dim;
}



/* La funzione salva una la matrice quadrata m di dimensione riemp nel file 
   aperto in scrittura ed il cui handler è passato attraverso il parametro f.
   La funzione salva su file solo i valori della matrice non nulli. Nel file 
   viene creata una riga per ogni valore da salvare; ogni riga contiene la terna
   di valori costituita nell'ordine dall'indice di riga, dall'indice di colonna 
   e dal valore dell'elemento.
*/
void salva_matrice_quadrata_sparsa(FILE *f, int m[MAXSIZE][MAXSIZE], int riemp)
{
     int i, j;
     
     fprintf(f, "Riga\tColonna\tValore\n");
     for(i = 0; i < riemp; i++)
     {
         for(j = 0; j < riemp; j++)
             if(m[i][j] != 0)
                fprintf(f, "%4d\t%7d\t%6d\n", i, j, m[i][j]);
     }
}



/* La funzione visualizza a video la matrice quadrata m di dimensione riemp
   come una immagine in cui i valori nulli sono rappresentati con il carattere 
   '-' e i valori non nulli con '+'.
*/
void visualizza_immagine_da_matrice(int m[MAXSIZE][MAXSIZE], int riemp)
{
     int i, j;
     
     printf("\n\nHai ottenuto la seguente matrice:\n\n");
     
     for(i = 0; i < riemp; i++)
     {   
        for(j = 0; j < riemp; j++)
        {
            if(m[i][j] == 0)
               printf("-");
            else
               printf("+");
        }
        printf("\n");
     }  
}

