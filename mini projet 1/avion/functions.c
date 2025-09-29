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

        printf("\033[32m"
               "Avion ajoute avec succes avec l'id = %d\n"
               "\033[0m",
               avions[counter - 1].id);

        counter++;
    }
    if (counter >= MAX)
    {
        printf("\033[32m"
               "La liste est complete\n"
               "\033[0m");
        return;
    }
}

void lister_avions()
{
    printf("Liste des avions:\n");
    for (int i = 0; i < counter - 1; i++)
    {
        printf("Avion %d \n", i + 1);
        printf("\033[33m"
               "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n"
               "\033[0m",
               avions[i].id, avions[i].modele, avions[i].capacite, avions[i].status, avions[i].date_entree);
        printf("---------------------------------------------------------------------------- \n");
    }
}

void modifier_avion(int searched_id)
{
    int status_choise;

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

            printf("\033[32m"
                   "Modification reussie!\n"
                   "\033[0m");
            break;
        }
    }

    if (!found)
    {
        printf("\033[31m"
               "Avion avec ID %d non trouve\n"
               "\033[0m",
               searched_id);
    }
}
void tri_avions_model(Avion table[MAX])
{
    Avion temp;

    for (int i = 0; i < counter - 2; i++)
    {
        for (int j = 0; j < counter - i - 2; j++)
        {
            if (strcasecmp(table[j].modele, table[j + 1].modele) > 0)
            {
                temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}

void tri_avions(int tri_choise)
{

    switch (tri_choise)
    {

    // case 1:
    //     char searched_model[10];
    //     printf("Entrez un model: ");
    //     scanf(" %[^\n]", &searched_model);
    //     rechercher_model(searched_model);
    //     break;
    case 2:
        tri_avions_model(avions);
        lister_avions();
        break;
    default:

        break;
    }
}
int rechercher_model(char searched_model[20]) 
{
    tri_avions_model(avions);

    int start = 0, end = counter - 2;
    int center;

    while (start <= end)
    {
        center = (start + end) / 2;

        int comparison = strcasecmp(avions[center].modele, searched_model);

        if (comparison == 0)
        {
            printf("\033[32m"
                   "Avion trouve: ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n"
                   "\033[0m",
                   avions[center].id, avions[center].modele, avions[center].capacite,
                   avions[center].status, avions[center].date_entree);
            return 1;
        }
        else if (comparison < 0)
        {
            start = center + 1;
        }
        else
        {
            end = center - 1;
        }
    }
}
int rechercher_id(int searched_id)
{
    int found = 0;

    for (int i = 0; i < counter; i++)
    {
        if (searched_id == avions[i].id)
        {
            found = 1;
            printf("\033[32m"
                   "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n"
                   "\033[0m",
                   avions[i].id, avions[i].modele, avions[i].capacite, avions[i].status, avions[i].date_entree);
            printf("---------------------------------------------------------------------------- \n");
            return 1;
        }
    }
    if (!found)
    {
        printf("\033[31m"
               "Avion avec ID %d non trouve\n"
               "\033[0m",
               searched_id);
    }
}

void rechercher_avion(int search_choise)
{

    switch (search_choise)
    {
    case 1:
        int searched_id;
        printf("Entrez un id: ");
        scanf("%d", &searched_id);
        rechercher_id(searched_id);
        break;
    case 2:
        char searched_model[10];
        printf("Entrez un model: ");
        scanf(" %[^\n]", &searched_model);
        rechercher_model(searched_model);
        break;
    default:

        break;
    }
}

void supprimer_avion(int searched_id)
{

    int found = 0;
    for (int i = 0; i < counter; i++)
    {
        if (searched_id == avions[i].id)
        {
            found = 1;
            for (int j = i; j < counter - 1; j++)
            {
                avions[j].id = avions[j + 1].id;
                strcpy(avions[j].modele, avions[j + 1].modele);
                avions[j].capacite = avions[j + 1].capacite;
                strcpy(avions[j].status, avions[j + 1].status);
                strcpy(avions[j].date_entree, avions[j + 1].date_entree);
            }
            counter--;
            printf("\033[32m"
                   "Avion avec ID %d supprime avec succes\n"
                   "\033[0m",
                   searched_id);
            break;
        }
    }
    if (!found)
    {
        printf("\033[31m"
               "Avion avec ID %d non trouve\n"
               "\033[0m",
               searched_id);
    }
}

void main_menu()
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
        printf("Pour tri la liste des avions entrez 6\n");
        printf("Pour quitter entrez 0\n");

        printf("Entrez votre choix: ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            system("cls");
            ajouter_avion();
            break;
        case 2:
            system("cls");
            int searched_id_m;
            printf("Entrez un id: ");
            scanf("%d", &searched_id_m);
            modifier_avion(searched_id_m);
            break;
        case 3:
            system("cls");
            int searched_id_s;
            printf("Entrez un id: ");
            scanf("%d", &searched_id_s);
            supprimer_avion(searched_id_s);
            break;
        case 4:
            system("cls");
            lister_avions();
            break;
        case 5:
            system("cls");
            int search_choise;
            printf("Donner le mode de recherche [1:id ,2:modele]: ");
            scanf("%d", &search_choise);
            rechercher_avion(search_choise);
            break;
        case 6:
            system("cls");
            int tri_choise;
            printf("Donner le mode de tri [1:capacite ,2:modele]: ");
            scanf("%d", &tri_choise);
            tri_avions(tri_choise);
            break;
        case 0:
            system("cls");
            printf("End of programme\n");
            break;
        default:
            printf("choix invalide\n");
            break;
        }

    } while (choise != 0);
}