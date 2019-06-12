#include <stdio.h>

int main ()
{
    int vett[9];
    int dim_logica;
    int cont;
    int somma_pari;
    int somma_dispari;
    int scelta;
    
    while(dim_logica < 1 || dim_logica > 10)
    {
         printf("Quanti elementi vuoi inserire? ");
         scanf("%d", &dim_logica);
    }
    
    printf("Di quali numeri vuoi effettuare la somma?\n1) Indice pari (compresa l'indice 0).\n2) Indice dispari.\nInserisci la tua scelta: ");
    scanf("%d", &scelta);
    
    for(cont = 0; cont < dim_logica; cont = cont + 1)
    {
        printf("Inserisci il valore che occupa l'indice %d: ", cont);
        scanf("%d", &vett[cont]);
    }

    switch(scelta)
    {     
          case 1:
          {     
                somma_pari = 0;
                for (cont = 0; cont < dim_logica; cont = cont + 1)
                     if(vett[cont] % 2 != 0 && vett[cont] != 0)
                     somma_pari = somma_pari + vett[cont]; 
                printf("La somma dei valori di indice pari e' %d", somma_pari);
          }      
          break;
          case 2: 
          {     
                somma_dispari = 0;
                for (cont = 0; cont < dim_logica; cont = cont + 1)
                     if(vett[cont] % 2 == 0)
                     somma_dispari = somma_dispari + vett[cont]; 
                printf("La somma dei valori di indice dispari e' %d", somma_dispari);
          }      
          break;

          default: printf("Si e' verificato un errore.");
    }
}
