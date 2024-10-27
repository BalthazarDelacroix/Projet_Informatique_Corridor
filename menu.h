//
//

#ifndef MENU_H
#define MENU_H
#include "Joueur.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

void configurerJoueurs( Joueur joueurs[], int *nbJoueurs);//Entrer les attributs des joueurs
void NombreBarrieres( Joueur joueurs[], int nbJoueurs);//Initialise nombre de barrieres
int afficherMenu();//Menu
void choisirHumainOuIA( Joueur joueurs[], int i);//Choix de l'humain ou IA
void saisirPionUnique( Joueur joueurs[], int nbJoueurs, int i);//Choix du pion
void saisirNomUnique( Joueur joueurs[], int nbJoueurs, int i);// Choix nom
int saisirNombreDeJoueurs();//Choix nombre de joueurs
void AfficherAide();//Aide
void Init_score(Joueur joueurs[], int nbJoueurs);//Initialise les scores

#endif //MENU_H
