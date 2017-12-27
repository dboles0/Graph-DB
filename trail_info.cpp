//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #5 

//trail_info.cpp file

#include"trail_info.h"

//default constructor for the event info struct
edge::edge()
{
    trail = NULL;
    description = NULL;
    length = NULL;
}

//destructor to deallocate the information saved to the struct
edge::~edge()
{
   if(trail) 
	delete [] trail; 
   if(description) 
	delete [] description;       
   if(length) 
	delete [] length;       
}
 
//copy function to take the infomrtiaon form the object and copy it 
//into the graph
int edge::copy(const edge & to_add)
{
    trail = new char [strlen(to_add.trail)+1];
    strcpy(trail, to_add.trail);
    description = new char [strlen(to_add.description)+1];
    strcpy(description, to_add.description);
    length = new char [strlen(to_add.length)+1];
    strcpy(length, to_add.length);
}

//take the informtation form the client to store to struct
int edge::create_entry(char * a_trail, char * a_description, char * a_length)
{
    trail = new char [strlen(a_trail)+1];
    strcpy(trail, a_trail);
    description = new char [strlen(a_description)+1];
    strcpy(description, a_description);
    length = new char [strlen(a_length)+1];
    strcpy(length, a_length);
}
 
int edge::compare(char * match)
{
    if(strcmp(trail, match) == 0)
    return 1;
    else 
    return 0;
}
