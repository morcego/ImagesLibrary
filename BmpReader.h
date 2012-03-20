#pragma once
#include "ImageReader.h"
#include "Readerr.h"

class BmpReader : public ImageReader
{
public:
    BmpReader(){}
    BmpReader(string filename)
    {
        inputFile.open(filename);
    }

    virtual void readHeader();
    virtual pRGBQUDS getData();

    void readBitmapHeader();

    virtual void setWidth(int){};
    virtual void setHeight(int){};

    ~BmpReader();
public:
    unsigned int offsetToImage;

private:
    const static int bitmapHeadSize = 0x28;
    const static short planesCount = 0x1;
    bool isRGB;
    unsigned int compressionType;
    unsigned int compressedImageSize;
    unsigned int usedColorCount;
    unsigned int importantColorCount;
};

