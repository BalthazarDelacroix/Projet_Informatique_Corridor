

#include "Code Maxence.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include <stdio.h>


// Fonction pour afficher le menu et gérer les choix
void afficherMenu() {
    int choix;
    char buffer[10]; // Utilisation d'un buffer pour capturer l'entrée

    do {
        // Affichage du menu
        printf("\n\t MENU DU JEU \n");
        printf("1. Lancer une nouvelle partie\n");
        printf("2. Reprendre une partie sauvegardee\n");
        printf("3. Afficher l'aide\n");
        printf("4. Afficher les scores des joueurs\n");
        printf("5. Quitter\n");
        printf("Veuillez choisir une option (1-5) : ");

        // Utilisation de fgets pour capturer l'entrée complète
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tentative de conversion de l'entrée en entier
            if (sscanf(buffer, "%d", &choix) != 1 || choix < 1 || choix > 5) {
                printf("Erreur: Veuillez entrer un nombre entre 1 et 5.\n");
                choix = -1;  // Réinitialiser le choix si c'est une entrée invalide
            }
        }

    } while (choix < 1 || choix > 5);  // Répète tant que l'entrée est invalide

    // Gestion des choix avec switch-case
    switch (choix) {
        case 1:
            printf("Vous avez choisi : Lancer une nouvelle partie\n");
            // Appeler ici la fonction qui démarre une nouvelle partie
            Joueur joueurs[MAX_JOUEURS];  // Déclaration du tableau de joueurs
            int nbJoueurs;                // Variable pour stocker le nombre de joueurs
            // Appel de la fonction configurerJoueurs avec les parametres requis
            configurerJoueurs(joueurs, &nbJoueurs);
            break;
        case 2:
            printf("Vous avez choisi : Reprendre une partie sauvegardée\n");
            // Appeler ici la fonction qui charge une partie sauvegardee
            break;
        case 3:
            printf("Vous avez choisi : Afficher l'aide\n");
            // Appeler ici la fonction qui affiche l'aide
            break;
        case 4:
            printf("Vous avez choisi : Afficher les scores des joueurs\n");
            // Appeler ici la fonction qui affiche les scores
            break;
        case 5:
            printf("Vous avez choisi : Quitter le jeu\n");
            break;
        default:
            printf("Erreur: Choix non reconnu.\n");
            break;
    }
}






int saisirNombreDeJoueurs() {
    int nbJoueurs;
    char buffer[10]; // Buffer pour capturer l'entrée

    do {
        printf("Veuillez entrer le nombre de joueurs (entre 2 et 4) : ");

        // Utilisation de fgets pour capturer l'entrée
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tentative de conversion de l'entrée en entier
            if (sscanf(buffer, "%d", &nbJoueurs) != 1 || nbJoueurs < 2 || nbJoueurs > 4) {
                printf("Erreur: Vous devez entrer un nombre entre 2 et 4.\n");
                nbJoueurs = -1;  // Réinitialiser si l'entrée est invalide
            }
        }
    } while (nbJoueurs < 2 || nbJoueurs > 4);  // Boucle tant que l'entrée est incorrecte

    return nbJoueurs;
}



void saisirNomUnique(Joueur joueurs[], int nbJoueurs, int i) {
    char nom[TAILLE_NOM];
    int nomUnique;
    do {
        nomUnique = 1;
        printf("Joueur %d, entrez votre nom : \n", i + 1);
        scanf("%s", &nom);

        // Vérification de l'unicité du nom
        for (int j = 0; j < i; j++) {
            if (strcmp(joueurs[j].nom, nom) == 0) {
                nomUnique = 0; // Nom déjà pris
                printf("Erreur: Ce nom est deja pris. Veuillez choisir un autre nom.\n");
                break;
            }
        }
    } while (nomUnique == 0);

    strcpy(joueurs[i].nom, nom);  // Copier le nom dans la structure du joueur
}
void saisirPionUnique(Joueur joueurs[], int nbJoueurs, int i) {
    char pion;
    int pionUnique;
    do {
        pionUnique = 1;
        char temp[2];
        printf("Joueur %d, choisissez un pion (caractere unique) : \n", i + 1);

        // Lire une ligne pour vérifier s'il n'y a qu'un caractère
        if (scanf("%1s", temp) != 1 || getchar() != '\n') {
            printf("Erreur: Veuillez entrer un seul caractère pour le pion.\n");
            pionUnique = 0;
            while (getchar() != '\n'); // Nettoyer le tampon
            continue;
        }
        pion = temp[0]; // Assigner le pion s'il y a bien un seul caractère

        // Vérification de l'unicité du pion
        for (int k = 0; k < i; k++) {
            if (joueurs[k].pion == pion) {
                pionUnique = 0;  // Pion déjà pris
                printf("Erreur: Ce pion est deja utilise par un autre joueur.\n");
                break;
            }
        }
    } while (pionUnique == 0);
}

void choisirHumainOuIA(Joueur joueurs[], int i) {
    char buffer[10]; // Un buffer assez grand pour contenir l'entrée
    int choix;

    do {
        printf("Le joueur %s est-il un humain (0) ou une IA (1) ?\n", joueurs[i].nom);
        // Utilisation de fgets pour capturer l'entrée en entier
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tentative de conversion de l'entrée en entier
            if (sscanf(buffer, "%d", &choix) != 1 || (choix != 0 && choix != 1)) {
                printf("Erreur: Vous devez entrer 0 pour Humain ou 1 pour IA.\n");
            }
        } else {
            // Si fgets échoue, on réinitialise choix pour refaire le choix
            choix = -1;
        }
    } while (choix != 0 && choix != 1); // Boucle tant que l'entrée est incorrecte

    // Assigner le choix à la structure joueur
    joueurs[i].estIA = (choix == 1);
}

void configurerJoueurs(Joueur joueurs[], int *nbJoueurs) {
    // 1. Saisie et validation du nombre de joueurs
    *nbJoueurs = saisirNombreDeJoueurs();
    // 2. Boucle pour configurer chaque joueur
    for (int i = 0; i < *nbJoueurs; i++) {
        // 3. Saisie et validation du nom
        saisirNomUnique(joueurs, *nbJoueurs, i);
        // .4 Saisie et validation du pion

        saisirPionUnique(joueurs, *nbJoueurs, i);

        // 5. Choix entre Humain ou IA
        choisirHumainOuIA(joueurs, i);
    }

    // Affichage de la configuration finale des joueurs
    printf("\nConfiguration des joueurs :\n");
    for (int i = 0; i < *nbJoueurs; i++) {
        printf("Joueur %d : Nom = %s, Pion = %c, Type = %s\n",
               i + 1,
               joueurs[i].nom,
               joueurs[i].pion,
               joueurs[i].estIA ? "IA" : "Humain");
    }
}
