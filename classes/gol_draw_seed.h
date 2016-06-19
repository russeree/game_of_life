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
#include <gdkmm/pixbuf.h>
#include <glibmm/refptr.h>

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

// Main Class: Game of Life Drawing seed.
class GolDrawSeed : public Gtk::Window
{
    public:
        GolDrawSeed();
        virtual ~GolDrawSeed();
    // Class Configuration
    protected:
        int status;
        int debug;
    // Magiks
    Glib::ustring window_title = "Game of Life Seed Drawing Editor";
    // Window Layout
    protected:
        Gtk::VBox *main_layout;
        Gtk::Box *exit_methds_container;
    // Drawing Utilities
        guint8 *seed_img_raw_buf;
        Glib::RefPtr<Gdk::Pixbuf> seed_img;
        Gtk::DrawingArea *visual_seed_dw;
    // Debug Functions
        guint8 *debug_image_gen (unsigned int x_size, unsigned int y_size, int channels);
};
#endif
