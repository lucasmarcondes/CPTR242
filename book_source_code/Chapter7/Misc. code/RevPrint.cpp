#include <iostream>
template <class ItemType>
void RevPrint(NodeType<ItemType>* listPtr) {
    using namespace std;
    if (listPtr != NULL) {
        RevPrint(listPtr->next);
        cout << listPtr->info << endl;
    }
}
