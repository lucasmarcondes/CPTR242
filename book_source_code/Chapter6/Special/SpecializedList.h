// Specialized List that goes in both directions
struct NodeType;
#include <cstddef>

class SpecializedList {
  public:
    SpecializedList();  // Class constructor
                        //  ~SpecializedList();                   // Class destructor
                        //  SpecializedList(const SpecializedList& someList);
    // Copy constructor

    void ResetForward();
    // Initializes current position for an iteration
    //  through the list from first item to last item.

    void GetNextItem(int& item, bool& finished);
    // Gets the next item in the structure.
    //  finished is true if all the items have been accessed.
    //  GetNextItem and GetPriorItem are independent; a forward
    //  iteration and a backward iteration may be in progress
    //  at the same time.

    void ResetBackward();
    // Initializes current position for an iteration
    //  through the list from last item to first item.

    void GetPriorItem(int& item, bool& finished);
    // Gets the previous item in the structure.
    //  finished is true if all the items have been accessed.

    void PutFront(int item);
    // Inserts item as the first item in the structure.

    void PutEnd(int item);
    // Inserts item as the last item in the structure.

    int GetLength();
    // Returns the number of items in the structure.
  private:
    NodeType* list;
    NodeType* currentNextPos;
    NodeType* currentBackPos;
    int length;
};
