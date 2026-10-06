//without object
// WAP to print student details like roll.no name for 2 different students using a function called print studentDetails. Imagine doing it for 100 students. Do the same by passing a student object to the same function(print details). What problem did it solve.
#include <iostream>
using namespace std;

void printStudentDetails(int roll, string name) {
    cout << "Roll No: " << roll << endl;
    cout << "Name: " << name << endl;
    cout << "-------------------" << endl;
}

int main() {
    // For 2 students
    printStudentDetails(1, "Ram");
    printStudentDetails(2, "Sita");

    return 0;
}

//with object
#include <iostream>
using namespace std;

// Define a structure (student object)
struct Student {
    int roll;
    string name;
};

// Function using object
void printStudentDetails(Student s) {
    cout << "Roll No: " << s.roll << endl;
    cout << "Name: " << s.name << endl;
    cout << "-------------------" << endl;
}

int main() {
    Student s1 = {1, "Ram"};
    Student s2 = {2, "Sita"};

    printStudentDetails(s1);
    printStudentDetails(s2);

    return 0;
}
