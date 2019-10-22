#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Strcuture de donnée pour un article
typedef struct st_article
{
    long identifiant;
    char *titre;
    char *contenu;
} article, *ptrarticle;

ptrarticle creer_article(long identifiant, char *titre, char *contenu);
void afficher_article(ptrarticle a);