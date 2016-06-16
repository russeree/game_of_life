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

}

// Game of Life Seed Drawign Deconstructor
GolDrawSeed::~GolDrawSeed()
{
}

