/****************************************************************************
 *
 * Howemork.06: Implement a two recursive functions on a linked unsorted list.
 *
 * File Name:  minSort.cpp
 * Name:       Lucas Marcondes
 * Course:     CPTR 242
 * Date:       5/23/18
 * Time Taken: ?
 *
 */
#include "ItemType.h"
#include "unsorted.h"

using namespace std;

NodeType* MinLoc(NodeType* list, NodeType*& minPtr)
{
    // TODO Add recursive MinLoc.
    if (list->info.ComparedTo(minPtr->info) == LESS)
        minPtr = list;
    if (list->next != NULL)
        return MinLoc(list->next, minPtr);

        return minPtr;
}

void Sort(NodeType* list)
{
    // TODO Add recursive sort method that uses MinLoc.

if (list->next == NULL)
{

}
else 
{

    ItemType tempItem;
    NodeType* x = list;
    x = MinLoc(list->next, x);

    tempItem = list->info;
    list->info = x->info;
    x->info = tempItem;

    Sort(list->next);
}
}
