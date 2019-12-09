#include "header.h"
#include <time.h>

void clear_term() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    printf("\n");
}

int main(){
    long id = 0;
    char str[500];
    char quit[20];
    clock_t t;
    double dt;
    encyclopedie r;

    clear_term();

    encyclopedie e = creer_encyclopedie();
    printf("Une encyclopedie a ete creee.\n");
    e = remplissage_encyclopedie(e);

    int choix = -1;
    while(choix) {
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
            printf("Au revoir !\n");
            break;

        case 1:
            afficher_encyclopedie(e);
            printf("Taper un caractere pour quitter\n");
            scanf("%s",quit);
            clear_term();
            break;

        case 2:
            printf("Quel est l'identifiant de l'article a rechercher ?\n");
            scanf("%ld",&id);
            clear_term();
            printf("%s\n",rechercher_article(e,id));
            break;

        case 3:
            printf("Que voulez vous rechercher ?\n");
            scanf("%s",str);
            clear_term();
            t = clock();
            r = rechercher_article_plein_texte(e,str);
            t = clock() - t;
            dt = (double)t / CLOCKS_PER_SEC;
            afficher_encyclopedie(r);
            printf("Recherche effectuee en %lfs\n",dt);
            break;

        case 4:
            printf("Quel est l'identifiant de l'article a supprimer ?\n");
            scanf("%ld",&id);
            clear_term();
            e = supprimer(e,id);
            break;

        default:
            clear_term();
            printf("Commande invalide\n");
            break;
        }
    }

    return 0;
}
