#include "QueType.h"

QueType::QueType(int p)
{
    front = NULL;
    rear = NULL;
    priority = p;
    length = 0;
}

void QueType::Enqueue(Applicant item)
{
        NodeType* newNode;
        newNode = new NodeType;
        newNode->applicant = item;
        newNode->next = NULL;
        if (length == 0) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
        }
        rear = newNode;

    length ++;
}

Applicant QueType::Dequeue()
{
        NodeType* tempPtr;
        tempPtr = front;
        Applicant item;
        item = front->applicant;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tempPtr;

        length --;

        return item;
}

int QueType::GetLength() {
    return length;
}

void QueType::setPriority(int p) {
    priority = p;
}

void QueType::printQueue(int &num) {
    NodeType* ptr = new NodeType;
    ptr = front;

    while (ptr != NULL) {
        cout << "APPLICANT " + to_string(num) << std::endl;
        ptr->applicant.displayApplicant();
        ptr = ptr->next;
        num ++;
    }
}

Applicant QueType::getApplicant(Applicant item, bool& found) {
    NodeType* tempPtr = front;
    while(front != NULL){
        if(front->item.getName() != applicant.getName())
        {
            found = true;
            return front->applicant;
        }
        front = front->next;
    }
    found = front;
    front = tempPtr;

    return Applicant();
}