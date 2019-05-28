#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int cherche_exercice(char exos_dispos[][25])
{
    char noms_des_fichiers[100][25];
    struct dirent *lecture;
    int nbfichier=0,nb_exos=0;
    DIR *rep;
    rep = opendir("." );
    while ((lecture = readdir(rep)))
        {
        //printf("%s\n", lecture->d_name);
        strcpy(noms_des_fichiers[nbfichier++],lecture->d_name);
        }
    closedir(rep);

    for(int i=0;i<nbfichier;i++)
    {
        if((strcmp(&noms_des_fichiers[i][strlen(noms_des_fichiers[i])-3],"txt")==0)&&(strcmp(noms_des_fichiers[i],"resultat.txt")!=0))
        {
            strncpy(exos_dispos[nb_exos],noms_des_fichiers[i],strlen(noms_des_fichiers[i])-4);
            exos_dispos[nb_exos][strlen(noms_des_fichiers[i])-4]='\0';
            nb_exos++;
        }
    }
    return nb_exos;

}
