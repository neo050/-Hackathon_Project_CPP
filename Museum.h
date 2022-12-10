#pragma once
#include "Handing.h"
#include "Artist.h"
//class Artist;
//class Creation;
class Museum
{
public:
	Museum();
	~Museum();
	void menu();
	void add_null_artistz(char *artist);
	void add_new_creation();
	void remove_creation(int index);
	void print_all_atrs_creation();
	void print_the_all_creations();
	void print_all_picture();
	void print_all_statue();
	void print_specific_art_creation();
	void print_specific_current();
	void print_atrs_picture();
	void print_atrs_statue();
	void print_statue_weight();
	void adding_the_Artwork(int j, char* name_c);

private:

	Artist** a_arr;
	Creation** c_arr;
	int size_a_arr, size_c_arr;
};


