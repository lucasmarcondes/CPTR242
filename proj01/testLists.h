#include "ItemType.h"
#include "SortedType.h"

using namespace std;

void mergeLists(SortedType list1, SortedType list2, SortedType& result);

void splitLists(SortedType list, ItemType item, SortedType& list1,
                SortedType& list2);

bool testMergeLists(SortedType list1, SortedType list2);

bool testSplitLists(SortedType list, ItemType item);