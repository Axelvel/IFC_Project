

char saisie() {
  char reponse;
  do {
    printf("Tapez M pour Maths, P pour Physique et A pour Anglais\n");
    scanf("%c", reponse);
    reponse = toupper(reponse);
  } while(reponse != 'M' && reponse != 'P' && reponse != 'A' );

  return reponse;
}
