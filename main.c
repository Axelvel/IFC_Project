#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char saisie();

int main() {
  char rep;
  printf("Quelle matière voulez vous reviser ? ?\n");
  rep = saisie();
  printf("%c\n", rep);
  return 0;

}


char saisie() {
  char reponse;
  do {
    printf("Tapez M pour Maths, P pour Physique et A pour Anglais\n");
    scanf("%c", &reponse);
    reponse = toupper(reponse);
  } while(reponse != 'M' && reponse != 'P' && reponse != 'A' );

  return reponse;
}
