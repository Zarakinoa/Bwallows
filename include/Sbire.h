#ifndef SBIRE_H
#define SBIRE_H

#include <raylib.h>
#include "Position.h"
#include "Direction.h"

//-----------------------------------Structures-----------------------------------//

typedef struct
{

    coord_t pos;
    int radius;
    Color color;
    direction_t direction;
} sbire_t;

//-----------------------------------Fonctions-----------------------------------//

//Initialise un nombre de sbires aléatoire avec des propriétés aléatoire
void init_sbires(sbire_t *sbires, int sbires_nb);

//Affiche les sbires
void draw_sbires(sbire_t *sbires, int sbires_nb);

//Déplace les sbires en diagonales/verticales/horizontales
void move_sbires(sbire_t *sbires, int sbires_nb);

//Met à jour la position et direction d'un Sbire hors écran
void sbires_out_screen(sbire_t *sbires);

//Choisit une position aléatoire pour la réaparition du Sbire hors écran
void alea_position(sbire_t *sbire);

//Met à jour la direction du Sbire hors écran
void update_direction(sbire_t *sbire);

//Destruction des sbires manger ou sortant de la fenêtre de jeu
void delete_sbires(sbire_t *sbires);

//Deplacement infini des Sbires après la fin de jeu
void move_sbires_end(sbire_t *sbires, int sbires_nb, int *score);

#endif