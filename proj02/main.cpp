#include "test_driver.h"
#include <iostream>

using namespace std;

void viewWaitlist(PriorityList* p) {
    p->viewApplicants();
}

int main() {

       //UI
    bool display = true;
    PriorityList* waitingList = new PriorityList();
    PriorityList *l;
    int input;

        cout << "Village Housing Main Menu\n\n";
        cout << "1 - Enqueue Applicants\n";
        cout << "2 - Dequeue Applicants\n";
        cout << "3 - Search For Applicants\n";
        cout << "4 - Display Waiting List\n";
        cout << "5 - Run Queue Tests\n";
        cout << "0 - Quit\n";

        cin >> input;

    while(display){
        switch (input) {
            case 1:
                l->inputApplicant();
                break;
            case 2:
                if (waitingList->allApplicants() == 0)
                    cout << "There are currently no applicants in the waiting list.\n";
                else
                    l->deleteApplicant();
                break;
            case 3: {
                string first;
                string last;
                bool found;
                Applicant a = l->getApplicant(first + " " + last, found);

                cout << "Please enter the first name of the applicant: \n";
                cin >> first;
                cout << "Please enter s1the last name of the applicant: \n";
                cin >> last;
                if (found)
                    a.displayApplicant();
                else
                    cout << "Applicant not found.\n";
                break;
            }
            case 4: {
                if (waitingList->allApplicants() == 0)
                    cout << "There are currently no applicants in the waiting list.\n";
                else
                    viewWaitlist(waitingList);
                break;
                case 5:
                    bool correctLength = testQueueLength();
                bool correctDelete = testQueueDelete();

                if (!correctLength)
                    cout << "Error: Incorrect queue length\n";

                if (!correctDelete)
                    cout << "Error: Failure to fully delete queue item\n";

                if (correctDelete && correctLength)
                    cout << "Tests passed Correctly.\n";
                break;
            }
            case 0:
                display = false;
                break;
        }
    }
    return 0;
}


