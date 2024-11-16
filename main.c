#include "header.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int j =saisirNombreDeJoueurs();
    char plateau[TAILLE][TAILLE];
    // Initialisation du plateau
    initPlateau(plateau);
    Joueur joueurs[MAX_JOUEURS];

    afficherMenu(joueurs,j);

    placerPionsSurPlateau(plateau, joueurs,&j);
    // Affichage du plateau vide
    afficherPlateau(plateau);

    srand(time(NULL)); // Initialisation du générateur aléatoire


    int continuer = 1;
    int tour = 1;

    // Boucle principale du jeu qui permet plusieurs tours
    while (continuer) {
        printf("\n----- Tour %d -----\n", tour);
        // Appel de la fonction pour gérer le tour de chaque joueur
        jouerTour(joueurs, j);

        // Demander si l'utilisateur souhaite continuer un nouveau tour
        printf("\nVoulez-vous commencer un nouveau tour ? (1: Oui, 0: Non) : ");
        scanf("%d", &continuer);

        if (continuer) {
            tour++;  // Incrémenter le numéro du tour
        }
    }

    printf("Merci d'avoir joue !\n");



    // Pose des murs (exemple d'interaction)
    int x, y;
    char typeMur;

    // Exemple de boucle pour poser 3 murs
    for (int i = 0; i < 10; i++) {
        printf("Entrez les coordonnees pour placer un mur (x y) et le type de mur ('v' pour vertical, 'h' pour horizontal) : ");
        scanf("%d %d %c", &x, &y, &typeMur);

        placerMur(plateau, x, y, typeMur);
        afficherPlateau(plateau);  // Réafficher le plateau après la pose d'un mur
    }
    return 0;
}