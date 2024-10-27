//
//

#ifndef LOGIQUE_IA_H
#define LOGIQUE_IA_H
#include "Joueur.h"
#define TAILLE 9
#define CASE '.'  // Représente une case vide
#define MUR_HORIZONTALE '-'
#define MUR_VERTICALE '|'
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

void obj_victoire(Joueur joueurs[],char plateau [2*TAILLE-1] [2*TAILLE-1],int nb_joueurs,int*obj_x, int*obj_y);
void danger_joueur_proche(Joueur joueurs[], char plateau [2*TAILLE-1] [2*TAILLE-1], int nb_joueurs);

#endif //LOGIQUE_IA_H
