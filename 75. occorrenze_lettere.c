/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 20 febbraio 2007
   
Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- chiede all'utente di aprire un file di testo il cui nome è fornito 
  interattivamente dall'utente e carica in una stringa solo i caratteri 
  alfabetici presenti nel file; durante il caricamento i caratteri alfabetici 
  minuscoli vengono convertiti in maiuscoli;
- visualizza a video i caratteri caricati nella stringa;
- calcola il numero di occorrenze di ogni carattere alfabetico presente nella 
  stringa
- visualizza a video l'istogramma delle occorrenze dei caratteri alfabetici; 
  l'istogramma deve essere visualizzato rispettando le specifiche riportate 
  successivamente nella traccia

Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- CaricaCaratteri
- CalcolaOccorrenze
- VisualizzaIstogramma

ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!

NOTE:
Per maggiore chiarezza al candidato è fornito il file di input di esempio 
"testo.txt" utilizzato anche per l'esempio riportato di seguito.
L'istogramma deve essere visualizzato in orizzontale riportando il carattere 
maiuscolo, un numero che rappresenta il numero di occorrenze seguito da tanti 
caratteri '#' quante sono le occorrenze del carattere nella stringa.
Il programma deve essere in grado di caricare al massimo 200 caratteri.

Esempio.
Di seguito si riporta un esempio di esecuzione del programma.

                  ---> INIZIO ESEMPIO <---
                  
Digitare il nome del file contenente il testo da elaborare: testo.txt
Caricamento avvenuto correttamente.
Sono stati caricati 113 caratteri alfabetici che sono di seguito riportati:
LANOTAALLAVIGILIADELVERTICEATREFRAILPRESIDENTEPALESTINESEABUMAZENILPREMIERISRAEL
IANOOLMERTEILSEGRETARIODISTATOUSA
Questo programma calcola il numero di occorrenze di ogni carattere.
Istogramma delle occorrenze:
A  15 ###############
B   1 #
C   1 #
D   3 ###
E  18 ##################
F   1 #
G   2 ##
H   0
I  14 ##############
J   0
K   0
L  11 ###########
M   3 ###
N   5 #####
O   5 #####
P   3 ###
Q   0
R  10 ##########
S   7 #######
T   9 #########
U   2 ##
V   2 ##
W   0
X   0
Y   0
Z   1 #
Premere un tasto per continuare . . .

                  ---> FINE ESEMPIO <---
*/ 

#include <stdio.h>
#include <stdlib.h>

#define MAX_CARATTERI 200
#define NUM_CARATTERI 26
#define MAX_CAR 20

/* Prototipi delle funzioni da implementare da parte del candidato*/
int CaricaCaratteri(char nomefile[], char stringa[], int dim_fisica);
void CalcolaOccorrenze(char stringa[], int occorrenze[]);
void VisualizzaIstogrammaCaratteriMaiuscoli(int occorrenze[]);
                      
                      
int main()
{
    char filename[MAX_CAR];
    int caratteri;
    char stringa_car[MAX_CARATTERI];
    int vettore_lettere[NUM_CARATTERI];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    caratteri = CaricaCaratteri(filename, stringa_car, MAX_CARATTERI);   
    if(caratteri == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;          
    }
    else
       printf("\nCaricamento avvenuto correttamente.\n");
       
    printf("\nSono stati caricati %d caratteri alfabetici che sono di seguito riportati:\n", caratteri);
    printf("%s", stringa_car);
    printf("\n\n");
    
    CalcolaOccorrenze(stringa_car, vettore_lettere);
    
    printf("*****Questo programma calcola il numero delle occorrenze di ogni carattere*****\n");
    VisualizzaIstogrammaCaratteriMaiuscoli(vettore_lettere);
    
    system("PAUSE");
}


/* La funzione carica dal file di testo il cui nome è passato attraverso il 
   parametro nomefile tutti e soli i caratteri alfabetici. All'atto del 
   caricamento i caratteri alfabetici minuscoli sono convertiti in maiuscolo.
   La funzione restituisce -1 nel caso in cui si dovessero verificare errori di
   accesso al file, altrimenti il numero di caratteri alfabetici letti dal file
   ed inseriti nella stringa. 
   La funzione si interrompe quando è raggiunta la fine del file o quando sono
   stati letti dim_fisica-1 caratteri.                                        */
int CaricaCaratteri(char nomefile[], char stringa[], int dim_fisica)
{
    FILE* f;
    int i = 0;
    
    f = fopen(nomefile, "r");
    if(f == NULL)
       return -1;
    
    while(fscanf(f, "%c", &stringa[i]) != EOF)
    {
          if(stringa[i] >= 'a' && stringa[i] <= 'z'){
             stringa[i] = stringa[i] - 'a' + 'A';
             i++;
          }
          else if(stringa[i] >= 'A' && stringa[i] <= 'Z')
             i++;
    }
    stringa[i] = '\0';
    
    fclose(f);
    
    return i;
}



/* La funzione calcola quante volte ogni singolo carattere alfabetico maiuscolo
   occorre nel parametro stringa. Il numero di occorrenze per il carattere 'A'
   sarà memorizzato in occorrenze[0], 'B' in occorrenze[1], 'C' in 
   occorrenze[2], ..., 'Z' in occorrenze[25].                                 */
void CalcolaOccorrenze(char stringa[], int occorrenze[])
{
   int i, j;
   int num;
   int num2 = 0;
   
   for(j = 'A'; j <= 'Z'; j++)
   {
      i = 0;
      num = 0;
      while(stringa[i] != '\0')
      {
         if(stringa[i] == j)
            num++;
            i++;
      }
      
      occorrenze[num2] = num;
      num2++;
   }
}


/* La funzione visualizza a video l'istogramma delle occorrenze dei caratteri
   alfabetici maiuscoli. Il numero di occorrenze del carattere 'A' è in 
   occorrenze[0], 'B' in occorrenze[1], ..., 'Z' in occorrenze[25]. 
   L'istogramma deve essere visualizzato in orizzontale riportando il carattere 
   maiuscolo, un numero che rappresenta il numero di occorrenze seguito da tanti
   caratteri '#' quante sono le occorrenze del carattere.                     */
void VisualizzaIstogrammaCaratteriMaiuscoli(int occorrenze[])
{
     int i, j;
     char lettera = 'A';
     
     printf("\nIstogramma delle occorrenze:\n\n");
     
     for(i = 0; i < NUM_CARATTERI; i++)
     {
         printf("%c\t %2d\t", lettera, occorrenze[i]);
         for(j = 0; j < occorrenze[i]; j++){
             printf("#");
         }
         lettera++;
         printf("\n");
     }
     
     printf("\n");
}
