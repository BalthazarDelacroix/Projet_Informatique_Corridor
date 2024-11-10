
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


                int tour = 1;
                // Boucle principale du jeu qui permet plusieurs tours
                do {
                    printf("\n----- Tour %d -----\n", tour);
                    // Appel de la fonction pour gérer le tour de chaque joueur
                    jouerTour(joueurs, j, plateau);
                    if ((j==2 &&(joueurs[0].y == 16 || joueurs[1].y == 0)) || (j==4 &&(joueurs[0].y == 16 || joueurs[1].y == 0 || joueurs[2].x ==16 || joueurs[3].x ==0))) {
                        if (joueurs[0].y == 16) {
                            printf("%s a gagne la partie",joueurs[0].nom);
                            joueurs[0].score += 5;
                        }
                        else if (joueurs[1].y == 0) {
                            printf("%s a gagne la partie",joueurs[1].nom);
                            joueurs[1].score += 5;
                        }
                        else if (joueurs[2].x == 16) {
                            printf("%s a gagne la partie",joueurs[2].nom);
                            joueurs[2].score += 5;
                        }
                        else if (joueurs[3].x == 16) {
                            printf("%s a gagne la partie",joueurs[3].nom);
                            joueurs[3].score += 5;
                        }
                    }
                    tour ++;


                }while((j==2 &&(joueurs[0].y != 16 || joueurs[1].y != 0)) || (j==4 &&(joueurs[0].y != 16 || joueurs[1].y != 0 || joueurs[2].x !=16 || joueurs[3].x !=0)));
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
