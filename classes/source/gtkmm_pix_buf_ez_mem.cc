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

// This function is not memory safe if you exceed the boundries of the array please use safely
void GtkmmPixBufEzMem::write_pix(guint8 *image, guint8 *pix_data, unsigned int channels, unsigned int loc_x, unsigned int loc_y, unsigned int rowstride, unsigned int array_size)
{
    guint8 *pixel_arr_loc = image + (loc_y * rowstride) + (loc_x * channels);
    for(unsigned int i = 0; i < channels; i++)
    {
        pixel_arr_loc[i] = pix_data[i];
    }
}

// This function is not memory safe; Take in R,G and B values and pushes them to an array
void GtkmmPixBufEzMem::rgb_to_pix_data(guint8 *pixdata, guint8 red, guint8 green, guint8 blue)
{
    pixdata[0] = red;
    pixdata[1] = blue;
    pixdata[2] = green;
}

// This function is not memory safe; Take in R,G and B values and pushes them to an array
void GtkmmPixBufEzMem::rgba_to_pix_data(guint8 *pixdata, guint8 red, guint8 green, guint8 blue, guint8 alpha)
{
    pixdata[0] = red;
    pixdata[1] = blue;
    pixdata[2] = green;
    pixdata[3] = alpha;
}
