//

//
#include "Code Maxence.h"




// Fonction pour sauvegarder les données des joueurs dans un fichier
void sauvegarderJoueurs(Joueur joueurs[], int nbJoueurs, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    for (int i = 0; i < nbJoueurs; i++) {
        fprintf(fichier, "%s %d %d %d %d %d %d\n",
                joueurs[i].nom,
                joueurs[i].pion,
                joueurs[i].estIA,
                joueurs[i].nombreBarrieres,
                joueurs[i].score,
                joueurs[i].x,
                joueurs[i].y);
    }

    fclose(fichier);
}

// Fonction pour afficher uniquement les noms et scores des joueurs depuis le fichier
void afficherNomsEtScores(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    //Si le fichier ne contient rien
    if (fichier == NULL) {
        perror("Erreur ouverture du fichier");
        return;
    }

    char nom[TAILLE_NOM];
    int pion, estIA, nombreBarrieres, score, x, y;
    // Affichage des donnees des joueurs sauvegardés
    printf("Noms et Scores des Joueurs de la partie precedente :\n");
    while (fscanf(fichier, "%s %d %d %d %d %d %d", nom, &pion, &estIA, &nombreBarrieres, &score, &x, &y) == 7) {
        printf("Nom : %s, Score : %d\n", nom, score);
    }

    fclose(fichier);
}

// Fonction pour charger une partie sauvegardée
void reprendrePartie(Joueur joueurs[], int* nbJoueurs, char plateau[2*TAILLE-1][2*TAILLE-1], const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur ouverture du fichier");
        return;
    }

    // Charger le plateau
    for (int i = 0; i < 2*TAILLE-1; i++) {
        for (int j = 0; j < 2*TAILLE-1; j++) {
            fscanf(fichier, "%d", &plateau[i][j]);
        }
    }

    // Charger les joueurs
    *nbJoueurs = 0;
    while (fscanf(fichier, "%s %d %d %d %d %d %d",
                  joueurs[*nbJoueurs].nom,
                  &joueurs[*nbJoueurs].pion,
                  &joueurs[*nbJoueurs].estIA,
                  &joueurs[*nbJoueurs].nombreBarrieres,
                  &joueurs[*nbJoueurs].score,
                  &joueurs[*nbJoueurs].x,
                  &joueurs[*nbJoueurs].y) == 7) {
        (*nbJoueurs)++;
                  }
    // Charger le dernier tour
    printf("Partie reprise !\n");
    printf("Etat des joueurs :\n");
    //Affichage des informations sur les joueurs
    for (int i = 0; i < *nbJoueurs; i++) {
        printf("Nom : %s, Pion : %c, Score : %d, Position : (%d, %d)\n",
               joueurs[i].nom, joueurs[i].pion, joueurs[i].score, joueurs[i].x, joueurs[i].y);
    }
    printf("Etat du plateau :\n");
    //Affichage du plateau sauvegardé
    for (int i = 0; i < 2*TAILLE-1; i++) {
        for (int j = 0; j < 2*TAILLE-1; j++) {
            // Vérifier si c'est un pion
            if (plateau[i][j] != CASE && plateau[i][j] != ' ' && plateau[i][j] != MUR_HORIZONTALE && plateau[i][j] != MUR_VERTICALE ) {
                changerCouleur(9); // Bleu pour les pions
                printf("%c ", plateau[i][j]);
                reinitialiserCouleur();
            }
            // Vérifier si c'est un mur horizontal ou vertical
            else if (plateau[i][j] == MUR_HORIZONTALE || plateau[i][j] == MUR_VERTICALE) {
                changerCouleur(12); // Rouge pour les murs horizontaux
                printf("%c ", plateau[i][j]);
                reinitialiserCouleur();
            }

            else {
                printf("%c ", plateau[i][j]);
            }
        }
        printf("\n");
    }

    fclose(fichier);
    }

// Fonction pour sauvegarder le plateau dans un fichier
void sauvegarderPlateau(char plateau[2 * TAILLE - 1][2 * TAILLE - 1], const char* nomFichier) {
    // Ouverture du fichier en mode ecriture
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    // Parcours du plateau et ecriture dans le fichier
    for (int i = 0; i < 2 * TAILLE - 1; i++) {
        for (int j = 0; j < 2 * TAILLE - 1; j++) {
            fprintf(fichier, "%c", plateau[i][j]);
        }
        fprintf(fichier, "\n"); // Ajouter un retour a la ligne a la fin de chaque ligne du plateau
    }

    fclose(fichier); // Fermeture du fichier
}

// Fonction pour reafficher le plateau depuis le fichier
void Annulation_Plateau(const char* nomFichier,int*annulation,char plateau[2 * TAILLE - 1][2 * TAILLE - 1]) {
    // Ouverture du fichier en mode lecture
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur ouverture du fichier");
        return;
    }

    char ligne[2 * TAILLE]; // Tampon pour lire une ligne du fichier
    int ligneIndex = 0;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        for (int i = 0; i < 2*TAILLE-1; i++) {
            for (int j = 0; j < 2*TAILLE-1; j++) {
                // Vérifier si c'est un pion
                if (plateau[i][j] != CASE && plateau[i][j] != ' ' && plateau[i][j] != MUR_HORIZONTALE && plateau[i][j] != MUR_VERTICALE ) {
                    changerCouleur(9); // Bleu pour les pions
                    printf("%c ", plateau[i][j]);
                    reinitialiserCouleur();
                }
                // Vérifier si c'est un mur horizontal ou vertical
                else if (plateau[i][j] == MUR_HORIZONTALE || plateau[i][j] == MUR_VERTICALE) {
                    changerCouleur(12); // Rouge pour les murs horizontaux
                    printf("%c ", plateau[i][j]);
                    reinitialiserCouleur();
                }

                else {
                    printf("%c ", plateau[i][j]);
                }
            }
            printf("\n");
            ligneIndex++;
            *annulation=0;
        }

        fclose(fichier); // Fermeture du fichier
    }
}






