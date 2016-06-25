/***
 * Creator: Reese Russell
 * Class: GtkmmPixbufEzMem
 * Desc: Ez and Fast pixel writing to a Gtkmm::Pixbuf
 ***/

#include "gtkmm_pixbuf_ez_mem.h"

// Constructor
GtkmmPixBufEzMem::GtkmmPixBufEzMem()
{
}

// Deconsturctor
GtkmmPixBufEzMem::~GtkmmPixBufEzMem()
{
}

void GtkmmPixBufEzMem::write_pix(guint8 *image, guint8 *pix_data, unsigned int channels, unsigned int loc_x, unsigned int loc_y, unsigned int rowstride, unsigned int array_size)
{
    guint8 *pixel_arr_loc = image + (loc_y * rowstride) + (loc_x * channels);
    // std::cout << "The Location of the Pixel Buffer is " << &pixel_arr_loc << '\n';
    // std::cout << "The max size of the array is "<< &image + array_size << '\n';
    // Now write the pixel locations
    for(unsigned int i = 0; i < channels; i++)
    {
        pixel_arr_loc[i] = pix_data[i];
    }
}
