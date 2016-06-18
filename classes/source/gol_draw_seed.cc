/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A popup window to draw a game of life seed
 ***/

#include "gol_draw_seed.h"

#include <iostream>
#include <stdlib.h>

// Game of Life Seed Drawing  Constructor
GolDrawSeed::GolDrawSeed()
{
    // Set the default class states
    this -> status = (int)enumGolDrawSeedStatus::initialized;
    this -> debug = (int)enumGolDrawSeedDebug::none;
    // Construct the drawing window.
    this -> visual_seed_dw = new Gtk::DrawingArea;
    this -> main_layout = new Gtk::VBox;
    this -> exit_methds_container = new Gtk::Box;
    this -> set_title(this -> window_title);
    this -> add (*visual_seed_dw);
    // Show the widgets
    this -> show_all();
}

// Game of Life Seed Drawign Deconstructor
GolDrawSeed::~GolDrawSeed()
{
    delete this -> exit_methds_container;
    delete this -> main_layout;
    delete this -> visual_seed_dw;
}

guint8 *GolDrawSeed::debug_image_gen (unsigned int x_size, unsigned int y_size, int channels)
{
    unsigned int array_size = (x_size * y_size * channels);
    guint8 *image = new guint8[array_size];
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            unsigned int current_cell = ((y_size * i) + j);

        }
    }
    return image;
}

