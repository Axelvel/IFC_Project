#include <stdio.h>
#include <stdlib.h>

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
        {
        c = getchar();
        }
}

void Creation_exercice()
{
    int nb_questions,nb_pts;
    char nom_fichier[25],solution[25],intitule[25];

    printf("\nComment voulez-vous appeler votre test? rajoutez .txt derriere :");
    gets(nom_fichier);
    FILE* fichier_test= fopen(nom_fichier, "w");
    do
    {
        printf("\nCombien de questions voulez-vous dans le test? ");
        scanf("%d",&nb_questions);
        viderBuffer();
    }
    while(nb_questions<0);

    for(int k=0;k<nb_questions;k++)
    {
        printf("\n----------Question %d/%d----------",k+1,nb_questions);
        printf("\nQuel est l'intitule de la question?");
        gets(intitule);
        printf("\nQuelle est la solution à la question?");
        gets(solution);
        printf("\nDonnez le nombre de points de cette question");
        scanf("%d",&nb_pts);
        viderBuffer();
        fprintf(fichier_test,"@%s %d\n%s\n#\n\n",solution,nb_pts,intitule);
    }
    fclose(fichier_test);

}
