#ifndef HEADERS_H
#define HEADERS_H
#define MAX 100
#define Title "Application de gestion aeroport fictif et son parc d'avions"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char modele[20];
    int capacite;
    char status[20];
    char date_entree[20];
} Avion;

void ajouter_avion();
void lister_avions();
void modifier_avion(int searched_id);
void supprimer_avion(int searched_id);
void rechercher_avion(int search_choise);
void get_min_max_capacite(Avion table[MAX]);
void get_somme_capacite(Avion table[MAX]);
void main_menu();

#endif