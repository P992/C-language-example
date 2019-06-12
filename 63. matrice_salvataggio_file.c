/* PROVA SCRITTA DI FONDAMENTI DI INFORMATICA DEL 18 FEBBRAIO 2008
   CORSI DI LAUREA IN INGEGNERIA ELETTRONICA E INGEGNERIA INFORMATICA

Al candidato è richiesto di scrivere un programma in grado di effettuare le 
seguenti operazioni:
- inizializza una matrice quadrata con dei valori reali e di dimensione forniti
  interattivamente dall'utente
- visualizza a video la matrice caricata
- calcola la media dei valori presenti sulle due diagonali della matrice
- visualizza a video i due valori calcolati al passo precedente
- avendo indicato con MEDmin e MEDmax rispettivamente il minimo ed il massimo 
  tra i due valori medi calcolati precedentemente, salva in un file il cui nome 
  è fornito interattivamente dall'utente la matrice precedente in cui tutti i 
  valori minori/maggiori di MEDmin/MEDmax sono impostati al valore MEDmin/MEDmax  

ULTERIORI SPECIFICHE
- Il programma deve essere in grado di gestire matrici quadrate con dimensione 
  fisica non superiore a 10x10  

COSA E' RICHIESTO AL CANDIDATO
Al candidato è richiesto di implementare il main ed i seguenti sottoprogrammi di 
cui sono forniti i prototipi:
- carica_matrice_quadrata
- calcola_medie_diagonali_matrice
- salva_matrice_saturata


ATTENZIONE!!! 
Il codice fornito non deve ASSOLUTAMENTE essere modificato dal candidato!!!


-------------------  ESEMPIO DI ESECUZIONE DEL PROGRAMMA -----------------------
Digitare la dimensione della matrice
Selezionare un valore nell'intervallo [1,10]: -3
Digitare la dimensione della matrice
Selezionare un valore nell'intervallo [1,10]: 12
Digitare la dimensione della matrice
Selezionare un valore nell'intervallo [1,10]: 3
Digitare l'elemento di posizione 0,0: -4
Digitare l'elemento di posizione 0,1: 2
Digitare l'elemento di posizione 0,2: 50
Digitare l'elemento di posizione 1,0: 3
Digitare l'elemento di posizione 1,1: 0
Digitare l'elemento di posizione 1,2: -5
Digitare l'elemento di posizione 2,0: 25
Digitare l'elemento di posizione 2,1: -4
Digitare l'elemento di posizione 2,2: -20
Caricata una matrice quadrata di dimensioni 3x3
-4.00  2.00 50.00
 3.00  0.00 -5.00
25.00 -4.00 -20.00
La media dei valori sulla diagonale principale e': -8.00
La media dei valori sulla diagonale secondaria e': 25.00
Digitare il nome del file di output: mats.txt
Salvataggio riuscito
Premere un tasto per continuare . . .
---------------- TERMINE ESEMPIO DI ESECUZIONE DEL PROGRAMMA -------------------


Altro: con riferimento all'esempio precedente il file mats.txt avrà il seguente 
contenuto:
-4.00	2.00	25.00	
3.00	0.00	-5.00	
25.00	-4.00	-8.00	          
*/


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define MAXCAR_NOMEFILE 256

/* funzioni già fornite al candidato */
void visualizza_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col);

/* funzioni la cui implementazione è richiesta al candidato */
int carica_matrice_quadrata(double m[MAXSIZE][MAXSIZE]);
                                                          
void calcola_medie_diagonali_matrice(double mat[MAXSIZE][MAXSIZE], int dim,  
                              double *diag_principale, double *diag_secondaria);
                                                      
int salva_matrice_saturata(char nomefile[], double mat[MAXSIZE][MAXSIZE],  
                                               int dim, double min, double max);

