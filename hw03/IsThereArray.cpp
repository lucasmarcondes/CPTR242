/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 * 
 * File Name:   IsThereArray.cpp
 * Name:        Lucas Marcondes
 * Course:      CPTR 242
 * Date:        4/25/18
 * Time Taken:  ?
 * 
 */
#include "ItemType.h"
#include "SortedArray.h"

// Boolean IsThere(ItemType item)
//  Function:	    Determines if item is in the list.
//  Precondition:	List has been initialized.
// 	Postcondition:	Function value = there exist an item in the list whose key is the same as item's.	
bool SortedArray::IsThere(ItemType item) const {
    
	int first = GetLength() - 1;
	int last = 0;
	bool moreToSearch = last <= first;
	int mid;

	while (moreToSearch) {
		mid = (first + last) / 2;
		switch (item.ComparedTo(info[mid])) 
		{
		case GREATER:
			last = mid + 1;
			moreToSearch = last <= first;
			break;
		case LESS:
			first = last - 1;
			moreToSearch = last <= first;
			break;
		case EQUAL:
			return true;
			break;
		}
	}
	return false;

}