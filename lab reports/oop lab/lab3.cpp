// /*
// lab question 1:-

/*
 * Simplified C++ Program to manage departments and employees
 */

// #include <iostream>
// #include <string>
// using namespace std;

// const int MAX_EMP = 5;
// const int MAX_DEPT = 3;

// struct Employee {
//     int id;
//     string name;
//     string designation;
//     float salary;
// };

// struct Department {
//     string name;
//     Employee emp[MAX_EMP];
//     int totalEmp;
//     int head;
// };

// int main() {
//     Department dept[MAX_DEPT];

//     // INPUT
//     for (int i = 0; i < MAX_DEPT; i++) {

//         cout << "\n--- Department " << i + 1 << " ---\n";

//         cin.ignore();

//         cout << "Department name: ";
//         getline(cin, dept[i].name);

//         do {
//             cout << "Number of employees (1-5): ";
//             cin >> dept[i].totalEmp;
//         } while (dept[i].totalEmp < 1 || dept[i].totalEmp > MAX_EMP);

//         for (int j = 0; j < dept[i].totalEmp; j++) {

//             cout << "\nEmployee " << j + 1 << endl;

//             cout << "ID: ";
//             cin >> dept[i].emp[j].id;

//             cin.ignore();

//             cout << "Name: ";
//             getline(cin, dept[i].emp[j].name);

//             cout << "Designation: ";
//             getline(cin, dept[i].emp[j].designation);

//             cout << "Salary: ";
//             cin >> dept[i].emp[j].salary;
//         }

//         do {
//             cout << "Enter head index (0 to "
//                  << dept[i].totalEmp - 1 << "): ";
//             cin >> dept[i].head;
//         } while (dept[i].head < 0 || dept[i].head >= dept[i].totalEmp);
//     }

//     // DISPLAY
//     cout << "\n\n========== COMPANY DETAILS ==========\n";

//     for (int i = 0; i < MAX_DEPT; i++) {

//         cout << "\nDepartment: " << dept[i].name << endl;

//         for (int j = 0; j < dept[i].totalEmp; j++) {

//             cout << "ID: " << dept[i].emp[j].id
//                  << " | Name: " << dept[i].emp[j].name
//                  << " | Designation: " << dept[i].emp[j].designation
//                  << " | Salary: " << dept[i].emp[j].salary;

//             if (j == dept[i].head)
//                 cout << " <-- Department Head";

//             cout << endl;
//         }
//     }

//     return 0;
// }

//  * Lab Exercise 3 - Question 2
//  * Display only the names of department heads
//  */

// #include <iostream>
// #include <string>
// using namespace std;

// const int MAX_EMP = 5;
// const int MAX_DEPT = 3;

// struct Employee {
//     int id;
//     string name;
//     string designation;
//     float salary;
// };

// struct Department {
//     string name;
//     Employee emp[MAX_EMP];
//     int totalEmp;
//     int head;
// };

// int main() {

//     Department dept[MAX_DEPT];

//     // INPUT
//     for (int i = 0; i < MAX_DEPT; i++) {

//         cout << "\n--- Department " << i + 1 << " ---\n";

//         cin.ignore();

//         cout << "Department name: ";
//         getline(cin, dept[i].name);

//         // Number of employees
//         do {
//             cout << "Number of employees (1-5): ";
//             cin >> dept[i].totalEmp;
//         } while (dept[i].totalEmp < 1 || dept[i].totalEmp > MAX_EMP);

//         // Employee details
//         for (int j = 0; j < dept[i].totalEmp; j++) {

//             cout << "\nEmployee " << j + 1 << endl;

//             cout << "ID: ";
//             cin >> dept[i].emp[j].id;

//             cin.ignore();

//             cout << "Name: ";
//             getline(cin, dept[i].emp[j].name);

//             cout << "Designation: ";
//             getline(cin, dept[i].emp[j].designation);

//             cout << "Salary: ";
//             cin >> dept[i].emp[j].salary;
//         }

//         // Department head index
//         do {
//             cout << "Enter head index (0 to "
//                  << dept[i].totalEmp - 1 << "): ";
//             cin >> dept[i].head;

//         } while (dept[i].head < 0 || dept[i].head >= dept[i].totalEmp);
//     }

//     // DISPLAY ONLY HEAD NAMES
//     cout << "\n\n===== DEPARTMENT HEADS =====\n";

//     for (int i = 0; i < MAX_DEPT; i++) {

//         cout << "Department: " << dept[i].name << endl;

//         cout << "Head: "
//              << dept[i].emp[dept[i].head].name
//              << endl << endl;
//     }

//     return 0;
// }


//lab question 3:-
/*
 * Program to store and display details
 * of 3 bank account holders using class
 */

#include <iostream>
#include <string>
using namespace std;

class Account {

private:
    int accountNo;
    string accountHolderName;
    float balance;

public:

    // Method to store values
    void store() {

        cout << "\nEnter Account Number: ";
        cin >> accountNo;

        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolderName);

        cout << "Enter Balance: ";
        cin >> balance;
    }

    // Method to display values
    void display() {

        cout << "\nAccount Number: " << accountNo << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {

    Account customer[3];

    // Store details
    for (int i = 0; i < 3; i++) {

        cout << "\n--- Customer " << i + 1 << " ---";
        customer[i].store();
    }

    // Display details
    cout << "\n\n===== CUSTOMER DETAILS =====\n";

    for (int i = 0; i < 3; i++) {

        cout << "\n--- Customer " << i + 1 << " ---";
        customer[i].display();
    }

    return 0;
}