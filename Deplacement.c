#include "Code Maxence.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Fonction pour générer un nombre aléatoire entre min et max (inclus)
int nombreAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Fonction pour appeler un joueur au hasard et lui proposer un menu
void jouerTour(Joueur joueurs[], int nombreJoueurs, char plateau[TAILLE][TAILLE]) {
    // Table pour vérifier les joueurs qui ont déjà joué
    int dejaJoue[nombreJoueurs];
    for (int i = 0; i < nombreJoueurs; i++) {
        dejaJoue[i] = 0;
    }

    int joueursRestants = nombreJoueurs;

    while (joueursRestants > 0) {
        // Choisir un joueur aléatoirement qui n'a pas encore joué
        int indexJoueur;
        do {
            indexJoueur = nombreAleatoire(0, nombreJoueurs - 1);
        } while (dejaJoue[indexJoueur]);

        Joueur *joueurActuel = &joueurs[indexJoueur];
        printf("\nAu tour de %s !\n", joueurActuel->nom);

        // Afficher le menu d'options
        int choix;
        do {
            printf("Choisissez une action :\n");
            printf("1. Se deplacer\n");
            printf("2. Passer son tour\n");
            printf("3. Annuler une action\n");
            printf("4. Placer un mur\n");
            printf("Votre choix (1-4) : ");


            // Vérifie que la saisie est un entier et entre 1 et 4
            if (scanf("%d", &choix) != 1) {
                printf("Choix invalide.\n");
                while (getchar() != '\n'); // Vider le buffer
                choix = -1; // Valeur invalide pour relancer la boucle
            } else if (choix < 1 || choix > 4) {
                printf("Choix invalide.\n");
            }
        } while (choix < 1 || choix > 4 || (choix == 4 && joueurActuel->nombreBarrieres == 0));

        // Traiter le choix avec un switch case
        switch (choix) {
            case 1: {
                char direction;
                printf("%s choisit de se deplacer.\n", joueurActuel->nom);
                do {
                    printf("Dans quelle direction souhaitez-vous vous deplacer ?\n"
                           "(z = Haut)\n"
                           "(s = Bas)\n"
                           "(q = Gauche)\n"
                           "(d = Droite)\n");
                    if (scanf(" %c", &direction) != 1 ||
                     (direction != 'z' && direction != 's' && direction != 'q' && direction != 'd')) {
                        printf("Entrée invalide. Veuillez entrer une seule direction valide.\n");
                        while (getchar() != '\n'); // Vider le buffer
                        direction = '\0'; // Valeur invalide pour relancer la boucle
        }
                }while (direction != 'z' && direction != 's' && direction != 'q' && direction != 'd');
                switch (direction){
                    case 'z':
                        if (joueurActuel->x == 0) {
                            printf("Vous ne pouvez pas aller plus haut.");
                        }
                        else {
                            plateau[joueurActuel->x][joueurActuel->y] = VIDE;
                            joueurActuel->x--;



                        }

                    case 's':
                        if (joueurActuel->x == TAILLE-1) {
                            printf("Vous ne pouvez pas aller plus bas");
                        }
                        else {
                            plateau[joueurActuel->x][joueurActuel->y] = VIDE;
                            joueurActuel->x++;

                        }
                        break;
                    case 'q':
                        if (joueurActuel->y == 0) {
                            printf("Vous ne pouvez pas aller plus a gauche");
                        }
                        else {
                            plateau[joueurActuel->x][joueurActuel->y] = VIDE;
                            joueurActuel->y--;

                        }
                        break;
                    case 'd':
                        if (joueurActuel->y == TAILLE-1) {
                            printf("Vous ne pouvez pas aller plus a droite");
                        }
                        else {
                            plateau[joueurActuel->x][joueurActuel->y] = VIDE;
                            joueurActuel->y++;

                        }
                        break;

                }
                // Mettre à jour le plateau avec la nouvelle position du joueur
                plateau[joueurActuel->x][joueurActuel->y] = joueurActuel->pion;
                break;
            }
            case 2:
                printf("%s choisit de passer son tour.\n", joueurActuel->nom);
                break;
            case 3:
                printf("%s veut annuler une action.\n", joueurActuel->nom);
                // Logique pour annuler une action ici
                break;
            case 4:

                    if (joueurActuel->nombreBarrieres > 0) {
                        printf("%s choisit de placer un mur.\n", joueurActuel->nom);
                        placerMur(plateau, joueurActuel,nombreJoueurs);
                        joueurActuel->nombreBarrieres--;
                        // Logique pour placer un mur ici
                    } else {
                        printf("%s ne possede plus de barrieres disponibles !\n", joueurActuel->nom);
                    }

                break;
            default:
                // Ce cas ne devrait jamais se produire
                printf("Erreur inattendue.\n");
                break;
        }

        // Marquer ce joueur comme ayant joué
        dejaJoue[indexJoueur] = 1;
        joueursRestants--;
        // Afficher le plateau après déplacement
        afficherPlateau(plateau);

    }
}