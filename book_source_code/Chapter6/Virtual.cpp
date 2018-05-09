#include <iostream>
class One {
  public:
    virtual void Print();
};

class Two : public One {
  public:
    void Print();
};

void PrintTest(One*);

int main() {
    using namespace std;
    One* onePtr;
    onePtr = new One;

    cout << "Result of passing an object of class One: " << endl;
    PrintTest(onePtr);

    onePtr = new Two;

    cout << "Result of passing an object of class Two: " << endl;

    PrintTest(onePtr);
    return 0;
}

void PrintTest(One* ptr) {
    ptr->Print();
}

void One::Print() {
    std::cout << "Print member function of class One" << std::endl;
}

void Two::Print() {
    std::cout << "Print member function of class Two " << std::endl;
}
