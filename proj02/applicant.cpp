#include "applicant.h"

Applicant::Applicant(string n, int a, bool m, int c) {
    name = n;
    age = a;
    isMarried = m;
    hasChildren = c;
}

void Applicant::setName(string n) {
    name = n;
}

void Applicant::setAge(int a) {
    age = a;
}

void Applicant::setMarried(bool m) {
    isMarried = m;
}

void Applicant::setChildren(int c) {
    hasChildren = c;
}

std::string Applicant::getName() {
    return name;
}

int Applicant::getAge() {
    return age;
}

bool Applicant::getMarried() {
    return isMarried;
}

int Applicant::getChildren() {
    return hasChildren;
}

int Applicant::getPriority() {
    int priority = 0;
    if (getChildren() > 0) {
        priority ++;
    }
    if (getAge() >= 25) {
        priority ++;
    }
    if (isMarried) {
        priority ++;
    }

    return priority;
}

void Applicant::displayApplicant(){
    cout << "\nName: " + getName() << endl;
    cout << "Age: " + to_string(getAge()) << endl;
    if (isMarried)
        cout << "Relationship Status: Married";
    else
        cout << "Relationship Status: Single";
}
