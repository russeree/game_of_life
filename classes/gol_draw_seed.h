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
#include <gtkmm/menuitem.h>

namespace enumGolDrawSeedStatus{
    enum golDrawSeedStatus{
        success,
        failure,
        initialized
    };
}
class GolDrawSeed : public Gtk::Window
{
    public:
        GolDrawSeed();
        virtual ~GolDrawSeed();
    protected:
        int status;
};
#endif
