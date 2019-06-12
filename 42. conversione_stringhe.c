    /*Dato un file con n stringhe da 8 bit, caricare le stringhe e convertirle in complemento a 2 e stampare i valori ottenuti.*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #define N 9
    #define M 20

    /*Prototipi*/
    int carica(char stringhe [][N]);
    void elabora(char el[][N], int dim, int v[M]);
    void stampa(char stringhe[][N], int riemp, int vett[M]);

    /*Programma*/
    int main ()
    {
        char elenco [M][N];
        int vettore [M];
        int r,i;
       
        r = carica(elenco);
        if(r == -1)
           printf("Errore nel caricamento del file!");
        else
           elabora(elenco, r, vettore);
           stampa(elenco, r, vettore);
           system("pause");
    }

    /*Funzione CARICA*/
    int carica(char stringhe[][N])
    {
        FILE* f;
        int riemp = 0;
       
        f = fopen("stringhe_bit.txt", "r");
        if(f == NULL)
           return -1;

        /*Il seguente ciclo while serve a "scoprire" il numero delle stringhe presenti nell'elenco*/
        while(fscanf(f, "%s", stringhe[riemp]) != EOF)
             riemp++;
             
        fclose(f);
       
        return riemp;
    }

    /*Funzione ELABORA*/
    void elabora(char el[][N], int dim, int v[M])
    {
         int i, j;
         int somma;
         
         for(i = 0; i < dim; i++)
         {
            somma = 0;
            somma = somma - (el[i][0] - '0') * pow(2,8-1);
            for(j=0;j<N-1;j++)
           
              somma = somma - (el[i][j] - '0') * pow(2,8-j-1);
           
                v[i] = somma;
         }
    }

    /*Funzione STAMPA*/
    void stampa(char stringhe[][N], int riemp, int vett[])
    {
         int i;
         for(i=0; i<riemp;i++)
            printf("%s = %d\n", stringhe[i], vett[i]);
            printf("\n");
    }
