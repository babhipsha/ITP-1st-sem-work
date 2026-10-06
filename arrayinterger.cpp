//Write a C++ program that initializes an array of integers and prints the sum of all the elements in the array.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    cout << "Sum of array elements = " << sum << endl;

    return 0;
}
//important
