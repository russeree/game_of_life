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
    // Set the default class states
    this -> status = (int)enumGolDrawSeedStatus::initialized;
    this -> debug = (int)enumGolDrawSeedDebug::none;
    // Setup the seed image size
    this -> seed_img_height = 512;
    this -> seed_img_width = 512;
    // Construct the drawing window.
    this -> visual_seed_dw = new Gtk::DrawingArea;
    this -> main_layout = new Gtk::VBox;
    this -> exit_methds_container = new Gtk::Box;
    this -> set_title (this -> window_title);
    this -> add (*visual_seed_dw);
    this -> seed_img_raw_buf = debug_image_gen(seed_img_width, seed_img_width, 3);
    this -> seed_img = Gdk::Pixbuf::create_from_data
        (
            seed_img_raw_buf,
            Gdk::COLORSPACE_RGB,
            false,
            8,
            seed_img_width,
            seed_img_height,
            128*3
        );
    // Show the widgets
    this -> show_all();
}

// Game of Life Seed Drawign Deconstructor
GolDrawSeed::~GolDrawSeed()
{
    delete this -> exit_methds_container;
    delete this -> main_layout;
    delete this -> visual_seed_dw;
}

guint8 *GolDrawSeed::debug_image_gen (unsigned int x_size, unsigned int y_size, int channels)
{
    unsigned int array_size = (x_size * y_size * channels);
    guint8 *image = new guint8[array_size];
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            unsigned int current_cell = ((y_size * i) + j);
            image[current_cell] = rand();
        }
    }
    return image;
}

bool GolDrawSeed::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    if (!seed_img)
    {
        return false;
    }
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    // Draw the image in the middle of the drawing area
    Gdk::Cairo::set_source_pixbuf(cr, seed_img, 128 , 128);
    cr -> paint();

    return true;
}
