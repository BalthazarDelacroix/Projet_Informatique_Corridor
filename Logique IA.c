#include "Code Maxence.h"

void obj_victoire(Joueur joueurs[],char plateau [2*TAILLE-1] [2*TAILLE-1],int nb_joueurs,int*obj_x, int*obj_y) {
    int i;
    for (i=0;i<nb_joueurs;i++) {
        if (joueurs[i].estIA == 1) {
            if (nb_joueurs == 2) {
                if (joueurs->y == 0) {
                    *obj_y = 16;
                } else {
                    *obj_y=0;
                }
            }
            else if (nb_joueurs == 4) {
                if (joueurs->y == 0) {
                    *obj_y = 16;
                }
                else if (joueurs->y == 16) {
                    *obj_y=0;
                }
                else if (joueurs->x == 0) {
                    *obj_x=16;
                }
                else if (joueurs->x == 16) {
                    *obj_x=0;
                }
            }
        }
    }

}

void danger_joueur_proche(Joueur joueurs[], char plateau [2*TAILLE-1] [2*TAILLE-1], int nb_joueurs) {
    Joueur ia;
    if (nb_joueurs == 2) {
        int i,j1, j2;
        j1 = 16;
        j2 = 0;
        if(joueurs[0].estIA) ia=joueurs[0];
        else if(joueurs[1].estIA) ia=joueurs[1];
    }
    else {
        if (nb_joueurs == 4) {
            int i,j1_y, j2_y, j3_x, j4_x, dis_1, dis_2, dis_3, dis_4;
            j1_y = 16;
            j2_y = 0;
            j3_x = 16;
            j4_x = 0;
            for (i=0;i<nb_joueurs;i++) {
                if (joueurs[i].estIA == 1) {
                    ia=joueurs[i];
                }
            }
            while ((joueurs[0].y != 16)||(joueurs[1].y != 0)||(joueurs[2].x != 16)||(joueurs[3].x != 0)){
                dis_1 = j1_y - joueurs[0].y;
                dis_2 = j2_y - joueurs[1].y;
                dis_3 = j3_x - joueurs[2].x;
                dis_4 = j4_x - joueurs[3].x;

            }

        }
    }
}

