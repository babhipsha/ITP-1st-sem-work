#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 10) {
        cout << "Welcome to the club!";
    } else {
        cout << "Sorry, come back when you're older!";
    }

    return 0;
}
