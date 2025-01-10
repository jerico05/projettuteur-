#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifndef JEU_H
#define JEU_H
#include "random.h"

typedef struct {
    int borne_min;
    int borne_max;
    int tentatives_max;
}Niveau;
//prototypes des fonctions

void enregistrer_tentatives(int tentatives[], int *taille, int tentatives_utilisees );
double calculer_ecart_type(const int tentatives[], int taille);
void choisir_niveau(Niveau *niveau);
void jouer_partie(const char*pseudo, Niveau niveau);
#endif // JEU_H
