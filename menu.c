#include "Code Maxence.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#include <stdio.h>


// Fonction pour afficher le menu et gérer les choix
void afficherMenu(Joueur joueurs[],int j) {
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
            // Appel de la fonction configurerJoueurs avec les parametres requis
            configurerJoueurs(joueurs, &j);
            break;
        case 2:
            printf("Vous avez choisi : Reprendre une partie sauvegardée\n");
            // Appeler ici la fonction qui charge une partie sauvegardee
            break;
        case 3:
            printf("Vous avez choisi : Afficher l'aide\n");
            AfficherAide();
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
        printf("Veuillez entrer le nombre de joueurs (2 ou 4) : ");

        // Utilisation de fgets pour capturer l'entrée
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tentative de conversion de l'entrée en entier
            if (sscanf(buffer, "%d", &nbJoueurs) != 1 || (nbJoueurs != 2 && nbJoueurs != 4)) {
                printf("Erreur: Vous devez entrer un nombre entre 2 et 4.\n");
                nbJoueurs = -1;  // Réinitialiser si l'entrée est invalide
            }
        }
    } while (nbJoueurs != 2 && nbJoueurs != 4);  // Boucle tant que l'entrée est incorrecte

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
    unsigned char pion;
    int pionUnique;
    char temp[4];

    do {
        pionUnique = 1;
        printf("Joueur %d, choisissez un pion (code hexadecimal unique) : \n", i + 1);

        if (scanf("%4s", temp) != 1 || getchar() != '\n') {
            printf("Erreur: Veuillez entrer un code hexadecimal valide (ex: 41 pour 'A').\n");
            pionUnique = 0;
            while (getchar() != '\n');
            continue;
        }

        int code = (int)strtol(temp, NULL, 16);

        if (code < 0x00 || code > 0xFF) {
            printf("Erreur: Veuillez entrer un code hexadecimal valide pour un caractère imprimable (entre 20 et FE).\n");
            pionUnique = 0;
            continue;
        }

        pion = (unsigned char)code;

        for (int k = 0; k < i; k++) {
            if (joueurs[k].pion == pion) {
                pionUnique = 0;
                printf("Erreur: Ce pion est deja utilise par un autre joueur.\n");
                break;
            }
        }
    } while (pionUnique == 0);

    joueurs[i].pion = pion;


    printf("Pion selectionne: %c\n", pion);  // Affichage du pion choisi
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
void NombreBarrieres(Joueur joueurs[], int nbJoueurs) {
    if (nbJoueurs == 2) {
        for(int i=0;i<nbJoueurs;i++) {
            joueurs[i].nombreBarrieres = 10;
        }
    }
    else if (nbJoueurs == 4) {

        for(int j=0;j<nbJoueurs;j++) {
            joueurs[j].nombreBarrieres = 5; }
    }

}

void configurerJoueurs(Joueur joueurs[], int *nbJoueurs) {
    // 2. Boucle pour configurer chaque joueur
    for (int i = 0; i < *nbJoueurs; i++) {
        // 3. Saisie et validation du nom
        saisirNomUnique(joueurs, *nbJoueurs, i);
        // .4 Saisie et validation du pion

        saisirPionUnique(joueurs, *nbJoueurs, i);

        // 5. Choix entre Humain ou IA
        choisirHumainOuIA(joueurs, i);
        NombreBarrieres(joueurs,*nbJoueurs);
    }

    // Affichage de la configuration finale des joueurs
    printf("\nConfiguration des joueurs :\n");
    for (int i = 0; i < *nbJoueurs; i++) {
        printf("Joueur %d : Nom = %s, Pion = %c, Type = %s, Barrieres = %d\n",
               i + 1,
               joueurs[i].nom,
               joueurs[i].pion,
               joueurs[i].estIA ? "IA" : "Humain",
               joueurs[i].nombreBarrieres);
    }

}

void AfficherAide(){
    printf("- Chaque joueur est soit humain soit une IA, a choisir avant de lancer la partie.\n"
           "- Plateau de 9 cases par ligne et 9 cases par colonne. Entre les lignes et entre les colonnes il y"
           " a un emplacement prevu pour planter les murs du corridor (ou Quoridor) !\n"
           "- 20 barrieres ( (10 barrieres par joueur pour 2 joueurs ou 5 barrieres pour 4 joueurs).\n"
           "- Chaque barriere a une longueur de 2 cases et se positionnera entre deux lignes ou deux\n"
           "colonnes.\n"
           "- 1 zone de stockage par joueur des barrieres en début de partie (inventaire)\n"
           "- ♟Un pion par joueur avec un jeton a choisir parmi un caractere de son choix");
}