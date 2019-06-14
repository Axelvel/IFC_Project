#include <stdio.h>
#include <stdlib.h>

void enlever_les_espaces(char chaine[])
{
    for(int k=0;k<strlen(chaine);k++)
    {
        while (chaine[k]==' ')
        {
            for (int i=k;i<strlen(chaine);i++)
            {
                chaine[i]=chaine[i+1];
            }
        }
    }
}
