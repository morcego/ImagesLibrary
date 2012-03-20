#pragma once
#include <iostream>
#include <fstream>

#include "imagecontainer.h"

using namespace std;
class ImageReader: public ImageContainer
{
public:
    ImageReader(){};
    
    virtual void readHeader()= 0;
    virtual pRGBQUDS getData()= 0;

    int getWidth() const{return width;}
    int getHeight() const{return height;}

    float getFileSize()const{return fileSize / (1024*1024);}


    virtual void setWidth(int) = 0;
    virtual void setHeight(int) = 0;

    ~ImageReader(void);

protected:
    ifstream inputFile;
};

