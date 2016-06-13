/***
 * Creator: Reese Russell
 * Class: GolSeed
 * Desc: A game of life Seed State
 ***/

#ifndef GAME_OF_LIFE_SEED
#define GAME_OF_LIFE_SEED

#include <string>
#include <vector>

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>

#include "gol_config_state.h"

class GolSeed : public Gtk::Window
{
    public:
        int debug;
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
    // Constructors and Class Specific functions
    public:
        GolSeed();
        virtual ~GolSeed();
        int enable_debug(void);
        int enable_debug(int level);
        int disable_debug(void);
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
        std::vector<GolMenuItem*> menu_items;
        std::vector<unsigned int> menu_children;
        GolMenuItem *temp_menu;
        int add_temp_menu_child(unsigned int child_id);
        int set_temp_menu_id(unsigned int id);
        int set_temp_menu_text(std::string menu_text);
        int add_menu(GolMenuItem *menu_item);
        int add_menu(unsigned int id, std::vector<unsigned int> children, std::string menu_text);
    // Layout Containers
    protected:
        Gtk::VBox main_layout;
        Gtk::Box commit_btn_container;
    // Internals
    GolConfigState *state;
};
#endif
