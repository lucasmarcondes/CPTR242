/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 * 
 * File Name:   IsThereArray.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 * Tine Taken:  ?
 * 
 */
#include "ItemType.h"
#include "UnsortedArray.h"

// Boolean IsThere(ItemType item)
//  Function:	    Determines if item is in the list.
//  Precondition:	List has been initialized.
// 	Postcondition:	Function value = there exist an item in the list whose key is the same as item's.	
bool UnsortedArray::IsThere(ItemType item) const
{

	// TODO Implement the Linked version of IsThere().
	bool moreToSearch;
	int location = 0;
	int length = UnsortedArray::GetLength();

	moreToSearch = (location < length);

	while (moreToSearch)
	{
		if (item.ComparedTo(UnsortedArray::info[location]) == EQUAL)
		{
			return true;
		}
		else
		{
			location++;
			moreToSearch = (location < length);
		}
	}
	return false;
}