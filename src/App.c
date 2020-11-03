#include "../include/App.h"
#include "../include/Slider.h"
#include "../include/Sbire.h"
#include "../include/Crab.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../include/define.h"

void init_Window()
{

    InitWindow(WINDOW_W, WINDOW_H, "Bwallows");
}

void Launching()
{
    init_Window();
    SetTargetFPS(60);

    bool gameOver = false;

    slider_t *slider = calloc(1, sizeof(slider_t));
    init_slider(slider);

    int *score = &slider->score; 

    srand(time(NULL));
    int sbires_nb = 200;

    sbire_t *sbires = calloc(sbires_nb, sizeof(sbire_t));
    crab_t  *crabs  = calloc(3, sizeof(crab_t));

    init_sbires(sbires, sbires_nb);
    init_crabs(crabs);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground((Color){147, 177, 242, 255});

        DrawFPS(10, 10);
       // DrawText()

        draw_slider(slider);
        draw_crabs(crabs);

        //chase_crabs();

        press_key(slider);

        eats_sbire(slider, sbires, sbires_nb);

        display_game_score(slider);

        draw_sbires(sbires, sbires_nb);
        move_sbires(sbires, sbires_nb);
        move_crabs(crabs);
        eat_crabs(crabs, sbires, sbires_nb);

        gameOver = slider_hit_crab(slider, crabs);

        if(gameOver == true) break;

        EndDrawing();
    }

    move_sbires_end(sbires, sbires_nb, score);
    
    free(sbires);
}