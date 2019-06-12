/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 29 GENNAIO 2008
   CORSI DI LAUREA IN INGEGNERIA ELETTRONICA E INGEGNERIA INFORMATICA

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- carica da tastiera un vettore di valori interi non negativi
- visualizza a video il vettore appena caricato
- ordina il vettore in maniera crescente sulla base della cifra meno 
  significativa del numero (vedi esempio di esecuzione riportato più avanti)
- visualizza a video il vettore appena ordinato
- salva l'array così ordinato in un file il cui nome è fornito dall'utente
  interattivamente; maggiori dettagli sul formato del file sono riportati 
  nella sezione di ULTERIORI SPECIFICHE

ULTERIORI SPECIFICHE
- il programma deve essere in grado di gestire vettori di massimo 100 elementi
- il salvataggio deve essere effettuato su un file di testo rispettando la 
  seguente sintassi:
           NUMERO VALORI: <<dimensione logica>>
           VALORI: <<elenco valori>>
  dove <<dimensione logica>> è la dimensione logica dell'array, mentre 
  <<elenco valori>> è la sequenza di valori presenti nell'array ognuno separato
  dal successivo mediante un carattere di BLANK
- l'esempio  
       
COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_vettore
- ordina_vettore
- salva_vettore


ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------

Caricamento vettore di interi non negativi
Digitare il numero di elementi che intendi inserire: -10
ATTENZIONE!!!
Devi inserire un valore positivo
Digitare il numero di elementi che intendi inserire: 5
Digitare il valore dell'array di indice 0: -5
Digitato un valore negativo
1. Voglio annullare l'operazione di caricamento dell'array
2. Ho digitato un valore scorretto: non considerarlo
Scegliere [1 o 2]: 2
Digitare il valore dell'array di indice 0: 3
Digitare il valore dell'array di indice 1: 5
Digitare il valore dell'array di indice 2: 14
Digitare il valore dell'array di indice 3: 22
Digitare il valore dell'array di indice 4: 31
Caricato vettore di 5 elementi
I valori caricati sono i seguenti: 3    5       14      22      31
I valori ordinati sono i seguenti: 31    22      3       14      5
Digitare il nome del file su cui salvare il vettore: dati.txt
Salvataggio effettuato correttamente
Premere un tasto per continuare . . .

--------------- TERMINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA --------------------

NOTA: con riferimento all'esempio precedente il contenuto del file dati.txt sarà
      quello di seguito riportato:
             
NUMERO VALORI: 5
VALORI: 31 22 3 14 5 

*/


#include <stdio.h>
#include <stdlib.h>
#define DIM_FISICA_ARRAY 100
#define MAXCAR_NOMEFILE 256

/* funzioni già fornite al candidato */
void visualizza_vettore(int v[], int dim_logica);

/* funzioni la cui implementazione è richiesta al candidato */
int carica_vettore(int v[], int dim_logica);
void ordina_vettore(int v[], int dim_logica);
int salva_vettore(char nomefile[], int v[], int dim_logica);


int main()
{
    int vettore[DIM_FISICA_ARRAY];
    int carica, salvataggio;
    int dimensione;
    char filename[MAXCAR_NOMEFILE];
    
    printf("Inserisci la dimensione del vettore: ");
    scanf("%d", &dimensione);
    
    carica = carica_vettore(vettore, dimensione);
    if(carica == 0)
    {
       return -1;
       system("PAUSE");
    }
    else
    {
       printf("Hai ottenuto il seguente vettore:\n");
       visualizza_vettore(vettore, dimensione);
    }
    
    ordina_vettore(vettore, dimensione);
    printf("\nEcco il vettore ordinato:\n");
    visualizza_vettore(vettore, dimensione);
    
    printf("\nInserisci il nome del file in cui salvare il vettore: ");
    scanf("%s", filename);
    
    salvataggio = salva_vettore(filename, vettore, dimensione);
    if(salvataggio == 0)
       printf("Errore nel salvataggio.\n");
    else if(salvataggio == 1)
       printf("Salvataggio effettuato correttamente!\n");
       
    system("PAUSE");
}


