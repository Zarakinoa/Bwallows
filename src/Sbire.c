#include "../include/Sbire.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/define.h"
#include "../include/Color.h"


//Initialise un nombre de sbires aléatoire avec des propriétés aléatoire
void init_sbires(sbire_t *sbires, int sbires_nb)
{
    for (int i = 0; i < sbires_nb; i++)
    {
        sbires[i].radius = 5;
        sbires[i].color = alea_color();
        sbires[i].pos.x = rand() % WINDOW_W;
        sbires[i].pos.y = rand() % WINDOW_H;
        sbires[i].direction = rand() % 8;
    }
}

//Affiche les sbires
void draw_sbires(sbire_t *sbires, int sbires_nb)
{
    for (int i = 0; i < sbires_nb; i++)
    {
        DrawCircle(sbires[i].pos.x, sbires[i].pos.y, sbires[i].radius, sbires[i].color);
    }
}

//Déplace les sbires en diagonales/verticales/horizontales
void move_sbires(sbire_t *sbires, int sbires_nb)
{

    for (int i = 0; i < sbires_nb; i++)
    {
        if (sbires[i].direction == VERTICAL_P)
        {
            sbires[i].pos.y += 2;
        }

        else if (sbires[i].direction == VERTICAL_N)
        {
            sbires[i].pos.y -= 2;
        }

        else if (sbires[i].direction == HORIZONTAL_P)
        {
            sbires[i].pos.x += 2;
        }

        else if (sbires[i].direction == HORIZONTAL_N)
        {
            sbires[i].pos.x -= 2;
        }

        else if (sbires[i].direction == DIAGONAL_PXY)
        {
            sbires[i].pos.x += 2;
            sbires[i].pos.y += 2;
        }

        else if (sbires[i].direction == DIAGONAL_NXY)
        {
            sbires[i].pos.x -= 2;
            sbires[i].pos.y -= 2;
        }

        else if (sbires[i].direction == DIAGONAL_PXNY)
        {
            sbires[i].pos.x += 2;
            sbires[i].pos.y -= 2;
        }

        else if (sbires[i].direction == DIAGONAL_PYNX)
        {
            sbires[i].pos.x -= 2;
            sbires[i].pos.y += 2;
        }

        sbires_out_screen(&sbires[i]);
    }
}

//Met à jour la position et direction d'un Sbire hors écran
void sbires_out_screen(sbire_t *sbire)
{
    if ((sbire->pos.x + (sbire->radius / 2) <= 0) || (sbire->pos.x - (sbire->radius / 2) >= WINDOW_W) || (sbire->pos.y + (sbire->radius / 2) <= 0) || (sbire->pos.y - (sbire->radius / 2) >= WINDOW_H))
    {
        alea_position(sbire);
        update_direction(sbire);
    }
}

//Choisit une position aléatoire pour la réaparition du sbire sorti de l'écran
void alea_position(sbire_t *sbire)
{
    int alea = 1 + rand() % 4;

    //Haut
    if (alea == 1)
    {
        sbire->pos.x = 1 + rand() % WINDOW_W;
        sbire->pos.y = 0 - (sbire->radius / 2);
    }

    //Bas
    else if (alea == 2)
    {
        sbire->pos.x = 1 + rand() % WINDOW_W;
        sbire->pos.y = WINDOW_H + (sbire->radius / 2);
    }

    //Gauche
    else if (alea == 3)
    {
        sbire->pos.x = 0 - (sbire->radius / 2);
        sbire->pos.y = 1 + rand() % WINDOW_H;
    }

    //Droite
    else if (alea == 4)
    {
        sbire->pos.x = WINDOW_W + (sbire->radius / 2);
        sbire->pos.y = 1 + rand() % WINDOW_H;
    }
}

//Met à jour la direction du sbires après être sortie de l'écran
void update_direction(sbire_t *sbire)
{
    int new_direction;
    
    while (1)
    {
        new_direction = rand() % 8;

        if ((sbire->pos.x <= 0 || sbire->pos.x >= WINDOW_W) && (new_direction != VERTICAL_N && new_direction != VERTICAL_P))
        {
            sbire->direction = new_direction;
            break;
        } 

        else if ((sbire->pos.y <= 0 || sbire->pos.y >= WINDOW_H) && (new_direction != HORIZONTAL_N && new_direction != HORIZONTAL_P))
        {
            sbire->direction = new_direction;
            break;
        }
    }
}

//Destruction d'un Sbire manger par le Slider
void delete_sbires(sbire_t *sbires)
{
        sbires->radius = 5;
        sbires->color = alea_color();
        sbires->pos.x = rand() % WINDOW_W;
        sbires->pos.y = rand() % WINDOW_H;
        sbires->direction = rand() % 8;
}

//Deplacement infini des Sbires après la fin de jeu
void move_sbires_end(sbire_t *sbires, int sbires_nb, int *score){

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground((Color){147, 177, 242, 255});
        DrawFPS(10, 10);

        draw_sbires(sbires, sbires_nb);
        move_sbires(sbires, sbires_nb);

        display_game_over_score(score);

        EndDrawing();
    }
}