#pragma once
#include "Creation.h"
class Statue :virtual public Creation
{
protected:
    float space, weight;

public:
    Statue(char *name, int year, char* current, float height,  Artist* artist, float space, float weight);
    Statue(const Statue& A);
    virtual const char* get_type()const;
    virtual~Statue();
    virtual void print()const;
    float  get_weight()const;

};

