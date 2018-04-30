#ifndef SORTED_TYPE_H
#define SORTED_TYPE_H

#include "ItemType.h"

using namespace std;

// Header file for Sorted List ADT.
struct NodeType {
    ItemType info;
    NodeType *next;
};

class SortedType {
  public:
    SortedType();   // Class constructor
    SortedType(const SortedType &st);
    ~SortedType();  // Class destructor

    bool IsFull() const;
    int GetLength() const;
    void MakeEmpty();
    ItemType GetItem(ItemType &item, bool &found);
    void PutItem(ItemType item);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
    void GetNextItem(ItemType &item);
    void Print(ostream &dataFile);

  private:
    NodeType *listData;
    int length;
    NodeType *currentPos;
};

#endif  // SORTED_TYPE_H