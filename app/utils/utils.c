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
    printf("\033[0;31mID = %ld\n",a->identifiant);
    printf("Titre: %s\n",a->titre);
    printf("%s\033[0m\n",a->contenu);
    printf("-------------\n");
}
