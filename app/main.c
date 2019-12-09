#include "header.h"

void clear_term() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main(){
    long id = 0;
    char str[500];
    char quit[20];

    encyclopedie e = creer_encyclopedie();
    printf("Une encyclopedie a ete creee.\n");
    e = remplissage_encyclopedie(e);

    int choix = -1;
    while(choix) {
        clear_term();
        printf("\nQue voulez vous faire ? :\n");
        printf("1 : Afficher l'encyclopedie\n");
        printf("2 : Rechercher un article par identifiant\n");
        printf("3 : Recherche plein texte\n");
        printf("4 : Supprimer un article par identifiant\n");
        printf("0 : Quitter\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 0:
            detruire_encyclopedie(e);
            printf("Aurevoir !\n");
            break;

        case 1:
            afficher_encyclopedie(e);
            printf("Taper un caractere pour quitter\n");
            scanf("%s",quit);
            break;

        case 2:
            printf("Quel est l'identifiant de l'article a rechercher ?\n");
            scanf("%ld",&id);
            printf("%s\n",rechercher_article(e,id));
            break;

        case 3:
            printf("Que voulez vous rechercher ?\n");
            scanf("%s",str);
            afficher_encyclopedie(rechercher_article_plein_texte(e,str));
            break;

        case 4:
            printf("Quel est l'identifiant de l'article a supprimer ?\n");
            scanf("%ld",&id);
            e = supprimer(e,id);
            break;

        default:
        printf("Commande invalide\n");
            break;
        }
    }

    return 0;
}
