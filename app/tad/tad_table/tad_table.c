#include "tad_table.h"
int TAILLE = 1000;

ptrtable creer_table(int taille) {
    ptrtable table = (ptrtable)malloc(sizeof(table));
    table->taille = taille;
    table->liste = (ptrmaillon*)malloc(sizeof(ptrmaillon)*taille);
    int i;
    for(i=0; i<taille; i++)
        table->liste[i] = NULL;
    return table;
}

int hachage(ptrtable table, long identifiant) {
    return identifiant%table->taille;
}

encyclopedie inserer(encyclopedie e, long identifiant, char *titre, char *contenu) {
    if ( e.premier == NULL) {
        e.premier = creer_table(TAILLE);
    }
    ptrtable table = e.premier;
    long position = hachage(table,identifiant);
    ptrmaillon nouveau;
    nouveau = (ptrmaillon)malloc(sizeof(maillon));
    nouveau->art = creer_article(identifiant,titre,contenu);
    nouveau->suivant = table->liste[position];
    table->liste[position] = nouveau;
    return e;
}

void afficher_encyclopedie(encyclopedie e) {
    ptrtable table = e.premier;
    if ( table ) {
        for (int i=0; i < table->taille; i++) {
            ptrmaillon parcours = table->liste[i];
            while( parcours ) {
                afficher_article(parcours->art);

                parcours = parcours->suivant;
            }
        }
    } else {
        printf("L'encyclopedie est vide\n");
    }
}

encyclopedie supprimer(encyclopedie e, long identifiant) {
    ptrtable table = e.premier;
    if ( table ) {
        long position = hachage(table,identifiant);
        ptrmaillon parcours = table->liste[position];
        ptrmaillon precedent = NULL;
        while( parcours ) {
            if( parcours->art->identifiant == identifiant) {
                free(parcours->art->titre);
                free(parcours->art->contenu);
                free(parcours->art);
                if( !precedent ) {
                    table->liste[position] = parcours->suivant;
                    
                } else {
                    precedent->suivant = parcours->suivant;
                }
                free(parcours);
                return e;
            }
            precedent = parcours;
            parcours = parcours->suivant;
        }
    } else {
        printf("L'encyclopedie est vide\n");
    }
    return e;
}

char* rechercher_article(encyclopedie e, long identifiant) {
    ptrtable table = e.premier;
    if ( table ) {
        long position = hachage(table,identifiant);
        ptrmaillon correspondant = table->liste[position];
        while( correspondant ) {
            if( correspondant->art->identifiant == identifiant ) {
                return correspondant->suivant->art->contenu;
            }
            correspondant = correspondant->suivant;
        }
    } else {
        printf("L'encyclopedie est vide\n");
    }
    return "Aucune correspondance\n";
}

encyclopedie rechercher_article_plein_texte(encyclopedie e, char* mot) {
    encyclopedie res = creer_encyclopedie();
    ptrtable table = e.premier;
    if ( table ) {
        ptrarticle current;
        for (int i=0; i < table->taille; i++) {
            ptrmaillon parcours = table->liste[i];
            while( parcours ) {
                current = parcours->art;
                if(strstr(current->contenu,mot)){
                    res = inserer(res,current->identifiant,current->titre,current->contenu);
                    i++;
                }

                parcours = parcours->suivant;
            }
        }
    } else {
        printf("L'encyclopedie est vide\n");
    }
    return res;
}

encyclopedie detruire_encyclopedie(encyclopedie e) {
    ptrtable table = e.premier;
    if ( table ) {
        for (int i=0; i < table->taille; i++) {
            ptrmaillon parcours = table->liste[i];
            ptrmaillon tmp;
            while( parcours ) {
                free(parcours->art->titre);
                free(parcours->art->contenu);
                free(parcours->art);
                tmp = parcours;
                parcours = parcours->suivant;
                free(tmp);
            }
        }
        e.premier = NULL;
        free(table->liste);
        free(table);
    } else {
        printf("L'encyclopedie est vide\n");
    }
    return e;
}