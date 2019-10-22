#include "header.h"

int main(){
    encyclopedie e = creer_encyclopedie();

    e = remplissage_encyclopedie(e);

    afficher_encyclopedie(e);

    e = detruire_encyclopedie(e);

    return 0;
}