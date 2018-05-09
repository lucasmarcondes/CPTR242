// file: revpr2.cpp
// Non recursive version -- stacks

#include "Stack3.h"
void ListType::RevPrint() {
    StackType<NodeType*> stack;
    NodeType* listPtr;
    listPtr = listData;
    while (listPtr != NULL)  // Put pointers onto the stack.
    {
        stack.Push(listPtr);
        listPtr = listPtr->next;
    }
    // Retrieve pointers in reverse order and print elements.
    while (!stack.IsEmpty()) {
        stack.Pop(listPtr);
        cout << listPtr->info;
    }
}
