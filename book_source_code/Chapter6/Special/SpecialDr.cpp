// Test driver
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "SpecializedList.h"

using namespace std;

int main() {
    ifstream inFile;     // file containing operations
    ofstream outFile;    // file containing output
    string inFileName;   // input file external name
    string outFileName;  // output file external name
    string outputLabel;
    string command;  // operation to be executed
    bool finished;

    int item;
    SpecializedList list;
    int numCommands;

    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
    outFile << outputLabel << endl;

    inFile >> command;

    numCommands = 0;
    while (command != "Quit") {
        outFile << command << endl;
        if (command == "PutFront") {
            inFile >> item;
            list.PutFront(item);
            outFile << item;
            outFile << " is put at the front" << endl;
        } else if (command == "PutEnd") {
            inFile >> item;
            list.PutEnd(item);
            outFile << item;
            outFile << " is put at the end" << endl;
        } else if (command == "ResetBackward")
            list.ResetBackward();
        else if (command == "ResetForward")
            list.ResetForward();
        else if (command == "GetNextItem") {
            list.GetNextItem(item, finished);
            outFile << "Next item is " << item << endl;
            if (finished)
                outFile << "Last item in the list returned." << endl;
        }

        else if (command == "GetPriorItem") {
            list.GetPriorItem(item, finished);
            outFile << "Prior item is " << item << endl;
            if (finished)
                outFile << "First item in the list returned." << endl;
        } else if (command == "GetLength")
            outFile << "Length is " << list.GetLength() << endl;
        else
            outFile << command << " is not found" << endl;

        numCommands++;
        cout << " Command number " << numCommands << " completed." << endl;
        inFile >> command;
    }

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}
