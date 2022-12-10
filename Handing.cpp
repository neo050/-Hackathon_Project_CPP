#include "Handing.h"
Handing::Handing(int num_screws, char *name, int year, char* current, float height,  Artist* artist, float length, float space, float weight):Creation(name, year, current, height, artist), Picture(name, year, current, height, artist, length), Statue(name, year, current, height, artist, space, weight)
{
	this->num_screws = num_screws;
}
Handing::~Handing()
{

}
void Handing::print()const
{
	Creation::print();
	cout << "length: " << length << endl << "space: " << space << endl << "weight: " << weight << endl << "num crews: " << num_screws << endl;
}
Handing::Handing(const Handing& ob) :Creation(ob), Picture(ob), Statue(ob)
{
	this->num_screws = ob.num_screws;
}
const char* Handing::get_type()const
{
	return "Handing";
 }