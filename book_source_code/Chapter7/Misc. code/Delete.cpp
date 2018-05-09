// delete.cpp
//
// Description: Recursively search for and delete a node from a linked list.
//
// Function:     Delete
// Definition:   Deletes item from a list each specified in arguments
// Size:         Number of items in the list
// Base Case:    If item.ComparedTO(listPtr->info) = EQUAL, delete pointed to by listPtr.
// General Case: Delete(listPtr->next, item)

template <class ItemType>
void Delete(NodeType<ItemType>*& listPtr, ItemType item) {
    if (item == listPtr->info) {
        NodeType<ItemType>* tempPtr = listPtr;
        listPtr = listPtr->next;
        delete tempPtr;
    } else
        Delete(listPtr->next, item);
}
