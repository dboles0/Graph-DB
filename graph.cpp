//Donald C Boles
//ID: 903512975
//CS_163 Spring 2017
//Program Assignment #5 

//graph.cpp file

#include "graph.h"
using namespace std;

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Constructor 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

graph::graph(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
      adjacency_list = new vertex[size];
      for(int i=0; i<size; ++i)
      {
           adjacency_list[i].entry = NULL;
           adjacency_list[i].head = NULL;
      }
      list_size = size;

}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Destructor 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
graph::~graph()
{
    for(int i=0; i<list_size; ++i)
    { 
           delete [] adjacency_list[i].entry;
           delete [] adjacency_list[i].head;
    }
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions - 1 Insert a vertex
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
int graph::insert_vertex(const edge & to_add)
{

        for(int i=0; i<list_size; ++i)
            if(adjacency_list[i].entry == NULL) 
            {
                adjacency_list[i].entry = new edge;
                adjacency_list[i].entry->copy(to_add);
                return 1;
            }
        
        return 0;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions - 2 Insert an edge
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

int graph::insert_edge(char * current_vertex, char * to_attach)
{
       int connection1 = find_location(current_vertex);
       int connection2 = find_location(to_attach);
        
       if(connection1 == -1 || connection2 == -1) return 0;
       node * temp = new node; 
       temp->adjacent = &adjacency_list[connection2];
       temp->next = adjacency_list[connection1].head;
       adjacency_list[connection1].head = temp;
       
       temp = new node;
       temp->adjacent = &adjacency_list[connection1];
       temp->next = adjacency_list[connection2].head;
       adjacency_list[connection2].head = temp;

       return 1;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions - 3 display all of the paths of the trail head 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//Display all vertices adjacent to the one specified
int graph::display_adjacent(char * key_value)
{
    for(int i=0; i<list_size; ++i)
    {
       if(adjacency_list[i].entry != NULL)
       if(adjacency_list[i].entry->compare(key_value))
       {
           node * current = adjacency_list[i].head;
           while(current)
           {
               if(current->adjacent)
               {
                   cout << current->adjacent->entry->trail << endl;
               }
               current = current->next;
           }
       }
    }
       return 0;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions - 4 display all tarail connections form specified vertex
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

int graph::display_vertisies(char * key)
{
    bool visited = false;
    node * current = adjacency_list->head;
    return display_vertisies(current, key, visited);
}
//display connections
int graph::display_vertisies(node * head, char * key, bool visited)
{
    for(int i=0; i<list_size; ++i)
    {
       if(adjacency_list->head == NULL) return 0;
       if(adjacency_list[i].head != NULL && visited == false) 
       if(adjacency_list[i].entry->compare(key))
       {
                   cout << head->adjacent->entry->trail << endl;
       }
       visited = true;
       display_vertisies(adjacency_list->head->next, key, visited);
    }
    return 1;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions - 4 load in form a file
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/*
int binary_node_tree::load(graph & load, edge & a_trial)
{  
    char t_trail[SIZE];
    char t_lenght[SIZE];
    char t_description[SIZE];
    
    ifstream in_file;                              //create object 
    in_file.open("Trail.txt");                    //open txt file
    if (in_file)
    {
        //prime the pump
        in_file.get(t_trail, SIZE, '|');
	in_file.ignore(SIZE, '|');
        a_head.trail = new char[strlen(t_trail) + 1];
        strcpy(a_head.trail, t_trail); 

	while (in_file && !in_file.eof()) 
	{
            in_file.get(t_length, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            a_head.length = new char[strlen(t_length) + 1];
            strcpy(a_trail.trail, t_length); 
	   
            //read in until we find the end of the line             
	    in_file.get(t_descripton, SIZE, '\n');
	    in_file.ignore(SIZE, '\n');
            a_trail.description = new char[strlen(t_description) + 1];
            strcpy(a_trail.description, t_description); 

            load.insert_edge(char * current_vertex, a_trail);

	    //Prime the pump
	    in_file.get(t_trail, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            if(strlen(t_trail) > 0) 
            {            
            a_trail.trail = new char[strlen(t_trail) + 1];
            strcpy(a_trail.tral, t_trail); 
            }

	}                                         //end while
        //close the connectoin to the out file
	in_file.close();
	in_file.clear();
   }                                              //end if	
                                                 //end load 
}
*/


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Helper Functions - find location 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//return address of the match passed in
int graph::find_location(char * to_find)
{ 
  for(int i=0; i<list_size; ++i)
  {
      if(adjacency_list[i].entry != NULL)  
      {
          if(strcmp(adjacency_list[i].entry->trail, to_find) == 0)
          {
              return i;
          }
      }
       
  }
  return -1;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Helpper Functions - conditional statements to add additional entries 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//bool value to continue entering entries
bool again()
{
    char response;
    cout <<"Would you like to add another? Y/N ";
    cin >> response;
    cin.ignore(100, '\n');
    if (toupper(response)== 'N')
    {    
	return false;
    }
    else 
    { 
        return true;
    }
}
