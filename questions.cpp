// ============================================================
// C++ OOP Assignment — All 10 Programs
// ============================================================


// ============================================================
// Q1. BOOK Class — Return Object with Lower Price
// ============================================================
// A class BOOK with name and price.
// A member function compares two BOOK objects and returns
// the one with the lower price.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class BOOK {
public:
    string name;
    float price;

    void getdata() {
        cout << "Enter book name: ";
        cin >> name;
        cout << "Enter book price: ";
        cin >> price;
    }

    void putdata() {
        cout << "Book: " << name << ", Price: " << price << endl;
    }

    // Member function: returns object with lower price
    BOOK lowerPrice(BOOK b1, BOOK b2) {
        return (b1.price < b2.price) ? b1 : b2;
    }
};

void q1_main() {
    BOOK b1, b2, result;
    cout << "\n--- Q1: BOOK Lower Price ---\n";
    cout << "Enter details for Book 1:\n"; b1.getdata();
    cout << "Enter details for Book 2:\n"; b2.getdata();
    result = result.lowerPrice(b1, b2);
    cout << "Book with lower price:\n";
    result.putdata();
}


// ============================================================
// Q2. Currency Conversion — Rupee <-> Dollar
// ============================================================
// Two classes Rupee and Dollar.
// Conversion operators convert between them.
// 1 Dollar = 133 Rupees
// ============================================================

class Dollar;  // Forward declaration

class Rupee {
    float amount;
public:
    Rupee(float a = 0) : amount(a) {}
    float getAmount() const { return amount; }

    // Convert Rupee -> Dollar
    operator Dollar();

    void display() {
        cout << "Rupees: " << amount << endl;
    }
};

class Dollar {
    float amount;
public:
    Dollar(float a = 0) : amount(a) {}
    float getAmount() const { return amount; }

    // Convert Dollar -> Rupee
    operator Rupee() {
        return Rupee(amount * 133);
    }

    void display() {
        cout << "Dollars: " << amount << endl;
    }
};

// Define after Dollar is fully declared
Rupee::operator Dollar() {
    return Dollar(amount / 133);
}

void q2_main() {
    cout << "\n--- Q2: Currency Conversion ---\n";
    int choice;
    cout << "Convert from: 1) Rupee->Dollar  2) Dollar->Rupee\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        float r;
        cout << "Enter amount in Rupees: "; cin >> r;
        Rupee rupee(r);
        Dollar dollar = (Dollar)rupee;
        rupee.display();
        dollar.display();
    } else {
        float d;
        cout << "Enter amount in Dollars: "; cin >> d;
        Dollar dollar(d);
        Rupee rupee = (Rupee)dollar;
        dollar.display();
        rupee.display();
    }
}


// ============================================================
// Q3. Constructor Demonstration
// ============================================================
// Demonstrates:
//   - Default constructor    : called when no arguments given
//   - Parameterized constructor: called with arguments
//   - Copy constructor       : called when one object copies another
//
// Constructor: special member function, same name as class,
//   no return type. Automatically called on object creation
//   to initialize data members.
//
// Destructor: special member function with ~ prefix.
//   Called automatically when object goes out of scope.
//   Used to release resources (memory, file handles, etc.)
// ============================================================

class Demo {
    int value;
    string label;
public:
    // Default constructor
    Demo() {
        value = 0;
        label = "default";
        cout << "[Default Constructor] value=" << value << endl;
    }

    // Parameterized constructor
    Demo(int v, string l) {
        value = v;
        label = l;
        cout << "[Parameterized Constructor] value=" << value
             << ", label=" << label << endl;
    }

    // Copy constructor
    Demo(const Demo &d) {
        value = d.value;
        label = d.label;
        cout << "[Copy Constructor] Copied value=" << value
             << ", label=" << label << endl;
    }

    void display() {
        cout << "Demo(" << label << ", " << value << ")" << endl;
    }

    // Destructor
    ~Demo() {
        cout << "[Destructor] Object '" << label << "' destroyed. Memory released.\n";
    }
};

void q3_main() {
    cout << "\n--- Q3: Constructor Demonstration ---\n";
    Demo d1;                    // default constructor
    Demo d2(42, "parameterized"); // parameterized constructor
    Demo d3(d2);                // copy constructor
    d1.display();
    d2.display();
    d3.display();
    // destructors called automatically at end of scope
}


// ============================================================
// Q4. Multilevel / Multiple Inheritance — Author, Publication, Book
// ============================================================
// Author   -> name, qualification
// Publication -> pname
// Book derives from BOTH Author and Publication (multiple inheritance)
//   and adds title, price
// Each class has getdata() and putdata().
// ============================================================

