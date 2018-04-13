// This file contains the linked implementation of class
// UnsortedLinked.

#include "UnsortedLinked.h"

UnsortedLinked::UnsortedLinked() {
    // Class constructor
    length = 0;
    listData = NULL;
}
bool UnsortedLinked::IsFull() const {
    // Returns true if there is no room for another ItemType 
    //  on the free store; false otherwise.
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch(std::bad_alloc exception) {
        return true;
    }
}

int UnsortedLinked::GetLength() const {
    // Post: Number of items in the list is returned.
    return length;
}

void UnsortedLinked::MakeEmpty() {
// Post: List is empty; all items have been deallocated.
    NodeType* tempPtr;
    
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
void UnsortedLinked::PutItem(ItemType item) {
    // item is in the list; length has been incremented.
    NodeType* location;			// Declare a pointer to a node
    
    location = new NodeType;	// Get a new node 
    location->info = item;		// Store the item in the node
    location->next = listData;	// Store address of first node 
    					        //   in next field of new node
    listData = location;	// Store address of new node into
    					    //   external pointer
    length++;				// Increment length of the list
}

ItemType UnsortedLinked::GetItem(ItemType& item, bool& found) {
// Pre:  Key member(s) of item is initialized.
    // Post: If found, item's key matches an element's key in the 
    //       list and a copy of that element has been stored in item;
    //       otherwise, item is unchanged. 
    bool moreToSearch;
    NodeType* location;
    
    location = listData;
    found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found) {
        switch (item.ComparedTo(location->info)) {
            case LESS: 
            case GREATER: 
                location = location->next;
                moreToSearch = (location != NULL);
                break;
            case EQUAL: 
                found = true;
                item = location->info;
                break;
        }
    }
    return item;
}

void UnsortedLinked::DeleteItem(ItemType item) {
    // Pre:  item's key has been initialized.
    //       An element in the list has a key that matches item's.
    // Post: No element in the list has a key that matches item's.
    NodeType* location = listData;
    NodeType* tempLocation;
    
    // Locate node to be deleted.
    if (item.ComparedTo(listData->info) == EQUAL) {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    } else {
        while (item.ComparedTo((location->next)->info) != EQUAL)
            location = location->next;
        
        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void UnsortedLinked::ResetList() {
    // Post: Current position has been initialized.
    currentPos = NULL;
}

ItemType UnsortedLinked::GetNextItem() {
    // Post:  A copy of the next item in the list is returned.
    //        When the end of the list is reached, currentPos
    //        is reset to begin again.
    ItemType item;
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
    return item;
}

UnsortedLinked::~UnsortedLinked() {
    // Post: List is empty; all items have been deallocated.
    NodeType* tempPtr;
    
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

