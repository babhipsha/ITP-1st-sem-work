//WAP that takes an array as an argument and prints their element. You can initialize this array on your own.
#include <iostream>
using namespace std;

// Function to print array elements
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Initialize array
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Call function
    printArray(numbers, size);

    return 0;
}
