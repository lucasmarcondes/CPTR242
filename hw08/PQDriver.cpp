// Test driver
#include <fstream>
#include <iostream>
typedef int ItemType;
#include "PQType.h"

using namespace std;

int main() {
    ifstream inFile;     // file containing operations
    ofstream outFile;    // file containing output
    string inFileName;   // input file external name
    string outFileName;  // output file external name
    string outputLabel;
    string command;  // operation to be executed

    ItemType item;
    PQType<int> queue(5);
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
        try {
            if (command == "Enqueue") {
                inFile >> item;
                queue.Enqueue(item);
                outFile << item << " is enqueued." << endl;
            } else if (command == "Dequeue") {
                queue.Dequeue(item);
                outFile << item << " is dequeued." << endl;
            }  else          if (command == "EnqueueIterative") {
                inFile >> item;
                queue.EnqueueIterative(item);
                outFile << item << " is enqueued (iterative)." << endl;
            } else if (command == "DequeueIterative") {
                queue.DequeueIterative(item);
                outFile << item << " is dequeued (iterative)." << endl;
            } else if (command == "IsEmpty")
                if (queue.IsEmpty())
                    outFile << "Queue is empty." << endl;
                else
                    outFile << "Queue is not empty." << endl;

            else if (command == "IsFull")
                if (queue.IsFull())
                    outFile << "Queue is full." << endl;
                else
                    outFile << "Queue is not full." << endl;
            else if (command == "MakeEmpty")
                queue.MakeEmpty();
        } catch (FullPQ) {
            outFile << "FullQueue exception thrown." << endl;
        }

        catch (EmptyPQ) {
            outFile << "EmtpyQueue exception thrown." << endl;
        }
        numCommands++;
        cout << " Command number " << numCommands << " completed." << endl;
        inFile >> command;
    };

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}
