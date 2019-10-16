#include "tad_chaine.h"

encyclopedie inserer(encyclopedie e, long identifiant, char *titre, char *contenu) {
    ptrmaillon nouveau;
    nouveau = (ptrmaillon)malloc(sizeof(maillon));
    nouveau->art = creer_article(identifiant,titre,contenu);
    nouveau->suivant = e.premier;
    e.premier = nouveau;
    return e;
}

void affiche_encyclopedie(encyclopedie e) {
    ptrmaillon parcours = e.premier;
    while( parcours ) {
        printf("Title: %s\n",parcours->art->titre);
        parcours = parcours->suivant;
    }
}
