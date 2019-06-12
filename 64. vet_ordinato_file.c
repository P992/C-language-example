/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 18 FEBBRAIO 2008
   CORSI DI LAUREA IN INGEGNERIA ELETTRONICA E INGEGNERIA INFORMATICA

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- inizializza due vettori di interi chiedendo all'utente di fornire 
  interattivamente sia la dimensione che i valori dei due vettori; il programma
  verifica anche che i valori selezionati dall'utente per i due vettori siano
  compatibili con le dimensioni fisiche dei due vettori;
- visualizza i vettori caricati al punto precedente;  
- ordina i due vettori in ordine decrescente impiegando l'algoritmo del 
  selection sort
- visualizza i vettori ordinati al punto precedente;  
- salva in un file di testo il cui nome è fornito interattivamente dall'utente
  i valori risultanti dalla fusione ordinata dei suddetti vettori. (NB: per 
  fusione ordinata si intende il processo che consente di generare a partire da
  due vettore ordinati un terzo vettore derivante dall'unione dei due vettori ed
  anch'esso ordinato)

ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire vettori con dimensione fisica non
  superiore a 100
- 

COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_vettore
- ordina_vettore
- salva_vettore_fusione

Per maggiore chiarezza al candidato sono forniti i file di input di esempio 
"v1.txt" e "v2.txt".

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------
Inizializzazione vettore #1
Digitare la dimensione logica [0,100]: -1
Digitare la dimensione logica [0,100]: 101
Digitare la dimensione logica [0,100]: 5
Digitare l'elemento 0 del vettore: 10
Digitare l'elemento 1 del vettore: 3
Digitare l'elemento 2 del vettore: 9
Digitare l'elemento 3 del vettore: 6
Digitare l'elemento 4 del vettore: 8
Inizializzazione vettore #2
Digitare la dimensione logica [0,100]: 4
Digitare l'elemento 0 del vettore: -4
Digitare l'elemento 0 del vettore: 4
Digitare l'elemento 1 del vettore: 12
Digitare l'elemento 2 del vettore: 16
Digitare l'elemento 3 del vettore: 1

Vettore #1: 10 3 9 6 8
Vettore #2: 4 12 16 1
Vettore #1 ordinato: 10 9 8 6 3
Vettore #2 ordinato: 16 12 4 1
Digitare il nome del file di output: f.txt
Salvataggio effettuato correttamente
Premere un tasto per continuare . . .
--------------- TERMINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA --------------------

NOTA: con riferimento all'esempio precedente il contenuto del file f.txt sarà
      quello di seguito riportato:
             
16 12 10 9 8 6 4 3 1 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 100
#define MAXCAR 30

/* funzioni già fornite al candidato */
void visualizza_vettore(int v[], int dim_logica);

/* funzioni la cui implementazione è richiesta al candidato */
void carica_vettore(int vet[], int dim_logica);
void ordina_vettore(int vet[], int dim_logica);
int salva_vettore_fusione(char nomefile[], int vet1[], int d1, int vet2[], 
                                                                        int d2);
int cerca_max(int v[], int inizio, int fine);

int main()
{
    int vettore1[MAXDIM];
    int vettore2[MAXDIM];
    int dim1, dim2;
    char filename[MAXCAR];
    int ritorno;
    
    do{
    printf("Inserisci la dimensione del primo vettore: ");
    scanf("%d", &dim1);
    }while(dim1 <= 0 || dim1 > MAXDIM);
    
    carica_vettore(vettore1, dim1);
    printf("Hai ottenuto il seguente vettore:\n");
    visualizza_vettore(vettore1, dim1);
    
    do{
    printf("\nInserisci la dimensione del secondo vettore: ");
    scanf("%d", &dim2);
    }while(dim2 <= 0 || dim2 > MAXDIM);
    
    carica_vettore(vettore2, dim2);
    printf("Hai ottenuto il seguente vettore:\n");
    visualizza_vettore(vettore1, dim1);
    
    ordina_vettore(vettore1, dim1);
    printf("\nPrimo vettore ordinato:\n");
    visualizza_vettore(vettore1, dim1);
    
    ordina_vettore(vettore2, dim2);
    printf("\nSecondo vettore ordinato:\n");
    visualizza_vettore(vettore2, dim2);
    
    printf("\nInserisci il nome del file in cui vuoi salvare il nuovo vettore: ");
    scanf("%s", filename);
    ritorno = salva_vettore_fusione(filename, vettore1, dim1, vettore2, dim2);
    if(ritorno == -1)
       printf("Salvataggio effettuato correttamente!\n");
    else
       printf("Errore nel salvataggio.\n");
       
    printf("\n");
    
    system("PAUSE");
}


/* Il sottoprogramma visualizza a video separati da un carattere di tabulazione
   tutti gli elementi dell'array passato attraverso il parametro v e la cui
   dimensione logica è passata attraverso il parametro dim_logica
*/
void visualizza_vettore(int vet[], int dim_logica){
   int i;
   
   for(i=0; i<dim_logica; i++)
      printf("%d ", vet[i]);
}

/* Il sottoprogramma inizializza il vettore passato attraverso il parametro vet
   con degli elementi non negativi forniti interattivamente dall'utente. Il 
   numero di elementi che l'utente deve fornire è specificato attraverso il 
   parametro dim_logica. Nel caso l'utente digiti un valore negativo il 
   sottoprogramma non considera il valore digitato.
*/
void carica_vettore(int vet[], int dim_logica)
{
     int i;
     
     for(i = 0; i < dim_logica; i++)
     {
         printf("Inserisci l'elemento di indice %d: ", i);
         scanf("%d", &vet[i]);  
     }
}


/* Il sottoprogramma ordina gli elementi presenti nell'array v la cui dimensione
   logica è specificata attraverso il parametro dim_logica. Il criterio di 
   ordinamento è decrescente. 
   Il sottoprogramma implementa l'algoritmo di ordinamento per selezione
*/
void ordina_vettore(int vet[], int dim_logica)
{
     int i, j;
     int temp;
     int indice_max;
            
     for(i = 0; i < dim_logica; i++)
     {
         indice_max = cerca_max(vet, i, dim_logica); 
         temp = vet[i];
         vet[i] = vet[indice_max];
         vet[indice_max] = temp;
     }
}

int cerca_max(int v[], int inizio, int fine)
{
    int i;
    int ind_max = inizio;
    
    for(i = inizio+1; i < fine; i++)
    {
        if(v[ind_max] < v[i])
           ind_max = i;
    }
    
    return ind_max;
}
              

/* Il sottoprogramma salva in un file di testo il cui nome è fornito 
   interattivamente dall'utente i valori risultanti dalla fusione ordinata dei 
   due vettori passati attraverso i parametri vet1 e vet2 le cui dimensioni 
   logiche sono specificate tramite i parametri d1 e d2, rispettivamente.
   Per fusione ordinata si intende il processo che consente di generare a 
   partire da due vettori ordinati un terzo vettore derivante dall'unione dei 
   due vettori ed anch'esso ordinato.
   Il sottoprogramma restituisce 1 se il salvataggio va a buon fine, 0 
   altrimenti. 
   NB: il sottoprogramma deve effettuare la fusione salvando direttamente i
   valori sul file senza allocare un vettore di appoggio.
   SUGGERIMENTO: effettuare un ciclo durante il quale viene salvato il massimo
   tra l'elemento corrente dei due vettori ed incrementando di uno l'indice 
   della posizione corrente del vettore da cui si è prelevato l'elemento; il 
   ciclo termina quando sono stati esauriti gli elementi di almeno uno dei due 
   vettori; al termine del ciclo si salvano sul file gli elementi restanti 
   dell'altro vettore.
*/
int salva_vettore_fusione(char nomefile[], int vet1[], int d1, int vet2[], 
                                                                        int d2)
{
    FILE* f;
    int dimensione_unione;
    int indice_min = 0;
    int temp;
    int i, j;
   
    f = fopen(nomefile, "w");
    if(f == NULL)
       return 0;
    
    dimensione_unione = d1 + d2;
    
    for(i = 0; i < dimensione_unione; i++)
    {
        vet1[d1+i] = vet2[i];
        vet1[dimensione_unione] = '\0';
    }
       
    ordina_vettore(vet1, dimensione_unione);
    
    fprintf(f, "Vettore ordinato:\n");
    for(i = 0; i < dimensione_unione; i++)
        fprintf(f, "%d ", vet1[i]);
    
    fclose(f);
    
    return -1;
}
