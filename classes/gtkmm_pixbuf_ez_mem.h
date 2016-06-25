/***
 * Creator: Reese Russell
 * Class: GtkmmPixbufEzMem
 * Desc: Ez and Fast Pixel Drawing Methods for GTKMM::Pixbuf
 ***/

#ifndef GTKMM_PIXBUF_EZ_MEM
#define GTKMM_PIXBUF_EZ_MEM

// Include the Pixbuf Type to Gain Access to the GTKMM Pixbuf types

#include <gdkmm/pixbuf.h>

class GtkmmPixbufEzMem
{
    // Con/de(structors)
    public:
        GtkmmPixbufEzMem();
        virtual ~GtkmmPixbufEzMem();
    public:
        //Static  Write a pixel to an 1d array of guint8: No rowstep handler yet
        static int write_3_chnl_pix(guint8 *image, unsigned int loc_x, unsigned int loc_y, unsigned int array_size, guint8 red, guint8 green, guint8 blue);
};
#endif
