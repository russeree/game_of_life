/***
 * Creator: Reese Russell
 * Class: GtkmmPixbufEzMem
 * Desc: Ez and Fast Pixel Drawing Methods for GTKMM::Pixbuf
 ***/

#ifndef GTKMM_PIXBUF_EZ_MEM
#define GTKMM_PIXBUF_EZ_MEM

// Include the Pixbuf Type to Gain Access to the GTKMM Pixbuf types

#include <gdkmm/pixbuf.h>
#include <iostream>

class GtkmmPixBufEzMem
{
    // Con/de(structors)
    public:
        GtkmmPixBufEzMem();
        virtual ~GtkmmPixBufEzMem();
    public:
        //Static  Write a pixel to an 1d array of guint8: No rowstep handler yet
        static void write_pix(guint8 *image, guint8 *pix_data, unsigned int channels, unsigned int loc_x, unsigned int loc_y, unsigned int rowstride, unsigned int array_size);
};
#endif
