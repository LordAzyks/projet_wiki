#include "utils.h"

ptrarticle creer_article(long identifiant, char *titre, char *contenu){
    ptrarticle nouveau;
    nouveau = (ptrarticle)malloc(sizeof(article));
    nouveau->identifiant = identifiant;
    nouveau->titre = titre;
    nouveau->contenu = contenu;
    return nouveau;
}
