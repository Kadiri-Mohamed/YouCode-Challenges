#ifndef HEADERS_H
#define HEADERS_H
#define MAX 100
#define Title "Application de gestion aeroport fictif et son parc d'avions"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// extern int choise;
// extern int id[MAX];
// extern int capacite[MAX];
// extern char modele[MAX][20];
// extern char status[MAX][20];
// extern char date_entree[MAX][20];
// extern int counter;

void ajouter_avion();
void lister_avions();
void modifier_avion(int searched_id);
void supprimer_avion(int searched_id);
void rechercher_avion(int search_choise);
void main_menu();

#endif