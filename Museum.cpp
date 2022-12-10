//tal sinay id 316261353
//neoray hagag id 208090738
#include<ostream>
#include"Museum.h"
#include <typeinfo>
Museum::Museum()
{
	a_arr=NULL;
	c_arr = NULL;
	size_a_arr = 0;
	size_c_arr = 0;
}
Museum::~Museum()
{
	for (int i = 0; i < size_a_arr; ++i)
	{
		delete a_arr[i];
	}
	delete[]a_arr;
	/*for (int i = 0; i < size_c_arr; ++i)
	{
		delete c_arr[i];
	}*/
	delete[]c_arr;
}
void Museum::menu()
{

	int index;
	char choice;
	char art[20];
	do
	{
		cout << endl;
		cout << "what are you want to do:" << endl << "A->add artist" << endl << "B->add creation" << endl << "C->sub creation" << endl << "D->print artists with a min 1 creation" << endl << "E->print all creations" << endl << "F->print all picturs" << endl << "G->print all statues" << endl << "H->print creations by a artist" << endl << "I->print creations by a current" << endl << "J->print all artists with a min 1 picture" << endl << "M->print all artists with a min 1 statue" << endl << "N->print all statues by weight" << endl << "L->to exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 'A':
			cout << "enter the name of the artist" << endl;
			cin >> art;
			add_null_artistz(art);

			break;
		case 'B':
			add_new_creation();
			break;
		case 'C':
			cout << "enter index of creation:" << endl;
			cin >> index;
			remove_creation(index);
			break;
		case 'D':
			print_all_atrs_creation();
			break;
		case 'E':
			print_the_all_creations();
			break;
		case 'F':
			print_all_picture();
			break;
		case 'G':
			print_all_statue();
			break;
		case 'H':
			print_specific_art_creation();
			break;
		case 'I':
			print_specific_current();
			break;
		case 'J':
			print_atrs_picture();
			break;
		case 'M':
			print_atrs_statue();
			break;
		case 'N':
			print_statue_weight();
			break;
		default:
			if (choice < 'A' || choice >'L')
				cout << "this is a wrong number! please pick number form the list" << endl;
			break;
		}
	} while (choice != 'L');
	cout << "Goodbye" << endl;
		
}
	
void Museum::add_null_artistz(char* artist)
{
	Artist** temp;
	/*char name[20];*/
	Date db, dd;
	temp = new Artist * [size_a_arr + 1];
	if (!temp)
	{
		cout << "No memory";
		exit(1);
	}
	for (int i = 0; i < size_a_arr; i++)
	{
		temp[i] = a_arr[i];
	}
	delete[] a_arr;
	/*cout << "enter name of the artist:";
	cin >> name;*/
	cout << "Enter date of birth: ";
	cin >> db;
	cout << endl;
	cout << "Enter date of dead,if he's still alive enter 0 0 0: ";
	cin >> dd;
	cout << endl;
	temp[size_a_arr] = new Artist(artist, db, dd);
	a_arr = temp;
	++size_a_arr;
}

void Museum::add_new_creation()
{
	/*Creation** temp;
	int yaer;
	temp = new Creation * [size_c_arr + 1];
	if (!temp)
	{
		cout << "No memory";
		exit(1);
	}
	for (int i = 0; i < size_c_arr; ++i)
	{
		temp[i] = c_arr[i];
	}*/
	int index = 0;
	char name_a[20], name_c[20];
	cout << "Enter name of artist: "; cin >> name_a; cout << endl;
	cout << "Enter name of creation: "; cin >> name_c; cout << endl;
	for (int j = 0; j < size_a_arr; ++j)
	{
		if (strcmp(a_arr[j]->get_name(), name_a) == 0)
		{
			if (size_c_arr > 0)
			{
				for (int i = 0; i < size_c_arr; ++i)
				{
					if (strcmp(c_arr[i]->get_name(), name_c) == 0 && c_arr[i]->get_Artist() == a_arr[j])
					{

						cout << "This artist already has a creation by that name" << endl;
						return;
					}
					else
					{

						adding_the_Artwork(j, name_c);
						return;
					}
				}
			}
			else
			{
				adding_the_Artwork(j, name_c);
				return;
			}
		}
	}
	add_null_artistz(name_a);
	adding_the_Artwork(size_a_arr - 1, name_c);
}
void  Museum::adding_the_Artwork(int j, char* name_c)
{
	Creation** temp;
	temp = new Creation * [size_c_arr + 1];
	if (!temp)
	{
		cout << "No memory" << endl;
		exit(1);
	}
	for (int i = 0; i < size_c_arr; ++i)
	{
		temp[i] = c_arr[i];
	}
	delete[]c_arr;

	temp[size_c_arr]= a_arr[j]->addArtwork(name_c);
	++size_c_arr;
	c_arr = temp;
	/*Handing* k0 = dynamic_cast<Handing*>(l);
	if (k0)
	{
		Handing* c0 = new Handing(*k0);
		temp[size_c_arr] = c0;
		c_arr = temp;
		++size_c_arr;
		return;

	}
	Picture* k = dynamic_cast<Picture*>(l);
	if (k)
	{
		Picture* c = new Picture(*k);
		temp[size_c_arr] = c;
		c_arr = temp;
		++size_c_arr;
		return;

	}
	Statue* k1 = dynamic_cast<Statue*>(l);
	if (k1)
	{
		Statue *c1 =new Statue(*k1);
		temp[size_c_arr] = c1;
		c_arr = temp;
		++size_c_arr;
		return;

	}
	else
	{
		cout << "No memory" << endl;
		exit(1);
	}*/
}


