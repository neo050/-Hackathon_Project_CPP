#include"Picture.h"
Picture::Picture(char *name, int year, char* current, float height,  Artist* artist, float length) :Creation(name, year, current, height, artist)
{
    this->length = length;
}
Picture::Picture(const Picture& A) : Creation(A)
{

    this->length = A.length;
}
void Picture::print()const
{
    Creation::print();
    cout << "length: "<<this->length << endl;
}
const char* Picture::get_type()const
{
    return "Picture";
}
Picture::~Picture()
{
}