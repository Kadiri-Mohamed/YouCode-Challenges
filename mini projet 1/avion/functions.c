#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers.h"

Avion avions[MAX];
int counter = 0;
int counter_id = 0;

void ajouter_avion(Avion table[MAX])
{
    int status_choise;
    int num_avions;
    printf("Combien d'avions ? ");
    scanf("%d", &num_avions);

    if (counter + num_avions >= MAX)
    {
        printf("\033[31m"
               "Impossible d'ajouter %d avions. Capacite maximale depassee.\n"
               "\033[0m",
               num_avions);
        return;
    }

    for (int i = 0; i < num_avions; i++)
    {
        table[counter].id = counter_id + 1;

        printf("Donner le modele d'avion: ");
        scanf(" %[^\n]", table[counter].modele);

        printf("Donner la capacite d'avion: ");
        scanf("%d", &table[counter].capacite);

        printf("Donner le status d'avion [1:disponible ,2:En maintenece ,3:En vole]: ");
        scanf("%d", &status_choise);
        switch (status_choise)
        {
        case 1:
            strcpy(table[counter].status, "Disponible");
            break;
        case 2:
            strcpy(table[counter].status, "En maintenece");
            break;
        case 3:
            strcpy(table[counter].status, "En vole");
            break;
        default:
            strcpy(table[counter].status, "Status invalide");
            break;
        }

        printf("Donner la date d'entree d'avion (JJ/MM/AAAA): ");
        scanf(" %[^\n]", table[counter].date_entree);

        printf("\033[32m"
               "Avion ajoute avec succes avec l'id = %d\n"
               "\033[0m",
               table[counter].id);
        counter_id++;
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

void lister_avions(Avion table[MAX])
{
    if (counter == 0)
    {
        printf("\033[33m"
               "Aucun avion dans la liste\n"
               "\033[0m");
        return;
    }

    printf("Liste des avions:\n");
    for (int i = 0; i < counter; i++)
    {
        printf("Avion %d \n", i + 1);
        printf("\033[33m"
               "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n"
               "\033[0m",
               table[i].id, table[i].modele, table[i].capacite, table[i].status, table[i].date_entree);
        printf("---------------------------------------------------------------------------- \n");
    }
}

void modifier_avion(int searched_id, Avion table[MAX])
{
    int status_choise;
    int found = 0;

    for (int i = 0; i < counter; i++)
    {
        if (searched_id == table[i].id)
        {
            found = 1;
            printf("Donner le modele d'avion: ");
            scanf(" %[^\n]", table[i].modele);

            printf("Donner la capacite d'avion: ");
            scanf("%d", &table[i].capacite);

            printf("Donner le status d'avion [1:disponible ,2:En maintenece ,3:En vole]: ");
            scanf("%d", &status_choise);
            switch (status_choise)
            {
            case 1:
                strcpy(table[i].status, "Disponible");
                break;
            case 2:
                strcpy(table[i].status, "En maintenece");
                break;
            case 3:
                strcpy(table[i].status, "En vole");
                break;
            default:
                strcpy(table[i].status, "Status invalide");
                break;
            }

            printf("Donner la date d'entree d'avion: ");
            scanf(" %[^\n]", table[i].date_entree);

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

    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter - i - 1; j++)
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

void tri_avions_capacite(Avion table[MAX])
{
    Avion temp;

    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter - i - 1; j++)
        {
            if (table[j].capacite > table[j + 1].capacite)
            {
                temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}

void tri_avions(int tri_choise, Avion table[MAX])
{
    switch (tri_choise)
    {
    case 1:
        tri_avions_capacite(table);
        lister_avions(table);
        break;

    case 2:
        tri_avions_model(table);
        lister_avions(table);
        break;
    default:
        break;
    }
}

int rechercher_model(char searched_model[20], Avion table[MAX])
{
    tri_avions_model(table);

    int start = 0, end = counter - 1;
    int center;

    while (start <= end)
    {
        center = (start + end) / 2;

        int comparison = strcasecmp(table[center].modele, searched_model);

        if (comparison == 0)
        {
            printf("\033[32m"
                   "Avion trouve: ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n"
                   "\033[0m",
                   table[center].id, table[center].modele, table[center].capacite,
                   table[center].status, table[center].date_entree);
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
    return 0;
}

int rechercher_id(int searched_id, Avion table[MAX])
{
    int found = 0;

    for (int i = 0; i < counter; i++)
    {
        if (searched_id == table[i].id)
        {
            found = 1;
            printf("\033[32m"
                   "ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n"
                   "\033[0m",
                   table[i].id, table[i].modele, table[i].capacite, table[i].status, table[i].date_entree);
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
    return 0;
}

void rechercher_avion(int search_choise, Avion table[MAX])
{
    switch (search_choise)
    {
    case 1:
    {
        int searched_id;
        printf("Entrez un id: ");
        scanf("%d", &searched_id);
        rechercher_id(searched_id, table);
        break;
    }
    case 2:
    {
        char searched_model[20];
        printf("Entrez un model: ");
        scanf(" %[^\n]", searched_model);
        rechercher_model(searched_model, table);
        break;
    }
    default:
        break;
    }
}

void supprimer_avion(int searched_id, Avion table[MAX])
{
    int found = 0;
    for (int i = 0; i < counter; i++)
    {
        if (searched_id == table[i].id)
        {
            found = 1;
            for (int j = i; j < counter - 1; j++)
            {
                table[j] = table[j + 1];
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

void get_min_max_capacite(Avion table[MAX])
{
    tri_avions_capacite(table);

    printf("\033[32m"
           "Grand capacite : %d , avions id : %d \n"
           "\033[0m",
           table[counter - 1].capacite, table[counter - 1].id);
    printf("\033[32m"
           "Petite capacite : %d , avions id : %d \n"
           "\033[0m",
           table[0].capacite, table[0].id);
}

void get_somme_capacite(Avion table[MAX])
{
    int somme = 0;
    for (int i = 0; i < counter; i++)
    {
        somme += table[i].capacite;
    }
    printf("\033[32m"
           "la somme des capacites est : %d\n"
           "\033[0m",
           somme);
}

void get_somme_status(Avion table[MAX])
{
    int count = 0;
    int status_choise;
    printf("Entrez le status tu veux calculer : ");
    scanf("%d", &status_choise);

    switch (status_choise)
    {
    case 1:
        for (int i = 0; i < counter; i++)
        {
            if (strcasecmp(table[i].status, "Disponible"))
            {
                count++;
            }
        }
        printf("le nombre des avions avec status disponible :%d" , count);
        break;
    case 2:
        for (int i = 0; i < counter; i++)
        {
            if (strcasecmp(table[i].status, "En maintenece"))
            {
                count++;
            }
        }
        printf("le nombre des avions avec status en maintenece :%d" , count);

        break;
    case 3:
        for (int i = 0; i < counter; i++)
        {
            if (strcasecmp(table[i].status, "En vole"))
            {
                count++;
            }
        }
        printf("le nombre des avions avec status en vole :%d" , count);

        break;
    default:
        printf("choix invalide\n");
        break;
    }
    
}

void main_menu()
{
    int choise;

    do
    {
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
            printf("_______________________________________________\n");
            ajouter_avion(avions);
            break;
        case 2:
            system("cls");
            printf("_______________________________________________\n");
            int searched_id_m;
            printf("Entrez un id: ");
            scanf("%d", &searched_id_m);
            modifier_avion(searched_id_m, avions);
            break;
        case 3:
            system("cls");
            printf("_______________________________________________\n");
            int searched_id_s;
            printf("Entrez un id: ");
            scanf("%d", &searched_id_s);
            supprimer_avion(searched_id_s, avions);
            break;
        case 4:
            system("cls");
            printf("_______________________________________________\n");
            lister_avions(avions);
            break;
        case 5:
            system("cls");
            printf("_______________________________________________\n");
            int search_choise;
            printf("Donner le mode de recherche [1:id ,2:modele]: ");
            scanf("%d", &search_choise);
            rechercher_avion(search_choise, avions);
            break;
        case 6:
            system("cls");
            printf("_______________________________________________\n");
            int tri_choise;
            printf("Donner le mode de tri [1:capacite ,2:modele]: ");
            scanf("%d", &tri_choise);
            tri_avions(tri_choise, avions);
            break;
        case 7:
            system("cls");
            printf("_______________________________________________\n");
            get_min_max_capacite(avions);
            break;
        case 8:
            system("cls");
            printf("_______________________________________________\n");
            get_somme_capacite(avions);
            break;
        case 9:
            system("cls");
            printf("_______________________________________________\n");
            get_somme_status(avions);
            break;
        case 0:
            system("cls");
            printf("_______________________________________________\n");
            printf("End of programme\n");
            break;
        default:
            system("cls");
            printf("_______________________________________________\n");
            printf("choix invalide\n");
            break;
        }

    } while (choise != 0);
}
