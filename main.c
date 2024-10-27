

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
        fflush(stdin);
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

                int tour = 1;
                int termine;
                int choix2;
                char buffer[10]; // Un buffer assez grand pour contenir l'entrée
                // Boucle principale du jeu qui permet plusieurs tours
                do {
                    termine = 0;
                    printf("\n----- Tour %d -----\n", tour);
                    // Appel de la fonction pour gérer le tour de chaque joueur
                    jouerTour(joueurs, j, plateau);
                    if (j==4 &&(joueurs[0].y == 16 || joueurs[1].y == 0 || joueurs[2].x ==16 || joueurs[3].x ==0)) {
                        if (joueurs[0].y == 16) {
                            printf("%s a gagne la partie. \n",joueurs[0].nom);
                            joueurs[0].score += 5;
                            printf("%s a %d points. \n",joueurs[0].nom,joueurs[0].score);
                            termine = 1;
                        }
                        else if (joueurs[1].y == 0) {
                            printf("%s a gagne la partie. \n",joueurs[1].nom);
                            joueurs[1].score += 5;
                            printf("%s a %d points. \n",joueurs[1].nom,joueurs[1].score);
                            termine = 1;
                        }
                        else if (joueurs[2].x == 16) {
                            printf("%s a gagne la partie. \n",joueurs[2].nom);
                            joueurs[2].score += 5;
                            printf("%s a %d points. \n",joueurs[2].nom,joueurs[2].score);
                            termine = 1;
                        }
                        else if (joueurs[3].x == 16) {
                            printf("%s a gagne la partie. \n",joueurs[3].nom);
                            joueurs[3].score += 5;
                            printf("%s a %d points. \n",joueurs[3].nom,joueurs[3].score);
                            termine = 1;
                        }
                    }
                    else if (j==2 &&(joueurs[0].y == 16 || joueurs[1].y == 0)) {
                            if (joueurs[0].y == 16) {
                            printf("%s a gagne la partie. \n",joueurs[0].nom);
                            joueurs[0].score += 5;
                            printf("%s a %d points. \n",joueurs[0].nom,joueurs[0].score);
                            termine = 1;
                            }
                            else if (joueurs[1].y == 0) {
                             printf("%s a gagne la partie. \n",joueurs[1].nom);
                             joueurs[1].score += 5;
                             printf("%s a %d points. \n",joueurs[1].nom,joueurs[1].score);
                             termine = 1;
                            }
                    }
                    if (termine == 1) {
                        do {
                            fflush(stdin);
                            printf("Souhaitez-vous refaire une partie (0: non ou 1: oui) ?\n");

                            // Utilisation de fgets pour capturer l'entrée en entier
                            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                                // Tentative de conversion de l'entrée en entier
                                if (sscanf(buffer, "%d", &choix2) != 1 || (choix2 != 0 && choix2 != 1)) {
                                    printf("Erreur: Vous devez entrer 0 pour non ou 1 pour oui.\n");
                                    choix2 = -1; // Réinitialisation de choix2 pour continuer la boucle
                                }
                            } else {
                                // Si fgets échoue, on réinitialise choix pour refaire le choix
                                choix2 = -1;
                            }

                            // Ce bloc doit être exécuté si choix2 est égal à 1
                            if (choix2 == 1) {
                                tour = 0;
                                initPlateau(plateau);
                                placerPionsSurPlateau(plateau, joueurs, &j);
                                printf("UNE NOUVELLE PARTIE COMMENCE.\n");
                                afficherPlateau(plateau);
                                termine = 0;
                            }

                        } while (choix2 != 0 && choix2 != 1); // Boucle tant que l'entrée est incorrecte
                    }

                    tour ++;


                }while(termine == 0);
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
