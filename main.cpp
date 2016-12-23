#include <iostream>
#include "Linked_List.h"

using namespace std;

int main(int argc, char * argv[])
{
	Linked_List TeamList;

	node * Node_A = new node;
	Node_A -> number = 11;
	Node_A -> name = "Player A";
	Node_A -> year = "1975";

	node * Node_B = new node;
	Node_B -> number = 22;
	Node_B -> name = "Player B";
	Node_B -> year = "1987";

	node * Node_C = new node;
	Node_C -> number = 33;
	Node_C -> name = "Player C";
	Node_C -> year = "1992";

	node * Node_D = new node;
	Node_D -> number = 44;
	Node_D -> name = "Player D";
	Node_D -> year = "1981";

	node * Node_E = new node;
	Node_E -> number = 55;
	Node_E -> name = "Player E";
	Node_E -> year = "1999";

	node * Node_F = new node;
	Node_F -> number = 66;
	Node_F -> name = "Player F";
	Node_F -> year = "2001";

	node * Node_G = new node;
	Node_G -> number = 77;
	Node_G -> name = "Player G";
	Node_G -> year = "2009";

	node * Node_H = new node;
	Node_H -> number = 88;
	Node_H -> name = "Player H";
	Node_H -> year = "2015 (New Born :-)";

/*****************************************************************************
  * Add 3 players to the list in sequence
  * Print out the contents of the string
*****************************************************************************/
	TeamList.insert_node(Node_A, 1, 0);
	TeamList.insert_node(Node_B, 2, 0);
	TeamList.insert_node(Node_C, 3, 0);

	TeamList.printout(1);
	TeamList.printout(2);
	TeamList.printout(3);


/*****************************************************************************
  * Insert 2 more Player at specified locations within the list (Mode 0)
  * Print out the updated List
*****************************************************************************/
	TeamList.insert_node(Node_D, 2, 0);
	TeamList.insert_node(Node_E, 4, 0);
	cout << "-----------------------------------------------------------------" << endl;
    cout << "After Insertion - Mode 0" << endl;
    cout << "-----------------------------------------------------------------" << endl;
	TeamList.printout(1);
	TeamList.printout(2);
	TeamList.printout(3);
	TeamList.printout(4);
	TeamList.printout(5);


/*****************************************************************************
  * Replace one of the players in the list (Mode 1)
  * Print out the updated List
*****************************************************************************/
	TeamList.insert_node(Node_F, 5, 1);
	cout << "-----------------------------------------------------------------" << endl;
	cout << "After Insertion - Mode 1" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	TeamList.printout(1);
	TeamList.printout(2);
	TeamList.printout(3);
	TeamList.printout(4);
	TeamList.printout(5);


/*****************************************************************************
  * Again insert a player at the end of the list (Mode 0)
  * Print out the updated List
*****************************************************************************/
	TeamList.insert_node(Node_G, 6, 0);
	cout << "-----------------------------------------------------------------" << endl;
	cout << "After a new insertion - Mode 0" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	TeamList.printout(1);
	TeamList.printout(2);
	TeamList.printout(3);
	TeamList.printout(4);
	TeamList.printout(5);
	TeamList.printout(6);


/*****************************************************************************
  * Remove one of the players
  * Print out the updated List
*****************************************************************************/
	TeamList.remove_node(6);
	cout << "-----------------------------------------------------------------" << endl;
	cout << "After Deletion" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	TeamList.printout(1);
	TeamList.printout(2);
	TeamList.printout(3);
	TeamList.printout(4);
	TeamList.printout(5);

/*****************************************************************************
  * This should print out "Error: Index out of range!!!"
  *
*****************************************************************************/
	TeamList.printout(6);

	return 0;
}