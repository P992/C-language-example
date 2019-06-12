#include <stdio.h>

int main ()
{
    FILE* f;
    char vett1[101];
    char vett2[101];
    int i=0;
    
    f = fopen("scrittura_file.txt", "r");
    
    if((f = fopen("scrittura_file.txt", "r")) == NULL)
       printf("Errore nell'apertura del file!");
    else
    {
       {
         printf("Ecco il testo del file:\n");
         while((fscanf(f, "%c", &vett1[i])) != EOF)
         {
              printf("%c", vett1[i]);
              i++;
         }
         fclose(f);
       }
       
       f = fopen("scrittura_file.txt", "a");
       
       printf("\nVuoi aggiungere altro? (SPAZIO: _)");
       scanf("%s", vett2);
            fprintf(f, "\nTesto aggiunto:\n%s", vett2);
       fclose(f);
    }
}
