#include "map.h"
// Specification for SetType using explicit representation.
// File map.h must include a definition of ItemType and a function
//  named "map" that maps an item of ItemType into an index between
//  0 and max - 1 if the parameterized constructor is used and
//  between 0 and 399 if the default constructor is used.
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
    int maxItems;
    ItemType* items;
};
