/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 18 settembre 2007

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di aprire due file di testo i cui nomi sono forniti 
  interattivamente dall'utente da tastiera; in ogni file sono riportati i valori 
  di un vettore di interi;
- carica i dati da tali file in due array;
- visualizza a video i dati caricati da file secondo il seguente formato; su 
  ogni riga viene visualizzata la seguente stringa:
             i+1   vettore1[i]    vettore2[i]    +/-
  dove i è un valore progressivo che va da 0 fino alla dimensione logica - 1
  dei due array; inoltre in ultima posizione sulla riga viene visualizzato il
  carattere '+' se vettore1[i] e vettore2[i] sono uguali altrimenti viene 
  visualizzato il carattere '-';
- calcola e visualizza a video la percentuale di sovrapposizione tra i due 
  array; tale valore è calcolato moltiplicando per 100 la frazione di valori 
  uguali tra i due vettori in posizione omologa.       
  

ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire vettori con dimensione fisica non
  superiore a 100
- Il programma deve terminare fornendo opportuna segnalazione di errore in uno  
  dei seguenti casi:
    - fallimento nella apertura di un file
    - file di input vuoto
    - i due vettori caricati da file hanno diversa dimensione logica

COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_dati
- visualizza_dati_affiancati
- calcola_percentuale_sovrapposizione

Per maggiore chiarezza al candidato sono forniti i file di input di esempio 
"v1.txt" e "v2.txt".

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA ------------------------
Digitare il nome del primo file da cui caricare i dati: v1.txt
Sono stati caricati 20 valori dal file v1.txt

Digitare il nome del secondo file da cui caricare i dati: v2.txt
Sono stati caricati 20 valori dal file v2.txt


Visualizzazione affiancata del contenuto dei due vettori
Progressivo  Vettore1     Vettore2  Uguale(+)/Diverso(-)
===========  ========     ========  ====================
    1            4           44              -
    2           -1           -1              +
    3            6            6              +
    4            9            9              +
    5           23           23              +
    6          -45          -45              +
    7           32          452              -
    8            1            1              +
    9          335          335              +
   10         -901         -901              +
   11            3            3              +
   12           56          536              -
   13            8            8              +
   14           32           32              +
   15           54          564              -
   16           43           43              +
   17          -44          -44              +
   18          102          102              +
   19          338          338              +
   20            0          120              -
I due vettori hanno il 75.0% dei valori in comune

Premere un tasto per continuare . . .*/

#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 100
#define MAXCAR 30

int carica_dati(FILE *f, int vet[], int maxnum);
void visualizza_dati_affiancati(int vet1[], int vet2[], int riemp);
double calcola_percentuale_sovrapposizione(int vet1[], int vet2[], int riemp);

int main()
{
    char primofile[MAXCAR], secondofile[MAXCAR];
    FILE* file1;
    FILE* file2;
    int dim1, dim2;
    int vettore[MAXDIM], vettore2[MAXDIM];
    double perc;
    
    printf("Inserisci il nome del primo file da aprire: ");
    scanf("%s", primofile);
    
    file1 = fopen(primofile, "r");
    if(file1 == NULL)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
   
    dim1 = carica_dati(file1, vettore, MAXDIM);
    fclose(file1);
    printf("Sono stati caricati %d valori dal primo file.\n", dim1);    
    
    printf("\nInserisci il nome del secondo file da aprire: ");
    scanf("%s", secondofile);

    file2 = fopen(secondofile, "r");
    if(file2 == NULL)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    } 
    dim2 = carica_dati(file2, vettore2, MAXDIM);
    fclose(file2);
    printf("Sono stati caricati %d valori dal secondo file.\n", dim2);
    
    visualizza_dati_affiancati(vettore, vettore2, dim1);
    
    perc = calcola_percentuale_sovrapposizione(vettore, vettore2, dim1);
    printf("\nI due vettori hanno il %.1lf%% dei valori in comune.\n", perc);
    system("PAUSE");
}



/* La funzione riceve in input l'handler f di un file di testo aperto in 
   lettura che contiene una sequenza di numeri interi separati dal carattere di
   new-line. La funzione carica nel parametro vet i valori che man mano legge
   dal file fino al raggiungimento della fine del file o della dimensione fisica
   dell'array vet passata attraverso il parametro maxnum. La funzione 
   restituisce il numero di valori letti dal file che costituisce anche la nuova
   dimensione logica dell'array vet.
*/
int carica_dati(FILE *f, int vet[], int maxnum)
{
    int i = 0;
    
    while((fscanf(f, "%d", &vet[i]) != EOF) && i < maxnum)
         i++;
         
    return i;
}



/* La funzione riceve due array attraverso i parametri vet1 e vet2 e la relativa
   dimensione logica, uguale per entrambi gli array, attraverso il parametro 
   riemp. La funzione visualizza i valori di entrambi gli array rispettando il 
   seguente formato: su ogni riga viene visualizzata la seguente stringa:
             i+1   vet1[i]    vet2[i]    +/-
  dove i è un valore progressivo che va da 0 fino alla dimensione logica - 1
  dei due array; inoltre in ultima posizione sulla riga viene visualizzato il
  carattere '+' se vet1[i] e vet2[i] sono uguali altrimenti viene 
  visualizzato il carattere '-'.
*/
void visualizza_dati_affiancati(int vet1[], int vet2[], int riemp)
{
     int i;
     
     printf("\n\nVisualizzazione affiancata dei valori dei due vettori\n\n");
     printf("Progressivo\tVettore1\tVettore2\tUguale(+)/Diverso(-)\n");
     printf("===========\t========\t========\t====================\n");
     
     for(i = 0; i < riemp; i++)
     {
         printf("%11d\t%8d\t%8d\t", i+1, vet1[i], vet2[i]);
         if(vet1[i] == vet2[i])
            printf("\t+");
         else
            printf("\t-");
            
         printf("\n");
     }
}



/* La funzione riceve due array attraverso i parametri vet1 e vet2 e la relativa
   dimensione logica, uguale per entrambi gli array, attraverso il parametro 
   riemp. 
   La funzione calcola la percentuale di sovrapposizione tra i due array; tale 
   valore è calcolato moltiplicando per 100 la frazione di valori uguali tra i 
   due vettori in posizione omologa.
*/
double calcola_percentuale_sovrapposizione(int vet1[], int vet2[], int riemp)
{
       int uguali = 0;
       double percentuale;
       int i;
       
       for(i = 0; i < riemp; i++)
       {
           if(vet1[i] == vet2[i])
              uguali++;
       }
       
       percentuale = (uguali*100)/riemp;
       
       return percentuale;
}
