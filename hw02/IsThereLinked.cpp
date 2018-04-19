/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 * 
 * File Name:   IsThereLinked.cpp
 * Name:        Lucas Marcondes
 * Course:      CPTR 242
 * Date:        ?
 * Tine Taken:  ?
 * 
 */
#include "ItemType.h"
#include "UnsortedLinked.h"

// Boolean IsThere(ItemType item)
//  Function:	    Determines if item is in the list.
//  Precondition:	List has been initialized.
// 	Postcondition:	Function value = there exist an item in the list whose key is the same as item's.	
bool UnsortedLinked::IsThere(ItemType item) const
{

	// TODO Implement the Linked version of IsThere().

	bool moreToSearch;
	NodeType *location;
	location = listData;

	moreToSearch = (location != NULL);

	while (moreToSearch)
	{
		if (item.ComparedTo(location->info) == EQUAL)
			return true;
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	return false;
}