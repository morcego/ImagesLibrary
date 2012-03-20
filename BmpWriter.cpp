#include "StdAfx.h"
#include "BmpWriter.h"
#include "Write_err.h"

void BmpWriter::wrtieHeader()
{
    if(file.is_open())
    {
        short size = 0xFFFF;
        int reserv = 0x0;
        int offset = 0xABCD;
        file.write("BM", 2);
        

    }
    else
        throw Write_err();
}
void BmpWriter::writeData(const ImageContainer::pRGBQUDS& rgbData)
{
    if(file.is_open())
    {

    }
    else
    {
        throw Write_err();
    }
}