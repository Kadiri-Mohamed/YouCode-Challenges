#include <stdio.h>
#include "headers.h"

int choise;
int id[MAX];
char modele[MAX][20];
int capacite[MAX];
char status[MAX][20];
char date_entree[MAX][20];
int counter = 1;

void ajouter_avion()
{
    int status_choise;
    int num_avions;
    printf("Combien d'avions ? ");
    scanf("%d", &num_avions);
    for (int i = 0; i < num_avions; i++)
    {

        id[counter - 1] = counter;

        printf("Donner le modele d'avion: ");
        scanf(" %[^\n]", modele[counter - 1]);

        printf("Donner la capacite d'avion: ");
        scanf("%d", &capacite[counter - 1]);

        printf("Donner le status d'avion [1:disponible ,2:En maintenece ,3:En vole]: ");
        scanf("%d", &status_choise);
        switch (status_choise)
        {
        case 1:
            strcpy(status[counter - 1], "Disponible");
            break;
        case 2:
            strcpy(status[counter - 1], "En maintenece");
            break;
        case 3:
            strcpy(status[counter - 1], "En vole");
            break;
        default:
            strcpy(status[counter - 1], "Status invalide");
            break;
        }

        printf("Donner la date d'entree d'avion (JJ/MM/AAAA): ");
        scanf(" %[^\n]", date_entree[counter - 1]);

        printf("\033[32m" "Avion ajoute avec succes avec l'id = %d\n" "\033[0m", id[counter - 1]);

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
        printf("\033[33m" "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n" "\033[0m", id[i], modele[i], capacite[i], status[i], date_entree[i]);
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
        if (searched_id == id[i])
        {
            found = 1;
            printf("Donner le modele d'avion: ");
            scanf(" %[^\n]", modele[i]);

            printf("Donner la capacite d'avion: ");
            scanf("%d", &capacite[i]);

            printf("Donner le status d'avion [1:disponible ,2:En maintenece ,3:En vole]: ");
            scanf("%d", &status_choise);
            switch (status_choise)
            {
            case 1:
                strcpy(status[i], "Disponible");
                break;
            case 2:
                strcpy(status[i], "En maintenece");
                break;
            case 3:
                strcpy(status[i], "En vole");
                break;
            default:
                strcpy(status[i], "Status invalide");
                break;
            }

            printf("Donner la date d'entree d'avion: ");
            scanf(" %[^\n]", date_entree[i]);

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

int rechercher_model()
{
    char searched_model[10];
    int found = 0;

    printf("Entrez un modele: ");
    scanf(" %[^\n]", searched_model);

    for (int i = 0; i < counter; i++)
    {
        if (strcmp(searched_model, modele[i]) == 0)
        {
            found = 1;
            printf("\033[32m" "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n" "\033[0m", id[i], modele[i], capacite[i], status[i], date_entree[i]);
            printf("---------------------------------------------------------------------------- \n");
            return 1;
        }
    }
    if (!found)
    {
        printf("Avion avec ID %d non trouve\n", searched_model);
    }
}
int rechercher_id(int searched_id)
{

    int found = 0;

    for (int i = 0; i < counter; i++)
    {
        if (searched_id == id[i])
        {
            found = 1;
            printf("\033[32m" "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n" "\033[0m", id[i], modele[i], capacite[i], status[i], date_entree[i]);
            printf("---------------------------------------------------------------------------- \n");
            return id[i];
        }
    }
    if (!found)
    {
        printf("\033[31m" "Avion avec ID %d non trouve\n" "\033[0m", searched_id);
    }
}

int rechercher_avion()
{

    int searched_id;
    int search_choise;
    printf("Donner le mode de recherche [1:id ,2:modele]: ");

    scanf("%d", &search_choise);

    switch (search_choise)
    {
    case 1:
        printf("Entrez un id: ");
        scanf("%d", &searched_id);
        rechercher_id(searched_id);
        break;
    case 2:
        rechercher_model();
        break;
    default:

        break;
    }
}

int supprimer_avion()
{

    int searched_id;
    int found = 0;
    printf("Entrez un id: ");
    scanf("%d", &searched_id);
    for (int i = 0; i < counter; i++)
    {
        if (searched_id == id[i])
        {
            found = 1;
            for (int j = i; j < counter - 1; j++)
            {
                id[j] = id[j + 1];
                strcpy(modele[j], modele[j + 1]);
                capacite[j] = capacite[j + 1];
                strcpy(status[j], status[j + 1]);
                strcpy(date_entree[j], date_entree[j + 1]);
            }
            counter--;
            printf("\033[32m" "Avion avec ID %d supprime avec succes\n" "\033[0m", searched_id);
            break;
        }
    }
    if (!found)
    {
        printf("\033[31m" "Avion avec ID %d non trouve\n" "\033[0m", searched_id);
    }
    return 0;
}

int main_menu(){
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