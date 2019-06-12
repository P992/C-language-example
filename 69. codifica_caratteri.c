/*******************************************************************************
*   Esame scritto di Fondamenti di Informatica
*   CdL in Ingegneria Elettronica e Ingegneria Informatica
*   Prova del: 9 gennaio 2007
*
*   Al candidato si richiede di implementare un programma che deve eseguire 
*   nell'ordine i seguenti passi:
*   - inizializza una stringa con i caratteri letti da un file di testo il cui
*     nome è fornito dall'utente interattivamente: durante la fase di 
*     caricamento il programma memorizza nella stringa solo i caratteri 
*     alfabetici saltando tutti gli altri caratteri (cifre, separatori, 
*     caratteri accentati, ...) presenti nel file
*   - visualizza a video la stringa caricata dal file;
*   - sostituisce tutti i caratteri maiuscoli nel corrispondente minuscolo
*   - chiede interattivamente all'utente di fornire un numero intero K compreso 
*     tra 1 e 25
*   - sostituisce ogni carattere della stringa precedentemente acquisita con il
*     carattere che occupa K posizioni in avanti nell'alfabeto; si noti che
*     l'alfabeto viene considerato circolare nel senso che dopo la 'z' si 
*     riparte dalla lettera 'a' (ad es. se K = 3, allora 'a' è sostituita con 
*     'd', 'b' è sostituita con 'e', ..., 'y' è sostituita con 'b',
*     'z' è sostituita con 'c');
*   - visualizza a video la stringa modificata; 
*
*   Esempio:
*   Supponendo che il contenuto del file di input sia il seguente:
*
*      Colpo di scena in Iraq. 
*   
*   allora la funzione di caricamento da file dovrà inizializzare la stringa 
*   come segue:
*
*      ColpodiscenainIraq
*
*   quindi dopo la sostituzione dei caratteri maiuscoli in minuscoli:
*
*      colpodiscenainiraq
*
*   supponendo inoltre che l'utente scelga come valore di K = 1 allora la 
*   stringa sarà:
*
*      dpmqpejtdfobjojsbr 
*
*
*   Ulteriori specifiche: 
*   LUNGHEZZA MASSIMA DELLA STRINGA: il programma deve gestire stringe composte
*   da non più di 1000 caratteri.
*
*   Cosa è richiesto al candidato:
*   Si richiede di scrivere un programma completo che esegua quanto 
*   precedentemente richiesto. Inoltre, il programma deve impiegare i seguenti 
*   sottoprogrammi di cui si riportano il prototipo ed una breve descrizione. 
*   Oltre al main, il candidato deve implementare tali sottoprogrammi senza 
*   modificare nè il prototipo, nè la funzionalità.
*
*   int CaricaMessaggioDaFile(char nomefile[], char stringa[], int maxcar);
*      Carica da un file di testo, il cui nome è passato attraverso il parametro
*      "nomefile", una sequenza di maxcar-1 caratteri alfabetici saltando tutti
*      gli altri caratteri (cifre, separatori, caratteri accentati, ...), 
*      arrestandosi prima nel caso in cui sia raggiunta la fine del file. I 
*      caratteri letti vengono memorizzati nel parametro "stringa"; la funzione 
*      termina il parametro "stringa" con il carattere di terminazione '\0'. La 
*      funzione restituisce -1 se il caricamento non è andato a buon fine (nel 
*      caso in cui non riesca ad aprire il file), altrimenti restituisce il 
*      numero di caratteri letti (restituisce 0 nel caso in cui il file sia 
*      vuoto).
*
*   void SostituisciMaiuscole(char stringa[]);
*      Sostituisce tutti i caratteri maiuscoli presenti nel parametro "stringa"
*      con il corrispondente carattere minuscolo
*
*   void CodificaCaratteri(char stringa[], int K);
*     Sostituisce ogni carattere del parametro "stringa" con il carattere 
*     ottenuto traslando il carattere originario di K posizioni in avanti in
*     maniera circolare 
*
*    Altro:
*       - per maggiore chiarezza è stato allegato al presente compito un file di
*         input di esempio ("testo.txt")
*/


#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 100


int CaricaMessaggioDaFile(char nomefile[], char stringa[], int maxcar);
void SostituisciMaiuscole(char stringa[], int dim);
void CodificaCaratteri(char stringa[], int k, int dim);

int main()
{
    char filename[MAXDIM];
    char messaggio[MAXDIM];
    int numero_caratteri, numero;
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    numero_caratteri = CaricaMessaggioDaFile(filename, messaggio, MAXDIM);
    SostituisciMaiuscole(messaggio, numero_caratteri);
    
    printf("Hai ottenuto il seguente testo:\n");
    printf("%s", messaggio);
    
    printf("\n\nInserisci un valore: ");
    scanf("%d", &numero);
    
    CodificaCaratteri(messaggio, numero, numero_caratteri);
    printf("\nHai ottenuto il seguente testo (carattere + valore):\n");
    printf("%s", messaggio);
    
    printf("\n");
    system("PAUSE");
}

int CaricaMessaggioDaFile(char nomefile[], char stringa[], int maxcar)
{
    FILE* f;
    int i = 0;
    
    f = fopen(nomefile, "r");
    if(f == NULL)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return - 1;                 
    }
    
    while(fscanf(f, "%c", &stringa[i]) != EOF && i < maxcar)
    {
          if(stringa[i] >= 'A' && stringa[i] <= 'Z' || stringa[i] >= 'a' && stringa[i] <= 'z')
          i++;
    }
          
    stringa[i] = '\0';
    
    fclose(f);
    
    return i;
}

void SostituisciMaiuscole(char stringa[], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
     {
        if(stringa[i] >= 'A' && stringa[i] <= 'Z')
           stringa[i] = stringa[i] - 'A' + 'a';
     }
}

void CodificaCaratteri(char stringa[], int k, int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
     {
         if((stringa[i] + k) >= 'a' && (stringa[i] + k) <= 'z')
            stringa[i] = stringa[i] + k;
         else
            stringa[i] = 'a' - 1 + k; 
     }
}

