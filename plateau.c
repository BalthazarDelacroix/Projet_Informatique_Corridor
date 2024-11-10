#include "Code Maxence.h"


// Fonction pour initialiser le plateau (9x9)
void initPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]) {
    for (int i = 0; i < 2*TAILLE-1; i++) {
        for (int j = 0; j < 2*TAILLE-1; j++) {
            if (i%2==0||j%2==0)
            {
                plateau[i][j] = VIDE;
            } // Chaque case est initialisée avec un point
            else{
                plateau[i][j]=' ';
            }
        }
    }
}

// Fonction pour afficher le plateau
void afficherPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]) {
    printf("\n");
    for (int i = 0; i < 2*TAILLE-1; i++) {
        for (int j = 0; j < 2*TAILLE-1; j++) {
            printf("%c ", plateau[i][j]);  // Affiche chaque case du plateau
        }
        printf("\n");
    }
    printf("\n");
}

// Fonction pour placer un mur sur le plateau
// typeMur : 'v' pour mur vertical, 'h' pour mur horizontal


void placerMur(char plateau[2*TAILLE-1][2*TAILLE-1], Joueur joueurs[], int nombreDeJoueurs) {
    int x, y;
    char typeMur;
    int erreur;

    do {
        erreur = 0;  // Réinitialisation de l'erreur pour chaque nouvelle tentative

        printf("Entrez les coordonnees (x, y) du mur et sa position (v: verticale ou h: horizontale) : \n");
        if (scanf("%d %d %c", &x, &y, &typeMur) != 3) {
            printf("Erreur : veuillez entrer deux entiers suivis d'un caractere ('v' ou 'h').\n");
            erreur = 1;

            // Vider le buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else if (x < 0 || x >= 2*TAILLE-1 || y < 0 || y >= 2*TAILLE-1 || (typeMur != 'v' && typeMur != 'h')) {
            printf("Coordonnees ou position non valides.\n");
            erreur = 1;
        }
        else if ((typeMur == 'h' && y >= 2*TAILLE-1 - 1) || (typeMur == 'v' && x >= 2*TAILLE-1 - 1)) {
            printf("Emplacement hors plateau pour un mur de type %c.\n", typeMur);
            erreur = 1;
        }
        else if ((typeMur == 'h' && (plateau[x][y] == MUR || plateau[x][y + 1] == MUR)) ||
                 (typeMur == 'v' && (plateau[x][y] == MUR || plateau[x + 1][y] == MUR))) {
            printf("Il y a deja un mur pose.\n");
            erreur = 1;
        }
        else {
            // Vérification de chevauchement avec les pions de chaque joueur
            for (int i = 0; i < nombreDeJoueurs; i++) {
                if ((typeMur == 'h' && (plateau[x][y] == joueurs[i].pion || plateau[x][y + 1] == joueurs[i].pion)) ||
                    (typeMur == 'v' && (plateau[x][y] == joueurs[i].pion || plateau[x + 1][y] == joueurs[i].pion))) {
                    printf("Emplacement invalide: le mur chevauche le pion du joueur %d.\n", i + 1);
                    erreur = 1;
                    break;  // Sortir de la boucle dès qu'un pion est détecté
                }
            }
        }

        // Placement du mur si toutes les vérifications ont été passées
        if (erreur == 0) {
            if (typeMur == 'h') {
                plateau[x][y] = MUR;
                plateau[x][y + 1] = MUR;
                printf("Mur horizontal place en (%d, %d) et (%d, %d).\n", x, y, x, y + 1);
            } else if (typeMur == 'v') {
                plateau[x][y] = MUR;
                plateau[x + 1][y] = MUR;
                printf("Mur vertical place en (%d, %d) et (%d, %d).\n", x, y, x + 1, y);
            }
        }

    } while (erreur != 0);  // Répéter tant qu'il y a une erreur
}



void placerPionsSurPlateau(char plateau[2*TAILLE-1][2*TAILLE-1], Joueur joueurs[], int *nbJoueurs) {
    if (*nbJoueurs == 2) {
        // Placer les pions pour 2 joueurs au milieu des colonnes extrêmes
        plateau[2*TAILLE-1 / 2][0] = joueurs[0].pion;           // Milieu de la première colonne
        plateau[2*TAILLE-1 / 2][2*TAILLE-1 - 1] = joueurs[1].pion; // Milieu de la dernière colonne
        joueurs[0].x =2*TAILLE-1 / 2 ;
        joueurs[0].y =0;
        joueurs[1].x = 2*TAILLE-1 / 2;
        joueurs[1].y =2*TAILLE-1-1;
    } else if (*nbJoueurs == 4) {
        // Placer les pions pour 4 joueurs aux quatre coins du plateau
        plateau[0][0] = joueurs[0].pion;                     // Coin supérieur gauche
        plateau[0][2*TAILLE-1 - 1] = joueurs[1].pion;            // Coin supérieur droit
        plateau[2*TAILLE-1 - 1][0] = joueurs[2].pion;            // Coin inférieur gauche
        plateau[2*TAILLE-1 - 1][2*TAILLE-1 - 1] = joueurs[3].pion;   // Coin inférieur droit
        joueurs[0].x = 0;
        joueurs[0].y =0;
        joueurs[1].x = 0;
        joueurs[1].y =2*TAILLE-1-1;
        joueurs[2].x = 2*TAILLE-1 -1;
        joueurs[2].y =0;
        joueurs[3].x = 2*TAILLE-1 -1;
        joueurs[3].y =2*TAILLE-1 - 1;
    }
}