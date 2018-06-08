#ifndef PROJ02_QUETYPE_H
#define PROJ02_QUETYPE_H

#include "applicant.h"

struct NodeType {
    Applicant applicant;
    NodeType *next;
};

class QueType {
public:
    QueType(int=0);
    void Enqueue(Applicant);
    Applicant Dequeue();
    int GetLength();
    void printQueue(int&);
    void setPriority(int);
    Applicant getApplicant(Applicant, bool&);

private:
    NodeType* front;
    NodeType* rear;
    int length;
    int priority;
};

#endif //PROJ02_QUETYPE_H
