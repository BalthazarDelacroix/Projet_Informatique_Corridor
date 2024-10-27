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


void placerMur(char plateau[TAILLE][TAILLE], Joueur joueurs[]) {
    int x, y;
    char typeMur;

    do {
        printf("Entrez les coordonnees (x, y) du mur et sa position (v: verticale ou h: horizontale) : \n");
        scanf("%d %d %c", &x, &y, &typeMur);

        // Vérification des conditions de placement
        if ((x < 0 || x >= TAILLE || y < 0 || y >= TAILLE) ||  // Coordonnées hors limites
            (typeMur != 'v' && typeMur != 'h') ||              // Type de mur invalide
            (typeMur == 'h' && (x - y != 1 || plateau[x][y] != VIDE || plateau[x][y + 1] != VIDE ||
                                plateau[x][y] == joueurs->pion || plateau[x][y + 1] == joueurs->pion)) ||  // Mur horizontal
            (typeMur == 'v' && (y - x != 1 || plateau[x][y] != VIDE || plateau[x + 1][y] != VIDE ||
                                plateau[x][y] == joueurs->pion || plateau[x + 1][y] == joueurs->pion))      // Mur vertical
        ) {
            printf("Coordonnees ou position non valides.\n");
            continue;  // Demande de nouvelles coordonnées
        }

        // Placement du mur une fois que toutes les conditions sont validées
        if (typeMur == 'h') {
            plateau[x][y] = MUR;
            plateau[x][y + 1] = MUR;
            printf("Mur horizontal place en (%d, %d) et (%d, %d).\n", x, y, x, y + 1);
        } else if (typeMur == 'v') {
            plateau[x][y] = MUR;
            plateau[x + 1][y] = MUR;
            printf("Mur vertical place en (%d, %d) et (%d, %d).\n", x, y, x + 1, y);
        }

        break;  // Sort de la boucle si le mur est placé

    } while (1);  // Continue jusqu'à ce qu'un mur valide soit placé
}


void placerPionsSurPlateau(char plateau[TAILLE][TAILLE], Joueur joueurs[], int *nbJoueurs) {
    if (*nbJoueurs == 2) {
        // Placer les pions pour 2 joueurs au milieu des colonnes extrêmes
        plateau[TAILLE / 2][0] = joueurs[0].pion;           // Milieu de la première colonne
        plateau[TAILLE / 2][TAILLE - 1] = joueurs[1].pion; // Milieu de la dernière colonne
    } else if (*nbJoueurs == 4) {
        // Placer les pions pour 4 joueurs aux quatre coins du plateau
        plateau[0][0] = joueurs[0].pion;                     // Coin supérieur gauche
        plateau[0][TAILLE - 1] = joueurs[1].pion;            // Coin supérieur droit
        plateau[TAILLE - 1][0] = joueurs[2].pion;            // Coin inférieur gauche
        plateau[TAILLE - 1][TAILLE - 1] = joueurs[3].pion;   // Coin inférieur droit
    }
}