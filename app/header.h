#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Structure de donnée encyclopédie
typedef struct st_encyclopedie
{
    void *premier;
} encyclopedie, *ptrencyclopedie;


// Strcuture de donnée pour un article
typedef struct st_article
{
    long identifiant;
    char *titre;
    char *contenu;
} article, *ptrarticle;

encyclopedie creer_encyclopedie();
ptrarticle creer_article(long identifiant, char *titre, char *contenu);
encyclopedie inserer(encyclopedie encyclopedie, long identifiant, char *titre, char *contenu);