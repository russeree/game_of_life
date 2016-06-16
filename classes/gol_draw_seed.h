/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A class to open a window and allow a user
 *     ~ to draw a seed.
 ***/

#ifndef GAME_OF_LIFE_SEED_DRAW
#define GAME_OF_LIFE_SEED_DRAW

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>

// Drawing Seed Status
namespace enumGolDrawSeedStatus
{
    enum golDrawSeedStatus
    {
        success,
        failure,
        initialized
    };
}

// Drawing Seed Debug Levels
namespace enumGolDrawSeedDebug
{
    enum golDrawSeedDebug
    {
        none,
        mininal,
        moderate,
        verbose
    };
}

// Main Class: Game of Life Draw Seed
class GolDrawSeed : public Gtk::Window
{
    public:
        GolDrawSeed();
        virtual ~GolDrawSeed();
    // Class Configuration
    protected:
        int status;
        int debug;
    // Window Layout
    protected:
        Gtk::VBox main_layout;
        Gtk::Box exit_methds_container;
    // Drawing Utilities
        Gtk::DrawingArea *visual_seed_dw;
};
#endif
