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
    protected:
        int status;
        int debug;
    protected:
        Gtk::Vbox main_layout;
        Gtk::Box release_btn_container;
};
#endif