class Author {
public:
    string name, qualification;
    void getdata() {
        cout << "Author Name: "; cin >> name;
        cout << "Qualification: "; cin >> qualification;
    }
    void putdata() {
        cout << "Author: " << name << ", Qualification: " << qualification << endl;
    }
};

class Publication {
public:
    string pname;
    void getdata() {
        cout << "Publication Name: "; cin >> pname;
    }
    void putdata() {
        cout << "Publication: " << pname << endl;
    }
};

class BookInherited : public Author, public Publication {
public:
    string title;
    float price;
    void getdata() {
        Author::getdata();
        Publication::getdata();
        cout << "Book Title: "; cin >> title;
        cout << "Book Price: "; cin >> price;
    }
    void putdata() {
        Author::putdata();
        Publication::putdata();
        cout << "Title: " << title << ", Price: " << price << endl;
    }
};

void q4_main() {
    cout << "\n--- Q4: Multiple Inheritance (Author + Publication -> Book) ---\n";
    BookInherited b;
    b.getdata();
    cout << "\n--- Book Details ---\n";
    b.putdata();
}


// ============================================================
// Q5. Copy Constructor — Default vs Custom/Overloaded
// ============================================================
// Default copy constructor: performs a shallow (memberwise) copy.
// Custom copy constructor: allows deep copy or special logic.
// When a class has pointer members, default shallow copy can
// cause double-free bugs; custom copy constructor fixes this.
// ============================================================

class MyArray {
    int *data;
    int size;
public:
    // Parameterized constructor
    MyArray(int s) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = i * 10;
        cout << "[Constructor] Array created, size=" << size << endl;
    }

    // Custom (deep) copy constructor
    MyArray(const MyArray &other) {
        size = other.size;
        data = new int[size];          // allocate new memory
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];   // copy values
        cout << "[Custom Copy Constructor] Deep copy performed\n";
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }

    ~MyArray() {
        delete[] data;
        cout << "[Destructor] Array memory freed\n";
    }
};

class SimpleClass {
public:
    int x, y;
    SimpleClass(int a, int b) : x(a), y(b) {
        cout << "[Constructor] SimpleClass(" << x << ", " << y << ")\n";
    }
    // No custom copy constructor -> default memberwise copy is used
    void display() { cout << "x=" << x << ", y=" << y << endl; }
};

void q5_main() {
    cout << "\n--- Q5: Copy Constructor (Default vs Custom) ---\n";

    cout << "\n[Default copy constructor — SimpleClass]\n";
    SimpleClass s1(5, 10);
    SimpleClass s2 = s1;   // default copy constructor
    s1.display();
    s2.display();

    cout << "\n[Custom deep copy constructor — MyArray]\n";
    MyArray a1(4);
    MyArray a2 = a1;       // calls custom copy constructor
    a1.display();
    a2.display();
}


// ============================================================
// Q6. Student Object Input/Output
// ============================================================
// Class Student with sid, sname, level.
// Reads two student objects and displays their data.
// ============================================================

class Student {
public:
    int sid;
    string sname;
    string level;

    void getdata() {
        cout << "Student ID: "; cin >> sid;
        cout << "Student Name: "; cin >> sname;
        cout << "Level (UG/PG/PhD): "; cin >> level;
    }

    void putdata() {
        cout << "ID: " << sid
             << " | Name: " << sname
             << " | Level: " << level << endl;
    }
};

void q6_main() {
    cout << "\n--- Q6: Student Object Input/Output ---\n";
    Student s1, s2;
    cout << "Enter details for Student 1:\n"; s1.getdata();
    cout << "Enter details for Student 2:\n"; s2.getdata();
    cout << "\n--- Student Records ---\n";
    s1.putdata();
    s2.putdata();
}


// ============================================================
// Q7. Destructor Program
// ============================================================
// Demonstrates that destructor is called automatically when
// an object goes out of scope and prints "memory is released".
// ============================================================

class Resource {
    string name;
public:
    Resource(string n) : name(n) {
        cout << "Object '" << name << "' created.\n";
    }
    ~Resource() {
        cout << "memory is released (" << name << ")\n";
    }
};

void q7_main() {
    cout << "\n--- Q7: Destructor Demo ---\n";
    {
        Resource r1("R1");
        Resource r2("R2");
        cout << "Inside block — objects alive.\n";
        // r2 destroyed first (LIFO), then r1
    }
    cout << "Outside block — objects destroyed.\n";
}


