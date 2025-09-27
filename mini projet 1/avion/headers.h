#ifndef HEADERS_H
#define HEADERS_H
#define MAX 100
#include <string.h>

extern int choise;
extern int id[MAX];
extern int capacite[MAX];
extern char modele[MAX][20];
extern char status[MAX][20];
extern char date_entree[MAX][20];
extern int counter;

void ajouter_avion();
int lister_avions();
int modifier_avion();
int supprimer_avion();
int rechercher_avion();

#endif