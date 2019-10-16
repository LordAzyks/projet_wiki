#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Structure de donnée encyclopédie
typedef struct st_encyclopedie
{
    void *premier;
} encyclopedie, *ptrencyclopedie;

encyclopedie creer_encyclopedie();
