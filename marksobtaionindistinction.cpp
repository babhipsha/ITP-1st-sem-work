//WAP to classify grades of the marks obtained by a student >=10  pass >=40 && <60 = second, >= 60 && <70= first >= 70 is distinction
#include <iostream>
using namespace std;

int main() {
    int marks;

    cout << "Enter marks: ";
    cin >> marks;

    if (marks < 10) {
        cout << "Fail" << endl;
    }
    else if (marks >= 10 && marks < 40) {
        cout << "Pass" << endl;
    }
    else if (marks >= 40 && marks < 60) {
        cout << "Second Division" << endl;
    }
    else if (marks >= 60 && marks < 70) {
        cout << "First Division" << endl;
    }
    else if (marks >= 70) {
        cout << "Distinction" << endl;
    }

    return 0;
}
