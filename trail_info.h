#include<iostream>
#include<cstring>
#include<cctype>

//this struct will house the trail informaoitn 
struct edge
{
    char * trail;
    char * length;
    char * description;
    edge();
    ~edge();
    int copy(const edge & to_add);
    int create_entry(char * a_trail, char * a_length, char * a_description);
    int compare(char * match);
};
