/***
 * Creator: Reese Russell
 * Class: GolDrawSeed
 * Desc: A popup window to draw a game of life seed
 ***/

#include "gol_draw_seed.h"

// Game of Life Seed Drawing Construction
GolDrawSeed::GolDrawSeed() :
    grid_x_size_adj_digits(Gtk::Adjustment::create(50.0, 0.0, 100.0, 5.0, 20.0)),
    grid_y_size_adj_digits(Gtk::Adjustment::create(50.0, 0.0, 100.0, 5.0, 20.0))
{
    this -> grid_line_width = 1;
    this -> slider_coeff = 1;
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
    this -> seed_img = Gdk::Pixbuf::create_from_data (
            seed_img_raw_buf,
            Gdk::COLORSPACE_RGB,
            false,
            8,
            seed_img_width,
            seed_img_height,
            seed_img_width
        );
    // Construct the Window Sliders
    this -> grid_x_size = new Gtk::HScale (grid_x_size_adj_digits);
    this -> grid_y_size = new Gtk::HScale (grid_y_size_adj_digits);
    this -> grid_x_size -> set_digits(grid_precision_decimals);
    this -> grid_y_size -> set_digits(grid_precision_decimals);
    this -> grid_x_size_adj_digits -> signal_value_changed().connect(sigc::mem_fun(*this, &GolDrawSeed::on_grid_x_size_change));
    this -> grid_y_size_adj_digits -> signal_value_changed().connect(sigc::mem_fun(*this, &GolDrawSeed::on_grid_y_size_change));
    // Construct the Drawing Window
    this -> visual_seed_dw = new SeedDrawingArea (this);
    // Generate the Window Elements
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
    this -> drawing_container -> pack_start (*grid_y_size);
    this -> add (*drawing_container);
    // Show the widgets
    this -> show_all();
}

// Game of Life Seed Drawign Deconstructor
GolDrawSeed::~GolDrawSeed()
{
    if (this -> debug == enumGolDrawSeedDebug::verbose)
    {
        std::cout << "Deconstructing Class -> GolDrawSeed";
    }
    // Any time 'new' is used; !!!MAKE SURE TO CLEAN UP!!!
    delete this -> grid_x_size;
    delete this -> grid_y_size;
    delete this -> drawing_container;
    delete this -> exit_methds_container;
    delete this -> main_layout;
    delete this -> visual_seed_dw;
    delete this -> seed_img_raw_buf;
}
// Generates a grid for users to visualize the game of life seed
guint8 *GolDrawSeed::seed_grid_image_gen (unsigned int x_size, unsigned int y_size, unsigned int channels)
{
    // Get the size of the divisons by taking the width and dividing it by a scale and the current desired grid size)
    float denominator = ((current_grid_x_size) * (this -> slider_coeff));
    if (denominator <= 0)
    {
         denominator = 1;
    }
    unsigned int divisions = floor(x_size / denominator);
    unsigned int array_size = (x_size * y_size * channels);
    guint8 *pix_data = new guint8[channels];
    guint8 *image = new guint8[array_size];
    // Determine if a pixel needs to be drawn
    for (int y = 0; y < y_size; y++){
        for(int x = 0; x < x_size; x++)
        {
            if((x % divisions == 0) || (y % divisions == 0)){
                GtkmmPixBufEzMem::rgb_to_pix_data(pix_data, 255, 255, 255);
            }
            else
            {
                GtkmmPixBufEzMem::rgb_to_pix_data(pix_data, 0, 0, 0);
            }
            GtkmmPixBufEzMem::write_pix(image, pix_data, channels, x, y, x_size * channels, array_size);
        }
    }
    // Generate the Grid based on the scale of the drawing area
    this -> status = enumGolDrawSeedStatus::success;
    return image;
}

// Generates Debug Image (Consists of Random Pixels)
guint8 *GolDrawSeed::debug_image_gen (unsigned int x_size, unsigned int y_size, unsigned int channels)
{
    // A section of memory is alocated here make sure to delete at some point
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
    this -> status = enumGolDrawSeedStatus::success;

    return image;
}

// Drawing Area Draw Function (Overide in Inner Seed Drawing Area Class)
bool GolDrawSeed::SeedDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    if (!gds_p -> seed_img)
    {
        this -> status = (int)enumGolDrawSeedStatus::failure;
        return false;
    }
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    // Draw the image in the middle of the drawing area
    Gdk::Cairo::set_source_pixbuf(cr, gds_p -> seed_img, 0, 0);
    cr -> paint();
    this -> status = (int)enumGolDrawSeedStatus::success;

    return true;
}

// Chaing the Grid X Size Handler: This should be fixed later to take in a point of a Adjustment and a var
// and store the result
void GolDrawSeed::on_grid_x_size_change()
{
    this -> current_grid_x_size = this -> grid_x_size -> get_value();
    /* FIX ME
    if (this -> debug = (int)enumGolDrawSeedDebug::verbose)
    {
        std::cout << "The X Size Slider Value is " << this -> current_grid_x_size << '\n';
    }
    */
    this -> seed_img_raw_buf = seed_grid_image_gen(seed_img_width, seed_img_height, seed_img_channels);
    this -> seed_img = Gdk::Pixbuf::create_from_data (
            seed_img_raw_buf,
            Gdk::COLORSPACE_RGB,
            false,
            8,
            seed_img_width,
            seed_img_height,
            seed_img_width * seed_img_channels
        );
    this ->  visual_seed_dw -> queue_draw();
    this -> status = (int)enumGolDrawSeedStatus::success;
}

// Store the  Y Size Varible of the slider
void GolDrawSeed::on_grid_y_size_change()
{
    this -> current_grid_y_size = this -> grid_y_size -> get_value();
    if (this -> debug = (int)enumGolDrawSeedDebug::verbose)
    {
        std::cout << "The Y Size Slider Value is " << this -> current_grid_y_size << '\n';
    }
    this -> status = (int)enumGolDrawSeedStatus::success;
}

// Seed Drawing Area Constructor
GolDrawSeed::SeedDrawingArea::SeedDrawingArea(GolDrawSeed *gol_draw_seed)
{
    // Use 'this' as an arguement to access parent class: DO NOT USE DELETE!;
    this -> gds_p = gol_draw_seed;
}
// Seed Drawing Area Deconstuctor
GolDrawSeed::SeedDrawingArea::~SeedDrawingArea()
{
}
