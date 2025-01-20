#include <stdio.h>
#include <math.h>
int main() {
 int N,i;
 // les N premiers termes de la séquence de Fibonacci
 int terme1 = 0, terme2 = 1, termeSuivant;
 // Demander à l'utilisateur de saisir le nombre de termes
 printf("Entrez le nombre de termes de la séquence de Fibonacci : ");
 scanf("%d", &N);
 printf("Les %d premiers termes de la séquence de Fibonacci sont :\n", N);
 for ( i = 0; i < N; ++i) {
 printf("%d ", terme1);
 termeSuivant = terme1 + terme2;
 terme1 = terme2;
 terme2 = termeSuivant;
 }
 return 0;
}
