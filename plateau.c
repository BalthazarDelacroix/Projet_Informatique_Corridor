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


void placerMur(char plateau[TAILLE][TAILLE], Joueur joueurs[], int nombreDeJoueurs) {
    int x, y;
    char typeMur;

    do {
        printf("Entrez les coordonnees (x, y) du mur et sa position (v: verticale ou h: horizontale) : \n");
        if (scanf("%d %d %c", &x, &y, &typeMur) != 3) {
            printf("Erreur : veuillez entrer deux entiers suivis d'un caractere ('v' ou 'h').\n");

            // Vider le buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Vérification des limites
        if (x < 0 || x >= TAILLE || y < 0 || y >= TAILLE || (typeMur != 'v' && typeMur != 'h')) {
            printf("Coordonnees ou position non valides.\n");
            continue;  // Redemande de nouvelles coordonnées
        }

        // Vérification d’emplacement sur les bords
        if ((typeMur == 'h' && y >= TAILLE - 1) || (typeMur == 'v' && x >= TAILLE - 1)) {
            printf("Emplacement hors plateau pour un mur de type %c.\n", typeMur);
            continue;
        }

        // Vérification de la présence d’un mur
        if ((typeMur == 'h' && (plateau[x][y] == MUR || plateau[x][y + 1] == MUR)) ||
            (typeMur == 'v' && (plateau[x][y] == MUR || plateau[x + 1][y] == MUR))) {
            printf("Il y a deja un mur pose.\n");
            continue;
        }

        // Réinitialiser l’indicateur de validité
        int emplacementValide = 1;

        // Vérification de chevauchement avec les pions de chaque joueur
        for (int i = 0; i < nombreDeJoueurs; i++) {
            if ((typeMur == 'h' && (plateau[x][y] == joueurs[i].pion || plateau[x][y + 1] == joueurs[i].pion)) ||
                (typeMur == 'v' && (plateau[x][y] == joueurs[i].pion || plateau[x + 1][y] == joueurs[i].pion))) {
                emplacementValide = 0;
                printf("Emplacement invalide: le mur chevauche le pion du joueur %d.\n", i + 1);
                break;  // Sort de la boucle si un chevauchement est détecté
            }
        }

        if (!emplacementValide) {
            continue;  // Redemande de nouvelles coordonnées si chevauchement avec un pion
        }

        // Placement du mur si toutes les conditions sont validées
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
        joueurs[0].x =TAILLE / 2 ;
        joueurs[0].y =0;
        joueurs[1].x = TAILLE / 2;
        joueurs[1].y =TAILLE-1;
    } else if (*nbJoueurs == 4) {
        // Placer les pions pour 4 joueurs aux quatre coins du plateau
        plateau[0][0] = joueurs[0].pion;                     // Coin supérieur gauche
        plateau[0][TAILLE - 1] = joueurs[1].pion;            // Coin supérieur droit
        plateau[TAILLE - 1][0] = joueurs[2].pion;            // Coin inférieur gauche
        plateau[TAILLE - 1][TAILLE - 1] = joueurs[3].pion;   // Coin inférieur droit
        joueurs[0].x = 0;
        joueurs[0].y =0;
        joueurs[1].x = 0;
        joueurs[1].y =TAILLE-1;
        joueurs[2].x = TAILLE -1;
        joueurs[2].y =0;
        joueurs[3].x = TAILLE -1;
        joueurs[3].y =TAILLE - 1;
    }
}