

#ifndef PARTIE_H
#define PARTIE_H
#include "Joueur.h"
#define TAILLE 9
#define MUR_HORIZONTALE '-'
#define MUR_VERTICALE '|'
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>


void gagnant (Joueur joueurs[], int nombreJoueurs,int* termine, int* blocage);//Verifie si un joueur a gagne
void interrompre_partie(int*termine,int*sauvegarde);//Interruption partie
void rejouer_partie (int*termine,int*choix2);//Choix de rejouer partie ou non
void gestion_partie (int *termine,int *choix2,int *sauvegarde,Joueur joueurs[],int j,char plateau [2*TAILLE-1][2*TAILLE-1],const char*nomFichier,int* blocage);// gere deroulement du jeu
void blocage_partie (Joueur joueurs[],char plateau [2*TAILLE-1][2*TAILLE-1],int*blocage,int nombrejoueurs,int* termine);//Verifie si le joueur peut encore se deplacer
#endif
