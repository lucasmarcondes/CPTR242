// This file contains the code for the FindItem using a doubly
// linked list

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
    NodeType<ItemType>* back;
} template <class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, bool& found)
// Assumption:  ItemType is a type for which the operators "<" and
//		"==" are defined--either an appropriate built-in type or a
//		class that overloads these operations.
// Pre:  List is not empty.
// Post: If there is an element someItem whose key matches item's
//		key, then found = true; otherwise, found = false.
//       If found, location contains the address of someItem;
//       otherwise, location contains the address of the logical
//		successor of item.
{
    bool moreToSearch = true;

    location = listData;
    found = false;
    while (moreToSearch && !found) {
        if (item < location->info)
            moreToSearch = false;
        else if (item == location->info)
            found = true;
        else {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
