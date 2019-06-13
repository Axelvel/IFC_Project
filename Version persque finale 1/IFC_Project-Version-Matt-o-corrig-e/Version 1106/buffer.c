#include <stdio.h>
#include <stdlib.h>

/* Fonction pour vider le buffer */

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
        {
        c = getchar();
        }
}
