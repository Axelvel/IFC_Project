#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int comptageExercices(char exos_dispos[][25])
{
    struct dirent *lecture;
    int nbfichier=0;
    DIR *rep;
    rep = opendir("." );
    while ((lecture = readdir(rep)))
        {
        printf("%s\n", lecture->d_name);
        strcpy(lecture->d_name,exos_dispos[nbfichier++]);
        }
    closedir(rep);
    return nbfichier;
}
