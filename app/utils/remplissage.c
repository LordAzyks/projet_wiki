#include "remplissage.h"

encyclopedie remplissage_encyclopedie(encyclopedie e){

    FILE *fichier;
    if (!(fichier = fopen("ressources/B46_wikipedia_500K_random.dat","r"))){
        printf("Erreur à l'ouverture du fichier");
    } else {
        char chaine[500000];
        while (! feof(fichier)){
            fgets(chaine, 500000 , fichier);
            int compteur = 1;
            long id_val;

            char titre[1000];
            char contenu[500000];
            
            char *segment = strtok(chaine,"|");
            while (segment != NULL)
            {
                if (compteur == 1){
                    id_val = atol(segment);
                } else if (compteur == 2){
                    strcpy(titre,segment);
                } else {
                    strcpy(contenu,segment);
                }
                segment = strtok(NULL, "|");
                compteur++;
            }
            e = inserer(e,id_val,titre,contenu);
        }
    }
    fclose(fichier);
    return e;
}