#include "game_of_life_seed.h"
#include <iostream>
/***
 * Creator: Reese Russell
 * Class: GameOfLifeSeed
 * Desc: Game of life configuration window openiong 
 *     ~ and management of initial seed. Upon consturction a window
 *     ~ the close button destroys the window but the class varibles
 *     ~ remain in memory to be accessed by the generation algorythm
 ***/
GameOfLifeSeed::GameOfLifeSeed(): okay_btn("Okay"), cancel_btn("Cancel")
{
    set_border_width(10);
    okay_btn.signal_clicked().connect(sigc::mem_fun(*this, &GameOfLifeSeed::on_okay_btn_clicked));
    cancel_btn.signal_clicked().connect(sigc::mem_fun(*this, &GameOfLifeSeed::on_cancel_btn_clicked));    
}

GameOfLifeSeed::~GameOfLifeSeed()
{
}

void GameOfLifeSeed::on_okay_btn_clicked()
{
    std::cout << "Settings Saved.";
}

void GameOfLifeSeed::on_cancel_btn_clicked()
{
    std::cout << "Settings Unsaved.";
} 
