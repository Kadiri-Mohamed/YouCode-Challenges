#include <stdio.h>
#include "headers.h"

// Define global variables in ONE .c file only
int choise;
int id[MAX];
char modele[MAX][20];
int capacite[MAX];
char status[MAX][20];
char date_entree[MAX][20];
int counter = 1;

void ajouter_avion()
{
    if (counter >= MAX) 
    {
        printf("La liste est complete\n");
        return;
    }
    
    id[counter - 1] = counter;
    printf("Donner le modele d'avion: ");
    scanf(" %[^\n]", modele[counter - 1]); 
    printf("Donner la capacite d'avion: ");
    scanf("%d", &capacite[counter - 1]);    
    printf("Donner le status d'avion: ");
    scanf(" %[^\n]", status[counter - 1]); 
    printf("Donner la date d'entree d'avion: ");
    scanf(" %[^\n]", date_entree[counter - 1]); 

    counter++;
}

int lister_avions()
{
    printf("Liste des avions:\n");
    for (int i = 0; i < counter - 1; i++) 
    {
        printf("ID: %d, Modele: %s, Capacite: %d, Status: %s, Date d'entree: %s\n", 
               id[i], modele[i], capacite[i], status[i], date_entree[i]);
    }
    return 0;
}

int modifier_avion()
{
    printf("Modifier fonctionnalite a implementer\n");
    return 0;
}

int supprimer_avion()
{
    printf("Supprimer fonctionnalite a implementer\n");
    return 0;
}

int rechercher_avion()
{
    printf("Rechercher fonctionnalite a implementer\n");
    return 0;
}