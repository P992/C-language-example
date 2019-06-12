#include <stdio.h>

int main ()
{
    int a1, b1, c1, m1;
    int a2, b2, c2, m2;
    int q1, q2;
    int risultato;
    
    printf("Inserisci i coefficienti a b c della prima retta: ");
    scanf("%d%d%d", &a1, &b1, &c1);
    
    printf("Inserisci i coefficienti a b c della seconda retta: ");
    scanf("%d%d%d", &a2, &b2, &c2);
    
    m1 = - (a1 / b1);
    m2 = - (a2 / b2);
    q1 = - (c1 / b1);
    q2 = - (c2 / b2);
    
    if(m1 == m2 && q1 != q2)
      risultato = 0;
    if(m1 == m2 && q1 == q2)
      risultato = 1;
    if(m1 * m2 == - 1 && q1 == q2)
      risultato = 2;
    if(m1 != m2 && q1 != q2 && (m1 * m2) != -1)
      risultato = 3;
      
    if(b1 == 0 && b2 == 0)
    {
          if(c1 == c2) 
            risultato = 2;
          else
            risultato = 1;
    }
    
    if(b1 == 0)
    {
          if(m2 == 0)
            risultato = 2;
          else
            risultato = 3;
    }
    
    if(b2 == 0)
    {
          if(m1 == 0)
            risultato = 2;
          else
            risultato = 3;
    }
    
    switch (risultato)
    {
      case 0: printf("Le due rette sono parallele.");
      break;
      case 1: printf("Le due rette sono coincidenti.");
      break;
      case 2: printf("Le due rette sono perpendicoari.");
      break;
      case 3: printf("Le due rette sono incidenti.");
      break;
      default: printf("Mi dispiace molto.. il programma ha qualche problema!!");
    }
    system("PAUSE");
    
}
