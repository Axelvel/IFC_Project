#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int comptageExercices(char toutfichier[][25])
{
    struct dirent *lecture;
    int nbfichier=0;
    DIR *rep;
    rep = opendir("." );
    while ((lecture = readdir(rep)))
        {
        //printf("%s\n", lecture->d_name);
        strcpy(toutfichier[nbfichier++],lecture->d_name);
        }
    closedir(rep);


    return nbfichier;
}
