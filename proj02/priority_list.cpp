#include "priority_list.h"
#include "applicant.h"

PriorityList::PriorityList() {
    priority0 = QueType(0);
    priority1 = QueType(1);
    priority2 = QueType(2);
    priority3 = QueType(3);
}

QueType PriorityList::getQueue(int i) {
    
    switch (i) {
        case 1:
            return priority1;
            break;
        case 2:
            return priority2;
            break;
        case 3:
            return priority3;
            break;
    }

    return priority0;
}

void PriorityList::viewApplicants() {
    QueType display[] = {priority3, priority2, priority1, priority0};
    int count = 1;

    for (int i = 0; i < 4; i++) {
        display[i].printQueue(count);
    }
}

void PriorityList::addApplicant(Applicant item) {
    int priority = item.getPriority();

    switch (priority) {
        case 0:
            priority0.Enqueue(item);
            break;
        case 1:
            priority1.Enqueue(item);
            break;
        case 2:
            priority2.Enqueue(item);
            break;
        case 3:
            priority3.Enqueue(item);
            break;
    }
}

void PriorityList::addApplicant(vector<Applicant> item) {
    for (int i = 0; i < item.size(); i++) {
        int priority = item[i].getPriority();

        switch (priority) {
            case 0:
                priority0.Enqueue(item[i]);
                break;
            case 1:
                priority1.Enqueue(item[i]);
                break;
            case 2:
                priority2.Enqueue(item[i]);
                break;
            case 3:
                priority3.Enqueue(item[i]);
                break;
        }
    }
}

Applicant PriorityList::deleteApplicant() {
    if (priority3.GetLength() != 0) {
        return priority3.Dequeue();
    } else if (priority2.GetLength() != 0) {
        return priority2.Dequeue();
    } else if (priority1.GetLength() != 0) {
        return priority1.Dequeue();
    } else if (priority0.GetLength() != 0) {
        return priority0.Dequeue();
    }

    Applicant item = Applicant();

    return item;
}

Applicant PriorityList::getApplicant(Applicant item, bool& found) {
    int priority = item.getPriority();

    switch (priority) {
        case 0:
            return priority0.getApplicant(item, found);
            break;
        case 1:
            return priority1.getApplicant(item, found);
            break;
        case 2:
            return priority2.getApplicant(item, found);
            break;
        case 3:
            return priority3.getApplicant(item, found);
            break;
        default:
            found = false;
            return Applicant();
    }
}

int PriorityList::allApplicants() {
    int total = 0;
    total += priority0.GetLength();
    total += priority1.GetLength();
    total += priority2.GetLength();
    total += priority3.GetLength();

    return total;    
}

void PriorityList::inputApplicant() {
    string first = "";
    string last = "";
    int age = 0;
    char married = ' ';
    int children = 0;

    cout << "To sign up for the wait-list, fill in the following information:\n";
    cout << "First name: ";
    cin >> first;
    cout << "\nLast name: ";
    cin >> last;
    cout << "\nAge: ";
    cin >> age;
    cout << "\nAre you married? (y/n): ";
    cin >> married;
    cout << "\nHow many children do you have?: ";
    cin >> children;


    if (married == 'y', 'Y') {
        bool isMarried = true;
    } else {
         bool isMarried = false;
    }


    addApplicant(Applicant(first + " " + last, age, married, children));
}

