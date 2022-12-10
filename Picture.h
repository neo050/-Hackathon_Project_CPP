#pragma once
#include "Creation.h"
class Picture :virtual public Creation
{
 protected:
    float length;

public:
    //(name, year, current, height, artist, length)
    Picture(char *name, int year, char* current, float height,  Artist* artist, float length);
    Picture(const Picture& A);
    virtual const char* get_type()const ;
    virtual void print()const;
    virtual ~Picture();
};


