Put #include "LargeInt.h"

    void
    Add(SpecializedList first, SpecializedList second, SpecializedList& result)
// Post:  result = first + second.
{
    int carry = 0;
    bool finished1 = false;
    bool finished2 = false;
    int temp;
    int digit1;
    int digit2;

    first.ResetBackward();
    second.ResetBackward();

    while (!finished1 && !finished2) {
        first.GetPriorItem(digit1, finished1);
        second.GetPriorItem(digit2, finished2);
        temp = digit1 + digit2 + carry;
        carry = temp / 10;
        result.PutFront(temp % 10);
    }
    while (!finished1) {  // Adds remaining digits (if any) in first to the sum.
        first.GetPriorItem(digit1, finished1);
        temp = digit1 + carry;
        carry = temp / 10;
        result.PutFront(temp % 10);
    }
    while (!finished2) {  // Adds remaining digits (if any) in second to the sum.
        second.GetPriorItem(digit2, finished2);
        temp = digit2 + carry;
        carry = temp / 10;
        result.PutFront(temp % 10);
    }
    if (carry != 0)  // Adds in carry (if any)
        result.PutFront(carry);
}

LargeInt LargeInt::operator+(LargeInt second)
// self is first operand
{
    SignType selfSign;
    SignType secondSign;
    LargeInt result;

    if (sign == second.sign) {
        Add(number, second.number, result.number);
        result.sign = sign;
    } else {
        selfSign = sign;
        secondSign = second.sign;
        sign = PLUS;
        second.sign = PLUS;
        if (*this < second) {
            Sub(second.number, number, result.number);
            result.sign = secondSign;
        } else if (second < *this) {
            Sub(number, second.number, result.number);
            result.sign = selfSign;
        }
        sign = selfSign;
    }
    return result;
}

enum RelationType { LESS, GREATER, EQUAL };
RelationType CompareDigits(SpecializedList first, SpecializedList second);

bool LargeInt::operator<(LargeInt second) {
    RelationType relation;

    if (sign == MINUS && second.sign == PLUS)
        return true;
    else if (sign == PLUS && second.sign == MINUS)
        return false;
    else if (sign == PLUS && numDigits < second.numDigits)
        return true;
    else if (sign == PLUS && numDigits > second.numDigits)
        return false;
    else if (sign == MINUS && numDigits > second.numDigits)
        return true;
    else if (sign == MINUS && numDigits < second.numDigits)
        return false;
    else  // Must compare digit by digit
    {
        relation = CompareDigits(number, second.number);
        if (sign == PLUS && relation == LESS)
            return true;
        else if (sign == PLUS && relation == GREATER)
            return false;
        else if (sign == MINUS && relation == GREATER)
            return true;
        else
            return false;
    }
}

RelationType CompareDigits(SpecializedList first, SpecializedList second) {
    bool same = true;
    bool finished = false;
    int digit1;
    int digit2;

    first.ResetForward();
    second.ResetForward();
    while (!finished) {
        first.GetNextItem(digit1, finished);
        second.GetNextItem(digit2, finished);
        if (digit1 < digit2)
            return LESS;
        if (digit1 > digit2)
            return GREATER;
    }
    return EQUAL;
}
