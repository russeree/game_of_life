/***
 * Creator: Reese Russell
 * Class: GtkmmPixbufEzMem
 * Desc: Ez and Fast pixel writing to a Gtkmm::Pixbuf
 ***/

#include "gtkmm_pixbuf_ez_mem.h"

// Constructor
GtkmmPixbufEzMem::GtkmmPixbufEzMem()
{
}

// Deconsturctor
GtkmmPixbufEzMem::~GtkmmPixbufEzMem()
{
}

void GtkmmPixbufEzMem::write_pix(guint8 *image, guint8 *pix_data, unsigned int channels, unsigned int loc_x, unsigned int loc_y, unsigned int rowstride, unsigned int array_size)
{
    guint8 *pixel_arr_loc;
    pixel_arr_loc = image + (loc_y * rowstride) + (loc_x * channels);
    try
    {
        if(pixel_arr_loc > (image + array_size))
        {
            throw 0;
        }
    }
    catch(int error_id)
    {
        std::cout << "Pixel location is out of image memory boundires.\n";
    }
}
