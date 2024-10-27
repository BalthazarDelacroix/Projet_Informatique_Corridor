//
// Created by wanga on 19/11/2024.
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
    if (fichier == NULL) {
        perror("Erreur ouverture du fichier");
        return;
    }

    char nom[TAILLE_NOM];
    int pion, estIA, nombreBarrieres, score, x, y;

    printf("Noms et Scores des Joueurs de la partie precedente :\n");
    while (fscanf(fichier, "%s %d %d %d %d %d %d", nom, &pion, &estIA, &nombreBarrieres, &score, &x, &y) == 7) {
        printf("Nom : %s, Score : %d\n", nom, score);
    }

    fclose(fichier);
}

// Fonction pour charger une partie sauvegardée
void reprendrePartie(Joueur joueurs[], int* nbJoueurs, int plateau[2*TAILLE-1][2*TAILLE-1], int* dernierTour, const char* nomFichier) {
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
    fscanf(fichier, "%d", dernierTour);
    printf("Partie reprise !\n");
    printf("Etat des joueurs :\n");
    for (int i = 0; i < *nbJoueurs; i++) {
        printf("Nom : %s, Pion : %c, Score : %d, Position : (%d, %d)\n",
               joueurs[i].nom, joueurs[i].pion, joueurs[i].score, joueurs[i].x, joueurs[i].y);
    }
    printf("Etat du plateau :\n");
    for (int i = 0; i <2*TAILLE-1 ; i++) {
        for (int j = 0; j < 2*TAILLE-1; j++) {
            printf("%c ", plateau[i][j]);
        }
        printf("\n");

        fclose(fichier);
    }
}







