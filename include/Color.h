#ifndef COLOR_H
#define COLOR_H

#include "Slider.h"
#include <raylib.h>

//Couleur aléatoire parmi rouge,gold et jaune
Color alea_color();

//Vérifie si la couleur du slider et la nouvelle couleur aléatoire sont différentes
bool same_color(slider_t* slider, Color c);


#endif