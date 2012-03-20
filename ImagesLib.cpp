// ImagesLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "ImageReader.h"
#include "Write_err.h"
#include "BmpReader.h"
#include "BmpWriter.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    string fileanme = "f://ExifIntel.bmp";
    string file = "f://myBmp.bmp";

    ImageReader* ir = new BmpReader(fileanme);
    try
    {
        ir->readHeader();
        cout<<ir->getWidth()<<endl;
        cout<<ir->getHeight()<<endl;
        cout<<ir->getFileSize()<<endl;
        ir->getData();
    } 
    catch(Readerr)
    {
        cout<<"read error"<<endl;
    }
    catch(...)
    {

    }
    
    ImageWriter* iw = new BmpWriter(file);
    try
    {
        iw->wrtieHeader();
    }
    catch(Write_err)
    {
        cout<<"some write errors occurs"<<endl;
    }
    catch(...)
    {
    }
    delete ir;
    delete iw;
    
	return 0;
}

