#include <stdio.h>
#include <string.h>
#include "fichiers.h"
#include "jeu.h"
#include "affichage.h"
#include "random.h"

void enregistrer_pseudo(const char *pseudo){
    FILE* fichier = fopen("pseudos.txt","a+");
    if (!fichier){
        printf("Erreur : Impossible d'ouvrir le fichier des pseudos.\n");
        return;
    }
    char ligne[50];
    int existe = 0;

    while (fgets(ligne, sizeof(ligne),fichier)){
        ligne[strcspn(ligne, "\n")]='\0';
        if (strcmp(ligne,pseudo)==0){
            existe=1;
            break;
        }
    }
    if (!existe){
        fprintf(fichier, "%s\n", pseudo);
        printf("Pseudo '%s' enregistré avec succès.\n",pseudo);

    }else{
        printf("Pseudo '%s' enregistré.\n", pseudo);
    }
    fclose(fichier);
}
void enregistrer_partie(const char *pseudo, Niveau niveau, int tentatives[], int taille, float ecart_type){
   FILE *fichier = fopen("parties.dat","ab");
   if (!fichier){
    printf("Erreur: Impossible d'ouvrir le fichier des partie.\n");
    return;
   }
   struct Partie {
       char pseudo[50];
       Niveau niveau;
       int tentatives[100];
       int taille;
       double ecart_type;
   }partie;
   strncpy(partie.pseudo, pseudo, sizeof(partie.pseudo));
   partie.niveau= niveau;
   memcpy(partie.tentatives,tentatives, taille*sizeof(int));
   partie.taille = taille;
   partie.ecart_type = ecart_type;

   fwrite(&partie, sizeof(partie),1,fichier);
   printf("Partie enregistree avec succes.\n");
   fclose(fichier);

}

void consulter_archives(){
    FILE *fichier = fopen("parties.dat","rb");
    if(!fichier){
        printf("Aucune archive disponible.\n");
        return;
    }
    struct Partie {
       char pseudo[50];
       Niveau niveau;
       int tentatives[100];
       int taille;
       double ecart_type;
   }partie;
   printf("===Archives des parties===");
   while (fread(&partie, sizeof(partie),1, fichier)){
    printf("Pseudo : %s \n", partie.pseudo);
    printf("Niveau (%d-%d), tentatives max : %d\n", partie.niveau.borne_min, partie.niveau.borne_max, partie.niveau.tentatives_max);
    printf("Tentatives : ");
    for (int i = 0; i<partie.taille; i++){
        printf("%d", partie.tentatives[i]);
    }
    printf("Ecart type : %2.f\n", partie.ecart_type);


   }
   fclose(fichier);

}
