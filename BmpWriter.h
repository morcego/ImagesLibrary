#pragma once
#include "imagewriter.h"
#include "Write_err.h"
#include "ImageContainer.h"

class BmpWriter : public ImageWriter
{
public:
    BmpWriter(void){};
    BmpWriter(string fileName)
    {
        file.open(fileName,std::ios::out|std::ios::binary);
        if(!file.is_open())
            throw Write_err();
    }

    virtual ~BmpWriter(void)
    {
        if(file.is_open())
            file.close();
    }


    virtual void wrtieHeader();
    virtual void writeData(const ImageContainer::pRGBQUDS& rgbData);
};

