#include "header.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Fonction pour générer un nombre aléatoire entre min et max (inclus)
int nombreAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Fonction pour appeler un joueur au hasard et lui proposer un menu
void jouerTour(Joueur joueurs[], int nombreJoueurs) {
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
            scanf("%d", &choix);

            // Vérification que le choix est bien entre 1 et 4.
            if (choix != 1 && choix != 2 && choix != 3 && choix != 4) {
                printf("Choix invalide. Veuillez choisir une option disponible.\n");
            }
        } while (choix != 1 && choix != 2 && choix != 3 && choix != 4);

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
                    scanf(" %c", &direction);
                    if (direction != 'z' && direction != 's' && direction != 'q' && direction != 'd') {
                        printf("Entrée invalide. Veuillez entrer une seule direction valide.\n");
                    }
                }
                while (direction != 'z' && direction != 's' && direction != 'q' && direction != 'd');
                switch (direction){
                    case 'z':
                        if ((joueurActuel->y = 0)) {
                            printf("Vous ne pouvez pas monter plus haut");
                        }
                        else {
                            joueurActuel->y++;
                        };
                        break;
                    case 's':
                        if ((joueurActuel->y = TAILLE)) {
                            printf("Vous ne pouvez pas descendre plus bas");
                        }
                        else {
                            joueurActuel->y--;
                        };
                        break;
                    case 'q':
                        if ((joueurActuel->y = 0)) {
                            printf("Vous ne pouvez pas aller plus a gauche");
                        }
                        else {
                            joueurActuel->x--;
                        };
                        break;
                    case 'd':
                        if ((joueurActuel->y = 0)) {
                            printf("Vous ne pouvez pas aller plus a droite");
                        }
                        else {
                            joueurActuel->x++;
                        };
                        break;
                }
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
                    joueurActuel->nombreBarrieres--;
                    // Logique pour placer un mur ici
                } else {
                    printf("%s ne possede plus de barrieres disponibles ! \n", joueurActuel->nom);
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
    }
}