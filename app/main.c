#include "header.h"


void remplissage_encyclopedie(encyclopedie e){

    FILE *fichier;
    if (!(fichier = fopen("../ressources/test.dat","r"))){
        printf("Erreur à l'ouverture du fichier");
    } else {
        char *chaine = malloc (sizeof(char) * 100000);
        while (! feof(fichier)){
            fgets(chaine, 100000 , fichier);
            char *segment = malloc (sizeof(char) * 100000);
            int compteur = 1;
            int id_val;
            char *identification = malloc (sizeof(char) * 100);
            char *titre = malloc (sizeof(char) * 100);
            char *contenu = malloc (sizeof(char) * 100000);
            segment = strtok (chaine,"|");
            while (segment != NULL)
            {
                if (compteur == 1){
                    identification = segment;
                    id_val = atoi(identification);
                } else if (compteur == 2){
                    titre = segment;    
                } else {
                    contenu = segment; 
                }
                segment = strtok (NULL, "|");
                compteur++;
            }
            printf(" ID : %s \n Titre : %s \n Contenu : %s \n", identification, titre, contenu);
            inserer(e,id_val,titre,contenu);
        }
        free(chaine);
    }
    fclose(fichier);

}

int main(){
    encyclopedie e = creer_encyclopedie();
    printf("création encyclo \n");
    
    e = inserer(e,1,"test1","test");
    e = inserer(e,2,"test2","test");
    e = inserer(e,3,"test3","test");

    remplissage_encyclopedie(e);
    //afficher_encyclopedie(e);

    return 0;
}