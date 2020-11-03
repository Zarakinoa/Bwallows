#include "../include/Slider.h"
#include <stdio.h>
#include <stdlib.h>

#include "../include/define.h"
#include "../include/Color.h"

//Initialise les valeurs du slider au début de partie
void init_slider(slider_t *slider)
{

    slider->pos.x = 300;
    slider->pos.y = 250;
    slider->radius = 20;
    slider->color = alea_color();
    slider->score = 0;
    slider->state = ALIVE;
}

//Deplace le slider vers le haut
void move_top(slider_t *slider)
{

    slider->pos.y -= 10;

    if (slider->pos.y + (slider->radius / 2) <= 0)
        slider->pos.y = WINDOW_H + 2 * slider->radius;
}

//Deplace le slider vers le bas
void move_bottom(slider_t *slider)
{

    slider->pos.y += 10;

    if (slider->pos.y - (slider->radius / 2) >= WINDOW_H)
        slider->pos.y = 0 - 2 * slider->radius;
}

//Deplace le slider vers la gauche
void move_left(slider_t *slider)
{

    slider->pos.x -= 10;

    if (slider->pos.x + (slider->radius / 2) <= 0)
        slider->pos.x = WINDOW_W + 2 * slider->radius;
}

//Deplace le slider vers la droite
void move_right(slider_t *slider)
{

    slider->pos.x += 10;

    if (slider->pos.x - (slider->radius / 2) >= WINDOW_W)
        slider->pos.x = 0 - 2 * slider->radius;
}

//Action de l'utilisateur sur la position du Slider
void press_key(slider_t *slider)
{

    if (IsKeyDown(KEY_UP))
        move_top(slider);
    else if (IsKeyDown(KEY_DOWN))
        move_bottom(slider);
    else if (IsKeyDown(KEY_LEFT))
        move_left(slider);
    else if (IsKeyDown(KEY_RIGHT))
        move_right(slider);
}

//Change la taille du slider après avoir manger un Sbire
void eats_sbire(slider_t *slider, sbire_t *sbire, int sbires_nb)
{

    Color c = alea_color();

    for (int i = 0; i < sbires_nb; i++)
    {
        if (hit_sbire(slider, &sbire[i]) && same_color(slider, sbire[i].color))
        {
            slider->score++;

            delete_sbires(&sbire[i]);

            while (same_color(slider, c))
            {
                c = alea_color();
            }

            slider->color = c;
        }
    }
}

//Affiche le score du Slider pendant la partie
void display_game_score(slider_t *slider)
{

    int NB = 0;

    while (slider->score / 10 > 10)
    {
        NB++;
    }

    char str[NB];

    sprintf(str, "%d", slider->score);

    DrawText("Score : ", 1600, 10, 50, WHITE);
    DrawText(str, 1800, 10, 50, WHITE);
}

//Affiche le score du Slider à la fin de partie
void display_game_over_score(int *score)
{

    int NB = 0;

    while (*score % 10 > 10)
    {
        NB++;
    }

    char str[NB];

    sprintf(str, "%d", *score);

    Rectangle rb = (Rectangle){960 - 350 , 505 - 200, 700, 400};
    DrawRectangleRounded(rb, 0.2, 4, DARKBLUE);

    Rectangle rf = (Rectangle){960 - 330 , 505 - 180, 660, 360};
    DrawRectangleRounded(rf, 0.2, 4,  WHITE);

    DrawText("Game Over", 960 - 250, 505 - 100, 100,BLACK);
    DrawText("Score : ", 960 - 200, 505 + 50, 70, DARKBLUE);
    DrawText(str, 960 + 100, 505 + 50, 70, DARKPURPLE);
}

//Le Slider entre en contact avec un Sbire
bool hit_sbire(slider_t *slider, sbire_t *sbire)
{
    Vector2 v1 = (Vector2){(float)slider->pos.x, (float)slider->pos.y};
    Vector2 v2 = (Vector2){(float)sbire->pos.x, (float)sbire->pos.y};

    if (CheckCollisionCircles(v1, slider->radius, v2, sbire->radius))
    {
        return true;
    }

    return false;
}

//Affiche le slider
void draw_slider(slider_t *slider)
{
    DrawCircle(slider->pos.x, slider->pos.y, slider->radius, slider->color);
}

//Le Slider touche un Crab, fin de partie
bool slider_hit_crab(slider_t *slider, crab_t *crabs)
{

    for (int i = 0; i < 3; i++)
    {

        if (collision(slider, &crabs[i]))
        {
            delete_slider(slider);
            delete_crabs(crabs);

            return true;
        }
    }

    return false;
}

//Si le Slider touche un Crab retourne vrai, sinon faux
bool collision(slider_t *slider, crab_t *crab)
{

    Vector2 v1 = (Vector2){(float)slider->pos.x, (float)slider->pos.y};
    Vector2 v2 = (Vector2){(float)crab->pos.x, (float)crab->pos.y};

    if (CheckCollisionCircles(v1, slider->radius, v2, crab->radius))
    {
        return true;
    }

    return false;
}

//Supprime le slider en cas de contact avec les Crabs
void delete_slider(slider_t *slider)
{
    free(slider);
}
