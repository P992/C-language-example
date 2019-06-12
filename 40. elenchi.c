/* Dato un elenco di parole, il programma crei due nuovi elenchi, uno in cui
le parole dell'elenco originale sono elencate in ordine di lunghezza, l'altro
in ordine alfabetico. Stampare tutti e tre gli elenchi */

/* Le funzioni necessarie sono:
      carica_parole
      ordina_lunghezza
      ordina_alfabeticamente
      stampa_elenco */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
     
/* Prototipo carica_parole */

#define N 10
#define M 20

int carica_parole(char el[][M]);

/* Prototipo ordina_lunghezza */

void ordina_lunghezza(char el1[][M], char el2[][M], int dim);

/* Prototipo ordina_alfabeticamente */

void ordina_alfabeticamente(char el1[][M], char el2[][M], int dim);

/* Prototipo stampa_elenco */

void stampa_elenco(char el[][M], int dim);

/* Programma principale */

int main ()
{
    int dim;
    char el1[N][M], el2[N][M], el3 [N][M];
   
    dim=carica_parole(el1);
    ordina_lunghezza(el1, el2, dim);
    ordina_alfabeticamente(el1, el3, dim);
   
    printf ("Elenco originale: \n");
    stampa_elenco (el1, dim);
   
    printf ("Elenco ordinato in base alla lunghezza: \n");
    stampa_elenco (el2, dim);
   
    printf ("Elenco ordinato in ordine alfabetico: \n");
    stampa_elenco (el3, dim);
   
    system ("PAUSE");
}

/* Prima funzione */

int carica_parole(char el[][M]){
    int i, dim;
   
    printf ("Quante parole vuoi inserire? (max 10): ");
    scanf ("%d", &dim);
   
    for (i=0; i<dim; i++)
        scanf ("%s", el[i]);
    return dim;
}

/* Seconda funzione */

void ordina_lunghezza(char el1[][M], char el2[][M], int dim){
     int i, j;
     char tmp[M];
     
     for (i=0; i<dim; i++)
         strcpy (el2[i], el1[i]);
         
     for (i=0; i<dim-1; i++)
         for (j=dim-1; j>i; j--)
             if (strlen(el2[j])<strlen(el2[j-1]))
               {
                strcpy(tmp, el2[j]);
                strcpy(el2[j], el2[j-1]);
                strcpy(el2[j-1], tmp);
               }
}

/* Terza funzione */

void ordina_alfabeticamente (char el1[][M], char el2[][M], int dim){
     int i, j;
     char tmp[M];
     
     for (i=0; i<dim; i++)
         strcpy (el2[i], el1[i]);
         
     for (i=0; i<dim-1; i++)
         for (j=dim-1; j>i; j--)
             if (strcmp(el2[j], el2[j-1])<0)
                {
                   strcpy(tmp, el2[j]);
                   strcpy(el2[j], el2[j-1]);
                   strcpy(el2[j-1], tmp);
                }
}

/* Quarta funzione */

void stampa_elenco (char el[][M], int dim){
     int i;
     
     for (i=0; i<dim; i++)
         printf ("%s\n", el[i]);
}
