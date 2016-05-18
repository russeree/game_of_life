#ifndef GAME_OF_LIFE_SEED
#define GANE_OF_LIFE_SEED
/***
 * Creator: Reese Russell
 * Class: GameOfLifeSeed
 * Desc: A game of life Seed State
 ***/

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class GameOfLifeSeed : public Gtk::Window
{
    public:
        GameOfLifeSeed();
        int GameOfLifeSeedConfigPrompt();
        virtual ~GameOfLifeSeed();

    protected:
        bool load_from_file;
        bool load_from_grid; 
        unsigned int grid_size_x, grid_size_y;
        unsigned int status;
    protected:
        void on_okay_btn_clicked();
        void on_cancel_btn_clicked();
        Gtk::Button okay_btn, cancel_btn;
        Gtk::Box commit_btn_container;
};
#endif
