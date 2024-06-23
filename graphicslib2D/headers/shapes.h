#ifndef SHAPES_H
#define SHAPES_H

#include "utility.h"

/**
 * Implementation of shapes object that will render basic shapes on screen using the shapes shader program. 
 */
class Shapes
{
public:

    unsigned int ID; // The shapes programs id
    unsigned int posLocation; // The locationo of the pos input into the vertex shader
    unsigned int colorLocation; // The location of the inputColor uniform

    /**
     * Creates a shapes program object that will be used to render shapes on screen.
     * 
     * @return None
     */
    Shapes();

    /**
     * Draws a rectangle on screen given the min and max points, along with the color.
     * 
     * @param[in] min const ref to the bottom left point of rectangle
     * @param[in] max const ref to the top right point of the rectangle
     * @param[in] color const ref to ColorRGBA which sets the color of the rectangle
     * 
     * @return none
     */
    void drawRect(const Point2D &min, const Point2D &max, const ColorRGBA &color) const;

    /**
     * Draws and fills a rectangle on screen given the min and max points, along with the color.
     *
     * @param[in] min const ref to the bottom left point of rectangle
     * @param[in] max const ref to the top right point of the rectangle
     * @param[in] color const ref to ColorRGBA which sets the color of the rectangle
     *
     * @return none
     */
    void fillRect(const Point2D& min, const Point2D& max, const ColorRGBA& color) const;
};


#endif