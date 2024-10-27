#include "Code Maxence.h"


// Fonction pour initialiser le plateau (9x9)
void initPlateau(char plateau[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = VIDE;  // Chaque case est initialisée avec un point
        }
    }
}

// Fonction pour afficher le plateau
void afficherPlateau(char plateau[TAILLE][TAILLE]) {
    printf("\n");
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf("%c ", plateau[i][j]);  // Affiche chaque case du plateau
        }
        printf("\n");
    }
    printf("\n");
}

// Fonction pour placer un mur sur le plateau
// typeMur : 'v' pour mur vertical, 'h' pour mur horizontal
void placerMur(char plateau[TAILLE][TAILLE], int x, int y, char typeMur) {
    if (typeMur == 'v') {
        // Placer un mur vertical à la position (x, y) et (x+1, y)
        if (x < TAILLE - 1 && plateau[x][y] == VIDE && plateau[x + 1][y] == VIDE) {
            plateau[x][y] = MUR;
            plateau[x + 1][y] = MUR;
        } else {
            printf("Position de mur vertical invalide.\n");
        }
    } else if (typeMur == 'h') {
        // Placer un mur horizontal à la position (x, y) et (x, y+1)
        if (y < TAILLE - 1 && plateau[x][y] == VIDE && plateau[x][y + 1] == VIDE) {
            plateau[x][y] = MUR;
            plateau[x][y + 1] = MUR;
        } else {
            printf("Position de mur horizontal invalide.\n");
        }
    } else {
        printf("Type de mur invalide. Utilisez 'v' pour vertical ou 'h' pour horizontal.\n");
    }
}

void placerPionsSurPlateau(char plateau[TAILLE][TAILLE], Joueur joueurs[], int *nbJoueurs) {
    if (*nbJoueurs == 2) {
        // Placer les pions pour 2 joueurs au milieu des colonnes extrêmes
        plateau[TAILLE / 2][0] = joueurs[0].pion;           // Milieu de la première colonne
        plateau[TAILLE / 2][TAILLE - 1] = joueurs[1].pion;   // Milieu de la dernière colonne
    } else if (*nbJoueurs == 4) {
        // Placer les pions pour 4 joueurs aux quatre coins du plateau
        plateau[0][0] = joueurs[0].pion;                     // Coin supérieur gauche
        plateau[0][TAILLE - 1] = joueurs[1].pion;            // Coin supérieur droit
        plateau[TAILLE - 1][0] = joueurs[2].pion;            // Coin inférieur gauche
        plateau[TAILLE - 1][TAILLE - 1] = joueurs[3].pion;   // Coin inférieur droit
    }
}