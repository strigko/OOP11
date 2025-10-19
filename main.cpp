#include "PrinterQueue.h"
#include <iostream>
using namespace std;
#include <string>
#include "PrintStat.h"

string getCurrentTime() {
    time_t now = time(nullptr);
    tm ltm{};
    localtime_s(&ltm, &now);
    char buf[32];
    strftime(buf, sizeof(buf), "%H:%M:%S", &ltm);
    return buf;
}

int main() {
	PrinterQueue<string, int> printQueue(10);
	PrinterQueue<PrintStat, int> statsQueue(20);
    int choice;

    while (true) {
        cout << "Menu" << endl;
        cout << "1. Append to the queue: \n";
        cout << "2. Extract one: \n";
        cout << "3. Show the queue: \n";
        cout << "4. Show the stats: \n";
        cout << "0. Exit: \n";
        cin >> choice;
        switch (choice) {
        case 1: {
            string user;
            int priority;
            cout << "Enter user`s name: ";
            cin >> user;
            cout << "Enter it`s priority: ";
            cin >> priority;
            printQueue.Add(user, priority);
            cout << "Success!\n";
            break;
        }
        case 2: {
            if (!printQueue.isEmpty()){
            string user = printQueue.Extract();
            PrintStat st;
            st.user = user;
            st.time = getCurrentTime();
            statsQueue.Add(st, 0);
            }
            else {
                cout << "The queue is empty!";
            }
            break;
        }
        case 3: {
            cout << "Current print queue: \n";
            printQueue.Print();
            break;
        }
        case 4: {
            cout << "\nStats of printing:\n";
            if (statsQueue.isEmpty()) {
                cout << "No data rn\n";
            }
            else {
                statsQueue.Print();
            }
            break;
        case 0:
            cout << "Ty for using!\n";
            break;
        default:
            cout << "Incorrect choice\n";
        }
        }
    }
}