//
//

#ifndef FICHIER_TEXTE_H
#define FICHIER_TEXTE_H
#include "Joueur.h"
#define MAX_JOUEURS 4
#define TAILLE 9
#define CASE '.'  // Représente une case vide
#define MUR_HORIZONTALE '-'
#define MUR_VERTICALE '|'
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

void sauvegarderPlateau(char plateau[2 * TAILLE - 1][2 * TAILLE - 1], const char* nomFichier);
void Annulation_Plateau(const char* nomFichier,int*annulation,char plateau[2 * TAILLE - 1][2 * TAILLE - 1]); // Annulation du coup, reaffiche l'etat du plateau avant le dernier changement
void sauvegarderJoueurs(Joueur joueurs[], int nbJoueurs, const char* nomFichier);// Sauvegarde partie, joueurs, plateau
void afficherNomsEtScores(const char* nomFichier);//Score
void reprendrePartie(Joueur joueurs[], int* nbJoueurs, char plateau[2*TAILLE-1][2*TAILLE-1], const char* nomFichier);//Charge une partie jouee avant

#endif //FICHIER_TEXTE_H