int main()
{
    int dimensione;
    double matrice[MAXSIZE][MAXSIZE];
    double diagonale_p, diagonale_s, MEDmin, MEDmax;
    char filename[MAXCAR_NOMEFILE];
    int salva;
    
    dimensione = carica_matrice_quadrata(matrice);

    printf("\nHai ottenuto la seguente matrice:\n");
    visualizza_matrice(matrice, dimensione, dimensione);                
    
    calcola_medie_diagonali_matrice(matrice, dimensione, &diagonale_p, &diagonale_s);
    printf("\nLa media del valori della diagonale principale e' %5.21lf.\n", diagonale_p);
    printf("La media dei valori della diagonale secondaria e' %5.21lf.\n", diagonale_s);
    
    if(diagonale_p > diagonale_s)
    {
       MEDmin = diagonale_s;
       MEDmax = diagonale_p;            
    }
    else
    {
       MEDmin = diagonale_p;
       MEDmax = diagonale_s;        
    }
    
    printf("\nDigita il nome del file di output: ");
    scanf("%s", filename);

    salva = salva_matrice_saturata(filename, matrice, dimensione, MEDmin, MEDmax);
    if(salva == 1)
       printf("Salvataggio effettuato!\n");
    if(salva == 0)
       printf("Errore nel salvataggio!\n");
    
    system("PAUSE");
}


/* Il sottoprogramma visualizza a video gli elementi della matrice passata 
   mediante il parametro m e le cui dimensioni per righe e per colonne sono
   specificate attraverso i parametri rig e col
*/
void visualizza_matrice(double m[MAXSIZE][MAXSIZE], int rig, int col){
     int i, j;
     for(i=0; i<rig; i++){
        for(j=0; j<col; j++)
            printf("%5.2lf ",m[i][j]);
        printf("\n");
     }
}

/* La funzione inizializza la matrice quadrata di reali passata con il parametro
   mat con i valori forniti interattivamente dall'utente secondo una scansione
   per righe. La funzione acquisisce dall'utente anche la dimensione della 
   matrice verificando che il valore fornito dall'utente sia compreso 
   nell'intervallo [1,MAXSIZE].
   La funzione restituisce la dimensione della matrice.   
*/
int carica_matrice_quadrata(double mat[MAXSIZE][MAXSIZE])
{
    int i, j;
    int dim;
    
    do
    { printf("Inserisci la dimensione della matrice quadrata: ");
      scanf("%d", &dim);}while(dim <= 0 || dim > MAXSIZE);

    for(i = 0; i < dim; i++)
    {
        for(j = 0; j < dim; j++)
        {
            printf("Inserisci l'elemento di indice [%d][%d]: ", i, j);
            scanf("%lf", &mat[i][j]);
        }  
    }
    
    return dim;
}


/* Il sottoprogramma calcola le medie dei valori presenti sulle due diagonali 
   della matrice passata attraverso il parametro mat e la cui dimensione in
   termini di numero di righe e di colonne è specificata mediante il parametro
   dim. I valori delle medie dei valori presenti sulla diagonale principale e 
   sulla diagonale secondaria sono restituiti attraverso i parametri di output 
   diag_principale e diag_secondaria. 
*/
void calcola_medie_diagonali_matrice(double mat[MAXSIZE][MAXSIZE], int dim,  
                              double *diag_principale, double *diag_secondaria)
{
     int somma1 = 0;
     int somma2 = 0;
     int i, j;
     
     for(i = 0; i < dim; i++)
     {
         for(j = 0; j < dim; j++)
         {
             if(i == j)
                somma1 = somma1 + mat[i][j];
             if((i+j) == (dim-1))
                somma2 = somma2 + mat[i][j];
         }
     }
     
     *diag_principale = (somma1/dim);
     *diag_secondaria = (somma2/dim);
}


/* La funzione salva in un file il cui nome è passato attraverso il parametro
   nomefile la matrice passata attraverso il parametro mat in cui tutti i 
   valori minori/maggiori di min/max sono impostati al valore min/max.
   La funzione restituisce 0 nel caso in cui il salvataggio non vada a buon fine
   altrimenti restituisce 1.
*/                                                      
int salva_matrice_saturata(char nomefile[], double mat[MAXSIZE][MAXSIZE],  
                                               int dim, double min, double max)
{
    FILE* f;
    int i, j;
    
    f = fopen(nomefile, "w");
    if(f == NULL)
       return 0;
    
    for(i = 0; i < dim; i++)
    {
        for(j = 0; j < dim; j++)
        {
            if(mat[i][j] < min)
               mat[i][j] = min;
            if(mat[i][j] > max)
               mat[i][j] = max;
        
            fprintf(f, "%5.21lf ", mat[i][j]);
        }
        fprintf(f, "\n");
    }
    
    fclose(f);
    
    return 1;
}
