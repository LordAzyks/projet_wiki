#include "../../utils/utils.h"
#include "../../encyclopedie/encyclopedie.h"

// Chaine pour lier les articles avec une liste chainée
typedef struct st_maillon
{
    ptrarticle art;
    struct st_maillon *suivant;
} maillon, *ptrmaillon;

encyclopedie inserer(encyclopedie encyclopedie, long identifiant, char *titre, char *contenu);
void afficher_encyclopedie(encyclopedie encyclopedie);
encyclopedie supprimer(encyclopedie e, long identifiant);
char* rechercher_article(encyclopedie e, long identifiant);
encyclopedie detruire_encyclopedie(encyclopedie e);
encyclopedie rechercher_article_plein_texte(encyclopedie e, char* mot);