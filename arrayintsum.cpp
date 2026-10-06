//Write a C++ program that initializes an array of integers and prints the sum of all the elements in the array.
#include <iostream>
using namespace std;

int main() {
    // Initialize array
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;

    // Calculate sum
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Display result
    cout << "Sum of array elements = " << sum << endl;

    return 0;
}
