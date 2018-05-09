// This file contains the coded functions from the text.
// The implementations are incomplete.

#include <fstream>
#include "SpecializedList.h"  // Gain access to SpecializedList
enum SignType { PLUS, MINUS };

class LargeInt {
  public:
    LargeInt();
    bool operator<(LargeInt second);
    bool operator==(LargeInt second);
    LargeInt operator+(LargeInt second);
    LargeInt operator-(LargeInt second);
    void InsertDigit(int);
    void Write(std::ofstream&);

  private:
    SpecializedList number;
    SignType sign;
    int numDigits;
};
