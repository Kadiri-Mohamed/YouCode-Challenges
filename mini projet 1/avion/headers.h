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

void ajouter_avion(Avion table[MAX]);
void lister_avions(Avion table[MAX]);
void modifier_avion(int searched_id,Avion table[MAX]);
void supprimer_avion(int searched_id,Avion table[MAX]);
void tri_avions(int tri_choise, Avion table[MAX]);
void rechercher_avion(int search_choise,Avion table[MAX]);
void get_min_max_capacite(Avion table[MAX]);
void get_somme_capacite(Avion table[MAX]);
void get_somme_status(Avion table[MAX]);
void main_menu();

#endif