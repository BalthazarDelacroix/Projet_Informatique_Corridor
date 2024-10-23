#ifndef CODE_MAXENCE_H
#define CODE_MAXENCE_H

#include <stdio.h>

#define TAILLE 9
#define MUR 'o'  // Représente un mur
#define VIDE '.'  // Représente une case vide

// Fonction pour initialiser le plateau (9x9)
int initPlateau(char plateau[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = VIDE;  // Chaque case est initialisée avec un point
        }
    }
}

// Fonction pour afficher le plateau
int afficherPlateau(char plateau[TAILLE][TAILLE]) {
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
int placerMur(char plateau[TAILLE][TAILLE], int x, int y, char typeMur) {
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

/*
int main() {
    int initPlateau(char plateau[TAILLE][TAILLE]);
    int afficherPlateau(char plateau[TAILLE][TAILLE]);
    int placerMur(char plateau[TAILLE][TAILLE], int x, int y, char typeMur);
    // Déclaration du plateau
    char plateau[TAILLE][TAILLE];

    // Initialisation du plateau
    initPlateau(plateau);

    // Affichage du plateau vide
    afficherPlateau(plateau);

    // Pose des murs (exemple d'interaction)
    int x, y;
    char typeMur;

    // Exemple de boucle pour poser 3 murs
    for (int i = 0; i < 3; i++) {
        printf("Entrez les coordonnées pour placer un mur (x y) et le type de mur ('v' pour vertical, 'h' pour horizontal) : ");
        scanf("%d %d %c", &x, &y, &typeMur);

        placerMur(plateau, x, y, typeMur);
        afficherPlateau(plateau);  // Réafficher le plateau après la pose d'un mur
    }

    return 0;
}
*/

#endif