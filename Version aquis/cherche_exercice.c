#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

/* Fonction qui recherche les différents exercices disponibles dans le repertoire du programme */

int cherche_exercice(char exos_dispos[][25])
{
    //VARIABLES
    char noms_des_fichiers[100][25];
    struct dirent *lecture;
    int nbfichier=0,nb_exos=0;


    //DEBUT
    DIR *rep;
    rep = opendir("." );
    while ((lecture = readdir(rep)))
        {
        //printf("%s\n", lecture->d_name);
        strcpy(noms_des_fichiers[nbfichier++],lecture->d_name); /* enregistre les noms de fichiers dans un tableau */
        }
    closedir(rep);

    for(int i=0;i<nbfichier;i++)    /* balaye tous les fichiers du repertoire */
    {
        if((strcmp(&noms_des_fichiers[i][strlen(noms_des_fichiers[i])-3],"txt")==0))        /* Cherche les fichiers au format txt */
        {
            strncpy(exos_dispos[nb_exos],noms_des_fichiers[i],strlen(noms_des_fichiers[i])-4); /* Mets le nom des exos dispos dans un tableau */
            exos_dispos[nb_exos][strlen(noms_des_fichiers[i])-4]='\0';         /* Ajout du caractère de fin de chaine */
            nb_exos++;
        }
    }
    return nb_exos;

}
