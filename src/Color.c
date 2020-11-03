#include "../include/Color.h"
#include <stdlib.h>

//Couleur aléatoire parmi rouge,gold et jaune
Color alea_color()
{
    Color tab[3] = {(Color){253, 249, 0, 255}, (Color){230, 41, 55, 255}, (Color){255, 203, 0, 255}};

    return tab[rand() % 3];
}

//Vérifie si la couleur du slider et la nouvelle couleur aléatoire sont différentes
bool same_color(slider_t *slider, Color c)
{
    if (slider->color.r == c.r && slider->color.g == c.g && slider->color.b == c.b)
        return true;

    return false;
}
