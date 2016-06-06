#include "gol_seed.h"

#include <iostream>
#include <string>
#include <vector>

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
    temp_menu = new GolMenuItem;
    // Window Propteries
    set_border_width(10);
    set_title("Game of Life Seed Generator");
    // Add the Button Contailer
    add(main_layout);
    // Button Signals
    okay_btn.signal_clicked().connect(sigc::mem_fun(*this, &GameOfLifeSeed::on_okay_btn_clicked));
    cancel_btn.signal_clicked().connect(sigc::mem_fun(*this, &GameOfLifeSeed::on_cancel_btn_clicked));
    // Pack buttons in the container
    main_layout.pack_start(menu_bar, Gtk::PACK_SHRINK);
    main_layout.pack_start(commit_btn_container);
    commit_btn_container.pack_start(okay_btn);
    commit_btn_container.pack_start(cancel_btn);
    // Display all the items
    show_all();
}

GameOfLifeSeed::GolMenuItem::GolMenuItem()
{
    this -> menu = new Gtk::MenuItem;
}

GameOfLifeSeed::~GameOfLifeSeed()
{
    delete this -> temp_menu;
}

GameOfLifeSeed::GolMenuItem::~GolMenuItem()
{
    delete this -> menu;
}

void GameOfLifeSeed::on_okay_btn_clicked()
{
    std::cout << "Settings Saved.";
}

void GameOfLifeSeed::on_cancel_btn_clicked()
{
    std::cout << "Settings Unsaved.";
    close();
}

int GameOfLifeSeed::add_temp_menu_child(unsigned int child_id){
    this -> temp_menu -> children.push_back(child_id);
    return 0;
}
int GameOfLifeSeed::set_temp_menu_id(unsigned int id)
{
    this -> temp_menu -> id = id;
    return 0;
}

int GameOfLifeSeed::set_temp_menu_text (std::string menu_text){
    this -> temp_menu -> menu -> set_label(menu_text);
    return 0;
}

int GameOfLifeSeed::add_menu(unsigned int id, std::vector<unsigned int> &children, std::string menu_text)
{
    // Create a Menu Pack item
    GolMenuItem *temp_menu = new GolMenuItem();
    // Setup the Menu Pack
    temp_menu -> id = id;
    temp_menu -> children = children;
    temp_menu -> menu -> set_label(menu_text);
    // Now append the menu pack to the end of the Class Vector
    this -> menu_items.push_back(*temp_menu);
    //Return a success status for completeion of this function
    return 0;
}

