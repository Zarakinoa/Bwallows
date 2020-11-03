#include "../include/Crab.h"
#include "../include/define.h"
#include <stdlib.h>

//Initialise 3 Crabs avec des propriétés aléatoires
void init_crabs(crab_t *crabs)
{
    for (int i = 0; i < 3; i++)
    {
        crabs[i].radius = 30;
        crabs[i].color = BLACK;
        crabs[i].pos.x = rand() % WINDOW_W;
        crabs[i].pos.y = rand() % WINDOW_H;
        crabs[i].direction = rand() % 8;
    }
}

//Affiche les Crabs
void draw_crabs(crab_t *crabs)
{
    for (int i = 0; i < 3; i++)
    {
        DrawCircle(crabs[i].pos.x, crabs[i].pos.y, crabs[i].radius, crabs[i].color);
    }
}

//Déplace les Crabs en diagonales/verticales/horizontales
void move_crabs(crab_t *crabs)
{

    for (int i = 0; i < 3; i++)
    {
        if (crabs[i].direction == VERTICAL_P)
        {
            crabs[i].pos.y += 2;
        }

        else if (crabs[i].direction == VERTICAL_N)
        {
            crabs[i].pos.y -= 2;
        }

        else if (crabs[i].direction == HORIZONTAL_P)
        {
            crabs[i].pos.x += 2;
        }

        else if (crabs[i].direction == HORIZONTAL_N)
        {
            crabs[i].pos.x -= 2;
        }

        else if (crabs[i].direction == DIAGONAL_PXY)
        {
            crabs[i].pos.x += 2;
            crabs[i].pos.y += 2;
        }

        else if (crabs[i].direction == DIAGONAL_NXY)
        {
            crabs[i].pos.x -= 2;
            crabs[i].pos.y -= 2;
        }

        else if (crabs[i].direction == DIAGONAL_PXNY)
        {
            crabs[i].pos.x += 2;
            crabs[i].pos.y -= 2;
        }

        else if (crabs[i].direction == DIAGONAL_PYNX)
        {
            crabs[i].pos.x -= 2;
            crabs[i].pos.y += 2;
        }

        crabs_out_screen(&crabs[i]);
    }
}

//Met à jour la position et direction d'un Crab hors écran
void crabs_out_screen(crab_t *crab)
{
    if ((crab->pos.x + (crab->radius / 2) <= 0) || (crab->pos.x - (crab->radius / 2) >= WINDOW_W) || (crab->pos.y + (crab->radius / 2) <= 0) || (crab->pos.y - (crab->radius / 2) >= WINDOW_H))
    {
        alea_position_crabs(crab);
        update_direction_crabs(crab);
    }
}

//Choisit une position aléatoire pour la réaparition du Crab sorti de l'écran
void alea_position_crabs(crab_t *crab)
{
    int alea = 1 + rand() % 4;

    //Haut
    if (alea == 1)
    {
        crab->pos.x = 1 + rand() % WINDOW_W;
        crab->pos.y = 0 - (crab->radius / 2);
    }

    //Bas
    else if (alea == 2)
    {
        crab->pos.x = 1 + rand() % WINDOW_W;
        crab->pos.y = WINDOW_H + (crab->radius / 2);
    }

    //Gauche
    else if (alea == 3)
    {
        crab->pos.x = 0 - (crab->radius / 2);
        crab->pos.y = 1 + rand() % WINDOW_H;
    }

    //Droite
    else if (alea == 4)
    {
        crab->pos.x = WINDOW_W + (crab->radius / 2);
        crab->pos.y = 1 + rand() % WINDOW_H;
    }
}

//Met à jour la direction du Crabs après être sortie de l'écran
void update_direction_crabs(crab_t *crab)
{
    int new_direction;

    while (1)
    {
        new_direction = rand() % 8;

        if ((crab->pos.x <= 0 || crab->pos.x >= WINDOW_W) && (new_direction != VERTICAL_N && new_direction != VERTICAL_P))
        {
            crab->direction = new_direction;
            break;
        }

        else if ((crab->pos.y <= 0 || crab->pos.y >= WINDOW_H) && (new_direction != HORIZONTAL_N && new_direction != HORIZONTAL_P))
        {
            crab->direction = new_direction;
            break;
        }
    }
}

//Fait grossir un Crab ayant manger un sbire
void eat_crabs(crab_t *crab, sbire_t *sbire, int sbires_nb)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < sbires_nb; j++)
        {
            if (crabs_hit_sbire(&crab[i], &sbire[j]))
            {
                crab[i].radius += 1;

                delete_sbires(&sbire[j]);
                break;
            }
        }
    }
}

//Retourne vrai si un crab entre en contact avec sbire
bool crabs_hit_sbire(crab_t *crab, sbire_t *sbire)
{

    Vector2 v1 = (Vector2){(float)crab->pos.x, (float)crab->pos.y};
    Vector2 v2 = (Vector2){(float)sbire->pos.x, (float)sbire->pos.y};

    if (CheckCollisionCircles(v1, crab->radius, v2, sbire->radius))
    {
        return true;
    }

    return false;
}

//Supprime les crabs
void delete_crabs(crab_t * crabs) {
    free(crabs);
}
