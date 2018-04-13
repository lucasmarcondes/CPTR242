// Implementation file for Unsorted.h

#include "UnsortedArray.h"

UnsortedArray::UnsortedArray() {
    length = 0;
}
bool UnsortedArray::IsFull() const {
    return (length == MAX_ITEMS);
}
int UnsortedArray::GetLength() const {
    return length;
}

ItemType UnsortedArray::GetItem(ItemType item, bool& found) {
    // Pre:  Key member(s) of item is initialized. 
    // Post: If found, item's key matches an element's key in the 
    //       list and a copy of that element has been returned;
    //       otherwise, item is returned. 
    bool moreToSearch;
    int location = 0;
    found = false;
    
    moreToSearch = (location < length);
    
    while (moreToSearch && !found) {
        switch (item.ComparedTo(info[location])) {
            case LESS: 
            case GREATER: 
                location++;
                 moreToSearch = (location < length);
                 break;
            case EQUAL: 
                found = true;
                 item = info[location];
                 break;
        }
    }
    return item;
}
void UnsortedArray::MakeEmpty() {
    // Post: list is empty.
    length = 0;
}
void UnsortedArray::PutItem(ItemType item) {
    // Post: item is in the list.
    info[length] = item;
    length++;
}
void UnsortedArray::DeleteItem(ItemType item) {
    // Pre:  item's key has been initialized.
    //       An element in the list has a key that matches item's.
    // Post: No element in the list has a key that matches item's.
    int location = 0;
    
    while (item.ComparedTo(info[location]) != EQUAL)
        location++;
    
    info[location] = info[length - 1];
    length--;
}
void UnsortedArray::ResetList() {
    // Post: currentPos has been initialized.
    currentPos = -1;
}

ItemType UnsortedArray::GetNextItem() {
    // Pre:  ResetList was called to initialized iteration.
    //       No transformer has been executed since last call.
    //       currentPos is defined.
    // Post: item is current item.
    //       Current position has been updated.
    currentPos++;
    return info[currentPos];
}

