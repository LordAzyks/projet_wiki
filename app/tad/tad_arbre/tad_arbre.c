#include "tad_arbre.h"

// Insertion d'un article dans l'arbre
encyclopedie inserer(encyclopedie e, long identifiant, char *titre, char *contenu) {
    ptrmaillon_arbre nouveau = (ptrmaillon_arbre)malloc(sizeof(maillon_arbre));
    nouveau->art = creer_article(identifiant,titre,contenu);
    nouveau->precedent = NULL;
    nouveau->suivant = NULL;
    if(e.premier){
        // La racine est présente
        ptrmaillon_arbre parcours = e.premier;
        while(parcours){
            // Orientation selon l'identifiant de l'article à insérer
            if(identifiant > parcours->art->identifiant){
                if (parcours->suivant == NULL){
                    // S'il n'y a pas de fils droit, on en créer un.
                    parcours->suivant = nouveau;
                    parcours = NULL;
                } else {
                    // S'il y a un fils droit, on passe au suivant
                    parcours = parcours->suivant;
                }
            } else {
                if (parcours->precedent == NULL){
                    // S'il n'y a pas de fils gauche, on en créer un.
                    parcours->precedent = nouveau;
                    parcours = NULL;
                } else {
                    // S'il y a un fils gauche, on passe au suivant
                    parcours = parcours->precedent;
                }
            }
        }
    } else {
        // Création de la racine s'il n'y en avait pas
        e.premier = nouveau;
    }
    return e;
}

// Affichage de l'encyclopédie
void afficher_encyclopedie(encyclopedie e){
    ptrmaillon_arbre pere = e.premier;
    ptrmaillon_arbre parcours = e.premier;
    ptrmaillon_arbre fils_gauche = parcours->precedent;
    ptrmaillon_arbre fils_droit = parcours->suivant;
    parcours_arbre_affichage(e,pere,parcours,fils_gauche,fils_droit);
}

// Parcours d'affichage de l'encyclopédie
void parcours_arbre_affichage(encyclopedie e, ptrmaillon_arbre pere, ptrmaillon_arbre parcours, ptrmaillon_arbre fils_gauche, ptrmaillon_arbre fils_droit){
    if (fils_gauche){
        // Parcours tant qu'il y a un fils gauche
        pere = parcours;
        parcours = fils_gauche;
        fils_droit = parcours->suivant;
        fils_gauche = parcours->precedent;
        parcours_arbre_affichage(e,pere,parcours,fils_gauche,fils_droit);
        afficher_article(parcours->art);
        parcours = pere;
        fils_gauche = parcours->precedent;
        fils_droit = parcours->suivant;
    }
    if (fils_droit){
        // Passe au fils droit lorsqu'il n'y a plus de fils gauche
        pere = parcours;
        parcours = fils_droit;
        fils_droit = parcours->suivant;
        fils_gauche = parcours->precedent;
        parcours_arbre_affichage(e,pere,parcours,fils_gauche,fils_droit);
        afficher_article(parcours->art);
        parcours = pere;
        fils_gauche = parcours->precedent;
        fils_droit = parcours->suivant;
    }
    if (parcours == e.premier){
        // Affichage de la racine en fin de parcours
        afficher_article(parcours->art);
    }
}

// Chercher et retourne le contenue de l'article en fonction de son identifiant
char* rechercher_article(encyclopedie e, long identifiant){
    ptrmaillon_arbre pere = e.premier;
    ptrmaillon_arbre parcours = e.premier;
    ptrmaillon_arbre fils_gauche = parcours->precedent;
    ptrmaillon_arbre fils_droit = parcours->suivant;
    // Parcours tant que l'identifiant n'est pas trouvé
    while(parcours->art->identifiant != identifiant){
        // Guidage du parcours en fonction de l'identifiant
        if (parcours->art->identifiant > identifiant){
            if (fils_gauche) {
                pere = parcours;
                parcours = fils_gauche;
                fils_droit = parcours->suivant;
                fils_gauche = parcours->precedent;
            } else {
                return "Il n'y a pas d'article avec cet identifiant";
            }
        } else if (parcours->art->identifiant < identifiant){
            if (fils_droit) {
                pere = parcours;
                parcours = fils_droit;
                fils_droit = parcours->suivant;
                fils_gauche = parcours->precedent;
            } else {
                return "Il n'y a pas d'article avec cet identifiant";
            }
        }
    }
    return parcours->art->contenu;
}

