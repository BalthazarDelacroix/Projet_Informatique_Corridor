#ifndef CODE_MAXENCE_H
#define CODE_MAXENCE_H
#include <stdio.h>

#define TAILLE 9
#define MUR 'o'  // Représente un mur
#define VIDE '.'  // Représente une case vide

void initPlateau(char plateau[TAILLE][TAILLE]);
void afficherPlateau(char plateau[TAILLE][TAILLE]);
void placerMur(char plateau[TAILLE][TAILLE], int x, int y, char typeMur);

#endif