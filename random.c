#include <stdlib.h>
#include <time.h>
#include "random.h"
#include "jeu.h"
#include "fichiers.h"

int generer_nombre_aleatoire(int borne_min, int borne_max){
    static int initialise=0;
    if (!initialise){
        srand(time(NULL));
        initialise=1;
    }
    return (rand()%(borne_max-borne_min+1))+borne_min;
}
