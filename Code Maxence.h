

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
#define GAGNERJ1(x, y) (((y)==16)?(1):(0))
#define GAGNERJ2(x, y) (((y)==0)?(1):(0))
#define GAGNERJ3(x, y) (((x)==16)?(1):(0))
#define GAGNERJ4(x, y) (((x)==0)?(1):(0))
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>


typedef struct {
    char nom[TAILLE_NOM]; // Nom du joueur
    unsigned char pion;            // Pion du joueur
    int estIA;
    int nombreBarrieres; // Nombre de barrieres pour chaque joueur
    int score;  // Score du joueur
    int x; // Position en x
    int y; // Position en y
} Joueur;



void jouerTour( Joueur joueurs[], int nombreJoueurs,char plateau[2*TAILLE-1][2*TAILLE-1]);
int nombreAleatoire(int min, int max);
void placerPionsSurPlateau(char plateau[2*TAILLE-1][2*TAILLE-1],  Joueur joueurs[], int *nbJoueurs);
void initPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]);
void afficherPlateau(char plateau[2*TAILLE-1][2*TAILLE-1]);
void placerMur(char plateau[2*TAILLE-1][2*TAILLE-1],  Joueur joueurs[],int nombreDeJoueurs);
void configurerJoueurs( Joueur joueurs[], int *nbJoueurs);
void NombreBarrieres( Joueur joueurs[], int nbJoueurs);
int afficherMenu();
void choisirHumainOuIA( Joueur joueurs[], int i);
void saisirPionUnique( Joueur joueurs[], int nbJoueurs, int i);
void saisirNomUnique( Joueur joueurs[], int nbJoueurs, int i);
int saisirNombreDeJoueurs();
void AfficherAide();
void configurerJoueurs(Joueur joueurs[], int *nbJoueurs);
void changerCouleur(int couleur);
void reinitialiserCouleur();


#endif
