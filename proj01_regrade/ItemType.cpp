// The following definitions go into file ItemType.cpp.
#include "ItemType.h"
#include <fstream>
#include <iostream>

using namespace std;

ItemType::ItemType() {
    value = 0;
}

ItemType::ItemType(int number) {
    value = number;
}

ItemType::ItemType(const ItemType &it) {
    value = it.value;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const {
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else
        return EQUAL;
}

void ItemType::Initialize(int number) {
    value = number;
}

void ItemType::Print(std::ostream &out) const {
    // pre:  out has been opened.
    // post: value has been sent to the stream out.
    out << value;
}
