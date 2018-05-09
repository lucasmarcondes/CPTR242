// copy.cpp
//
// This file contains the three Stack copy functions from the text.
//
// CopyStack is defined as if done by a user with StackType functions.
// A copy constructor is implemented.
// Copy is a friend of StackType so has access to private members.
//

// User defined Copy routine
template<class ItemType>
void CopyStack(StackType<ItemType> oldStack,
	       StackType<ItemType>& copy)
{
  StackType<ItemType> tempStack;
  ItemType item;
  while (!oldStack.IsEmpty())
  {
    oldStack.Pop(item);
    tempStack.Push(item);
  }
  // oldStack is now empty; tempStack is reverse of oldStack.
  while (!tempStack.IsEmpty())
  {
    tempStack.Pop(item);
    copy.Push(item);
  }
}

// Copy Constructor 
template <class ItemType>
StackType<ItemType>::StackType(const StackType<ItemType>&
			       anotherStack)
{
  NodeType<ItemType> * ptr1;
  NodeType<ItemType> * ptr2;
  if (anotherStack.topPtr == NULL)
    topPtr = NULL;
  else
  {
    topPtr = new NodeType<ItemType>;
    topPtr->info = anotherStack.topPtr->info;
    ptr1 = anotherStack.topPtr->next;
    ptr2 = topPtr;
    while (ptr1 != NULL)
    {
      ptr2->next = new NodeType<ItemType>;
      ptr2 = ptr2->next;
      ptr2->info = ptr1->info;
      ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
  }
}

// Copy routine is a friend of the class StackType so has access to
// private variables in the class
template<class ItemType>
void Copy(StackType<ItemType> original, StackType<ItemType>& copy)
{
  if (original.topPtr == NULL)
    copy.topPtr = NULL;
  else
  {
    NodeType<ItemType> * ptr1;
    NodeType<ItemType> * ptr2;
  
    copy.topPtr = new NodeType<ItemType>;
    copy.topPtr->info = original.topPtr->info;
    ptr1 = original.topPtr->next;
    ptr2 = copy.topPtr;
    while (ptr1 != NULL)
    {
      ptr2->next = new NodeType<ItemType>;
      ptr2 = ptr2->next;
      ptr2->info = ptr1->info;
      ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
  }
}


