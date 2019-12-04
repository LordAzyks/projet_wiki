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
void afficher_encyclopedi(encyclopedie e);
encyclopedie supprimer(encyclopedie e, long identifiant);
char* recherche_article(encyclopedie e, long identifiant);
encyclopedie rechercher_article_plein_texte(encyclopedie e, char* mot);
encyclopedie detruire_encyclopedie(encyclopedie e);

ptrmaillon_arbre parcours_arbre(encyclopedie e,ptrmaillon_arbre *pere,ptrmaillon_arbre parcours,ptrmaillon_arbre *fils_gauche,ptrmaillon_arbre *fils_droit,long id);
void parcours_arbre_affichage(encyclopedie e, ptrmaillon_arbre pere ,ptrmaillon_arbre parcour, ptrmaillon_arbre fils_gauche, ptrmaillon_arbre fils_droit);
encyclopedie parcours_arbre_recherche(encyclopedie e, encyclopedie e_recherche,ptrmaillon_arbre pere, ptrmaillon_arbre parcours, ptrmaillon_arbre fils_gauche, ptrmaillon_arbre fils_droit, char* mot);
encyclopedie parcours_detruire_encyclopedie(encyclopedie e,ptrmaillon_arbre pere, ptrmaillon_arbre parcours, ptrmaillon_arbre fils_gauche, ptrmaillon_arbre fils_droit);