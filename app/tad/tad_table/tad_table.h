#include "../../utils/utils.h"
#include "../../encyclopedie/encyclopedie.h"

// Chaine pour lier les articles avec une liste chainée
typedef struct st_maillon
{
    ptrarticle art;
    struct st_maillon *suivant;
} maillon, *ptrmaillon;

typedef struct st_table{
    int taille;
    struct st_maillon **liste;
} table, *ptrtable;

ptrtable creer_table(int taille);
encyclopedie inserer(encyclopedie e, long identifiant, char *titre, char *contenu);
void afficher_encyclopedie(encyclopedie e);
encyclopedie supprimer(encyclopedie e, long identifiant);
char* rechercher_article(encyclopedie e, long identifiant);
encyclopedie rechercher_article_plein_texte(encyclopedie e, char* mot);
encyclopedie detruire_encyclopedie(encyclopedie e);