// ============================================================
// Q8. new and delete Operators
// ============================================================
// Demonstrates dynamic memory allocation with new/delete.
//
// Advantages of new over malloc:
//   1. new calls the constructor automatically; malloc does not.
//   2. new is type-safe (no cast needed); malloc returns void*.
//   3. new throws std::bad_alloc on failure; malloc returns NULL.
//   4. delete calls the destructor; free() does not.
//   5. new/delete can be overloaded; malloc/free cannot.
// ============================================================

class Box {
public:
    int length, width;
    Box() : length(0), width(0) {
        cout << "[Box Constructor] Object created on heap\n";
    }
    Box(int l, int w) : length(l), width(w) {
        cout << "[Box Constructor] Box(" << l << "," << w << ") created\n";
    }
    int area() { return length * width; }
    ~Box() {
        cout << "[Box Destructor] Object deleted from heap\n";
    }
};

void q8_main() {
    cout << "\n--- Q8: new and delete Operators ---\n";

    // Single object
    Box *b1 = new Box(5, 3);
    cout << "Area = " << b1->area() << endl;
    delete b1;   // destructor called, memory freed

    // Array of objects
    cout << "\nAllocating array of 3 Box objects:\n";
    Box *arr = new Box[3];
    arr[0] = Box(2, 4);
    arr[1] = Box(6, 1);
    arr[2] = Box(3, 3);
    for (int i = 0; i < 3; i++)
        cout << "Box[" << i << "] area = " << arr[i].area() << endl;
    delete[] arr;   // delete array; calls destructor for each element
}


// ============================================================
// Q9. Multiple Inheritance — Teacher, Staff -> Coordinator
// ============================================================
// Teacher  : tid, subject
// Staff    : sid, position
// Coordinator (derived from both): department
// Two Coordinator objects are created, read, and displayed.
// ============================================================

class Teacher {
public:
    int tid;
    string subject;
    void readdata() {
        cout << "Teacher ID: "; cin >> tid;
        cout << "Subject: "; cin >> subject;
    }
    void displaydata() {
        cout << "Teacher ID: " << tid << ", Subject: " << subject << endl;
    }
};

class Staff {
public:
    int sid;
    string position;
    void readdata() {
        cout << "Staff ID: "; cin >> sid;
        cout << "Position: "; cin >> position;
    }
    void displaydata() {
        cout << "Staff ID: " << sid << ", Position: " << position << endl;
    }
};

class Coordinator : public Teacher, public Staff {
public:
    string department;
    void readdata() {
        Teacher::readdata();
        Staff::readdata();
        cout << "Department: "; cin >> department;
    }
    void displaydata() {
        Teacher::displaydata();
        Staff::displaydata();
        cout << "Department: " << department << endl;
    }
};

void q9_main() {
    cout << "\n--- Q9: Multiple Inheritance (Teacher + Staff -> Coordinator) ---\n";
    Coordinator c[2];
    for (int i = 0; i < 2; i++) {
        cout << "\nEnter details for Coordinator " << (i + 1) << ":\n";
        c[i].readdata();
    }
    for (int i = 0; i < 2; i++) {
        cout << "\n--- Coordinator " << (i + 1) << " ---\n";
        c[i].displaydata();
    }
}


// ============================================================
// Q10. Account Class with Static Member
// ============================================================
// Account: acc_no, balance, static min_balance
// Static member min_balance is shared by ALL objects.
// Static member function displays min_balance without an object.
// Array of 5 Account objects is created; each is read/displayed.
// ============================================================

class Account {
public:
    int acc_no;
    float balance;
    static float min_balance;   // shared across all objects

    void readdata() {
        cout << "Account Number: "; cin >> acc_no;
        cout << "Balance: "; cin >> balance;
    }

    void displaydata() {
        cout << "Acc No: " << acc_no
             << " | Balance: " << balance
             << " | Min Balance: " << min_balance << endl;
    }

    // Static member function — can only access static members
    static void showMinBalance() {
        cout << "Minimum Balance required: " << min_balance << endl;
    }
};

// Definition of static member outside class
float Account::min_balance = 1000.0f;

void q10_main() {
    cout << "\n--- Q10: Account Class with Static Member ---\n";
    Account::showMinBalance();   // called without any object

    Account acc[5];
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for Account " << (i + 1) << ":\n";
        acc[i].readdata();
    }
    cout << "\n--- All Account Records ---\n";
    for (int i = 0; i < 5; i++) {
        acc[i].displaydata();
    }
}


// ============================================================
// MAIN — Run all questions
// ============================================================

int main() {
    q1_main();
    q2_main();
    q3_main();
    q4_main();
    q5_main();
    q6_main();
    q7_main();
    q8_main();
    q9_main();
    q10_main();
    return 0;
}
