// These functions are made up until I make a header file/back them up with other code.
// Assumimg there are 4 lists: one for the wedded, another for 25+ students, another for regular students, and a list for all the applicants

//Tests the queue length of all the queues to see if it matches with the queue with all the applicants.
bool testQueueLength()
{
    if (priorityList1.getLength() + priorityList2.getLength() + priorityList3.getLength() != priorityList0.getLength)
        return false;
    else
        return true;
}

//compares the priority value (0-3) assigned to each applicant, and makes sure the applicant is in the correct list. This also checks the queue assignment test I had put in the test report.
bool testQueueOrder(QueueType* list, int priority)
{
    ItemType applicant = list.GetNextApplicant();
    if (priority == 1)
    {
        if (applicant.priority == 1)
            correctOrder(list->next, priority);
    }
    else   
        return false;
    else if (priority == 2)
    {
        if (applicant.priority == 2)
            correctOrder(list->next, priority)
    }
    else
        return false;
    else if (priority == 3)
    {
        if (applicant.priority == 3)
            correctOrder(list->next, priority)
    }
    else   
        return false;
}
//tests if the applicant was deleted correctly by comparing the new list with the old list
bool testQueueDelete(QueueType* list, ItemType item)
{
    QueueType* newList = list.remove(item);
    list.removeItem(item);

    if (newList.printList() == list.printList)
        return true;

    return false;
}

