#include"Statue.h"
Statue::Statue(char* name, int year, char* current, float height,  Artist* artist, float space, float weight) :Creation(name, year, current, height, artist)
{
    this->space = space;
    this->weight = weight;
}
Statue::Statue(const Statue& A) : Creation(A)
{
    this->space = A.space;
    this->weight = A.weight;
}
void Statue::print()const
{
    Creation::print();
    cout << "space: " << this->space << endl << "weight: " << this->weight << endl;
}
const char* Statue::get_type()const
{
    return "Statue";
}
float Statue::get_weight()const
{
    return weight;
}
Statue::~Statue()
{
}