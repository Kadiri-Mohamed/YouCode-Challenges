#include <stdio.h>
#include "headers.h"

typedef struct
{
    int id;
    char modele[20];
    int capacite;
    char status[20];
    char date_entree[20];
} Avion;
Avion avions[MAX];
int counter = 1;

void ajouter_avion()
{
    int status_choise;
    int num_avions;
    printf("Combien d'avions ? ");
    scanf("%d", &num_avions);
    for (int i = 0; i < num_avions; i++)
    {

        avions[counter - 1].id = counter;

        printf("Donner le modele d'avion: ");
        scanf(" %[^\n]", avions[counter - 1].modele);

        printf("Donner la capacite d'avion: ");
        scanf("%d", &avions[counter - 1].capacite);

        printf("Donner le status d'avion [1:disponible ,2:En maintenece ,3:En vole]: ");
        scanf("%d", &status_choise);
        switch (status_choise)
        {
        case 1:
            strcpy(avions[counter - 1].status, "Disponible");
            break;
        case 2:
            strcpy(avions[counter - 1].status, "En maintenece");
            break;
        case 3:
            strcpy(avions[counter - 1].status, "En vole");
            break;
        default:
            strcpy(avions[counter - 1].status, "Status invalide");
            break;
        }

        printf("Donner la date d'entree d'avion (JJ/MM/AAAA): ");
        scanf(" %[^\n]", avions[counter - 1].date_entree);

        printf("\033[32m" "Avion ajoute avec succes avec l'id = %d\n" "\033[0m", avions[counter - 1].id);

        counter++;
    }
    if (counter >= MAX)
    {
        printf("\033[32m" "La liste est complete\n" "\033[0m");
        return;
    }
        
}

int lister_avions()
{
    printf("Liste des avions:\n");
    for (int i = 0; i < counter - 1; i++)
    {
        printf("Avion %d \n", i + 1);
        printf("\033[33m" "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n" "\033[0m", avions[i].id, avions[i].modele, avions[i].capacite, avions[i].status, avions[i].date_entree);
        printf("---------------------------------------------------------------------------- \n");
    }
    return 0;
}

int modifier_avion()
{
    int searched_id;
    int status_choise;
    printf("Entrez un id: ");
    scanf("%d", &searched_id);

    int found = 0;
    for (int i = 0; i < counter; i++)
    {
        if (searched_id == avions[i].id)
        {
            found = 1;
            printf("Donner le modele d'avion: ");
            scanf(" %[^\n]", avions[i].modele);

            printf("Donner la capacite d'avion: ");
            scanf("%d", &avions[i].capacite);

            printf("Donner le status d'avion [1:disponible ,2:En maintenece ,3:En vole]: ");
            scanf("%d", &status_choise);
            switch (status_choise)
            {
            case 1:
                strcpy(avions[i].status, "Disponible");
                break;
            case 2:
                strcpy(avions[i].status, "En maintenece");
                break;
            case 3:
                strcpy(avions[i].status, "En vole");
                break;
            default:
                strcpy(avions[i].status, "Status invalide");
                break;
            }

            printf("Donner la date d'entree d'avion: ");
            scanf(" %[^\n]", avions[i].date_entree);

            printf("\033[32m" "Modification reussie!\n" "\033[0m" );
            break;
        }
    }

    if (!found)
    {
        printf("\033[31m" "Avion avec ID %d non trouve\n" "\033[0m", searched_id);
    }

    return 0;
}
int rechercher_id(int searched_id)
{
}

int rechercher_avion()
{
}

int supprimer_avion()
{
}

int main_menu()
{
   int choise; 

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
            printf("choix invalide\n");
            break;
        }

    } while (choise != 0);
}