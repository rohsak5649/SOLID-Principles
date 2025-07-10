// 🚫 Bad Example (Violates SRP) 

#include <iostream>
using namespace std;

class Student {
public:
    string name;

    void study() {
        cout << name << " is studying." << endl;
    }

    void payFees() {
        cout << name << " is paying fees." << endl;
    }

    void playSports() {
        cout << name << " is playing sports." << endl;
    }
};

int main() {
    Student s;
    s.name = "Rohan";
    s.study();
    s.payFees();
    s.playSports();
    return 0;
}

//✅ Good Example (Follows SRP)

#include <iostream>
#include <fstream>
using namespace std;

// 1. Class to hold data (Single responsibility)
class Student {
public:
    string name;
    int marks;

    Student(string n, int m) {
        name = n;
        marks = m;
    }
};

// 2. Class to handle printing
class ReportPrinter {
public:
    void print(Student s) {
        cout << "Student: " << s.name << ", Marks: " << s.marks << endl;
    }
};

// 3. Class to handle saving
class FileSaver {
public:
    void save(Student s) {
        ofstream file("student.txt");
        file << s.name << " " << s.marks;
        file.close();
    }
};

int main() {
    Student s("Rohan", 95);
    ReportPrinter printer;
    FileSaver saver;

    printer.print(s);
    saver.save(s);

    cout << "Student data saved to student.txt" << endl;
    return 0;
}

