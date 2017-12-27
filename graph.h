//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #5 

//graph.h file

#include"trail_info.h"

struct vertex
{
       edge * entry;          //NULL, if the vertex isn't set
       struct node * head;           //edge list
       bool visit;                   //flag to check if visiyed:wqa
};

struct node
{
       vertex * adjacent;	  //Additional data would be needed
                                  //for a weighted graph
       node * next;
};

class graph
{
      public:
             graph(int size=5);    
             ~graph();                            
             int insert_vertex(const edge & to_add); 
             int insert_edge(char * current_vertex, char * to_attach);
             int display_adjacent(char * key_value);          
             int display_vertisies(char * key);
             int find_location(char * to_find);
  
      private:
             vertex * adjacency_list;
	     int list_size;
             int display_vertisies(node * head, char * key, bool visited);
};

bool again();
