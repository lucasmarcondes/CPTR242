// This file contains the individual functions from the text.
// Note that there are two InsertItems
int ItemType::Hash() const
// Post: Returns an integer between 0 and MAX_ITEMS -1.
{
    return (idNum % MAX_ITEMS);
}
template <class ItemType>
void ListType<ItemType>::RetrieveItem(ItemType& item)
// Post: Returns the element in the array at position
//       item.Hash().
{
    int location;

    location = item.Hash();
    item = info[location];
}
template <class ItemType>
void ListType<ItemType>::InsertItem(ItemType item)
// Post: item is stored in the array at position item.Hash().
{
    int location;

    location = item.Hash();
    info[location] = item;
    length++;
}
template <class ItemType>
void ListType<ItemType>::InsertItem(ItemType item)
// Post: item is stored in the array at position item.Hash()
//       or the next free spot.
{
    int location;

    location = item.Hash();
    while (info[location] != emptyItem)
        location = (location + 1) % MAX_ITEMS;
    info[location] = item;
    length++;
}
template <class ItemType>
void ListType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
    int location;
    int startLoc;
    bool moreToSearch = true;

    startLoc = item.Hash();
    location = startLoc;
    do {
        if (info[location] == item || info[location] == emptyItem)
            moreToSearch = false;
        else
            location = (location + 1) % MAX_ITEMS;
    } while (location != startLoc && moreToSearch);
    found = (info[location] == item);
    if (found)
        item = info[location];
}
