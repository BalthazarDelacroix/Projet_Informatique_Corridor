#ifndef CODE_MAXENCE_H
#define CODE_MAXENCE_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_JOUEURS 4
#define TAILLE_NOM 50
#define TAILLE 9
#define MUR 'o'  // Représente un mur
#define VIDE '.'  // Représente une case vide
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[TAILLE_NOM]; // Nom du joueur
    unsigned char pion;            // Pion du joueur
    int estIA;
    int nombreBarrieres; // Nombre de barrieres pour chaque joueur
    int score;  // Score du joueur
    int x; // Position en x
    int y; // Position en y
} Joueur;

void jouerTour(Joueur joueurs[], int nombreJoueurs,char plateau[TAILLE][TAILLE]);
int nombreAleatoire(int min, int max);
void placerPionsSurPlateau(char plateau[TAILLE][TAILLE], Joueur joueurs[], int *nbJoueurs);
void initPlateau(char plateau[TAILLE][TAILLE]);
void afficherPlateau(char plateau[TAILLE][TAILLE]);
void placerMur(char plateau[TAILLE][TAILLE], Joueur joueurs[]);
void configurerJoueurs(Joueur joueurs[], int *nbJoueurs);
void NombreBarrieres(Joueur joueurs[], int nbJoueurs);
void afficherMenu(Joueur joueurs[],int j);
void choisirHumainOuIA(Joueur joueurs[], int i);
void saisirPionUnique(Joueur joueurs[], int nbJoueurs, int i);
void saisirNomUnique(Joueur joueurs[], int nbJoueurs, int i);
int saisirNombreDeJoueurs();
void AfficherAide();


#endif