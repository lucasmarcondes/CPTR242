// file: factorial.cpp
// recursive factorial

int Factorial(int number)
// Pre: number is nonnegative.
// Post: Function value = factorial of number.
{
    if (number == 0)  // line 1
        return 1;     // line 2
    else
        return number * Factorial(number - 1);  // line 3
}
