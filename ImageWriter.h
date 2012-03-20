#pragma once

#include "imagecontainer.h"

using namespace std;

class ImageWriter : public ImageContainer
{
public:
    ImageWriter(void){}
    ~ImageWriter(void)
    {
        if(file.is_open())
            file.close();
    }

    virtual void wrtieHeader() = 0;
    virtual void writeData(const ImageContainer::pRGBQUDS& rgbData) = 0;

};

