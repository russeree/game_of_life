/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A class to open a window and allow a user
 *     ~ to draw a seed.
 ***/

#ifndef GAME_OF_LIFE_SEED_DRAW
#define GAME_OF_LIFE_SEED_DRAW
// Gtkmm Includes
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
// Gdkmm Includes
#include <gdkmm/pixbuf.h>
#include <gdkmm/general.h>
// Glibmm Includes
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
    int x = 1337;
    // Game of life Drawing Seed Class
    protected:
    class SeedDrawingArea : public Gtk::DrawingArea
    {
        public:
            GolDrawSeed *gds_p;
            SeedDrawingArea(GolDrawSeed *gol_draw_seed);
            virtual ~SeedDrawingArea();
            bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    };
    public:
        GolDrawSeed();
        virtual ~GolDrawSeed();
    // Class Parametes
    protected:
        int status;
        int debug;
        unsigned int window_size_x;
        unsigned int window_size_y;
    // Magiks
        Glib::ustring window_title = "Game of Life Seed Drawing Editor";
    // Window Layout
    protected:
        Gtk::VBox *main_layout;
        Gtk::Box *drawing_container;
        Gtk::Box *exit_methds_container;
    // Seed Visualization
        int seed_img_height;
        int seed_img_width;
        int seed_img_channels;
        guint8 *seed_img_raw_buf;
        Glib::RefPtr<Gdk::Pixbuf> seed_img;
    // Game of life Drawing Seed Class
        SeedDrawingArea *visual_seed_dw;
    // Debug Functions
        guint8 *debug_image_gen (unsigned int x_size, unsigned int y_size, unsigned int channels);
};
#endif
