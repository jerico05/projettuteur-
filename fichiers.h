#ifndef FICHIERS_H
#define FICHIERS_H

#include "jeu.h"

void enregistrer_pseudo(const char *pseudo);
void enregistrer_partie(const char *pseudo, Niveau niveau, int tentatives[], int taille, float ecart_type);
void consulter_archives();
#endif // FICHIERS_H
