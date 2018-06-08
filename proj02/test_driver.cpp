#include "test_driver.h"

//compares the amount of applicants to the added applicants.
bool testQueueLength()
{
    Applicant a1 = Applicant("Han Solo", 30, false, 1);
    Applicant a2 = Applicant("Chewy", 234, false, 0);
    Applicant a3 = Applicant("Luke Skywalker", 15, true, 2);
    Applicant a4 = Applicant("Jar Jar Binks", 30, true, 0);
    PriorityList p = PriorityList();
    std::vector<Applicant> test;
    test.push_back(a1);
    test.push_back(a2);
    test.push_back(a3);
    test.push_back(a4);
    p.addApplicant(test);

    if (p.allApplicants() != 4)
        return false;
    else
        return true;
}

//tests if the applicant was deleted correctly deleting an applicant and checking if it is there
bool testQueueDelete()
{

    Applicant a1 = Applicant("Han Solo", 30, false, 1);
    Applicant a2 = Applicant("Chewy", 234, false, 0);
    Applicant a3 = Applicant("Luke Skywalker", 15, true, 2);
    Applicant a4 = Applicant("Jar Jar Binks", 30, true, 0);
    PriorityList l = PriorityList();
    std::vector<Applicant> test;
    test.push_back(a1);
    test.push_back(a2);
    test.push_back(a3);
    test.push_back(a4);
    l.addApplicant(test);

    bool found;
    bool found1;

    l.deleteApplicant();
    l.deleteApplicant();

    l.getApplicant(a2, found);
    l.getApplicant(a4, found1);

    if (found || found1)
    return false;

    return true;
}