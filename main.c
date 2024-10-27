
#include "Code Maxence.h"

int main() {
    char plateau[2*TAILLE-1][2*TAILLE-1];
    Joueur joueurs[MAX_JOUEURS];
    const char* nomFichier = "Partie.txt";
    int a;
    do {
        fflush(stdin);
        //Choix du menu
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
                int termine;
                int blocage=0;
                int choix2=0;
                int sauvegarde;
                srand(time(NULL)); // Initialisation du générateur aléatoire
                // Boucle principale du jeu qui permet plusieurs tours
                gestion_partie (&termine,&choix2,&sauvegarde,joueurs,j,plateau,nomFichier,&blocage);
                sleep(1);
                break;
            case 2:
                 printf("Vous avez choisi : Reprendre une partie sauvegardee\n");
                // Continuer avec les données chargées
                 reprendrePartie(joueurs, &j, plateau,nomFichier);
                 // Gestion de la prtie en cours
                 gestion_partie (&termine,&choix2,&sauvegarde,joueurs,j,plateau,nomFichier,&blocage);
                 sleep(1);
                 break;
            case 3:
                printf("Vous avez choisi : Afficher l'aide\n");
                // Affichage de l'aide
                AfficherAide();
                sleep(1);
                break;
            case 4:
                printf("Vous avez choisi : Afficher les scores des joueurs\n");
                // Appeler ici la fonction qui affiche les scores
                afficherNomsEtScores(nomFichier);
                sleep(1);
                break;
            case 5:
                // On quitte le jeu
                printf("Vous avez choisi : Quitter le jeu\n");
                sleep(1);
                break;
        }
    }while(a!=5);
        printf("Merci d'avoir joue !\n");
        sleep(3);
        return 0;
}
