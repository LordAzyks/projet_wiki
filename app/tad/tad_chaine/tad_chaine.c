#include "tad_chaine.h"

/**
 * Permet d'inserer un article dans une encyclopedie.
 * L'article comprend un identifiant, un titre et un contenu.
 * 
 * @param e (encylcopedie) : L'encyclopedie cible
 * @param identifiant (long) : L'identifiant de l'article a inserer.
 * @param titre (char*) : Le titre de l'article a inserer.
 * @param contenu (char*) : Le contenu de l'article a inserer.
 */
encyclopedie inserer(encyclopedie e, long identifiant, char *titre, char *contenu) {
    ptrmaillon nouveau;
    nouveau = (ptrmaillon)malloc(sizeof(maillon));
    nouveau->art = creer_article(identifiant,titre,contenu);
    nouveau->suivant = e.premier;
    e.premier = nouveau;
    return e;
}

/**
 * Permet d'afficher une encyclopedie.
 * 
 * @param e (encylcopedie) : L'encyclopedie cible
 */
void afficher_encyclopedie(encyclopedie e) {
    ptrmaillon parcours = e.premier;
    while( parcours ) {
        afficher_article(parcours->art);

        parcours = parcours->suivant;
    }
}


/**
 * Permet de supprimer un article par identifiant dans une encyclopedie.
 * Le retour est une encyclopedie.
 * 
 * @param e (encylcopedie) : L'encyclopedie cible
 * @param identifiant (long) : L'article a supprimer
 */
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

/**
 * Permet de rechercher un article par identifiant dans une encyclopedie.
 * Le retour est une chaine de carateres.
 * 
 * @param e (encylcopedie) : L'encyclopedie cible
 * @param identifiant (long) : L'article a rechercher
 */
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

/**
 * Permet de rechercher un mot dans une encyclopedie.
 * Le retour est une encylcopedie (vide si aucun resultat).
 * 
 * @param e (encylcopedie) : L'encyclopedie cible
 * @param mot (char*) : Le mot a rechercher
 */
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

/**
 * Permet de detruire une encyclopedie.
 * Le retour est une encyclopedie vide.
 * Chaque article (titre, contenu et structure) sera free().
 * Chaque maillon sera free().
 * La table sera free()
 * 
 * @param e (encylcopedie) : L'encyclopedie cible
 */
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
