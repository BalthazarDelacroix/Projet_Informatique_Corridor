//
//

#ifndef JOUEUR_H
#define JOUEUR_H
#define TAILLE_NOM 50
#define MAX_JOUEURS 4
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

#endif //JOUEUR_H
