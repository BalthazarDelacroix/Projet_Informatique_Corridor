#include "Code Maxence.h"

void obj_victoire(Joueur joueurs[],char plateau [2*TAILLE-1] [2*TAILLE-1],int nb_joueurs,int*obj_x, int*obj_y) {
    int i=0;
    for (i;i<nb_joueurs;i++) {
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
        int i,j1=16, j2=0;
        if(joueurs[0].estIA) ia=joueurs[0];
        else if(joueurs[1].estIA) ia=joueurs[1];
    }
    else {
        if (nb_joueurs == 4) {
            int i=0,j1_y=16, j2_y=0, j3_x=16, j4_x=0, dis_0, dis_1, dis_2, dis_3, dis_ia;
            for (i;i<nb_joueurs;i++) {
                if (joueurs[i].estIA == 1) {
                    ia=joueurs[i];
                }
            }
            int obj_iax, obj_iay;
            while ((joueurs[0].y != 16)||(joueurs[1].y != 0)||(joueurs[2].x != 16)||(joueurs[3].x != 0)){
                dis_0 = j1_y - joueurs[0].y;
                dis_1 = j2_y - joueurs[1].y;
                dis_2 = j3_x - joueurs[2].x;
                dis_3 = j4_x - joueurs[3].x;;
                obj_victoire(joueurs, plateau, nb_joueurs, &obj_iax, &obj_iay);
                if (obj_iax == 0){
                    dis_ia = obj_iay - ia.y;}
                else if (obj_iay == 0) {
                    dis_ia = obj_iax - ia.x;}
            }
            if ((dis_ia<dis_0)||(dis_ia<dis_1)||(dis_ia<dis_2)||(dis_ia<dis_3)){
                printf("Passage au placement de mur");
            }
            else {
                printf("Passage au deplacement");
            }
        }
    }
}