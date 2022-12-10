#define _CRT_SECURE_NO_WARNINGS 
#include <typeinfo>
#include"Artist.h"
#include "Handing.h"
Artist::Artist(char *name,const Date& Date_of_birth, const Date& Date_of_death):Date_of_birth(Date_of_birth), Date_of_death(Date_of_death)
{
	names_Artwork = NULL;
	num_Artwork = 0;

	if (!(this->name = new char[strlen(name) + 1]))
	{
		Memory_error();
	}
	strcpy(this->name, name);
	/*this->Date_of_birth = Date_of_birth;
	this->Date_of_death = Date_of_death;*/

}
Creation* Artist::addArtwork(char* c_name)
{
	Creation** t_name_Artwork = NULL;
	/*char nameArt[20];*/
	char typ;
	int year;
	char current[20];
	float height;
	t_name_Artwork = new Creation * [num_Artwork + 1];
	if (!t_name_Artwork)
	{
		Memory_error();
	}
	for (int i = 0; i < num_Artwork; ++i)
	{
		t_name_Artwork[i] = this->names_Artwork[i];
	}
	cout << "Enter->year of art ,current,height: "; cin >> year >> current >> height;
	cout << "Enter typ of creation" << endl << "P-> picture" << endl << "S-> statue" << endl << "H-> Handing statue" << endl << "Enter your choice " << endl;
	cin >> typ;
	float space, weight;
	float length;
	int num_screws;
	switch (typ)
	{
	case 'S':

		cout << "Enter -> space,weight" << endl;
		cin >> space >> weight;
		t_name_Artwork[num_Artwork] = new Statue(c_name, year, current, height, this, space, weight);
		if (!t_name_Artwork[num_Artwork])
		{
			Memory_error();
		}
		break;

	case 'P':

		cout << "Enter -> length" << endl;
		cin >> length;
		t_name_Artwork[num_Artwork] = new Picture(c_name, year, current, height, this, length);
		if (!t_name_Artwork[num_Artwork])
		{
			Memory_error();
		}
		break;
	case 'H':
		cout << "Enter -> space,weight,length,num of screws" << endl;

		cin >> space >> weight >> length >> num_screws; //Handing(int num_screws, char *name, int year, char* current, float height,  Artist* artist, float length, float space, float weight);
		t_name_Artwork[num_Artwork] = new Handing(num_screws, c_name, year, current, height, this, length, space, weight);
		if (!t_name_Artwork[num_Artwork])
		{
			Memory_error();
		}
		break;
		
	}
	if(names_Artwork)
		delete []names_Artwork;
	names_Artwork = t_name_Artwork;
	++num_Artwork;
	return names_Artwork[num_Artwork - 1];

}
Artist ::~Artist()
{
	if (names_Artwork)
	{
		for (int i = 0; i < num_Artwork; ++i)
		{
			delete this->names_Artwork[i];
		}
		delete[] this->names_Artwork;
	}
	if (name)
		delete[] this->name;
}

void Artist::Memory_error()const
{
	cout << "Memory error" << endl;
	exit(1);
}
Artist::Artist(const Artist& ob)
{
	names_Artwork = new Creation * [ob.num_Artwork];
	for (int i = 0; i < ob.num_Artwork; ++i)
	{
		names_Artwork[i] = ob.names_Artwork[i];
	}
	Date_of_birth = ob.Date_of_birth;
	Date_of_death=ob.Date_of_death;
	this->name = new char[strlen(ob.name) + 1];
	strcpy(name, ob.name);
	num_Artwork=ob.num_Artwork;
}
ostream& operator<<(ostream& os, const Artist& A)
{
	os << "Artist details:" << endl << "name: " << A.name << endl << "Date of birth: ";
	A.Date_of_birth.printDate(); os << endl;
	if (A.Date_of_death.getYear() != 0)
	{
		os << "Date of death: "; A.Date_of_death.printDate();
		os << endl;
	}
	os << endl << "number of artworks:" << A.num_Artwork << endl;
	A.print_C();
	
	return os;
}
const char* Artist::get_name()const
{
	return name;
}
bool Artist::check_Pic()const
{
	for (int i = 0; i < num_Artwork; i++)
	{
		if (dynamic_cast<Picture*>(names_Artwork[i]))
		{
			return true;
		}
	}
	return false;
}


bool Artist::check_Sta()const
{

	for (int i = 0; i < num_Artwork; i++)
	{
		if (dynamic_cast<Statue*>(names_Artwork[i]))
		{
			return true;
		}
	}
	return false;
}
void Artist::print_C()const
{
	cout<< "the creations:" << endl;
	for (int i = 0; i < num_Artwork; i++)
	{
		cout << " creation: " << i << endl;
		names_Artwork[i]->print();
	}
}