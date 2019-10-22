#include "../../header.h"
#include "tad_arbre.h"

int main(){
    encyclopedie e = creer_encyclopedie();

    e = inserer_arbre(e,1,"test","test");

    return 0;
}