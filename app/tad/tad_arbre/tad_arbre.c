#include "tad_arbre.h"

encyclopedie inserer_arbre(encyclopedie e, long identifiant, char *titre, char *contenu) {
    ptrmaillon_arbre nouveau;
    nouveau = (ptrmaillon_arbre)malloc(sizeof(maillon_arbre));
    if (e.premier==NULL){
        // Création de la racine
        nouveau->art = creer_article(identifiant,titre,contenu);
        nouveau->precedent = NULL;
        nouveau->suivant = NULL;
        e.premier = nouveau;
    } else if(identifiant > e.premier) {
        //Parcours pour insertion à droite (suivant)

    } else if(identifiant < ) {
        //Parcours pour insertion à gauche (précédent)
    }

    return e;
}

void affichage_arbre(encyclopedie e){
    ptrmaillon_arbre parcours = e.premier;
    while( parcours != NULL) {
        afficher_article(parcours->art);

        parcours = parcours->suivant;
    }
}