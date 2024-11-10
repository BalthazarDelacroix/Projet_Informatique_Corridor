#include "Code Maxence.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int j =saisirNombreDeJoueurs();
    char plateau[2*TAILLE-1][2*TAILLE-1];
    // Initialisation du plateau
    initPlateau(plateau);
    Joueur joueurs[MAX_JOUEURS];
    int a;
    do {
        a= afficherMenu();
        switch (a) {
            case 1:
                printf("Vous avez choisi : Lancer une nouvelle partie\n");
                // Appeler ici la fonction qui démarre une nouvelle partie
                // Appel de la fonction configurerJoueurs avec les parametres requis
                configurerJoueurs(joueurs, &j);
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
                    jouerTour(joueurs, j, plateau);

                    // Demander si l'utilisateur souhaite continuer un nouveau tour
                    printf("\nVoulez-vous commencer un nouveau tour ? (1: Oui, 0: Non) : ");
                    scanf("%d", &continuer);

                    if (continuer) {
                     tour++;  // Incrémenter le numéro du tour
                }
            }
                sleep(1);
                break;
            case 2:
                 printf("Vous avez choisi : Reprendre une partie sauvegardée\n");
                 // Appeler ici la fonction qui charge une partie sauvegardee
                 sleep(1);
                 break;

            case 3:
                printf("Vous avez choisi : Afficher l'aide\n");
                AfficherAide();
                sleep(1);
                break;
            case 4:
                printf("Vous avez choisi : Afficher les scores des joueurs\n");
                // Appeler ici la fonction qui affiche les scores
                sleep(1);
                break;
            case 5:
                printf("Vous avez choisi : Quitter le jeu\n");
                sleep(1);
                break;

        }
    }while(a!=5);
        printf("Merci d'avoir joue !\n");
        sleep(3);
        return 0;
}