#ifndef SLIDER_H
#define SLIDER_H

#include <raylib.h>
#include "Position.h"
#include "Sbire.h"
#include "Crab.h"

//-----------------------------------Structures-----------------------------------//

typedef enum {

    ALIVE,
    DEAD
} state_t;

typedef struct {  
    
    coord_t pos;
    int radius;
    state_t state;
    Color color;
    int score;
} slider_t ;


//-----------------------------------Fonctions-----------------------------------//

//Initialise les valeurs du Slider au début de partie
void init_slider(slider_t *slider);

//Deplace le Slider vers le haut
void move_top(slider_t *slider);

//Deplace le Slider vers le bas
void move_bottom(slider_t *slider);

//Deplace le Slider vers la gauche
void move_left(slider_t *slider);

//Deplace le Slider vers la droite
void move_right(slider_t *slider);

//Action de l'utilisateur sur la position du Slider
void press_key(slider_t* slider);

//Change la taille du Slider après avoir manger un Sbire
void eats_sbire(slider_t* slider, sbire_t* sbire, int sbires_nb);

//Affiche le score du Slider pendant la partie
void display_game_score(slider_t *slider);

//Affiche le score du Slider à la fin de partie
void display_game_over_score(int *score);

//Le Slider entre en contact avec un Sbire
bool hit_sbire(slider_t *slider, sbire_t *sbire);

//Affiche le Slider
void draw_slider(slider_t* slider);

//Le Slider touche un Crab, fin de partie
bool slider_hit_crab(slider_t *slider, crab_t *crab);

//Si le Slider touche un Crab retourne vrai, sinon faux
bool collision(slider_t *slider, crab_t *crab);

//Supprime le slider en cas de contact avec les Crabs
void delete_slider(slider_t *slider);


#endif