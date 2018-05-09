//
//  main.cpp
//  MergeSort
//
//  Created by Charles Weems on 1/12/16.
//  Copyright © 2016 Charles Weems. All rights reserved.
//

#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

const int MAX_ITEMS = 20000000;
int numbers[MAX_ITEMS];
int temp[MAX_ITEMS];

template <class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast, ItemType tempArray[])
// Post: values[leftFirst]..values[leftLast] and
//       values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] are now sorted.
{
    int index = leftFirst;
    int saveFirst = leftFirst;
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        if (values[leftFirst] < values[rightFirst]) {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        } else {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }
    while (leftFirst <= leftLast)
    // Copy remaining items from left half.
    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }
    while (rightFirst <= rightLast)
    // Copy remaining items from right half.
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }
    for (index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];
}

template <class ItemType>
void MergeSort(ItemType values[], int first, int last, ItemType tempArray[])
// Post: The elements in values are sorted by key.
{
    if (first < last) {
        int middle = (first + last) / 2;
        MergeSort<ItemType>(values, first, middle, tempArray);
        MergeSort<ItemType>(values, middle + 1, last, tempArray);
        Merge<ItemType>(values, first, middle, middle + 1, last, tempArray);
    }
}

int main(int argc, const char* argv[]) {
    chrono::time_point<chrono::system_clock> start;
    chrono::time_point<chrono::system_clock> end;

    // Initialize the array with random integers
    for (int index = 0; index < MAX_ITEMS; index++) {
        numbers[index] = rand() % 1000000000;
    }

    start = chrono::system_clock::now();  // Record start time

    MergeSort<int>(numbers, 0, MAX_ITEMS - 1, temp);  // Run the sort

    end = chrono::system_clock::now();  // Record end time

    chrono::duration<float> elapsed = end - start;  // Calculate and report time
    cout << "Execution time in seconds = " << elapsed.count() << "\n";

    return 0;
}
