

#include "Code Maxence.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include <stdio.h>


// Fonction pour afficher le menu et gérer les choix
void afficherMenu() {
    int choix;

    do {
        // Affichage du menu
        printf("\n MENU DU JEU \n");
        printf("1. Lancer une nouvelle partie\n");
        printf("2. Reprendre une partie sauvegardee\n");
        printf("3. Afficher l'aide\n");
        printf("4. Afficher les scores des joueurs\n");
        printf("5. Quitter\n");
        printf("Veuillez choisir une option (1-5) : ");
        scanf("%d", &choix);
        // Verification de la validite du choix
        if (choix <= 0 || choix > 5) {
            printf("Erreur: Veuillez entrer un nombre entre 1 et 5.\n");
        }

    } while (choix <= 0 || choix > 5);  // Repete tant que l'entree est invalide

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
    do {
        printf("Entrez le nombre de joueurs (2 ou 4) : ");
        scanf("%d", &nbJoueurs);
        if (nbJoueurs != 2 && nbJoueurs != 4) {
            printf("Erreur: Le nombre de joueurs doit etre 2 ou 4.\n");
        }
    } while (nbJoueurs != 2 && nbJoueurs != 4);  // Répète tant que le nombre de joueurs n'est pas valide
    return nbJoueurs;  // Retourne le nombre de joueurs validé
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
int saisirPionUnique(Joueur joueurs[], int nbJoueurs, int i) {
    char pion;
    int pionUnique;
    do {
        printf("Joueur %d, choisissez un pion (caractere unique) : \n", i + 1);
        scanf(" %c", &pion);// Espace avant %c pour ignorer les caractères résiduels

        // Vérification de l'unicité du pion
        for (int j = 0; j < i; j++) {
            if (joueurs[j].pion == pion) {
                pionUnique = 0;  // Pion déjà pris
                printf("Erreur: Ce pion est deja utilise par un autre joueur.\n");
                break;
            }
        }
    } while (pionUnique == 0);  // Répète tant que le pion n'est pas unique

    joueurs[i].pion = pion;  // Attribue le pion au joueur
    return joueurs[i].pion;
}


int choisirHumainOuIA(Joueur joueurs[], int i) {
    int choix;
    do {

        printf("Le joueur %s est-il un humain (0) ou une IA (1) ?\n ", joueurs[i].nom);
        scanf(" %d", &choix);

        if (choix != 0 && choix != 1) {
            printf("Erreur: Vous devez entrer 0 pour Humain ou 1 pour IA.\n");
        }
    } while (choix != 0 && choix != 1);

    return joueurs[i].estIA = choix;  // Attribuer le type (Humain ou IA) au joueur
}
void configurerJoueurs(Joueur joueurs[], int *nbJoueurs) {
    // 1. Saisie et validation du nombre de joueurs
    *nbJoueurs = saisirNombreDeJoueurs();
    int p,a;
    // 2. Boucle pour configurer chaque joueur
    for (int i = 0; i < *nbJoueurs; i++) {
        // 3. Saisie et validation du nom
        saisirNomUnique(joueurs, *nbJoueurs, i);
        // 4. Choix entre Humain ou IA
        do {
            choisirHumainOuIA(joueurs, i);
            a = choisirHumainOuIA(joueurs, i);
        } while (a != 0 && a != 1);

        // 5. Saisie et validation du pion
        do {

            saisirPionUnique(joueurs, *nbJoueurs, i);
            p = saisirPionUnique(joueurs, *nbJoueurs, i);
            } while (p>255 && p<0);


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
