/****************************************************************************
 *
 * Howemork.08: Implement ReheapDown and ReheapUp functions using iteratation.
 *
 * File Name:  reheap.tpp
 * Name:       Lucas Marcondes
 * Course:     CPTR 242
 * Date:       6/8/18
 *
 */
 #include "Heap.h"

using namespace std;

template <class ItemType>
void HeapType<ItemType>::ReheapDownIterative(int root, int bottom) {
    int max;
    int right;
    int left;
    bool check = false;

    while ((root * 2 + 1 <= bottom) && !check) {
        left = root * 2 + 1;
        right = root * 2 + 2;
        if (left == bottom)
            max = left;
        else {
            if (elements[left] <= elements[right]) {
                max = right;
            } else {
                max = left;
            }
        }
        if (elements[root] < elements[max]) {
            Swap(elements[root], elements[max]);
        } else {
            check = true;
        }
    }
}

template <class ItemType>
void HeapType<ItemType>::ReheapUpIterative(int root, int bottom) {
    int Parent;
    bool check = false;

    while (bottom > root && !check) {
        Parent = (bottom - 1) / 2;
        if (elements[Parent] < elements[bottom]) {
            Swap(elements[Parent], elements[bottom]);
            bottom = Parent;
        } else {
            check = true;
        }
    }
}
