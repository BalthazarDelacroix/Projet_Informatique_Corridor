//
//

#ifndef TOUR_H
#define TOUR_H
#define MAX_JOUEURS 4
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


void jouerTour( Joueur joueurs[], int nombreJoueurs,char plateau[2*TAILLE-1][2*TAILLE-1],const char* nomFichier,int* blocage,int* termine);// Gestion des tours
int nombreAleatoire(int min, int max); // Pour les tours, appel un joueur aléatoire

#endif //TOUR_H