// Retour l'article correspondant à l'id
ptrmaillon_arbre parcours_arbre(encyclopedie e,ptrmaillon_arbre *pere,ptrmaillon_arbre parcours,ptrmaillon_arbre *fils_gauche,ptrmaillon_arbre *fils_droit,long id){
    // Parcours tant que l'identifiant n'est pas trouvé
    while(parcours->art->identifiant != id){
        if (parcours->art->identifiant > id){
            if (fils_gauche) {
                *pere = parcours;
                parcours = *fils_gauche;
                *fils_droit = parcours->suivant;
                *fils_gauche = parcours->precedent;
            } else {
                printf("\n Il n'y a pas d'article avec cet identifiant  \n");
                return NULL;
            }
        } else if (parcours->art->identifiant < id){
            if (fils_droit) {
                *pere = parcours;
                parcours = *fils_droit;
                *fils_droit = parcours->suivant;
                *fils_gauche = parcours->precedent;
            } else {
                printf("\n Il n'y a pas d'article avec cet identifiant  \n");
                return NULL;
            }
        }
    }
    return parcours;
}

// Supprime un article en fonction de son identifiant
encyclopedie supprimer(encyclopedie e, long identifiant){
    ptrmaillon_arbre sup_pere = e.premier;
    ptrmaillon_arbre sup_parcours = e.premier;
    ptrmaillon_arbre sup_fils_gauche = sup_parcours->precedent;
    ptrmaillon_arbre sup_fils_droit = sup_parcours->suivant;

    // Acquisition de l'article à supprimer
    sup_parcours = parcours_arbre(e,&sup_pere,sup_parcours,&sup_fils_gauche,&sup_fils_droit,identifiant);

    if(sup_parcours == NULL){ return e; }
    
    ptrmaillon_arbre pere = e.premier;
    ptrmaillon_arbre parcours = e.premier;
    ptrmaillon_arbre fils_gauche = parcours->precedent;
    ptrmaillon_arbre fils_droit = parcours->suivant;
    long racine = pere->art->identifiant;

    // Test si l'élément à supprimer est la racine => Pas possible
    if(sup_parcours->art->identifiant == racine){ printf("\n Impossible de supprimer la racine ! \n"); return e; }

    // Si l'article à supprimer n'a pas de descendance
    if(sup_fils_gauche == NULL && sup_fils_droit == NULL){
        if(sup_pere->art->identifiant > sup_parcours->art->identifiant){
            sup_pere->precedent = NULL;
        } else {
            sup_pere->suivant = NULL;
        }
        free(sup_parcours->art->contenu);
        free(sup_parcours->art->titre);
        free(sup_parcours);
    // S'il y a des descendants 
    }else if(sup_fils_gauche != NULL && sup_fils_droit != NULL){
        // On regarde de quel coté de l'arbre on se trouve
        // Si on est a gauche de la racine -> il faut prendre le plus petit supérieur à l'id de l'article à supprimer
        if(racine > identifiant){
            parcours = sup_fils_droit;
            pere = sup_parcours;
            parcours->suivant = sup_fils_droit->suivant;
            parcours->precedent = sup_fils_droit->precedent;
            while(fils_gauche){
                pere = parcours;
                parcours = fils_gauche;
                fils_droit = parcours->suivant;
                fils_gauche = parcours->precedent;
            }
            // On a trouvé l'id que l'on cherche, on place l'article à l'emplacement de celui à supprimer
            pere->precedent = NULL;
            parcours = sup_parcours;
            free(sup_parcours->art->contenu);
            free(sup_parcours->art->titre);
            free(sup_parcours);
        } else {
            //printf("\n test sup droit \n");
            parcours = sup_fils_gauche;
            pere = sup_parcours;
            parcours->suivant = sup_fils_gauche->suivant;
            parcours->precedent = sup_fils_gauche->precedent;
            // On cherche parcours tous les fils droits
            while(fils_droit){
                pere = parcours;
                parcours = fils_droit;
                fils_droit = parcours->suivant;
                fils_gauche = parcours->precedent;
            }
            // Une fois qu'il n'y a plus de fils droit on part à gauche pour y trouver le plus grand inférieur à l'article à supprimer
            while(fils_gauche){
                pere = parcours;
                parcours = fils_gauche;
                fils_droit = parcours->suivant;
                fils_gauche = parcours->precedent;
            }
            // On a trouvé l'id que l'on cherche, on place l'article à l'emplacement de celui à supprimer
            pere->suivant = NULL;
            sup_pere->suivant = parcours;
            parcours->precedent = sup_parcours->precedent;
            parcours->suivant = sup_parcours->suivant;
            free(sup_parcours->art->contenu);
            free(sup_parcours->art->titre);
            free(sup_parcours);
        }
    }else if(sup_fils_gauche != NULL || sup_fils_droit != NULL){
        if(sup_fils_droit != NULL){
            sup_pere->precedent = sup_parcours->suivant;
        } else {
            sup_pere->precedent = sup_parcours->precedent;
        }
        free(sup_parcours->art->contenu);
        free(sup_parcours->art->titre);
        free(sup_parcours);
    }
    return e;
}


