#include "Code Maxence.h"

void obj_victoire(Joueur joueurs[],char plateau [2*TAILLE-1] [2*TAILLE-1],int nb_joueurs) {
    int i,obj_x, obj_y;
    for (i=0;i<nb_joueurs;i++) {
        if (joueurs->estIA == 1) {
            if (nb_joueurs == 2) {
                if (joueurs->y == 0) {
                    obj_y = 16;
                } else {
                    obj_y=0;
                }
            }
            else if (nb_joueurs == 4) {
                if (joueurs->y == 0) {
                    obj_y = 16;
                }
                else if (joueurs->y == 16) {
                    obj_y=0;
                }
                else if (joueurs->x == 0) {
                    obj_x=16;
                }
                else if (joueurs->x == 16) {
                    obj_x=0;
                }
            }
        }
    }

}

