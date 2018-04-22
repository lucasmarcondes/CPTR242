#include "ItemType.h"
// Header file for Sorted List ADT.
struct NodeType {
  ItemType info;
  NodeType *next;
};

class SortedLinked {
public:
  SortedLinked();  // Class constructor
  ~SortedLinked(); // Class destructor

  bool IsFull() const;
  int GetLength() const;
  void MakeEmpty();
  ItemType GetItem(ItemType &item, bool &found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  ItemType GetNextItem();

  bool IsThere(ItemType item) const;
  // Function: Determines if item is in the list.
  // Pre:     List has been initialized.
  // Post:    Function value = there exist an item in the list whose key is the same as item's.	

private:
  NodeType *listData;
  int length;
  NodeType *currentPos;
};
