// file: ArrayLL.h

// This file contains the code for the array-of-records implementation
// in the text.  Incomplete definitions of ListType and NodeType and
// one stub routine have been included to confirm that the syntax of
// this code is correct. The student must write a complete definition
// to use this code.

typedef int ItemType;

struct NodeType;

struct MemoryType {
    int free;
    NodeType* nodes;
};

// An incomplete definition of ListType sufficient to compile the code
// in the array linked list implementation

class ListType {
  public:
    ListType();
    ListType(int);
    ~ListType();

    // Other member function prototypes go here.
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();

  private:
    int listData;
    int currentPos;
    int length;
    int maxItems;
    MemoryType storage;
};
