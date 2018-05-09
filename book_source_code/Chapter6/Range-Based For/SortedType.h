#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include <iostream>
#include "NodeType.h"
#include "SortedTypeIterator.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE
//
///////////////////////////////////////////////////////////////////////////////

// A template for an ADT that supports iteration using the range-based for loop.
// Each ADT will have a class that includes the begin/end methods. The begin/end
// methods return an Iterator value that overrides the *, ++, and != operators.
// The implementation of the Iterator is extracted out into a separate class
// that knows how to iterator over this ADT.
template <class T>
class SortedType {
  public:
    // Customize the name of the ADT constructors.
    SortedType();
    ~SortedType();

    bool IsFull() const;
    int GetLength() const;
    void MakeEmpty();
    T GetItem(T item, bool& found);
    void PutItem(T item);
    void DeleteItem(T item);

    // Customize with the associated ADT Iterator.
    SortedTypeIterator<T> begin();
    SortedTypeIterator<T> end();

  private:
    NodeType<T>* listData;
    int length;
};

#endif

///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
SortedType<T>::SortedType() {
    length = 0;
    listData = NULL;
}

template <class T>
SortedType<T>::~SortedType() {
    // This is slightly different than the book implementation which duplicates
    // code for MakeEmpty in the destructor. We can keep it the same in the book,
    // but I couldn't help myself...
    MakeEmpty();
}

template <class T>
bool SortedType<T>::IsFull() const {
    NodeType<T>* location;
    try {
        location = new NodeType<T>;
        delete location;
        return false;
    } catch (bad_alloc exception) {
        return true;
    }
}

template <class T>
int SortedType<T>::GetLength() const {
    return length;
}

template <class T>
void SortedType<T>::MakeEmpty() {
    NodeType<T>* curr = listData;
    while (curr != NULL) {
        NodeType<T>* prev = curr;
        curr = curr->next;
        delete prev;
        length--;
    }
}

template <class T>
T SortedType<T>::GetItem(T item, bool& found) {
    // We can leverage the range-based for loop here.
    found = false;
    for (T someItem : *this) {
        if (someItem == item) {
            found = true;
            return someItem;
        }
    }
    return item;
}

template <class T>
void SortedType<T>::PutItem(T item) {
    NodeType<T>* newNode;   // pointer to node being inserted
    NodeType<T>* predLoc;   // trailing pointer
    NodeType<T>* location;  // traveling pointer
    bool moreToSearch;      // boolean indicating to continue searching

    // Search for insertion point.
    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);

    while (moreToSearch) {
        if (item < location->info)
            moreToSearch = false;
        else if (item > location->info) {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }

    // Prepare node for insertion.
    newNode = new NodeType<T>;
    newNode->info = item;

    // Insert node into list.
    if (predLoc == NULL) {
        newNode->next = listData;
        listData = newNode;
    } else {
        newNode->next = location;
        predLoc->next = newNode;
    }

    length++;
}

template <class T>
void SortedType<T>::DeleteItem(T item) {
    NodeType<T>* location = listData;
    NodeType<T>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info) {
        tempLocation = location;
        listData = listData->next;  // Delete first node.
    } else {
        while (item != location->next) {
            location = location->next;
        }

        // Delete node at location->next.
        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

//
// The methods below provide the range-based for loop support. These would
// be customized with the companion Iterator class that is returned.
//

template <class T>
SortedTypeIterator<T> SortedType<T>::begin() {
    SortedTypeIterator<T> it(listData);
    return it;
}

template <class T>
SortedTypeIterator<T> SortedType<T>::end() {
    SortedTypeIterator<T> it(NULL);
    return it;
}
