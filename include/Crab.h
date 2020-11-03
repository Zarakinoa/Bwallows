#ifndef CRAB_H
#define CRAB_H

#include <raylib.h>
#include "Position.h"
#include "Direction.h"
#include "Sbire.h"
#include <stdlib.h>

//-----------------------------------Structures-----------------------------------//

typedef struct
{
    coord_t pos;
    int radius;
    Color color;
    direction_t direction;
} crab_t;

//-----------------------------------Fonctions-----------------------------------//

//Initialise 3 Crabs avec des propriétés aléatoires
void init_crabs(crab_t *crabs);

//Affiche les Crabs
void draw_crabs(crab_t *crabs);

//Déplace les Crabs en diagonales/verticales/horizontales
void move_crabs(crab_t *crabs);

//Met à jour la position et direction d'un Crab hors écran
void crabs_out_screen(crab_t *crabs);

//Choisit une position aléatoire pour la réaparition du Crab hors écran
void alea_position_crabs(crab_t *crabs);

//Met à jour la direction du Crab hors écran
void update_direction_crabs(crab_t *crabs);

//Fait grossir un Crab ayant manger un sbire
void eat_crabs(crab_t *crab, sbire_t *sbire, int sbires_nb);

//Retourne vrai si un crab entre en contact avec sbire
bool crabs_hit_sbire(crab_t *crab, sbire_t *sbire);

//Supprime les crabs
void delete_crabs(crab_t * crabs);

#endif