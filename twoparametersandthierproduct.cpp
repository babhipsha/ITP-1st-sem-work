//WAP that takes two parameters (integers) and returns their product. Write a program that uses this function to find and print the product of two numbers
#include <iostream>
using namespace std;

// Function to return product of two numbers
int multiply(int a, int b) {
    return a * b;
}

int main() {
    int num1 = 5, num2 = 4;

    // Function call
    int result = multiply(num1, num2);

    cout << "Product = " << result << endl;

    return 0;
}
