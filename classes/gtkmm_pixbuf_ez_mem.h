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
/*
 * This class constis of functions that can be called staticly from other classes.
 * the primary purpose of this class is to clean up code and allow for fast(unsafe)
 * and slow safe memory operations that modify guint8 buffers that will be converted
 * wrapped with a Gdk:Pixbuf. As of right now these functions are prelimanry and
 * offer untest ed functionality
 */

class GtkmmPixBufEzMem
{
    // Con/de(structors)
    public:
        GtkmmPixBufEzMem();
        virtual ~GtkmmPixBufEzMem();
    public:
        //Static  Write a pixel to an 1d array of guint8: No rowstep handler yet
        static void write_pix(guint8 *image, guint8 *pix_data, unsigned int channels, unsigned int loc_x, unsigned int loc_y, unsigned int rowstride, unsigned int array_size);
        static void rgb_to_pix_data(guint8 *pixdata, guint8 red, guint8 green, guint8 blue);
        static void rgba_to_pix_data(guint8 *pixdata, guint8 red, guint8 green, guint8 blue, guint8 alpha);
};
#endif
