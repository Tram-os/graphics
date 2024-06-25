#ifndef UTILITY_H
#define UTILITY_H

/**
 * Class defines Point2D object
 */
class Point2D
{
public:

	float x; // x-value of Point2D
	float y; // y-value of Point2D

	/**
	 * Constructor
	 */
	Point2D(float x, float y);
};

/**
 * Defines a ColorRGBA object, which has a red, green, blue, and alpha value.
 */
class ColorRGBA
{
public:

	float r; // red value
	float g; // green value
	float b; // blue value
	float a; // alpha value

	/**
	 * Constructor
	 */
	ColorRGBA(float r, float g, float b, float a);
};

#endif