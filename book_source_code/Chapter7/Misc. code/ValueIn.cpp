bool ValueInList(ListType list, int value, int startIndex) {
    if (list.info[startIndex] == value)
        return true;  // Base case 1
    else if (startIndex == list.length - 1)
        return false;  // Base case 2
    else
        return ValueInList(list, value, startIndex + 1);
}
