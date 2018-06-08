#ifndef APPLICANT_H
#define APPLICANT_H

#include <iostream>
#include <string>

using namespace std;

class Applicant {

    private:
        string name;
        int age;
        bool hasChildren;
        bool isMarried;

    public:
        Applicant(string = "", int = 18, bool = false, int = -1);

    void displayApplicant();
    void setName(string n);
    void setAge(int a);
    void setMarried(bool m);
    void setChildren(int c);

    string getName();
    int getAge();
    bool getMarried();
    int getChildren();
    int getPriority();
};

#endif // APPLICANT_H