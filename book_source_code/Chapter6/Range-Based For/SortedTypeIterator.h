#ifndef SORTEDTYPEITERATOR_H
#define SORTEDTYPEITERATOR_H

#include <stddef.h>
#include "NodeType.h"

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE
//
///////////////////////////////////////////////////////////////////////////////

// A template for an iterator that implements the contract required by the
// range-based for-loop. The name of the Iterator class would be customized
// to be XIterator where X is the name of the ADT that the iterator iterates
// over.
template <class T>
class SortedTypeIterator {
  public:
    // Customize the constructor to work with the ADT.
    SortedTypeIterator(NodeType<T>* start);

    T& operator*();

    // Customize to return the proper iterator class.
    SortedTypeIterator<T>& operator++();

    // Customize to receive the correct Iterator class.
    bool operator!=(const SortedTypeIterator<T>& it) const;

  private:
    // The start of the linked list.
    NodeType<T>* item;
};

#endif

///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
SortedTypeIterator<T>::SortedTypeIterator(NodeType<T>* start) {
    this->item = start;
}

template <class T>
T& SortedTypeIterator<T>::operator*() {
    return item->info;
}

template <class T>
SortedTypeIterator<T>& SortedTypeIterator<T>::operator++() {
    if (item == NULL || item->next == NULL)
        item = NULL;
    else
        item = item->next;
    return *this;
}

template <class T>
bool SortedTypeIterator<T>::operator!=(const SortedTypeIterator<T>& it) const {
    return item != it.item;
}
