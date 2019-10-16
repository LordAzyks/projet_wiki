#include "header.h"

// Chaine pour lier les articles avec une liste chainée
typedef struct st_maillon
{
    ptrarticle art;
    struct maillon *suivant;
} maillon, *ptrmaillon;

encyclopedie inserer(encyclopedie encyclopedie, long identifiant, char *titre, char *contenu){
    ptrmaillon nouveau;
    nouveau->art = creer_article(identifiant,titre,contenu);
    nouveau->suivant = encyclopedie.premier;
    encyclopedie.premier = nouveau;
    return encyclopedie;
}

