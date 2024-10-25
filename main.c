#include "Code Maxence.h"

int main() {
    afficherMenu();

    char plateau[TAILLE][TAILLE];


    // Initialisation du plateau
    initPlateau(plateau);
    Joueur joueurs[MAX_JOUEURS];

    // Placer les pions sur le plateau
    placerPionsSurPlateau(plateau, joueurs, saisirNombreDeJoueurs());
    // Affichage du plateau vide
    afficherPlateau(plateau);




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