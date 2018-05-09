#ifndef _NODETYPE_H
#define _NODETYPE_H

// A node used in a linked list.
template <typename T>
struct NodeType {
    T info;
    NodeType<T>* next;
};

#endif
