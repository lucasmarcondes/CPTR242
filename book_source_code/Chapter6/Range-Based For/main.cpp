#include <iostream>

#include "SortedType.h"

using namespace std;

int main() {
    cout << "List 1 Example" << endl;
    SortedType<int> list;

    list.PutItem(99);
    list.PutItem(12);
    list.PutItem(10);
    list.PutItem(9);
    list.PutItem(8);
    list.PutItem(7);
    list.PutItem(6);
    list.PutItem(5);
    list.PutItem(-1);

    for (int& x : list) {
        cout << x << endl;
    }

    cout << "List 2 Example" << endl;
    SortedType<int*> list2;
    int x = 10;
    int y = 1;
    list2.PutItem(&x);
    list2.PutItem(&y);

    for (int* v : list2) {
        cout << *v << endl;
    }

    cout << "Hello, World!" << endl;
    return 0;
}