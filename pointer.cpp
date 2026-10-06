//WAP to show pointer and its use
#include <iostream>
using namespace std;

int main() {
    int num = 10;      // normal variable
    int *ptr;          // pointer declaration

    ptr = &num;        // pointer stores address of num

    // Display values
    cout << "Value of num = " << num << endl;
    cout << "Address of num = " << &num << endl;

    cout << "Pointer ptr stores address = " << ptr << endl;
    cout << "Value at address (using pointer) = " << *ptr << endl;

    return 0;
}