/* Il sottoprogramma visualizza a video separati da un carattere di tabulazione
   tutti gli elementi dell'array passato attraverso il parametro v e la cui
   dimensione logica è passata attraverso il parametro dim_logica
*/
void visualizza_vettore(int v[DIM_FISICA_ARRAY], int dim_logica){
   int i;
   
   for(i=0; i<dim_logica; i++)
      printf("%d\t", v[i]);
}


/* La funzione richiede interattivamente all'utente di specificare una sequenza 
   di N valori interi non negativi dove N è specificato attraverso il parametro
   dim_logica. I valori letti vengono inseriti progressivamente nell'array 
   passato attraverso il parametro v. La funzione verifica se il valore di volta
   in volta digitato dall'utente è un intero non negativo: nel caso in cui 
   l'utente selezioni un valore negativo la funzione chiede all'utente se vuole
   annullare l'operazione di inizializzazione dell'array, nel qual caso la 
   funzione termina restituendo il valore 0, oppure se intende continuare 
   nell'inserimento senza però considerare l'ultimo valore (negativo) scelto; in
   tale ultimo caso la funzione termina quando si raggiunge la dimensione logica
   dell'array e la funzione restituisce il valore 1.
*/
int carica_vettore(int v[], int dim_logica)
{
    int i;
    int scelta;
    
    for(i = 0; i < dim_logica; i++)
    {
        printf("Inserisci l'elemento di indice %d: ", i);
        scanf("%d", &v[i]);
        
        if(v[i] < 0)
        {
           printf("Non puoi inserire un valore negativo. Cosa vuoi fare?\n");
           printf("1. Annullare l'operazione\n2. Continuare nell'inserimento senza considerare l'ultimo valore inserito\n");
           scanf("%d", &scelta);
           if(scelta == 1)
              return 0;
           else if(scelta == 2)
           {
                printf("Inserisci l'elemento di indice %d: ", i);
                scanf("%d", &v[i]);
           }
        }
    }
    
    return 1;
}
                                                          

/* Il sottoprogramma ordina gli elementi presenti nell'array v la cui dimensione
   logica è specificata attraverso il parametro dim_logica. Il criterio di 
   ordinamento è decrescente sulla base della cifra meno significativa del 
   numero. Il sottoprogramma implementa l'algoritmo di ordinamento per selezione
*/
void ordina_vettore(int v[], int dim_logica)
{
     int i, j;
     int temp;
     
     for(i = 0; i < dim_logica; i++)
     {
        for(j = dim_logica-1; j > i; j--)
           if(v[j]%10 < v[j-1]%10)
           {
              temp = v[j];
              v[j] = v[j-1];
              v[j-1] = temp;           
           }
     }
}
              

/* La funzione salva sul file il cui nome è passato attraverso il parametro 
   nomefile gli elementi dell'array v con dimensione logica passata mediante il
   parametro dim_logica. La funzione restituisce il valore 1 se il salvataggio
   va a buon fine, altrimenti restituisce 0. Il salvataggio viene effettuato su 
   un file di testo rispettando la seguente sintassi:
           NUMERO VALORI: <<dimensione logica>>
           VALORI: <<elenco valori>>
  dove <<dimensione logica>> è la dimensione logica dell'array, mentre 
  <<elenco valori>> è la sequenza di valori presenti nell'array ognuno separato
  dal successivo mediante un carattere di BLANK
*/                                                      
int salva_vettore(char nomefile[], int v[], int dim_logica)
{
    FILE* f;
    int i;
    
    f = fopen(nomefile, "w");
    if(f == NULL)
       return 0;
    
    fprintf(f, "NUMERO VALORI: %d\n", dim_logica);
    fprintf(f, "VALORI: ");
    for(i = 0; i < dim_logica; i++)
        fprintf(f, "%d ", v[i]);
    
    return 1;    
}

