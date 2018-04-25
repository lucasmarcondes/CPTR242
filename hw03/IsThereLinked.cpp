/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 * 
 * File Name:   IsThereLinked.cpp
 * Name:        Lucas Marcondes
 * Course:      CPTR 242
 * Date:        4/25/18
 * Time Taken:  ?
 * 
 */
#include "ItemType.h"
#include "SortedLinked.h"

// Boolean IsThere(ItemType item)
//  Function:	    Determines if item is in the list.
//  Precondition:	List has been initialized.
// 	Postcondition:	Function value = there exist an item in the list whose key is the same as item's.	
bool SortedLinked::IsThere(ItemType item) const {

	NodeType* location;
	location = listData;

	for (int i = 0; i < GetLength(); i++)
	{
		switch (item.ComparedTo(location->info))
		{
		case GREATER:
			location = location->next;
			break;
		case EQUAL:
			return true;
		case LESS:
			return false;
			break;
		}
	}
		return false;
	}
