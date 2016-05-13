//
// Created by Lokotochek on 13.05.16.
//

#ifndef RAYTRACER_TGA_H
#define RAYTRACER_TGA_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::cout;

//data structures
struct Colour {
	unsigned char r,g,b,a;
};

class TGAImage {

public:

	//Constructor
	TGAImage();

	//Overridden Constructor
	TGAImage(short width, short height);

	//Set all pixels at once
	void setAllPixels(Colour *pixels);

	//set individual pixels
	void setPixel(Colour inputcolor, int xposition, int yposition);

	void WriteImage(string filename);

//General getters and setters

	void setWidth(short width);
	void setHeight(short height);

	short getWidth();
	short getHeight();

private:

	//store the pixels
	Colour *m_pixels;

	short m_height;
	short m_width;

	//convert 2D to 1D indexing
	int convert2dto1d(int x, int y);



};


#endif //RAYTRACER_TGA_H
