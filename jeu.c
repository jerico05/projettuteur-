#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "jeu.h"
#include "affichage.h"
#include "fichiers.h"
#include "random.h"




//fonction pour choisir un niveaux
void choisir_niveau(Niveau *niveau){
    int choix;
    printf("Choississez un niveau: \n");
    printf("1-Débutant(1 à 100 avec 10 tentatives )\n");
    printf("2- Normal(1 à 500 avec 15 tentatives )\n");
    printf("3- Professionnel ( 1 à 1000 avec 20 tentatives) \n");
    printf("4-Legende (1 à 2000 avec 25 tentatives)\n");
    printf ("Votre choix:");
    scanf("%d",&choix);

    switch (choix){
    case 1 :
        niveau->borne_min=1;
        niveau->borne_max=100;
        niveau->tentatives_max=10;
        break;
    case 2 :
        niveau->borne_min=1;
        niveau->borne_max=500;
        niveau->tentatives_max=15;
        break;
    case 3 :
        niveau->borne_min=1;
        niveau->borne_max=1000;
        niveau->tentatives_max=20;
        break;
    case 4 :
        niveau->borne_min=1;
        niveau->borne_max=2000;
        niveau->tentatives_max=25;
        break;
    default :
        printf("Choix invalide. Par defaut : Niveau Facile.\n");
        niveau->borne_min=1;
        niveau->borne_max=100;
        niveau->tentatives_max=10;
        break;

    }

}

//fonction pour engeristrer une tentative
void enregistrer_tentatives(int tentatives[], int *taille, int tentatives_utilisees){
    if (*taille<100){
        tentatives[*taille]= tentatives_utilisees;
        (*taille)++;

    }else{
          printf("Erreur : Limite de tentatives enregistrees atteinte.\n");

    }

}
//fonction pour calculer l'ecart type
double calculer_ecart_type( const int tentatives[], int taille){
    if(taille==0){
        printf("Erreur: Aucune tentative enregistree.\n");
        return 0.0;
    }
    double somme = 0.0, moyenne, variance = 0;
    for (int i=0; i<taille; i++){
        somme+=tentatives[i];
    }
    moyenne=somme/taille;
    for (int i=0; i<taille; i++){
        variance+=pow(tentatives[i]-moyenne,2);
    }
    variance/=taille;
    return sqrt(variance);

}

//fonction pour jouer une partie
void jouer_partie(const char*pseudo, Niveau niveau){
    int nombre_aleatoire, nombre_saisi, tentatives_utilisees;
    int ecart_type=0;

    nombre_aleatoire=generer_nombre_aleatoire(niveau.borne_min, niveau.borne_max);

    printf("\n===Debut de la partie===\n");
    printf("Salut, %s! Devinez le nombre (entre %d et %d).Vous avez %d tentatives.\n",pseudo,niveau.borne_min, niveau.borne_max, niveau.tentatives_max);

    while(tentatives_utilisees<niveau.tentatives_max){
        printf("Tentative %d/%d :",tentatives_utilisees+1,niveau.tentatives_max);
        scanf("%d", &nombre_saisi);



        if(nombre_saisi==nombre_aleatoire){
            printf("Félicitations %s! Vous avez trouvé le nombre %d en %d tentatives.\n",pseudo,nombre_aleatoire,tentatives_utilisees+1);

            break;

        }else if (nombre_saisi<nombre_aleatoire){
            printf("Plus grand\n");
        }else{
            printf("Plus petit\n");
        }
        tentatives_utilisees++;
    }
    if (tentatives_utilisees==niveau.tentatives_max){
        printf("Dommage %s!, Vous avez epuise toutes vos tentatives, Le nombre aléatoire etait %d.\n", pseudo,nombre_aleatoire);
    }
   //enregistrer les tentatives

}
