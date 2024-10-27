#include "Code Maxence.h"


// Fonction pour générer un nombre aléatoire entre min et max (inclus)
int nombreAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Fonction pour appeler un joueur au hasard et lui proposer un menu
void jouerTour(Joueur joueurs[], int nombreJoueurs, char plateau[2*TAILLE-1][2*TAILLE-1]) {
    // Table pour vérifier les joueurs qui ont déjà joué
    int dejaJoue[nombreJoueurs];
    for (int i = 0; i < nombreJoueurs; i++) {
        dejaJoue[i] = 0;
    }

    int joueursRestants = nombreJoueurs;

    while (joueursRestants > 0 && (joueurs[0].y != 16 && joueurs[1].y != 0 && joueurs[2].x !=16 && joueurs[3].x !=0)){
        fflush(stdin);
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
            } else if (choix < 1 || choix > 4 || (choix == 4 && joueurActuel->nombreBarrieres == 0)) {
                printf("Choix invalide ou mur non disponible.\n");
            }
        } while (choix < 1 || choix > 4 || (choix == 4 && joueurActuel->nombreBarrieres == 0));

        // Traiter le choix avec un switch case
        switch (choix) {
            // Inclure cette logique de déplacement dans le `case 1` de `jouerTour` pour gérer le déplacement
            case 1: {
                char direction;
                printf("%s choisit de se deplacer.\n", joueurActuel->nom);
                int deplacementPossible;
                do {
                    printf("Dans quelle direction souhaitez-vous vous deplacer ?\n"
                           "(z = Haut)\n"
                           "(s = Bas)\n"
                           "(q = Gauche)\n"
                           "(d = Droite)\n");
                    if (scanf(" %c", &direction) != 1 ||
                        (direction != 'z' && direction != 's' && direction != 'q' && direction != 'd')) {
                        printf("Entree invalide. Veuillez entrer une seule direction valide.\n");
                        while (getchar() != '\n'); // Vider le buffer
                        direction = '\0'; // Valeur invalide pour relancer la boucle
                    }


                    // Calculer la position cible et vérifier s'il y a un mur bloquant
                    int newX = joueurActuel->x;
                    int newY = joueurActuel->y;
                    int murX = joueurActuel->x;
                    int murY = joueurActuel->y;
                    deplacementPossible = 1;

                    switch (direction) {
                        case 'z':
                            if (joueurActuel->x == 0) {
                                printf("Vous ne pouvez pas aller plus haut.\n");
                                deplacementPossible = 0;
                            } else if (plateau[murX - 1][murY] == MUR_HORIZONTALE) { // Vérifier la présence d'un mur horizontal
                                printf("Un mur bloque le passage en haut.\n");
                                deplacementPossible = 0;
                            }
                            else if (plateau[murX-2][murY] != CASE) {
                                if (plateau[murX-4][murY] == CASE && murX-4 >=0 &&  plateau[murX-3][murY] != MUR_HORIZONTALE) {
                                    // Vérifier la présence d'un mur vertical
                                    newX -= 4;
                                }
                                else {
                                    printf("Deplacement impossible. Vous devez bifurquer \n");
                                    deplacementPossible = 0;
                                }
                            }
                            else {
                                newX -= 2; // Met à jour la position cible
                            }
                            break;
                        case 's':
                            if (joueurActuel->x == 2*TAILLE - 2) {
                                printf("Vous ne pouvez pas aller plus bas.\n");
                                deplacementPossible = 0;
                            } else if (plateau[murX + 1][murY] == MUR_HORIZONTALE) { // Vérifier la présence d'un mur horizontal
                                printf("Un mur bloque le passage en bas.\n");
                                deplacementPossible = 0;
                            }
                            else if (plateau[murX+2][murY] != CASE) {
                                if (plateau[murX+4][murY] == CASE && murX+4 <= 16  &&  plateau[murX+3][murY] != MUR_HORIZONTALE) {
                                    // Vérifier la présence d'un mur vertical
                                    newX += 4;
                                }
                                else {
                                    printf("Deplacement impossible. Vous devez bifurquer \n");
                                    deplacementPossible = 0;
                                }
                            }
                            else {
                                newX += 2; // Met à jour la position cible
                            }
                            break;
                        case 'q':
                            if (joueurActuel->y == 0) {
                                printf("Vous ne pouvez pas aller plus a gauche.\n");
                                deplacementPossible = 0;
                            } else if (plateau[murX][murY - 1] == MUR_VERTICALE) { // Vérifier la présence d'un mur vertical
                                printf("Un mur bloque le passage a gauche.\n");
                                deplacementPossible = 0;


                            }
                            else if (plateau[murX][murY - 2] != CASE) {
                                if (plateau[murX][murY - 4] == CASE && murY-4 >= 0  &&  plateau[murX][murY - 3] != MUR_VERTICALE) {
                                    // Vérifier la présence d'un mur vertical
                                    newY -= 4;
                                }
                                else {
                                    printf("Deplacement impossible. Vous devez bifurquer \n");
                                    deplacementPossible = 0;
                                }
                            }
                            else {
                                newY -= 2; // Met à jour la position cible
                            }
                            break;
                        case 'd':
                            if (joueurActuel->y == 2*TAILLE - 2) {
                                printf("Vous ne pouvez pas aller plus a droite.\n");
                                deplacementPossible = 0;
                            } else if (plateau[murX][murY + 1] == MUR_VERTICALE) { // Vérifier la présence d'un mur vertical
                                printf("Un mur bloque le passage a droite.\n");
                                deplacementPossible = 0;
                            }
                            else if (plateau[murX][murY + 2] != CASE) {
                                if (plateau[murX][murY + 4] == CASE && murY+4 <= 16  &&  plateau[murX][murY + 3] != MUR_VERTICALE) {
                                    // Vérifier la présence d'un mur vertical
                                    newY += 4;
                                }
                                else {
                                    printf("Deplacement impossible. Vous devez bifurquer \n");
                                    deplacementPossible = 0;
                                }
                            }
                            else {
                                newY += 2; // Met à jour la position cible
                            }
                            break;
                    }


                    // Déplacer le joueur si le déplacement est possible
                    if (deplacementPossible) {
                        plateau[joueurActuel->x][joueurActuel->y] = CASE;  // Efface l'ancienne position
                        joueurActuel->x = newX;
                        joueurActuel->y = newY;
                        plateau[newX][newY] = joueurActuel->pion;  // Met à jour la nouvelle position
                        printf("Deplacement reussi en direction de %c.\n", direction);
                    }
                } while ((direction != 'z' && direction != 's' && direction != 'q' && direction != 'd') || deplacementPossible == 0);

            }

            case 2:
                printf("%s choisit de passer son tour.\n", joueurActuel->nom);
                break;
            case 3:
                printf("%s veut annuler une action.\n", joueurActuel->nom);
                // Logique pour annuler une action ici

                break;
            case 4:
                printf("%s choisit de placer un mur.\n", joueurActuel->nom);
                placerMur(plateau, joueurs, nombreJoueurs);  // placement murs
                joueurActuel->nombreBarrieres--;
                printf("Il vous reste %d barrieres. \n",joueurActuel->nombreBarrieres);
                break;
            default:
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
void gagnant (Joueur joueurs[], int nombreJoueurs,int* termine) {
    if (nombreJoueurs==4 &&(joueurs[0].y == 16 || joueurs[1].y == 0 || joueurs[2].x ==16 || joueurs[3].x ==0)) {
                        if (joueurs[0].y == 16) {
                            printf("%s a gagne la partie. \n",joueurs[0].nom);
                            joueurs[0].score += 5;
                            printf("%s a %d points. \n",joueurs[0].nom,joueurs[0].score);
                            *termine = 1;
                        }
                        else if (joueurs[1].y == 0) {
                            printf("%s a gagne la partie. \n",joueurs[1].nom);
                            joueurs[1].score += 5;
                            printf("%s a %d points. \n",joueurs[1].nom,joueurs[1].score);
                            *termine = 1;
                        }
                        else if (joueurs[2].x == 16) {
                            printf("%s a gagne la partie. \n",joueurs[2].nom);
                            joueurs[2].score += 5;
                            printf("%s a %d points. \n",joueurs[2].nom,joueurs[2].score);
                            *termine = 1;
                        }
                        else if (joueurs[3].x == 16) {
                            printf("%s a gagne la partie. \n",joueurs[3].nom);
                            joueurs[3].score += 5;
                            printf("%s a %d points. \n",joueurs[3].nom,joueurs[3].score);
                            *termine = 1;
                        }
                    }
                    else if (nombreJoueurs==2 &&(joueurs[0].y == 16 || joueurs[1].y == 0)) {
                            if (joueurs[0].y == 16) {
                            printf("%s a gagne la partie. \n",joueurs[0].nom);
                            joueurs[0].score += 5;
                            printf("%s a %d points. \n",joueurs[0].nom,joueurs[0].score);
                            *termine = 1;
                            }
                            else if (joueurs[1].y == 0) {
                             printf("%s a gagne la partie. \n",joueurs[1].nom);
                             joueurs[1].score += 5;
                             printf("%s a %d points. \n",joueurs[1].nom,joueurs[1].score);
                             *termine = 1;
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
void gestion_partie (int *termine,int *choix2,int *sauvegarde,Joueur joueurs[],int j,char plateau [2*TAILLE-1][2*TAILLE-1],const char*nomFichier){
    do {
        *termine = 0;
        printf("\n----- Tour suivant -----\n");
        // Appel de la fonction pour gérer le tour de chaque joueur
        jouerTour(joueurs, j, plateau);
        //Appel du sous-programme qui gere le gagnant de la partie
        gagnant (joueurs,j,termine);
        //Gestion interruption partie
        if (*termine==0) { //Interruption de la partie ?
            interrompre_partie(termine,sauvegarde);
            if (*sauvegarde==1) {
                sauvegarderJoueurs(joueurs,j,nomFichier);
            }
        }
        if (*termine == 1) {//rejouer une nouvelle partie ?
            rejouer_partie(termine,choix2);
            // Ce bloc doit être exécuté si choix2 est égal à 1
            if (*choix2 == 1) {
                initPlateau(plateau);//Reinitialise le plateau
                placerPionsSurPlateau(plateau, joueurs, &j);//Replace les pions
                afficherPlateau(plateau);
                NombreBarrieres(joueurs,j);
            }
            else {
                initPlateau(plateau);
                placerPionsSurPlateau(plateau,joueurs,&j);
                NombreBarrieres(joueurs,j);
                sauvegarderJoueurs(joueurs,j,nomFichier);

            }
        }
    }while(*termine == 0);
}