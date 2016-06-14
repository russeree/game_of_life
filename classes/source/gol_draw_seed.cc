/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A popup window to draw a game of life seed
 ***/

#include "gol_draw_seed.h"

#include <iostream>

GolDrawSeed::GolDrawSeed(){
    this -> status = (int)enumGolDrawSeedStatus::initialized;
}
