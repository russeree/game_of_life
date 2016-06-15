/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A class to open a window and draw a seed
 ***/

#ifndef GAME_OF_LIFE_SEED_DRAW
#define GAME_OF_LIFE_SEED_DRAW

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>

namespace enumGolDrawSeedStatus
{
    enum golDrawSeedStatus
    {
        success,
        failure,
        initialized
    };
}
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
        Gtk::DrawingArea visual_seed;
};
#endif
