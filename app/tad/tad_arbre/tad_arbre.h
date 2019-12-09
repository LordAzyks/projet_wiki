#include <stdlib.h>

#include "../../utils/utils.h"
#include "../../encyclopedie/encyclopedie.h"

typedef struct st_maillon_arbre
{
    ptrarticle art;
    struct st_maillon_arbre *precedent;
    struct st_maillon_arbre *suivant;
} maillon_arbre, *ptrmaillon_arbre;

encyclopedie inserer(encyclopedie encyclopedie, long identifiant, char *titre, char *contenu);
void afficher_encyclopedie(encyclopedie e);
encyclopedie supprimer(encyclopedie e, long identifiant);
char* rechercher_article(encyclopedie e, long identifiant);
encyclopedie rechercher_article_plein_texte(encyclopedie e, char* mot);
encyclopedie detruire_encyclopedie(encyclopedie e);
