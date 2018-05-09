// This file contains the code for the routines in the text.
// It is not complete and will not compile.

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType* next;
};

template <class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc,
              bool& found)
// Pre: List is not empty.
// Post:If there is an element someItem whose key matches item's
//      key, then found = true; otherwise, found = false.
//      If found, location contains the address of someItem and
//      predLoc contains the address of someItem's predecessor;
//      otherwise, location contains the address of item's logical
//      successor and predLoc contains the address of item's
//      logical predecessor.
{
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;

    while (moreToSearch && !found) {
        if (item.ComparedTo(location->info) == LESS)
            moreToSearch = false;
        else if (item.ComparedTo(location->info) == EQUAL)
            found = true;
        else {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item) {
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData != NULL) {
        FindItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;
        // If this is last node in list, reassign listData.
        if ((listData->info.ComparedTo(item)) == LESS)
            listData = newNode;
    } else  // Inserting into an empty list.
    {
        listData = newNode;
        newNode->next = newNode;
    }
    length++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
    NodeType<ItemType>* location;
    NodeType<ItemType>* predLoc;
    bool found;

    FindItem(listData, item, location, predLoc, found);
    if (predLoc == location)  // Only node in list?
        listData = NULL;
    else {
        predLoc->next = location->next;
        if (location == listData)  // Deleting last node in list?
            listData = predLoc;
    }
    delete location;
    length--;
}
