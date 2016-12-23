#include "Linked_List.h"


/****************************************************************************
* Function: Linked_List()
*****************************************************************************
*
* Initializes the root node
* 
*
****************************************************************************/
Linked_List::Linked_List() : ListLength(0)
{
	root = new node;
	root -> number = 0;
	root -> name = "";
	root -> year = "";
	root -> next_item = nullptr;
	current_node = root;
}


/****************************************************************************
* Function: insert_node(node * NewNode, int position)
*****************************************************************************
*
* Inserts a new node in the list
* Two modes:
*			Mode 0: Inserts the new node without removing existing node
*					(List length increase)
* 			Mode 1: Replaces the existing node
*					(List length remains the same)
*
****************************************************************************/

bool Linked_List::insert_node(node * NewNode, int position, int mode)
{
	if(position <= 0 || position > ListLength+1)
	{
		std::cout << "Error: Exceeds length of the list!!!" << std::endl;
		return(false);
	}
/*****************************************************************************
  * If the new node is inserted at the end of the list
 *****************************************************************************/
	if(position == ListLength+1)
	{
		current_node -> next_item = NewNode;
		current_node = NewNode;
		current_node -> next_item = nullptr;
		++ListLength;
	}
/*****************************************************************************
  * If the new node is inserted in the middle of the list
 *****************************************************************************/	
	else if(position != ListLength+1)
	{
		int count = 1;
		desired_location = root->next_item;
		before_desired_location = root;
		while(true)
		{
			if(count == position)
			{
				if(mode == 0 /* Insert */)
				{
					NewNode -> next_item = desired_location;
					before_desired_location -> next_item = NewNode;
					++ListLength;
					break;
				}
				else if (mode == 1 /* Replace */)
				{
					NewNode -> next_item = desired_location -> next_item;
					before_desired_location -> next_item = NewNode;
					delete desired_location;
					if (position == ListLength)
					{
						current_node = NewNode;
					}
					break;
				}
				else
				{
					std::cout << "Error: Illegal Mode Number! Mode Number can only be 0 or 1!!! \n";
					break; 
				}
			}
			else
			{
				before_desired_location = desired_location;
				desired_location = desired_location -> next_item;
				++count;
			}
		}

	}

	return(true);
}


/****************************************************************************
* Function: printout(int position)
*****************************************************************************
*
* Print out the contents of the selected node
* 
*
****************************************************************************/
bool Linked_List::printout(int position)
{
	if (position <= 0 || position > ListLength)
	{
		std::cout << "Error: Index out of range!!!" << std::endl;
		return(false);
	}
	node_to_display = root -> next_item;
	int count = 1;
	while(true)
	{
		if(count == position)
		{
			std::cout << node_to_display -> number << " " << node_to_display -> name 
			<< " " << node_to_display -> year << std::endl;
			break;
		}
		else
		{
			node_to_display = node_to_display -> next_item;
			++count;
		}
	}

	return (true);
}


/****************************************************************************
* Function: remove_node(int position)
*****************************************************************************
*
* Removes the specified node from the linked list
* 
*
****************************************************************************/
bool Linked_List::remove_node(int position)
{
	if (position <= 0 || position > ListLength)
	{
		std::cout << "Error: Index out of range!!!" << std::endl;
		return(false);
	}

	int count = 1;
	node * node_to_remove = root -> next_item;
	node * before_node_to_remove = root;
	
	while(true)
	{
		if(count == position)
		{
			before_node_to_remove -> next_item = node_to_remove -> next_item;
			delete node_to_remove;
			if (position == ListLength)
			{
				current_node = before_node_to_remove;
			}
			--ListLength;
			break; 
		}
		else
		{
			before_node_to_remove = node_to_remove;
			node_to_remove = node_to_remove -> next_item;
			++count;
		}
	}
	return(true);
}


Linked_List::~Linked_List()
{
	node * next = root -> next_item;
	node * current = root;
	for (int i = 0; i < ListLength; ++i)
	{
		delete current;
		current = next;
		next = next -> next_item;
	}
	delete current;
}