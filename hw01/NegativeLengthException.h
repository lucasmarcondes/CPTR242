/*************************************************************************
 *
 * Exception to be used in HW01 for CPTR 242.
 * 
 * File Name:  NegativeLengthException.h
 * Course:     CPTR 242
 * 
 * Provided code...
 */
#ifndef NEGATIVE_LENGTH_EXCEPTION_H
#define NEGATIVE_LENGTH_EXCEPTION_H

#include <iostream>
using namespace std;


class NegativeLengthException: public exception {
    public:
        virtual const char* what() const throw() {
            return "Negative Length";
        }
};

#endif // NEGATIVE_LENGTH_EXCEPTION_H