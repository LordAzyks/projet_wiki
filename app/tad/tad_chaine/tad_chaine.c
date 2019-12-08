#include "tad_chaine.h"

encyclopedie inserer(encyclopedie e, long identifiant, char *titre, char *contenu) {
    ptrmaillon nouveau;
    nouveau = (ptrmaillon)malloc(sizeof(maillon));
    nouveau->art = creer_article(identifiant,titre,contenu);
    nouveau->suivant = e.premier;
    e.premier = nouveau;
    return e;
}

void afficher_encyclopedie(encyclopedie e) {
    ptrmaillon parcours = e.premier;
    while( parcours ) {
        afficher_article(parcours->art);

        parcours = parcours->suivant;
    }
}


// Fonction permettant de supprimer un article en connaissant son identifiant
encyclopedie supprimer(encyclopedie e, long identifiant) {
    ptrmaillon parcours = e.premier;
    ptrmaillon precedent = NULL;
    while( parcours->suivant ) {
        if( parcours->art->identifiant == identifiant) {
            free(parcours->art->titre);
            free(parcours->art->contenu);
            free(parcours->art);
            if( !precedent ) {
                e.premier = parcours->suivant;
                
            } else {
                precedent->suivant = parcours->suivant;
            }
            free(parcours);
            return e;
        }
        precedent = parcours;
        parcours = parcours->suivant;
    }
    return e;
}

char* rechercher_article(encyclopedie e, long identifiant) {
    ptrmaillon correspondant = e.premier;
    while( correspondant ) {
        if( correspondant->art->identifiant == identifiant ) {
            return correspondant->suivant->art->contenu;
        }
        correspondant = correspondant->suivant;
    }
    return "Aucune correspondance\n";
}

encyclopedie rechercher_article_plein_texte(encyclopedie e, char* mot) {
    ptrmaillon parcours = e.premier;
    encyclopedie res = creer_encyclopedie();
    ptrarticle current;
    int i=0;
    while( parcours ) {
        current = parcours->art;
        if(strstr(current->contenu,mot)){
            res = inserer(res,current->identifiant,current->titre,current->contenu);
            i++;
        }
        parcours = parcours->suivant;
    }
    return res;
}

encyclopedie detruire_encyclopedie(encyclopedie e) {
    ptrmaillon parcours = e.premier;
    ptrmaillon tmp;
    while( parcours ) {
        free(parcours->art->titre);
        free(parcours->art->contenu);
        free(parcours->art);
        tmp = parcours;
        parcours = parcours->suivant;
        free(tmp);
    }
    e.premier = NULL;
    return e;
}
