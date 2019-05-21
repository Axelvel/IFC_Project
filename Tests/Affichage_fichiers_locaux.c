#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int Reperage_fichiers_locaux(char exos_dispos[][25])
{
    struct dirent *lecture;
    int compteur=0;
    DIR *rep;
    rep = opendir("." );
    while ((lecture = readdir(rep)))
        {
        printf("%s\n", lecture->d_name);
        strcpy(lecture->d_name,exos_dispos[compteur++]);
        }
    closedir(rep);
    return compteur;
}
