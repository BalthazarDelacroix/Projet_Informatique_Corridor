

#ifndef CODE_MAXENCE_H
#define CODE_MAXENCE_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_JOUEURS 4
#define TAILLE_NOM 50
#define TAILLE 9
#define CASE '.'  // Représente une case vide
#define MUR_HORIZONTALE '-'
#define MUR_VERTICALE '|'
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
//structure joueur
typedef struct {
    char nom[TAILLE_NOM]; // Nom du joueur
    unsigned char pion;            // Pion du joueur
    int estIA;
    int nombreBarrieres; // Nombre de barrieres pour chaque joueur
    int score;  // Score du joueur
    int x; // Position en x
    int y; // Position en y


} Joueur;



void jouerTour( Joueur joueurs[], int nombreJoueurs,char plateau[2*TAILLE-1][2*TAILLE-1],const char* nomFichier,int* blocage,int* termine);// Gestion des tours
int nombreAleatoire(int min, int max); // Pour les tours, appel un joueur aléatoire
void placerPionsSurPlateau(char plateau[2*TAILLE-1][2*TAILLE-1],  Joueur joueurs[], int *nbJoueurs);// place les pions en debut de partie
void initPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]);// Initialise le plateau
void afficherPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]);//Affiche le plateau
void placerMur(char plateau[2*TAILLE-1][2*TAILLE-1], Joueur joueurs[], int nombreDeJoueurs,int*x,int*y,char * typeMur);// Pose des barrieres
void configurerJoueurs( Joueur joueurs[], int *nbJoueurs);//Entrer les attributs des joueurs
void NombreBarrieres( Joueur joueurs[], int nbJoueurs);//Initialise nombre de barrieres
int afficherMenu();//Menu
void choisirHumainOuIA( Joueur joueurs[], int i);//Choix de l'humain ou IA
void saisirPionUnique( Joueur joueurs[], int nbJoueurs, int i);//Choix du pion
void saisirNomUnique( Joueur joueurs[], int nbJoueurs, int i);// Choix nom
int saisirNombreDeJoueurs();//Choix nombre de joueurs
void AfficherAide();//Aide
void changerCouleur(int couleur);//Change la couleur
void reinitialiserCouleur();//Remet la couleur par defaut
void gagnant (Joueur joueurs[], int nombreJoueurs,int* termine, int* blocage);//Verifie si un joueur a gagne
void interrompre_partie(int*termine,int*sauvegarde);//Interruption partie
void rejouer_partie (int*termine,int*choix2);//Choix de rejouer partie ou non
void sauvegarderJoueurs(Joueur joueurs[], int nbJoueurs, const char* nomFichier);// Sauvegarde partie, joueurs, plateau
void afficherNomsEtScores(const char* nomFichier);//Score
void reprendrePartie(Joueur joueurs[], int* nbJoueurs, char plateau[2*TAILLE-1][2*TAILLE-1], const char* nomFichier);//Charge une partie jouee avant
void gestion_partie (int *termine,int *choix2,int *sauvegarde,Joueur joueurs[],int j,char plateau [2*TAILLE-1][2*TAILLE-1],const char*nomFichier,int* blocage);// gere deroulement du jeu
void sauvegarderPlateau(char plateau[2 * TAILLE - 1][2 * TAILLE - 1], const char* nomFichier);
void Annulation_Plateau(const char* nomFichier,int*annulation,char plateau[2 * TAILLE - 1][2 * TAILLE - 1]); // Annulation du coup, reaffiche l'etat du plateau avant le dernier changement
void blocage_partie (Joueur joueurs[],char plateau [2*TAILLE-1][2*TAILLE-1],int*blocage,int nombrejoueurs,int* termine);//Verifie si le joueur peut encore se deplacer
#endif
