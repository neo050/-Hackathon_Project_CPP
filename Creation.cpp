#define _CRT_SECURE_NO_WARNINGS 
#include"Creation.h"
Creation::Creation(char* nema, int year, char* current, float height,  Artist* artist)
{
    this->name_of_creation = new char[strlen(nema) + 1];
    if (!this->name_of_creation)
    {
        Memory_error();
    }
    strcpy(this->name_of_creation, nema);
    this->year = year;
    this->current = new char[strlen(current) + 1];
    if (!this->current)
    {
        Memory_error();
    }
    strcpy(this->current, current);
    this->height = height;
    this->artist = artist;
}

Creation::~Creation()
{
    delete[] name_of_creation;
    delete[] current;
    artist = NULL;
}

/*Creation::set()
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name ,name);
    this->year = year;
    this->current = new char[strlen(current) + 1];
    strcpy(this->current ,current);
    this->height = height;
    this->artist = artist;
}
*/
void Creation::Memory_error()const
{
    cout << "Memory error" << endl;
    exit(1);
}

void Creation::print()const
{
    cout << "name of creation: " << this->name_of_creation << endl << "year: " << this->year << endl << "art's current: " << this->current << endl << "height of creation: " << this->height << endl;
}

Creation::Creation()
{
     name_of_creation=NULL;
    year=0;
    current=NULL;
    height=0.0;
     artist=NULL;
}
Creation::Creation(const Creation& ob)
{
    this->name_of_creation = new char[strlen(ob.name_of_creation) + 1];
    strcpy(name_of_creation, ob.name_of_creation);
    this->current = new char[strlen(ob.current) + 1];
    strcpy(current, ob.current);
    this->year = ob.year;
    this->height = ob.height;
    this->artist = ob.artist;
}
const char* Creation::get_name()const
{
    return name_of_creation;
}
const char* Creation::get_A_name()const
{
    return artist->get_name();
}
const char* Creation::get_current()const
{
    return  current;
}