void Museum::remove_creation(int index)
{
	int k = 0;
	Creation** temp;
	temp = new Creation * [size_c_arr - 1];
	if (!temp)
	{
		cout << "No memory"<<endl;
		exit(1);
	}
	for (int i = 0; i < size_c_arr; i++)
	{
		if (i != index)
		{
			temp[k] = c_arr[i];
			++k;
		}
		else
		{
			c_arr[i] = NULL;
		}

	}
	delete[]c_arr;
	c_arr = temp;
	--size_c_arr;
}
void Museum::print_all_atrs_creation()
{
	for (int i = 0; i < size_a_arr; i++)
	{
		if (a_arr[i]->get_num_Artwork() >= 1)
		{
			cout << *a_arr[i]<< endl;
		}
	}

}
void Museum::print_the_all_creations()
{
	for (int i = 0; i < size_c_arr; i++)
	{
		cout <<"Artist name: " << c_arr[i]->get_A_name() << endl;
		 c_arr[i]->print();
	}
}
void Museum::print_all_picture()
{
	for (int i = 0; i < size_c_arr; i++)
	{
		
			if (dynamic_cast<Picture*>(c_arr[i]))
			{
				cout << "Artist name: " << c_arr[i]->get_A_name() << endl;
				dynamic_cast<Picture*>(c_arr[i])->print();
			}
		
	}
}
void Museum::print_all_statue() 
{
	for (int i = 0; i < size_c_arr; i++)
	{
			if (dynamic_cast<Statue*>(c_arr[i]))
			{
				cout << "Artist name: " << c_arr[i]->get_A_name() << endl;
				dynamic_cast<Statue*>(c_arr[i])->print();
			} 
	}
}
void Museum::print_specific_art_creation()
{
	char name[20];
	int temp = 0;
	cout << "Enter a name of artist:" << endl;
	cin >> name;

	for (int i = 0; i < size_a_arr; i++)
	{
		if (strcmp(a_arr[i]->get_name(), name) == 0)
		{
			a_arr[i]->print_C();
			++temp;
		}
	}
	if (temp == 0)
	{
		cout << "There is no such artist in the museum" << endl;
	}
}
void Museum::print_specific_current()
{
	char current[20];
	int temp = 0;
	cout << "Enter a current:" << endl;
	cin >> current;

	for (int i = 0; i < size_c_arr; i++)
	{
		if (strcmp(c_arr[i]->get_current(), current) == 0)
		{
			c_arr[i]->print();
			temp++;
		}
	}
	if (temp == 0)
	{
		cout << "There is no such current in the museum" << endl;
	}

}
void Museum::print_atrs_picture()
{
	for (int i = 0; i < size_a_arr; i++)
	{
		if(a_arr[i]->check_Pic())
			cout << *a_arr[i] << endl;;
	}

}
void Museum::print_atrs_statue()
{
	for (int i = 0; i < size_a_arr; i++)
	{
		if(a_arr[i]->check_Sta())
			cout << *a_arr[i] << endl;
	}
}
void Museum::print_statue_weight()
{
	float weight;
	cout << "Enter a weight: ";  cin >> weight;cout<< endl;
		
		for (int i = 0; i < size_c_arr; i++)
		{
			if (strcmp(c_arr[i]->get_type(), "Picture") != 0)
			{
				if (dynamic_cast<Statue*>(c_arr[i]))
				{
					if (dynamic_cast<Statue*>(c_arr[i])->get_weight() > weight)
					{
						c_arr[i]->print();
					}
				}
			}
		}
}