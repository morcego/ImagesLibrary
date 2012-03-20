#include "StdAfx.h"
#include "BmpReader.h"

#define ToDWord(p) (*((unsigned int *)(p)))
#define ToWord(p) (*((unsigned short *)(p)))

using namespace std;
void BmpReader::readHeader()
{
    unsigned char* bytes = new unsigned char();
    if (inputFile.get() !=  0x42)throw Readerr();
    if (inputFile.get() != 0x4D)throw Readerr();

    inputFile.get((char*)bytes, 5);
    fileSize = ToDWord(bytes);

    inputFile.get((char*)bytes, 5);  //4 bytes is reserved

    inputFile.get((char*)bytes, 5);
    offsetToImage = ToDWord(bytes);

    readBitmapHeader();
}

void BmpReader::readBitmapHeader()
{
    unsigned char* bytes = new unsigned char();
    inputFile.get((char*)bytes, 5);
    unsigned int value = ToDWord(bytes);

    if (value != bitmapHeadSize) throw Readerr();

    inputFile.get((char*)bytes, 5);
    width = ToDWord(bytes);

    inputFile.get((char*)bytes, 5);
    height = ToDWord(bytes);

    inputFile.get((char*)bytes, 3);
    if(planesCount != ToWord(bytes))throw Readerr();

    inputFile.get((char*)bytes, 3);
    bitsPerPixel = ToWord(bytes);

    inputFile.get((char*)bytes, 5);
    compressionType = ToDWord(bytes);

    inputFile.get((char*)bytes, 5);
    compressedImageSize = ToDWord(bytes);

    inputFile.get((char*)bytes, 5);
    dpiX = ToDWord(bytes) / 39.3700787;
    
    inputFile.get((char*)bytes, 5);
    dpiY = ToDWord(bytes) / 39.3700787;
    
    inputFile.get((char*)bytes, 5);
    usedColorCount = ToDWord(bytes);

    inputFile.get((char*)bytes, 5);
    importantColorCount = ToDWord(bytes);
}

ImageContainer::pRGBQUDS BmpReader::getData()
{
    inputFile.seekg(offsetToImage);
    int imageLen = getWidth()*getHeight();
    rgbQuads = new RGBQUDS[imageLen];

    if(bitsPerPixel == TRUECOLOR)
    {        
        for(int i = 0; i < imageLen; i+=4)
        {
            rgbQuads[i].b = inputFile.get();
            rgbQuads[i].g = inputFile.get();
            rgbQuads[i].r = inputFile.get();
        }
    }
    return rgbQuads;
}

BmpReader::~BmpReader(void)
{
    delete [] rgbQuads;
}
