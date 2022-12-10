#pragma once
#include <iostream>
#include "Artist.h"
using namespace std;
class Artist;
class Creation
{
 protected:
    char* name_of_creation;
    int year;
    char* current;
    float height;
    Artist* artist;
    void Memory_error()const;

public:
    Creation(char *name, int year, char *current, float height, Artist *artist);
    virtual ~Creation();
    virtual const char* get_type()const=0;
    virtual void print()const;
    Creation();
    const char* get_name()const;
    Creation(const Creation& ob);
    const char* get_A_name()const;
    const Artist* get_Artist()const 
    {
        return artist;
    }
    const char* get_current()const;
};

