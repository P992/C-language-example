/*
Prova 2 di Fondamenti di Informatica
Corsi di Laurea in Ingegneria Elettronica e Ingegneria Informatica

I nominativi e i rispettivi voti di uno scritto di Diritto Privato 
sono stati salvati sul file "voti.txt".
Per poter visualizzare i risultati agli studenti, occorre caricare dal file 
tutti i dati e stamparli a video.
Ogni riga del file contiene: Cognome Nome e Voto.
I cognomi vengono caricati in una matrice di caratteri (tenendo conto che sono
costituiti sempre da unica parola e non da più parole separate da spazi).
I nomi vengono caricati in una matrice di caratteri (tenendo conto che sono
costituiti sempre da unica parola e non da più parole separate da spazi).
I voti vengono caricati in un vettore di interi.

Nella battitura pero' ci sono stati degli errori, per cui occorre correggerli.
In particolare occorre:
- Rendere maiuscole tutte le lettere iniziali di cognome e nome.
- Controllare se ci sono vocali ripetute, segnalare dove sono e eliminare la ripetizione.

Inoltre, per evidenziare i piu' meritevoli, occorre far diventare
completamente in maiuscolo i cognomi e i nomi di chi ha avuto 30. 
L'elenco modificato dovra' essere stampato a video.
Calcolare e stampare infine la media tra tutti i voti in elenco.

ESEMPIO DI ESECUZIONE:
RISULTATI DELLO SCRITTO DI DIRITTO PRIVATO
Digita il nome del file contenente i dati da caricare: voti.txt
ERRORE in Paoolo: due vocali ripetute in posizione 2.
ERRORE in Luuca: due vocali ripetute in posizione 1.
ERRORE in Pariide: due vocali ripetute in posizione 3.

Cognome Nome    Voto
Rossi   Mario   27
Verdi   Giacomo 23
PINZI   ARTURO  30
Corsi   Paolo   27
Bianchi Marco   18
Azzurro Stefano 25
GATTO   PIETRO  30
Gesta   Andrea  26
Giovani Luca    24
Vecchi  Paride  22

La media dei voti caricati e' 25.2
Press any key to continue . . .

L'allievo/a, dopo aver analizzato il codice fornito, completi le funzioni
mancanti, SENZA MODIFICARE IL CODICE FORNITO.
Il file elenco.txt fornito contiene i dati dell'esempio e puo' essere
usato per verificare la correttezza del programma sviluppato. 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXNOME 64
#define N 10
#define M 25

int LeggiDatiDaFile(char cognomi[N][M], char nomi[N][M], int voti[N], char filename[]);
void StampaDatiLetti(int num, char cognomi[N][M], char nomi[N][M], int voti[N]);
void CorreggiIniziale(char parola[M]);
void CorreggiVocaliRipetute(char parola[M]);
void TuttoMaiuscolo(char parola[M]);
float CalcolaVotoMedio(int num, int v[N]);

int main()
{
    char nomefile[N];
    char names[N][M];
    char surnames[N][M];
    int num_gente, marks[N];
    float media;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    num_gente = LeggiDatiDaFile(surnames, names, marks, nomefile);
    
    StampaDatiLetti(num_gente, surnames, names, marks);
    
    media = CalcolaVotoMedio(num_gente, marks);
    printf("\nLa media dei voti caricati e' %.1f.\n", media);
    system("PAUSE");
}

/* Carica i dati da file e carica cognomi, nomi e voti nei rispettivi array 
non conoscendo a priori il numero di candidati presenti nel file e restituisce
al main il numero di candidati presenti oppure 0 in caso di errore */
int LeggiDatiDaFile(char cognomi[N][M], char nomi[N][M], int voti[N], char filename[])
{
    FILE* f;
    int numero = 0;
    int i = 0;
    int j;
    
    f = fopen(filename, "r");
    if(f == NULL)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    while(fscanf(f, "%s %s %d", &cognomi[i], &nomi[i], &voti[i]) != EOF)
    {
                    
        if(cognomi[i][0] >= 'a' && cognomi[i][0] <= 'z')
           CorreggiIniziale(cognomi[i]);
        if(nomi[i][0] >= 'a' && nomi[i][0] <= 'z')
           CorreggiIniziale(nomi[i]);
        
        CorreggiVocaliRipetute(cognomi[i]);
        CorreggiVocaliRipetute(nomi[i]);
        
        if(voti[i] == 30)
        {
           TuttoMaiuscolo(cognomi[i]);
           TuttoMaiuscolo(nomi[i]);
        }
           
        i++;
        numero++;
    }
    
    return numero;
}

/* Stampa l'elenco dei dati presenti nelle matrici cognomi, nomi e nel vettore voti */
void StampaDatiLetti(int num, char cognomi[N][M], char nomi[N][M], int voti[N])
{
    int i;
    
    printf("\nCognome\tNome\tVoto\n");
    for(i = 0; i < num; i++)
        printf("%s\t%s\t%d\n", cognomi[i], nomi[i], voti[i]);
        printf("\n");
}

/* Se l'iniziale e' minuscola, la fa diventare maiuscola */
void CorreggiIniziale(char parola[M])
{
     parola[0] = parola[0] - 'a' + 'A';
}

/* Scorre la parola fino al carattere di fine stringa e se trova due vocali ripetute (maiuscole e/o minuscole)
stampa un messaggio all'utente che visualizza la parola e la posizione dell'errore e quindi corregge l'errore
eliminando la ripetizione */
void CorreggiVocaliRipetute(char parola[M])
{
     int i, j;
     char temp;
     
     for(j = 0; j < strlen(parola); j++)
        if(parola[j] == 'a' || parola[j] == 'e' || parola[j] == 'i' || parola[j] == 'o' || parola[j] == 'u')
        {
          if(parola[j] == parola[j+1])
          {
             printf("Errore in %s: due vocali ripetute in posizione %d.\n", parola, j+1);
             for(i = j; i < strlen(parola); i++)
                 parola[i] = parola[i+1];
          }
        }
}

/* Fino al carattere di fine stringa, rende maiuscoli tutti i caratteri minuscoli */
void TuttoMaiuscolo(char parola[M])
{
     int i = 1;
     
     while(parola[i] != '\0')
     {  
           parola[i] = parola[i] - 'a' + 'A';
           i++;
     }
}

/* Calcola la media su v e la restituisce al main */
float CalcolaVotoMedio(int num, int v[N])
{
      int i;
      float somma = 0.0;
      float med;
            
      for(i = 0; i < num; i++)
          somma = somma + v[i];

      med = somma/num;
      
      return med;
}
