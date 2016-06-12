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
 *     ~ remain in memory to be accessed by the generation algorithm
 ***/

// Game of Life Seed Gen: Class Constructor
GameOfLifeSeed::GameOfLifeSeed(): okay_btn("Okay"), cancel_btn("Cancel")
{
    // Construct a temporary menu class
    temp_menu = new GolMenuItem;
    temp_menu -> id = 0;
    temp_menu -> children = {1,2,3};
    temp_menu -> menu_text = "File";
    temp_menu -> menu -> set_label(temp_menu -> menu_text);
    status = add_menu(*temp_menu);
    // Add the Meny to the menubar from the vector
    menu_bar.add(*menu_items[0].menu);
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
// Game of Life Seed Gen: Single Menu Item Class Constructor
GameOfLifeSeed::GolMenuItem::GolMenuItem()
{
    this -> menu = new Gtk::MenuItem;
}
// Game of Life Seed Gen: Class Destructor
GameOfLifeSeed::~GameOfLifeSeed()
{
    delete this -> temp_menu;
}
// Game of Life Seed Gen: Class Destructor
GameOfLifeSeed::GolMenuItem::~GolMenuItem()
{
    delete this -> menu;
}
// Game of Life Seed Gen: Okay Button Clicked Signal Function
void GameOfLifeSeed::on_okay_btn_clicked()
{
    std::cout << "Settings Saved.";
}
// Game of Life Seed Gen: Cancel Button Clicked Signal Funcyion
void GameOfLifeSeed::on_cancel_btn_clicked()
{
    std::cout << "Settings Unsaved.";
    close();
}
// Game of Life Seed Gen: Add a child to the temporary menu item class varible
int GameOfLifeSeed::add_temp_menu_child(unsigned int child_id){
    this -> temp_menu -> children.push_back(child_id);
    return 0;
}
// Game of Life Seed Gen: Set the temporary menu id
int GameOfLifeSeed::set_temp_menu_id(unsigned int id)
{
    this -> temp_menu -> id = id;
    return 0;
}
// Game of Life Seed Gen: Set the temporary menu text
int GameOfLifeSeed::set_temp_menu_text (std::string menu_text)
{
    this -> temp_menu -> menu -> set_label(menu_text);
    return 0;
}
// Game of Life Seed Gen: Publish a menu to the menu vector uing a game of life menu item
int GameOfLifeSeed::add_menu(GolMenuItem &menu_item)
{
    this -> menu_items.push_back(menu_item);
    return 0;
}
// Game of Life Seed Gen: Publish a menu item using parameters.
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

/* GoL Menu Item Functions */
// Add a menu id with the + operator
GameOfLifeSeed::GolMenuItem GameOfLifeSeed::GolMenuItem::operator+(const unsigned int child_id)
{
    this -> children.push_back(child_id);
    return *this;
}

/*** LOGS ***
 * June 6 2016: Added many class functions and added minimal ad-hoc polymorphism.
 *** LOGS ***/
