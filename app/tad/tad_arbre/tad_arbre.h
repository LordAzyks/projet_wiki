#include <stdlib.h>

#include "../../utils/utils.h"
#include "../../encyclopedie/encyclopedie.h"

typedef struct st_maillon_arbre
{
    ptrarticle art;
    struct st_maillon_arbre *precedent;
    struct st_maillon_arbre *suivant;
} maillon_arbre, *ptrmaillon_arbre;

encyclopedie inserer_arbre(encyclopedie encyclopedie, long identifiant, char *titre, char *contenu);