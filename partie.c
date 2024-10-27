#include "partie.h"
#include "plateau.h"
#include "menu.h"
#include "Fichier_texte.h"
#include "Tour.h"




void gagnant (Joueur joueurs[], int nombreJoueurs,int* termine,int* blocage) {
    //On verifie si pour 4 joeurs, l'un d'entre eux à gagner
    if (nombreJoueurs==4 &&(joueurs[0].y == 16 || joueurs[1].y == 0 || joueurs[2].x ==16 || joueurs[3].x ==0)) {
                        if (joueurs[0].y == 16) {
                            printf("%s a gagne la partie. \n",joueurs[0].nom);
                            joueurs[0].score += 5;
                            printf("%s a %d points. \n",joueurs[0].nom,joueurs[0].score);
                            *termine = 1;
                            *blocage=1;
                        }
                        else if (joueurs[1].y == 0) {
                            printf("%s a gagne la partie. \n",joueurs[1].nom);
                            joueurs[1].score += 5;
                            printf("%s a %d points. \n",joueurs[1].nom,joueurs[1].score);
                            *termine = 1;
                            *blocage=1;
                        }
                        else if (joueurs[2].x == 16) {
                            printf("%s a gagne la partie. \n",joueurs[2].nom);
                            joueurs[2].score += 5;
                            printf("%s a %d points. \n",joueurs[2].nom,joueurs[2].score);
                            *termine = 1;
                            *blocage=1;
                        }
                        else if (joueurs[3].x == 16) {
                            printf("%s a gagne la partie. \n",joueurs[3].nom);
                            joueurs[3].score += 5;
                            printf("%s a %d points. \n",joueurs[3].nom,joueurs[3].score);
                            *termine = 1;
                            *blocage=1;
                        }
                    } // On verifie si pour 2 joueurs, l'un d'entre eux a gagné
                    else if (nombreJoueurs==2 &&(joueurs[0].y == 16 || joueurs[1].y == 0)) {
                            if (joueurs[0].y == 16) {
                            printf("%s a gagne la partie. \n",joueurs[0].nom);
                            joueurs[0].score += 5;
                            printf("%s a %d points. \n",joueurs[0].nom,joueurs[0].score);
                            *termine = 1;
                            *blocage =1;
                            }
                            else if (joueurs[1].y == 0) {
                             printf("%s a gagne la partie. \n",joueurs[1].nom);
                             joueurs[1].score += 5;
                             printf("%s a %d points. \n",joueurs[1].nom,joueurs[1].score);
                             *termine = 1;
                             *blocage=1;
                            }
                    }
}
void interrompre_partie(int*termine,int*sauvegarde) {
    char buffer [10];
    int choix;
    do{
        fflush(stdin);
        printf("Souhaitez-vous interrompre la partie (0: non ou 1: oui) ?\n");

        // Utilisation de fgets pour capturer l'entrée en entier
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tentative de conversion de l'entrée en entier
            if (sscanf(buffer, "%d", &choix) != 1 || (choix != 0 && choix != 1)) {
                printf("Erreur: Vous devez entrer 0 pour non ou 1 pour oui.\n");
                choix = -1; // Réinitialisation de choix2 pour continuer la boucle
            }
        }
        else {
            // Si fgets échoue, on réinitialise choix pour refaire le choix
            choix = -1;
        }

        // Ce bloc doit être exécuté si choix2 est égal à 1
        if (choix == 1) {
            *termine = 2;
            *sauvegarde = 1;
            printf("La partie a ete interrompue. \n");
        }

    } while (choix != 0 && choix != 1); // Boucle tant que l'entrée est incorrecte
}
void rejouer_partie (int*termine,int*choix2) {
    int choix;
    char buffer[10];
    do {
        fflush(stdin);
        printf("Souhaitez-vous refaire une partie (0: non ou 1: oui) ?\n");

        // Utilisation de fgets pour capturer l'entrée en entier
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tentative de conversion de l'entrée en entier
            if (sscanf(buffer, "%d", &choix) != 1 || (choix != 0 && choix != 1)) {
                printf("Erreur: Vous devez entrer 0 pour non ou 1 pour oui.\n");
                choix = -1; // Réinitialisation de choix pour continuer la boucle
            }
        } else {
            // Si fgets échoue, on réinitialise choix pour refaire le choix
            choix = -1;
        }

        // Ce bloc doit être exécuté si choix est égal à 1
        if (choix == 1) {
            printf("UNE NOUVELLE PARTIE COMMENCE.\n");
            *termine = 0;
            *choix2 = 1;
        }
        else if(choix==0) {
            *choix2=0;
        }

    } while (choix != 0 && choix != 1); // Boucle tant que l'entrée est incorrecte
}
void gestion_partie (int *termine,int *choix2,int *sauvegarde,Joueur joueurs[],int j,char plateau [2*TAILLE-1][2*TAILLE-1],const char*nomFichier,int*blocage){
    do {
        *termine = 0;
        printf("\n----- Tour suivant -----\n");
        // Appel de la fonction pour gérer le tour de chaque joueur
        jouerTour(joueurs, j, plateau,nomFichier,blocage,termine);
        //Appel du sous-programme qui gere le gagnant de la partie
        gagnant (joueurs,j,termine,blocage);
        //Gestion interruption partie
        if (*termine==0||*blocage==0) { //Interruption de la partie ?
            interrompre_partie(termine,sauvegarde);
            if (*sauvegarde==1) {
                sauvegarderJoueurs(joueurs,j,nomFichier);
            }
        }
        if (*termine == 1 || *blocage!=0) {//rejouer une nouvelle partie ?
            rejouer_partie(termine,choix2);
            // Ce bloc doit être exécuté si choix2 est égal à 1
            if (*choix2 == 1) {
                initPlateau(plateau);//Reinitialise le plateau
                placerPionsSurPlateau(plateau, joueurs, &j);//Replace les pions
                afficherPlateau(plateau);
                NombreBarrieres(joueurs,j);
                *termine =0;
                *blocage=0;


            }
            else {
                initPlateau(plateau);
                placerPionsSurPlateau(plateau,joueurs,&j);
                NombreBarrieres(joueurs,j);
                sauvegarderJoueurs(joueurs,j,nomFichier);
                *blocage=0;

            }
        }
    }while(*termine == 0);
}
void blocage_partie (Joueur joueurs[],char plateau [2*TAILLE-1][2*TAILLE-1],int*blocage,int nombrejoueurs, int* termine) {
    for (int i = 0; i < nombrejoueurs; i++) {
        if (joueurs[i].y==0&&joueurs[i].x!=0&& joueurs[i].x!=16) {
            if (plateau[joueurs[i].x-1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x+1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x][joueurs[i].y+1]==MUR_VERTICALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else if (joueurs[i].y==16&&joueurs[i].x!=0&& joueurs[i].x!=16) {
            if (plateau[joueurs[i].x-1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x+1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x][joueurs[i].y-1]==MUR_VERTICALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else if (joueurs[i].x==16&&joueurs[i].y!=0&& joueurs[i].y!=16) {
            if (plateau[joueurs[i].x][joueurs[i].y-1]==MUR_VERTICALE&&plateau[joueurs[i].x][joueurs[i].y+1]==MUR_VERTICALE&&plateau[joueurs[i].x-1][joueurs[i].y]==MUR_HORIZONTALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else if (joueurs[i].x==0&&joueurs[i].y!=0&& joueurs[i].y!=16) {
            if (plateau[joueurs[i].x][joueurs[i].y-1]==MUR_VERTICALE&&plateau[joueurs[i].x][joueurs[i].y+1]==MUR_VERTICALE&&plateau[joueurs[i].x+1][joueurs[i].y]==MUR_HORIZONTALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else if (joueurs[i].x==0&&joueurs[i].y==0) {
            if (plateau[joueurs[i].x+1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x][joueurs[i].y+1]==MUR_VERTICALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else if (joueurs[i].x==16&&joueurs[i].y==0) {
            if (plateau[joueurs[i].x-1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x][joueurs[i].y+1]==MUR_VERTICALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else if (joueurs[i].y==16&&joueurs[i].x==0) {
            if (plateau[joueurs[i].x+1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x][joueurs[i].y-1]==MUR_VERTICALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else if (joueurs[i].y==16&&joueurs[i].x==16) {
            if (plateau[joueurs[i].x-1][joueurs[i].y]==MUR_HORIZONTALE&&plateau[joueurs[i].x][joueurs[i].y-1]==MUR_VERTICALE) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
        else {
            if (plateau[joueurs[i].x-1][joueurs[i].y]==MUR_HORIZONTALE&& plateau[joueurs[i].x+1][joueurs[i].y]==MUR_HORIZONTALE && plateau[joueurs[i].x][joueurs[i].y-1]==MUR_VERTICALE && plateau[joueurs[i].x][joueurs[i].y+1]==MUR_VERTICALE ) {
                *blocage=1;
                printf("Partie bloquee. Un joueur ne peut plus avancer. \n");
                *termine=1;
            }
        }
    }
}