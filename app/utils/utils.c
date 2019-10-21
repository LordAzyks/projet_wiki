#include "utils.h"

ptrarticle creer_article(long identifiant, char *titre, char *contenu) {
    ptrarticle nouveau;
    nouveau = (ptrarticle)malloc(sizeof(article));
    nouveau->identifiant = identifiant;
    nouveau->titre = titre;
    nouveau->contenu = contenu;
    return nouveau;
}

void afficher_article(ptrarticle a) {
    printf("\033[0;31mID: %ld\n",a->identifiant);
    printf("Titre: %s\n",a->titre);
    printf("\033[0m[DEBUT ARTICLE]\n\033[0;31m%1.300s..\033[0m\n[FIN ARTICLE]\n",a->contenu);
    printf("----------------------------------------------------------------------------------------------------------\n");
}
