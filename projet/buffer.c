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
