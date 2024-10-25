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

typedef struct {
    char nom[TAILLE_NOM]; // Nom du joueur
    char pion;            // Pion du joueur
    int estIA;
    int nombreBarrieres; // Nombre de barrieres pour chaque joueur
    int score;  // Score du joueur
} Joueur;

void initPlateau(char plateau[TAILLE][TAILLE]);
void afficherPlateau(char plateau[TAILLE][TAILLE]);
void placerMur(char plateau[TAILLE][TAILLE], int x, int y, char typeMur);
void configurerJoueurs(Joueur joueurs[], int *nbJoueurs,int i);
void afficherMenu();
int choisirHumainOuIA(Joueur joueurs[], int i);
int saisirPionUnique(Joueur joueurs[], int nbJoueurs, int i);
void saisirNomUnique(Joueur joueurs[], int nbJoueurs, int i);
int saisirNombreDeJoueurs();

#endif