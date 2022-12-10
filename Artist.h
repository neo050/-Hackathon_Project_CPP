#pragma once
#include<iostream>
using namespace std;
#include"Date.h"
#include"Creation.h"
class Creation;
class Artist 
{
private:
	Date Date_of_birth, Date_of_death;
	char* name;
	Creation** names_Artwork;
	int num_Artwork;
	void Memory_error()const;
public:
	Artist(char* name, const Date &Date_of_birth, const Date &Date_of_eath);
	 ~Artist ();
	  Creation* addArtwork(char *c_name);
	Artist(const Artist& ob);
	 friend ostream& operator<<(ostream& os,  const Artist& A);
	 const char* get_name()const;
	 bool check_Pic()const;
	 bool check_Sta()const;
	 int get_num_Artwork()const 
	 {
		 return num_Artwork;
	 }
	 void print_C()const;
};