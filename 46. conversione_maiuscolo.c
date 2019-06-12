/*Conversione da minuscolo a maiuscolo*/

#include <stdio.h>
#define M 100

/*Prototipi*/
int carica_vettore(char vett[]);
void converti_vettore(char vett[]);

/*Programma*/
int main ()
{
    char v[M];
    
    printf("**QUESTO PROGRAMMA CONVERTE LA PAROLA INSERITA DA MINUSCOLO A MAIUSCOLO**\n\n");
     
    carica_vettore(v);
    converti_vettore(v);
    
    printf("La parola convertita e': %s\n", v);
    
    system("PAUSE");
}

/*Funzioni*/
int carica_vettore(char vett[])
{ 
    printf("Inserisci la parola da convertire: ");
    scanf("%s", vett);
}

void converti_vettore(char vett[])
{
     int i = 0;
     
     while(vett[i] != '\0')
     {
           vett[i] = vett[i] - 'a' + 'A';
           i++;        
     }   
}
