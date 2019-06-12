/*  Corso di laurea:    Ingegneria Informatica
*   Esame:              Fondamenti di Informatica 
*   Prova scritta del:  14 luglio 2006
*
*   Si scriva un programma che soddisfi le seguenti specifiche:
*       - carica da un file di testo un elenco di parole; una parola in 
*         questo contesto è definita come una sequenza continua di caratteri del 
*         codice ASCII che siano diversi dai seguenti caratteri separatori: 
*         ' '    ';'    ':'    '.'    ','    '\''     '\n'    '\t'
*       - visualizza a video il numero di parole caricate dal file
*       - costruisce una matrice in cui il valore nella generica posizione di 
*         riga i e colonna j rappresenta il numero di parole presenti 
*         nell'elenco caricato dal file che iniziano con la i+1-esima lettera 
*         dell'alfabeto e hanno una lunghezza di j+1 caratteri; ad esempio, 
*         l'elemento di riga 2 e colonna 3 della matrice dovrà contenere il 
*         numero di parole presenti nell'elenco che iniziano con la lettera 'C' 
*         o 'c' e lunghe 4 caratteri
*       - visualizza a video e salva in un file la matrice; si richiede anche 
*         la visualizzazione e il salvataggio dei nomi delle righe e delle 
*         colonne 
*       - elimina dall'elenco tutte le parole ripetute, lasciandone nell'elenco
*         solo la prima istanza 
*       - ricostruisce la matrice suddetta a partire dall'elenco modificato
*         al passo precedente
*       - visualizza a video e salva in un nuovo file la matrice; si richiede  
*         anche la visualizzazione e il salvataggio dei nomi delle righe e delle 
*         colonne 
*
*   Ulteriori specifiche:  
*       - il file contenente l'elenco riporta sequenze di parole separate da 
*         caratteri separatori; su una linea del file di input possono esser
*         presenti anche più parole; 
*       - la dimensione massima degli elenchi gestiti è pari a 1000; inoltre la
*         massima lunghezza di una parola è di 30 caratteri
*       - oltre al main si scrivano funzioni per effettuare le operazioni di:
*          -> caricamento di un elenco di parole da file
*          -> visualizzazione a video o salvataggio su file dell'elenco 
*          -> costruzione della matrice secondo le specifiche riportate in 
*             precedenza
*          -> eliminazione dall'elenco delle parole ripetute 
*
*    Altro:
*       - per maggiore chiarezza è stato allegato al presente compito un file di
*         input di esempio ("elenco.txt")
*
*    NOTA: l'allievo consideri che per la determinazione del voto della prova  
*          scritta ad ogni sezione del compito saranno attribuiti i seguenti
*          punteggi massimi:
*           4 <- main  
*           6 <- caricamento di un elenco di parole da file
*           4 <- visualizzazione a video o salvataggio su file dell'elenco 
*           6 <- costruzione della matrice secondo le specifiche riportate in 
*                precedenza
*          10 <- eliminazione dall'elenco delle parole ripetute 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 30
#define MAXDIM 100

int carica(char filename[], char elenco[][MAXCAR]);
int elimina(char elenco[][MAXCAR], char elenco2[][MAXCAR], int dim);
void visualizza(char elenco[][MAXCAR], int dim);

int main()
{
    char nomefile[MAXCAR];
    char parole[MAXDIM][MAXCAR], parole2[MAXDIM][MAXCAR];
    int num_parole, num2;
     
    printf("Inserisci il nome del file che vuoi utilizzare: ");
    scanf("%s", nomefile);
    
    num_parole = carica(nomefile, parole);
    if(num_parole == -1)
    {
       printf("Errore nel caricamento del file!\n");
       system("PAUSE");
       return -1;           
    }
    
    printf("\nIl file contiene %d parole:\n", num_parole);    
    visualizza(parole, num_parole);
    
    num2 = elimina(parole, parole2, num_parole);
    printf("\n");
    visualizza(parole2, num2);
    
    system("PAUSE");
    return 0;
}

int carica(char filename[], char elenco[][MAXCAR])
{
    FILE* f;
    int i, j;
    
    f = fopen(filename, "r");
    if(f == NULL)
       return -1;
    
    i = 0;
    while(fscanf(f, "%c", &elenco[i][0]) != EOF)
    {
          if(elenco[i][0] != ' ' && elenco[i][0] != '.' && elenco[i][0] != ',' && elenco[i][0] != ';' && elenco[i][0] != ':' && elenco[i][0] != '\n' && elenco[i][0] != '\t')
          {
             j = 1;
             
             do
             {
                fscanf(f, "%c", &elenco[i][j]);
                j++;
             }while(elenco[i][j-1] != ' ' && elenco[i][j-1] != '.' && elenco[i][j-1] != ',' && elenco[i][j-1] != ';' && elenco[i][j-1] != ':' && elenco[i][j-1] != '\n' && elenco[i][j-1] != '\t');    
             elenco[i][j-1] = '\0';
             i++;
          }
    }
    
    fclose(f);
    
    return i;
}

int elimina(char elenco[][MAXCAR], char elenco2[][MAXCAR], int dim)
{
     int i;
     int k = 0;
     int ind;
     
     for(i = 0; i < dim; i++)
     {
         ind = cerca_parola(elenco[i], elenco, i, dim);
         if(ind == i)
         {
            strcpy(elenco2[k], elenco[i]);
            k++;
         }
     }
     
     return k;
}

int cerca_parola(char vett[], char elenco[][MAXCAR], int inizio, int fine)
{
    int indice = inizio;
    int k;
    
    for(k = inizio+1; k < fine; k++)
        if(strcmp(vett, elenco[k]) == 0)
           indice = k;
           
    return indice;
}

void visualizza(char elenco[][MAXCAR], int dim)
{
     int i;
     
     for(i = 0; i < dim; i++)
         printf("%s\n", elenco[i]);
}
