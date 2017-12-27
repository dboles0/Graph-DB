#include "graph.h"

using namespace std;

int main()
{
    graph a_graph;
    edge to_add;
    char t_trail[100], t_connected[100];
    char t_description[300];
    char t_length[100];
    char key_value[100];
    char key[100];
    
    //read in the entries for the trail informaiton
    do
    {
       cout <<"Please enter the trail name: ";
       cin.get(t_trail, 100); cin.ignore(100,'\n');
       cout <<"What additional information would be usefull about the trail: ";
       cin.get(t_description, 300); cin.ignore(100,'\n');
       cout <<"Please enter the length of the trail: ";
       cin.get(t_length, 100); cin.ignore(100,'\n');
       to_add.create_entry(t_trail, t_description, t_length);
       
       //insert it into the graph
       a_graph.insert_vertex(to_add);
       
    } while (again());
   
    //prompt the user for connection associations
    do
    {
       cout <<"enter two trails that are connected: ";
       cout <<"trial 1: ";
       cin.get(t_trail, 100); cin.ignore(100,'\n');
       cout <<"trial 2: ";
       cin.get(t_connected, 100); cin.ignore(100,'\n');
       a_graph.insert_edge(t_trail, t_connected);
    } while (again());
   
    cout << "\nEnter your current trail head to display all avalible paths\n" << endl;
    cin.get(key_value, 100); cin.ignore(100,'\n');
    
    cout << "You will have the following paths avalable to you: " << endl;
    //Display direct connections (adjacent connections)
    a_graph.display_adjacent(key_value);
 
    cout << "\nIf you are at an intersection enter your trail head to see the connected trails\n" << endl;
    cin.get(key_value, 100); cin.ignore(100,'\n');

    //Display all of the trail vertecies form a specified vertex	
    cout <<"\n\nThe following trails are at your crossroad: \n";
    a_graph.display_vertisies(key);
    
    
    return 0;
}
