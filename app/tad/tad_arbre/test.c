#include "../../header.h"

int main(){
    encyclopedie e = creer_encyclopedie();

    e = inserer(e,20,"Racine","Racine Test");
    e = inserer(e,11,"Fils 11","Test 11");
    e = inserer(e,15,"Fils 15","Fils 15");
    e = inserer(e,13,"Fils 13","Fils 13");
    e = inserer(e,12,"Fils 12","Fils 12");
    e = inserer(e,14,"Fils 14","Fils 14");
    e = inserer(e,16,"Fils 16","Test 16");
    e = inserer(e,8,"Fils 8","Fils 8");
    e = inserer(e,5,"Fils 5","Fils 5");
    e = inserer(e,6,"Fils 6","Fils 6");    
    e = inserer(e,3,"Fils 3","Fils 3");
    e = inserer(e,1,"Fils 1","Fils 1");
    e = inserer(e,2,"Fils 2","Fils 2");
    e = inserer(e,40,"Fils 40","Fils 40");
    e = inserer(e,30,"Fils 30","Fils 30");
    e = inserer(e,35,"Fils 35","Fils 35");
    e = inserer(e,55,"Fils 55","Fils 55");
    e = inserer(e,50,"Fils 50","Fils 50");
    e = inserer(e,51,"Fils 51","Fils 51");
    e = inserer(e,41,"Fils 41","Fils 41");
    e = inserer(e,42,"Fils 42","Fils 42");
    e = inserer(e,60,"Fils 60","Fils 60");
    e = inserer(e,59,"Fils 59","Fils 59");
    e = inserer(e,70,"Fils 70","Fils 70");


    //printf("Contenu de l'article : %s \n", recherche_article_arbre(e,1));
    //afficher_encyclopedie_arbre(e);
    //supprimer(e,10);
    //afficher_encyclopedie_arbre(e);

    //encyclopedie recherche = rechercher_article_plein_texte(e,"Test");
    //afficher_encyclopedie_arbre(recherche);
    e = detruire_encyclopedie(e);

    printf(" \n ---- APRES DESTRUCTION ---- \n");
    afficher_encyclopedie_arbre(e);

    return 0;
}