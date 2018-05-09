bool ValueInList(ListType list, int value, int startIndex) {
    if (list.info[startIndex] == value)
        return true;
    else if (startIndex != list.length - 1)
        return ValueInList(list, value, startIndex + 1);
    else
        return false;
}
