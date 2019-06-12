        /*Data una matrice float e 4 valori interi, il programma estrae dalla
        matrice originale un'altra matrice avente per estremi i valori situati nella matrice di partenza ai 4 indici inseriti*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define N 10
    #define M 10

    /*Prototipi delle funzioni*/
    void carica_matrice(float m[][M], int righe, int colonne);
    void sottomatrice(float m[][N], float m2[][N], int righe, int colonne, int n1, int n2, int n3, int n4);
    void stampa(float m[][N], int dim2_i, int dim2_j);

    /*Programma*/
    int main (){
        float matr[N][M];
        float matr2[N][M];
        int dim_i, dim_j, dim2_i, dim2_j;
        int num1, num2, num3, num4;
       
        printf("Inserisci il numero di righe della matrice: ");
        scanf("%d", &dim_i);
        printf("Inserisci il numero di colonne della matrice: ");
        scanf("%d", &dim_j);
           
        carica_matrice(matr, dim_i, dim_j);   
           
        printf("Inserisci 4 valori: ");
        scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
           
        if(num1<=num3)
            dim2_i = (num3 - num1) + 1;
        else if(num1>num3)
            dim2_i = (num1 - num3) + 1;
       
        if(num2<=num4)
            dim2_j = (num4 - num2) + 1;
        else if(num2>num4)
            dim2_j = (num2 - num4) + 1;
       
        sottomatrice(matr, matr2, dim_i, dim_j, num1, num2, num3, num4);
        printf("Hai ottenuto la seguente matrice:\n");
        stampa(matr2, dim2_i, dim2_j);
        system("PAUSE");
    }

    /*Funzioni*/
    void carica_matrice(float m[][N], int righe, int colonne){
         int i, j;
         
         for(i = 0; i < righe; i++)
             for(j = 0; j < colonne; j++){
                  printf("Inserisci l'elemento di indice [%d][%d]: ", i, j);
                  scanf("%f", &m[i][j]);
             }
    }

    void sottomatrice(float m1[][N], float m2[][N], int righe, int colonne, int r1, int c1, int r2, int c2){
         
	 int i, j;
         
         for(i = r1; i <= r2; i++)
             for(j = c1; j <= c2; j++) {
		  m2[i-r1][j-c1] = m1[i][j];
             }       
    }

    void stampa(float m[][N], int righe, int colonne){
         int i, j;
           
         for(i = 0; i < righe; i++){
             for(j = 0; j < colonne; j++)
                  printf("%.1f ", m[i][j]);
             printf("\n");
         }
    }
