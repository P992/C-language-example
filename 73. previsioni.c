/*
Prova 3 di Fondamenti di Informatica
Corsi di Laurea in Ingegneria Elettronica e Ingegneria Informatica

Un sistema di previsioni meteorologiche riceve i dati da un motore di calcolo che
ipotizza per una settimana i dati relativi a:
- Temperatura massima
- Temperatura minima
- Umidità
- Pressione.

Questi dati vengono forniti in un file "previsioni.txt".
Occorre caricare il contenuto del file in una matrice di 7 righe e 4 colonne.
In modo che sulla riga 0 ci sono i dati di domenica, sulla 1 quelli di lunedì
e così via fino alla riga 6 in cui ci sono i dati di sabato.
Stampare a video, incolonnati giorno per giorno, i dati caricati.

Determinare il giorno con maggiore escursione termica ovvero quello in cui la 
differenza tra la temperatura massima e la minima sia maggiore.

Gli aumenti di pressione da un giorno all'altro determinano miglioramenti del clima.
Le diminuzioni di pressione da un giorno all'altro determinano peggioramenti del clima.
Ad eccezione del primo giorno, la domenica, determinare i giorni in cui il clima 
peggiora e i giorni in cui il clima migliora.

ESEMPIO DI ESECUZIONE:
Previsioni Meteorologiche - Software di analisi dei dati
Digita il nome del file contenente i dati da caricare:previsioni.txt
Giorno          T.Max   T.Min   Press.  Umid.
Domenica        19.1    12.3    1000.1  64.1
Lunedi'         19.6    12.4    1002.1  64.3
Martedi'        19.3    11.5    1010.5  65.9
Mercoledi'      20.1    13.7    1020.1  67.6
Giovedi'        21.6    15.1    1200.1  64.3
Venerdi'        19.9    14.2    998.1   70.3
Sabato          15.0    12.1    944.1   87.3
La maggiore escursione termica si avra' Martedi' con 7.8 gradi
Lunedi'  il clima migliora
Martedi' il clima migliora
Mercoledi' il clima migliora
Giovedi' il clima migliora
Venerdi' il clima peggiora
Sabato   il clima peggiora
Press any key to continue . . .

L'allievo/a, dopo aver analizzato il codice fornito, completi le funzioni
mancanti, SENZA MODIFICARE IL CODICE FORNITO.
Il file previsioni.txt fornito contiene i dati dell'esempio e puo' essere
usato per verificare la correttezza del programma sviluppato. 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXNOME 64
#define N 7
#define M 4

int LeggiDatiDaFile(float d[N][M], char filename[]);
void StampaDatiLetti(int num,float d[N][M],char giorni[7][11]);
int CalcolaEscursioneMassima(int num,float d[N][M], float *escmax);
void analisiPressione(int num,float d[N][M],char giorni[7][11]);


int main()
{
    int righe, giorno_max;
    float escursione_massima;
    float tabella[N][M];
    char nomefile[MAXNOME];
    char giorni[7][11] = {"Domenica", "Lunedi' ", "Martedi'", "Mercoledi'", "Giovedi'", "Venerdi'", "Sabato  "};
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    righe = LeggiDatiDaFile(tabella, nomefile);
    if(righe == 0)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;
    }
    
    printf("\nIl file contiene la seguente tabella:\n");
    StampaDatiLetti(righe, tabella, giorni);
    
    giorno_max = CalcolaEscursioneMassima(righe, tabella, &escursione_massima);
    printf("\nLa maggiore escursione termica si avra' %s con %.2f gradi.\n", giorni[giorno_max], escursione_massima);
    
    printf("\nSituazione generale:\n");
    analisiPressione(righe, tabella, giorni);
    
    system("PAUSE");
}

/* Legge i dati da file e li carica nella matrice di N righe e M colonne.
Restituisce al main il  numero degli elementi letti, oppure 0 in caso di errore.
Si consideri che ogni riga ha M dati, ma non si conosce a priori il numero di
righe da leggere */
int LeggiDatiDaFile(float d[N][M], char filename[])
{
    FILE* f;
    int i;
    int j;
    
    f = fopen(filename, "r");
    if(f == NULL)
       return 0;
    
    i = 0;
    
    while(fscanf(f, "%f", &d[i][0]) != EOF)
    {
          for(j = 1; j < M; j++){
             fscanf(f, "%f", &d[i][j]);
          }
          
          i++;                   
    }
       
    return i;
}

/* Stampa a video riga per riga il giorno e i relativi dati caricati di temperatura max e min, umidita' e
pressione */
void StampaDatiLetti(int num,float d[N][M],char giorni[7][11])
{
    int i, j;
    
    printf("\nGiorni\tT.Max.\tT.Min.\tPress.\tUmid.\n");
    for(i = 0; i < N; i++)
    {
       printf("%s\t", giorni[i]);
       for(j = 0; j < M; j++)
       {
           printf("%.2f\t", d[i][j]);
       }
       printf("\n");       
    }
}

/* Trova il giorno con escursione termica maggiore, ovvero con differenza tra 
temperatura massima e temperatura minima piu' alto, la conserva nella variabile
puntata da *escmax e restituisce al main l'indice della riga corrispondente 
alla escursione massima. */
int CalcolaEscursioneMassima(int num,float d[N][M], float *escmax)
{
    int giorno;
    float escursione;
    int i;
    int ind_max = 0;
    
    *escmax = d[0][0] - d[0][1];
    
    for(i = 1; i < N; i++)
    {
        escursione = d[i][0] - d[i][1];
        if(escursione > *escmax)
        { 
           *escmax = escursione;
           ind_max = i;
        }
    }
        
    return ind_max;
}

/* Analizza le variazioni di pressione e segnala peggioramenti e miglioramenti, escludendo
la domenica e analizzando le variazioni di pressione rispetto al giorno precedente */
void analisiPressione(int num,float d[N][M],char giorni[7][11])
{
     float pressione;
     int i;
     
     for(i = 0; i < N-1; i++)
     {
         if(d[i][2] > d[i+1][2])
            printf("%s il clima peggiora.\n", giorni[i+1]);
         else
            printf("%s il clima migliora.\n", giorni[i+1]);
     }
}
