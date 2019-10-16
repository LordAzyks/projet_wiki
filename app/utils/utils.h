#include <stdlib.h>

// Strcuture de donnée pour un article
typedef struct st_article
{
    long identifiant;
    char *titre;
    char *contenu;
} article, *ptrarticle;

ptrarticle creer_article(long identifiant, char *titre, char *contenu);