//WAP to print student details like roll_no, name for 2 different students using a function called print_studentDetails.  Imagine doing it for 100 students. Do the same by passing an student object to the same function (print details). What problem did it solve.
#include <iostream>
using namespace std;

// Define structure
struct Student {
    int roll_no;
    string name;
};

// Function using object
void print_studentDetails(Student s) {
    cout << "Roll No: " << s.roll_no << ", Name: " << s.name << endl;
}

int main() {
    // Create student objects
    Student s1 = {1, "Ram"};
    Student s2 = {2, "Shyam"};

    print_studentDetails(s1);
    print_studentDetails(s2);

    return 0;
}

//✅ What problem does this solve?

//Using a student object (structure):

//Groups related data into one unit
//Reduces number of parameters in function
//Makes code clean and scalable
//Easy to handle 100+ students
//Easy to add more fields (age, address, marks) without changing function calls

//👉 In short:
//It improves code organization, readability, and scalability.
