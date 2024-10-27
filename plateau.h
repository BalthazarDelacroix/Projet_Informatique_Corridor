//


#ifndef PLATEAU_H
#define PLATEAU_H
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



void placerPionsSurPlateau(char plateau[2*TAILLE-1][2*TAILLE-1],  Joueur joueurs[], int *nbJoueurs);// place les pions en debut de partie
void initPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]);// Initialise le plateau
void afficherPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]);//Affiche le plateau
void placerMur(char plateau[2*TAILLE-1][2*TAILLE-1], Joueur joueurs[], int nombreDeJoueurs,int*x,int*y,char * typeMur);// Pose des barrieres
void changerCouleur(int couleur);//Change la couleur
void reinitialiserCouleur();//Remet la couleur par defaut
#endif //PLATEAU_H
