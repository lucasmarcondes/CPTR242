#include "SpecializedList.h"
struct NodeType {
    NodeType* next;
    NodeType* back;
    int info;
};

SpecializedList::SpecializedList() {
    length = 0;
    list = NULL;
}

void SpecializedList::ResetForward()
// Post: currentNextPos has been initialized for a forward
//       traversal.
{
    currentNextPos = NULL;
}

void SpecializedList::GetNextItem(int& item, bool& finished)
// Pre:  ResetForward has been called before the first call to
//       this function.
// Post: item is a copy of the next item in the list.
//       finished is true if item is the last item in the list;
//       false otherwise.
{
    if (currentNextPos == NULL)
        currentNextPos = list->next;
    else
        currentNextPos = currentNextPos->next;
    item = currentNextPos->info;
    finished = (currentNextPos == list);
}

void SpecializedList::ResetBackward()
// Post: currentBackPos has been initialized for a backward
//       traversal.
{
    currentBackPos = NULL;
}

void SpecializedList::GetPriorItem(int& item, bool& finished)
// Post: item is a copy of the previous item in the list.
//       finished is true if item is the first item in the list;
//       false otherwise.
{
    if (currentBackPos == NULL)
        currentBackPos = list;
    else
        currentBackPos = currentBackPos->back;
    item = currentBackPos->info;
    finished = (currentBackPos == list->next);
}

void SpecializedList::PutFront(int item)
// Post: item has been inserted at the front of the list.
{
    NodeType* newNode;

    newNode = new NodeType;
    newNode->info = item;
    if (list == NULL) {  // list is empty.
        newNode->back = newNode;
        newNode->next = newNode;
        list = newNode;
    } else {
        newNode->back = list;
        newNode->next = list->next;
        list->next->back = newNode;
        list->next = newNode;
    }
    length++;
}

void SpecializedList::PutEnd(int item)
// Post: item has been inserted at the end of the list.
{
    PutFront(item);
    list = list->next;
}
