#include "header.h"

encyclopedie creer_encyclopedie(){
    encyclopedie e;
    e.premier = NULL;
    return e;
}

ptrarticle creer_article(long identifiant, char *titre, char *contenu){
    ptrarticle nouveau;
    nouveau->identifiant = identifiant;
    nouveau->titre = titre;
    nouveau->contenu = contenu;
    return nouveau;
}
