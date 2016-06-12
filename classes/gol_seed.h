#ifndef GAME_OF_LIFE_SEED
#define GANE_OF_LIFE_SEED

/***
 * Creator: Reese Russell
 * Class: GameOfLifeSeed
 * Desc: A game of life Seed State
 ***/

#include <string>
#include <vector>

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>

class GameOfLifeSeed : public Gtk::Window
{
    public:
        int status;
    // Class Specific Types
    protected:
        class GolMenuItem
        {
            public:
                unsigned int id;
                std::vector<unsigned int> children;
                std::string menu_text;
                Gtk::MenuItem *menu;
                GolMenuItem();
                virtual ~GolMenuItem();
                // Overloading Operators (+)
                GolMenuItem operator+(const unsigned int child_id);
        };
    // Constructors
    public:
        GameOfLifeSeed();
        virtual ~GameOfLifeSeed();
    // Signals and Events
    protected:
        bool load_from_file;
        bool load_from_grid;
        unsigned int grid_size_x, grid_size_y;
    // Buttons and Signals
    protected:
        void on_okay_btn_clicked();
        void on_cancel_btn_clicked();
        Gtk::Button okay_btn;
        Gtk::Button cancel_btn;
    // Menu Bar
    protected:
        Gtk::MenuBar menu_bar;
        std::string menu_text;
        std::vector<GolMenuItem> menu_items;
        std::vector<unsigned int> menu_children;
        GolMenuItem *temp_menu;
        int add_temp_menu_child(unsigned int child_id);
        int set_temp_menu_id(unsigned int id);
        int set_temp_menu_text(std::string menu_text);
        int add_menu(GolMenuItem &menu_item);
        int add_menu(unsigned int id, std::vector<unsigned int> &children, std::string menu_text);
    // Layout Containers
    protected:
        Gtk::VBox main_layout;
        Gtk::Box commit_btn_container;
};
#endif
