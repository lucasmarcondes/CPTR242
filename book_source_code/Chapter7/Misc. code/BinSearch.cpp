
// file: binsrch.cpp
//
template <class ItemType>
bool BinarySearch(ItemType info[], ItemType item, int fromLocation, int toLocation) {
    if (fromLocation > toLocation)  // Base case 1
        return false;
    else {
        int midPoint;
        midPoint = (fromLocation + toLocation) / 2;
        if (item < info[midPoint])
            return BinarySearch(info, item, fromLocation, midPoint - 1);
        else if (item == info[midPoint])
            return true;
        else
            return BinarySearch(info, item, midPoint + 1, toLocation);
    }
}
