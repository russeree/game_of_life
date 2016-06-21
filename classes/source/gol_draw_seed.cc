/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A popup window to draw a game of life seed
 ***/

#include "gol_draw_seed.h"

#include <iostream>
#include <random>

// Game of Life Seed Drawing  Constructor
GolDrawSeed::GolDrawSeed() : grid_x_size_adj_digits(Gtk::Adjustment::create(50.0, 0.0, 100.0, 5.0))
{
    // Setup Window Size
    this -> window_size_x = 512;
    this -> window_size_y = 512;
    // Set the default class states
    this -> status = (int)enumGolDrawSeedStatus::initialized;
    this -> debug = (int)enumGolDrawSeedDebug::verbose;
    // Setup the seed image size
    this -> seed_img_height = 512;
    this -> seed_img_width = 512;
    this -> seed_img_channels = 3;
    // Consturct the seed Image
    this -> seed_img_raw_buf = debug_image_gen(seed_img_width, seed_img_height, seed_img_channels);
    this -> seed_img = Gdk::Pixbuf::create_from_data (
            seed_img_raw_buf,
            Gdk::COLORSPACE_RGB,
            false,
            8,
            seed_img_width,
            seed_img_height,
            3
        );
    // Construct the drawing window.
    this -> grid_x_size = new Gtk::HScale (grid_x_size_adj_digits);
    this -> grid_x_size_adj_digits -> signal_value_changed().connect(sigc::mem_fun(*this, &GolDrawSeed::on_grid_x_size_change));
    this -> visual_seed_dw = new SeedDrawingArea (this);
    this -> main_layout = new Gtk::VBox;
    this -> exit_methds_container = new Gtk::Box;
    this -> drawing_container = new Gtk::Box;
    // Set Window Properties
    this -> set_title (this -> window_title);
    this -> set_border_width(10);
    this -> set_default_size(window_size_x, window_size_y);
    // Add the Visual Seed Drawing Widow to the Container
    this -> drawing_container -> pack_start (*visual_seed_dw);
    this -> drawing_container -> pack_start (*grid_x_size);
    this -> add (*drawing_container);
    // Show the widgets
    this -> show_all();
}

// Game of Life Seed Drawign Deconstructor
GolDrawSeed::~GolDrawSeed()
{
    delete this -> grid_x_size;
    delete this -> exit_methds_container;
    delete this -> main_layout;
    delete this -> visual_seed_dw;
    delete this -> seed_img_raw_buf;
}

// Generates Debug Image (Consists of Random Pixels)
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

// Drawing Area Draw Function (Overide in Inner Seed Drawing Area Class)
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

// Singal Handler for GTKMM Grid X Size Slider
void GolDrawSeed::on_grid_x_size_change()
{
    this -> current_grid_x_size = this -> grid_x_size -> get_value();
    if (this -> debug = (int)enumGolDrawSeedDebug::verbose)
    {
        std::cout << "The Slider Value is " << this -> current_grid_x_size << '\n';
    }
    this -> status = enumGolDrawSeedStatus::success;
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


