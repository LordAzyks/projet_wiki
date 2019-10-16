#include "header.h"

int main(){
    encyclopedie e = creer_encyclopedie();
    e = inserer(e,1,"test1","test");
    e = inserer(e,2,"test2","test");
    e = inserer(e,3,"test3","test");

    afficher_encyclopedie(e);


    return 0;
}