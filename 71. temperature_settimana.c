/*
Prova di Fondamenti di Informatica
Corsi di Laurea in Ingegneria Elettronica e Ingegneria Informatica

Una centralina di rilevamento meteorologico traccia nell'arco di 
una settimana i dati relativi a:
- Temperatura
- Pressione
- Umidità
- Vento.

Questi dati vengono forniti in un file "dati.txt".
Occorre caricare il contenuto del file in una matrice di 7 righe e 4 colonne.
In modo che sulla riga 0 ci siano i dati di domenica, sulla 1 quelli di lunedì
e così via fino alla riga 6 in cui ci siano i dati di sabato.
Stampare a video, incolonnati giorno per giorno, i dati caricati.

Determinare il giorno più caldo (con la temperatura più alta).
Determinare il giorno più freddo (con la temperatura più bassa).

Determinare la temperatura media.
Determinare la variazione (differenza tra temperatura massima e minima).

ESEMPIO DI ESECUZIONE:
Centralina Meteorologica - Software di analisi dei dati
Digita il nome del file contenente i dati da caricare:dati.txt
Giorno          Temp.   Press.  Umid.   Vento
Domenica        19.1    1000.1  64.1    4.1
Lunedi'         19.6    1002.1  64.3    3.6
Martedi'        19.3    1010.5  65.9    5.2
Mercoledi'      20.1    1020.1  67.6    11.7
Giovedi'        21.6    1200.1  64.3    12.7
Venerdi'        19.9    998.1   70.3    18.2
Sabato          15.0    944.1   87.3    21.9
Il giorno piu' caldo e' stato Giovedi' con 21.6 gradi
Il giorno piu' freddo e' stato Sabato   con 15.0 gradi
Temperatura media sulla settimana = 19.2
Variazione sulla temperatura della settimana = 6.6
Press any key to continue . . .

L'allievo/a, dopo aver analizzato il codice fornito, completi le funzioni
mancanti, SENZA MODIFICARE IL CODICE FORNITO.
Il file dati.txt fornito contiene i dati dell'esempio e puo' essere
usato per verificare la correttezza del programma sviluppato. 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXNOME 64
#define N 7
#define M 4

int LeggiDatiDaFile(float d[N][M], char filename[]);
void StampaDatiLetti(int num, float d[N][M],char giorni[7][11]);

int CalcolaTMassima(int num, float d[N][M], float *tmax);
int CalcolaTMinima(int num, float d[N][M], float *tmin);
float CalcolaTMedia(int num, float d[N][M]);
float CalcolaVariazioneT(float tmax, float tmin);

int main()
{
    char nomefile[MAXNOME];
    char giorni[7][11]={"Dom","Lun","Mar","Mer","Gio","Ven","Sab"};
    float tabella[N][M];
    float med, max, min, variazione;
    int righe;
    int ind_max, ind_min;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
    
    righe = LeggiDatiDaFile(tabella, nomefile);
    StampaDatiLetti(righe, tabella, giorni);
    
    med = CalcolaTMedia(righe, tabella);
    printf("\nIl valore medio della temperatura e' %.2f.\n", med);
    
    ind_max = CalcolaTMassima(righe, tabella, &max);
    printf("\nLa temperatura massima e' stata raggiunta %s ed e' pari a %.2f.\n", giorni[ind_max], max);
    
    ind_min = CalcolaTMinima(righe, tabella, &min);
    printf("\nLa temperatura minima e' stata raggiunta %s ed e' pari a %.2f.\n", giorni[ind_min], min);
    
    variazione = CalcolaVariazioneT(max, min);
    printf("\nVariazione sulla temperatura: %.2f.\n", variazione);
    system("PAUSE");
}

/* Legge i dati da file e li carica nella matrice di N righe e M colonne.
Restituisce al main il numero delle righe lette, oppure 0 in caso di errore.
Si consideri che su ogni riga del file sono presenti M dati, ma non si conosce
a priori il numero di righe. */
int LeggiDatiDaFile(float d[N][M], char filename[])
{
    FILE* f;
    int i, j;
    
    f = fopen(filename, "r");
    if(f == NULL)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;  
    }
    
    i = 0;
    while(fscanf(f, "%f", &d[i][0]) != EOF)
    {
          for(j = 1; j < M; j++)
          {
              fscanf(f, "%f", &d[i][j]);  
          }
          i++;
    }
    
    fclose(f);
    
    return i;
}

/* Stampa a video riga per riga il giorno e i relativi dati caricati di
temperatura, Umidita', pressione e velocita' del vento */
void StampaDatiLetti(int num, float d[N][M],char giorni[7][11])
{
    int i,j;
    printf("Giorno\tTemp.\tPress.\tUmid.\tVento\n");
    for(i=0;i<num;i++)
    {
       printf("%s\t",giorni[i]);
       for(j=0;j<M;j++)
           printf("%.1f\t",d[i][j]);
       printf("\n");
    }    
}

/* Calcola la temperatura media su N valori e la restituisce al main */
float CalcolaTMedia(int num, float d[N][M])
{
    int i;
    float somma = 0;
    float media;
    
    for(i = 0; i < num; i++)
    {
        somma = somma + d[i][0]; 
    }
    
    media = somma/num;
    
    return media;
}

/* Trova il giorno a temperatura massima, la conserva nella variabile puntata da *tmax e
restituisce al main l'indice della riga corrispondente alla temperatura massima. */
int CalcolaTMassima(int num, float d[N][M], float *tmax)
{
    int giorno_max = 0;
    int i;
    
    for(i = 0; i < num-1; i++)
    {
        if(d[i][0] < d[i+1][0])
           giorno_max = i+1;
    }
    
    *tmax = d[giorno_max][0];
    return giorno_max;
}

/* Trova il giorno a temperatura minima, la conserva nella variabile puntata da *tmin e
restituisce al main l'indice della riga corrispondente alla temperatura minima. */
int CalcolaTMinima(int num, float d[N][M], float *tmin)
{
    int giorno_min = 0;
    int i;
    
    for(i = 0; i < num-1; i++)
    {
        if(d[i][0] > d[i+1][0])
           giorno_min = i+1;
    }
    
    *tmin = d[giorno_min][0];
    return giorno_min;
}

/* Calcola la variazione sulla temperatura e la restituisce al main */
float CalcolaVariazioneT(float tmax, float tmin)
{
    int var;
    
    var = tmax - tmin;
    
    return var;
}
