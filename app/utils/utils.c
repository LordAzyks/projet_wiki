#include "utils.h"

ptrarticle creer_article(long identifiant, char *titre, char *contenu) {
    ptrarticle nouveau;
    nouveau = (ptrarticle)malloc(sizeof(article));
    nouveau->identifiant = identifiant;

    nouveau->titre = (char*)malloc(sizeof(char)*(strlen(titre)+1));
    strcpy(nouveau->titre,titre);

    nouveau->contenu = (char*)malloc(sizeof(char)*(strlen(contenu)+1));
    strcpy(nouveau->contenu,contenu);
    
    return nouveau;
}

void afficher_article(ptrarticle a) {
    printf("\033[0;32mID: %ld\n",a->identifiant);
    printf("Titre: %s\n",a->titre);
    printf("\033[0m[PREVIEW]\n\033[0;31m%1.300s..\033[0m\n",a->contenu);
    printf("----------------------------------------------------------------------------------------------------------\n");
}
