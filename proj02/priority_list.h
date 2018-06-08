#ifndef PRIORITY_LIST_H
#define PRIORITY_LIST_H

#include "QueType.h"
#include "applicant.h"
#include <vector>

class PriorityList {
    public:
        PriorityList();
        QueType getQueue(int=0);
        Applicant deleteApplicant();
        Applicant getApplicant(Applicant, bool&);
        int allApplicants();
        void addApplicant(Applicant);
        void addApplicant(std::vector<Applicant>);
        void inputApplicant();
        void viewApplicants();

    private:
        QueType priority0;
        QueType priority1;
        QueType priority2;
        QueType priority3;
};

#endif // PRIORITY_LIST_H
