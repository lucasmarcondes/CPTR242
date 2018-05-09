//
//  ItemType.cpp
//  MergeSort
//
//  Created by Charles Weems on 1/16/16.
//  Copyright © 2016 Charles Weems. All rights reserved.
//

#include "ItemType.hpp"

class ItemType {
  public:
    ItemType();
    ItemType(int value);
    bool operator<(ItemType second);
    ItemType& operator=(ItemType rhs);

  private:
    int item;
};

ItemType::ItemType(){};
ItemType::ItemType(int value) {
    item = value;
}

bool ItemType::operator<(ItemType second) {
    return item < second.item;
}

ItemType& ItemType::operator=(ItemType rhs) {
    item = rhs.item;
    return *this;
}
