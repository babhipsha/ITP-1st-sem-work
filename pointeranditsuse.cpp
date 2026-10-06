//WAP to show pointer and its use
#include <iostream>
using namespace std;

int main() {
    int num = 10;        // normal variable
    int *ptr;            // pointer declaration

    ptr = &num;          // storing address of num in pointer

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;

    cout << "Pointer ptr stores address: " << ptr << endl;
    cout << "Value using pointer (*ptr): " << *ptr << endl;

    // modifying value using pointer
    *ptr = 20;

    cout << "New value of num after modification: " << num << endl;

    return 0;
}
