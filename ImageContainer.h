#pragma once

#include <iostream>
#include <fstream>

#define TRUECOLOR 24
class ImageContainer
{
protected:
    typedef struct
    {
        char r;
        char g;
        char b;
    } RGBQUDS, *pRGBQUDS;

public:
    ImageContainer(void){};

    /*int getWidth() const{return width;}
    int getHeight() const{return height;}

    float getFileSize()const{return fileSize / (1024*1024);}*/

    virtual ~ImageContainer(void){};

protected:
    unsigned int height;
    unsigned int width;
    unsigned int dpiX;
    unsigned int dpiY;
    unsigned int bitsPerPixel;
    float fileSize;

    pRGBQUDS rgbQuads;

    std::fstream file;
};

