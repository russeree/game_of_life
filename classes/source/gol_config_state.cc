/***
 * Creator: Reese Russell
 * Class: Game of Life Config State
 * Desc: A current configuration State
 ***/
#include "gol_config_state.h"

#include <iostream>

GolConfigState::GolConfigState()
{
    this -> debug = 0;
    this -> status = (int)enumGolConfigStateStatus::success;
}

GolConfigState::GolConfigState(int debug_lvl)
{
    this -> debug = debug_lvl;
    this -> status = (int)enumGolConfigStateStatus::success;
}
GolConfigState::~GolConfigState()
{
}

/*** LOGS ***
 * 2016 June 12 : Initial Creation of Class
 *** LOGS ***/
