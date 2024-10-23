#include "Code Maxence.h"

int main() {
    afficherMenu();

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