// Créer une encyclopédie contenant tous les articles contenant une chaine de caractères précise
encyclopedie rechercher_article_plein_texte(encyclopedie e, char* mot){
    encyclopedie e_recherche = creer_encyclopedie();
    ptrmaillon_arbre pere = e.premier;
    ptrmaillon_arbre parcours = e.premier;
    ptrmaillon_arbre fils_gauche = parcours->precedent;
    ptrmaillon_arbre fils_droit = parcours->suivant;
    e_recherche = parcours_arbre_recherche(e,e_recherche,pere,parcours,fils_gauche,fils_droit,mot);
    return e_recherche;
}

// Parcours de l'arbre pour recherche plein texte
encyclopedie parcours_arbre_recherche(encyclopedie e, encyclopedie e_recherche,ptrmaillon_arbre pere, ptrmaillon_arbre parcours, ptrmaillon_arbre fils_gauche, ptrmaillon_arbre fils_droit, char* mot){
    ptrarticle current = parcours->art;
    // On commence le parcours par l'hémisphère gauche
    if (fils_gauche){
        pere = parcours;
        parcours = fils_gauche;
        fils_droit = parcours->suivant;
        fils_gauche = parcours->precedent;
        e_recherche = parcours_arbre_recherche(e,e_recherche,pere,parcours,fils_gauche,fils_droit,mot);
        parcours = pere;
        fils_gauche = parcours->precedent;
        fils_droit = parcours->suivant;
    }
    if (fils_droit){
        pere = parcours;
        parcours = fils_droit;
        fils_droit = parcours->suivant;
        fils_gauche = parcours->precedent;
        e_recherche = parcours_arbre_recherche(e,e_recherche,pere,parcours,fils_gauche,fils_droit,mot);
        parcours = pere;
        fils_gauche = parcours->precedent;
        fils_droit = parcours->suivant;
    }
    // On test si l'article continent la chaine -> si oui, on l'ajoute à notre encyclopédie de recherche
    if(strstr(current->contenu,mot)){
        e_recherche = inserer(e_recherche,current->identifiant,current->titre,current->contenu);
    }
    return e_recherche;
}

// Détruit l'encyclopédie
encyclopedie detruire_encyclopedie(encyclopedie e){
    ptrmaillon_arbre pere = e.premier;
    ptrmaillon_arbre parcours = e.premier;
    ptrmaillon_arbre fils_gauche = parcours->precedent;
    ptrmaillon_arbre fils_droit = parcours->suivant;
    e = parcours_detruire_encyclopedie(e,pere,parcours,fils_gauche,fils_droit);
    return e;
}

// Parcours de l'encyclopédie en supprimer tous les articles
encyclopedie parcours_detruire_encyclopedie(encyclopedie e,ptrmaillon_arbre pere, ptrmaillon_arbre parcours, ptrmaillon_arbre fils_gauche, ptrmaillon_arbre fils_droit){
    // Parcours de l'encyclopédie en commençant pas l'hémisphère gauche
    if (fils_gauche){
        pere = parcours;
        parcours = fils_gauche;
        fils_droit = parcours->suivant;
        fils_gauche = parcours->precedent;
        e = parcours_detruire_encyclopedie(e,pere,parcours,fils_gauche,fils_droit);
        parcours = pere;
        fils_gauche = parcours->precedent;
        fils_droit = parcours->suivant;
    }
    if (fils_droit){
        pere = parcours;
        parcours = fils_droit;
        fils_droit = parcours->suivant;
        fils_gauche = parcours->precedent;
        e = parcours_detruire_encyclopedie(e,pere,parcours,fils_gauche,fils_droit);
        parcours = pere;
        fils_gauche = parcours->precedent;
        fils_droit = parcours->suivant;
    }
/*  afficher_article(pere->art);
    afficher_article(parcours->art);   
    afficher_article(fils_gauche->art);
    afficher_article(fils_droit->art); */ 
    free(parcours->art->contenu);
    free(parcours->art->titre);
    free(parcours);
    return e;
}
