#include <stdio.h>
#include "headers.h"
int main()
{
    int choise; 

    printf("Application de gestion aeroport fictif et son parc d'avions \n");
    do
    {
        // system("cls");
        printf("Pour ajouter un avion entrez 1\n");
        printf("Pour modifier un avion entrez 2\n");
        printf("Pour supprimer un avion entrez 3\n");
        printf("Pour afficher la liste des avion entrez 4\n");
        printf("Pour Rechercher un avion entrez 5\n");
        printf("Pour quitter entrez 0\n");

        printf("Entrez votre choix: ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            ajouter_avion();
            break;
        case 2:
            modifier_avion();
            break;
        case 3:
            supprimer_avion();
            break;
        case 4:
            lister_avions();
            break;
        case 5:
            rechercher_avion();
            break;
        case 0:
            printf("End of programme\n");
            break;
        default:
            printf("invalide\n");
            break;
        }

    } while (choise != 0);
}