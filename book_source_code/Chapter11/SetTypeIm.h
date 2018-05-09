#include "map.h"
// Specification for SetType using implicit representation.
// Requires a list ADT of some sort.
class SetType {
  public:
    SetType();                          // Default constructor: Array size is 400.
    SetType(int max);                   // Paramaterized constructor
    ~SetType();                         // Destructor
    SetType(const SetType anotherSet);  // Copy constructor
    void MakeEmpty();
    void Store(ItemType item);
    void Delete(ItemType item);
    bool IsEmpty();
    bool IsFull();
    int CardinalityIs();
    SetType Union(SetType setB);
    SetType Intersection(SetType setB);
    SetType Difference(SetType setB);
    void Print(std::ofstream& outFile);

  private:
    ListType items;  // A list ADT
};
