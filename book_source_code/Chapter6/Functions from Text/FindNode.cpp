template <class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc,
              bool& found)
// Assumption:  ItemType is a type what has a ComparedTo function.
// Pre:  List is not empty.
// Post: If there is an element someItem whose key matches item's
//       key, then found = true; otherwise, found = false.
//       If found, location contains the address of someItem and
//       predLoc contains the address of someItem's predecessor;
//       otherwise, location contains the address of item's logical
//       successor and predLoc contains the address of item's
//       logical predecessor.
{
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;
    while (moreToSearch && !found) {
        if (item < location->info)
            moreToSearch = false;
        else if (item == location->info)
            found = true;
        else {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}
