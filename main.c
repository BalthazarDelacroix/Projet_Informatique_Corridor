
#include "Code Maxence.h"

int main() {
    char plateau[2*TAILLE-1][2*TAILLE-1];
    Joueur joueurs[MAX_JOUEURS];
    int a;
    do {
        fflush(stdin);
        a= afficherMenu();
        switch (a) {
            case 1:
                printf("Vous avez choisi : Lancer une nouvelle partie\n");
                int j =saisirNombreDeJoueurs();
                // Appeler ici la fonction qui démarre une nouvelle partie
                // Appel de la fonction configurerJoueurs avec les parametres requis
                configurerJoueurs(joueurs, &j);
                //Initialisation plateau
                initPlateau(plateau);
                placerPionsSurPlateau(plateau, joueurs,&j);
                // Affichage du plateau
                afficherPlateau(plateau);
                srand(time(NULL)); // Initialisation du générateur aléatoire
                int tour = 1;
                int termine;
                int choix2;
                // Boucle principale du jeu qui permet plusieurs tours
                do {
                    termine = 0;
                    printf("\n----- Tour %d -----\n", tour);
                    // Appel de la fonction pour gérer le tour de chaque joueur
                    jouerTour(joueurs, j, plateau);
                    //Appel du sous-programme qui gere le gagnant de la partie
                    gagnant (joueurs,j,& termine);
                    //Gestion interruption partie
                    if (termine==0) { //Interruption de la partie ?
                        interrompre_partie(&termine);
                    }
                    if (termine == 1) {//rejouer une nouvelle partie ?
                            rejouer_partie(&termine,&choix2);
                            // Ce bloc doit être exécuté si choix2 est égal à 1
                            if (choix2 == 1) {
                                tour = 0;//Reinitialise les tours
                                initPlateau(plateau);//Reinitialise le plateau
                                placerPionsSurPlateau(plateau, joueurs, &j);//Replace les pions
                                afficherPlateau(plateau);
                            }
                    }
                    tour ++;
                }while(termine == 0);
                sleep(1);
                break;
            case 2:
                 printf("Vous avez choisi : Reprendre une partie sauvegardee\n");
                // Continuer avec les données chargées
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
