/****************************************************************************
 *
 * File Name:  minSort.h
 * Course:     CPTR 242
 * Source:     Homework.06
 *
 */
#ifndef MIN_SORT_H
#define MIN_SORT_H

#include "unsorted.h"

using namespace std;

NodeType* MinLoc(NodeType* list, NodeType*& minPtr);

void Sort(NodeType* list);

#endif