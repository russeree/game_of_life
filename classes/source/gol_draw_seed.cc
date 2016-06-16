/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A popup window to draw a game of life seed
 ***/

#include "gol_draw_seed.h"

#include <iostream>

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

