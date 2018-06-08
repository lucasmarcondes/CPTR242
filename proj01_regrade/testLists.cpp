#include "testLists.h"
#include "ItemType.h"
#include "ListType.h"

bool testMergeLists(ListType list1, ListType list2) {

    ListType result;
    mergeLists(list1, list2, result);

    if ((list1.GetLength() + list2.GetLength()) != result.GetLength())
        return false;

    ItemType item;
    bool found;

    for (int i = 0; i < list1.GetLength(); i++)
    {
        item = list1.GetNextItem();
        result.GetItem(item, found);

        if (!found)
            return false;
    }

    for (int i = 0; i < list2.GetLength(); i++)
    {
        item = list2.GetNextItem();
        result.GetItem(item, found);

        if (!found)
            return false;
    }
    return true;
}

bool testSplitLists(ListType list, ItemType item) {

    ListType list1, list2;
    splitLists(list, item, list1, list2);

    ItemType item2;
    bool found1;
    bool found2;

    for (int i = 0; i < list.GetLength(); i++)
    {
        item2 = list.GetNextItem();
        list1.GetItem(item2, found1);
        list2.GetItem(item2, found2);

        if (!found1 || !found2)
            return false;
    }

    bool found3;

    for (int i = 0; i < list1.GetLength(); i++)
    {
        item2 = list1.GetNextItem();
        list.GetItem(item2, found3);

        if (!found3)
            return false;
    }

    for (int i = 0; i < list2.GetLength(); i++)
    {
        item2 = list2.GetNextItem();
        list.GetItem(item2, found3);

        if (!found3)
            return false;
    }



    ItemType thing;
    int size = -1;

    do
    {
        size++;
        thing = list.GetNextItem();
    }

    while (thing.ComparedTo(item) == LESS);

    int size2 = list.GetLength() - size;

    if (size2 != list2.GetLength())
        return false;

    if (size != list1.GetLength())
        return false;

    return true;
}
