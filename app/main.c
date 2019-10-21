#include "header.h"


encyclopedie remplissage_encyclopedie(encyclopedie e){

    FILE *fichier;
    if (!(fichier = fopen("../ressources/B46_wikipedia_test.dat","r"))){
        printf("Erreur à l'ouverture du fichier");
    } else {
        char *chaine = (char*)malloc(sizeof(char) * 100000);
        while (! feof(fichier)){
            fgets(chaine, 100000 , fichier);
            int compteur = 1;
            long id_val;

            char *titre;
            char *contenu;
            
            char *segment = strtok(chaine,"|");
            while (segment != NULL)
            {
                int size = strlen(segment)+1;
                if (compteur == 1){
                    char *identification = (char*)malloc(sizeof(char)*size);
                    strcpy(identification,segment);
                    id_val = atol(identification);
                } else if (compteur == 2){
                    titre = (char*)malloc(sizeof(char)*size);
                    strcpy(titre,segment);
                } else {
                    contenu = (char*)malloc(sizeof(char)*size);
                    strcpy(contenu,segment);
                }
                segment = strtok(NULL, "|");
                compteur++;
            }
            e = inserer(e,id_val,titre,contenu);
        }
        free(chaine);
    }
    fclose(fichier);
    return e;
}

int main(){
    encyclopedie e = creer_encyclopedie();

    e = remplissage_encyclopedie(e);
    // afficher_encyclopedie(e);

    afficher_encyclopedie(rechercher_article_plein_texte(e,"olympique"));


    return 0;
}