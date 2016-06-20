/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A popup window to draw a game of life seed
 ***/

#include "gol_draw_seed.h"

#include <iostream>
#include <random>

// Game of Life Seed Drawing  Constructor
GolDrawSeed::GolDrawSeed()
{
    // Setup Window Size
    this -> window_size_x = 512;
    this -> window_size_y = 512;
    // Set the default class states
    this -> status = (int)enumGolDrawSeedStatus::initialized;
    this -> debug = (int)enumGolDrawSeedDebug::none;
    // Setup the seed image size
    this -> seed_img_height = 512;
    this -> seed_img_width = 512;
    this -> seed_img_channels = 3;
    // Consturct the seed Image
    this -> seed_img_raw_buf = debug_image_gen(seed_img_width, seed_img_height, seed_img_channels);
    this -> seed_img = Gdk::Pixbuf::create_from_data
        (
            seed_img_raw_buf,
            Gdk::COLORSPACE_RGB,
            false,
            8,
            seed_img_width,
            seed_img_height,
            seed_img_width
        );
    // Construct the drawing window.
    this -> visual_seed_dw = new SeedDrawingArea(this);
    this -> main_layout = new Gtk::VBox;
    this -> exit_methds_container = new Gtk::Box;
    this -> drawing_container = new Gtk::Box;
    this -> set_title (this -> window_title);
    this -> set_default_size(window_size_x, window_size_y);
    this -> add (*visual_seed_dw);
    // Show the widgets
    this -> show_all();
}

// Game of Life Seed Drawign Deconstructor
GolDrawSeed::~GolDrawSeed()
{
    delete this -> exit_methds_container;
    delete this -> main_layout;
    delete this -> visual_seed_dw;
    delete this -> seed_img_raw_buf;
}

guint8 *GolDrawSeed::debug_image_gen (unsigned int x_size, unsigned int y_size, unsigned int channels)
{
    unsigned int array_size = (x_size * y_size * channels);
    guint8 *image = new guint8[array_size];
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            for (int k = 0; k < channels; k++)
            {
                unsigned int current_cell = ((x_size * i) + (channels * j) + k);
                image[current_cell] = rand();
            }

        }
    }

    return image;
}

bool GolDrawSeed::SeedDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    if (!gds_p -> seed_img)
    {
        return false;
    }
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    // Draw the image in the middle of the drawing area
    Gdk::Cairo::set_source_pixbuf(cr, gds_p -> seed_img, 0, 0);
    cr -> paint();

    return true;
}

// Seed Drawing Area Constructor
GolDrawSeed::SeedDrawingArea::SeedDrawingArea(GolDrawSeed *gol_draw_seed)
{
    // Use 'this' as an arguement to access parent class;
    this -> gds_p = gol_draw_seed;
}
// Seed Drawing Area Deconstuctor
GolDrawSeed::SeedDrawingArea::~SeedDrawingArea()
{
}


