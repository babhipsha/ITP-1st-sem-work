//WAP that takes two parameters (integers) and returns their product. Write a program that uses this function to find and print the product of two numbers

#include <iostream>
using namespace std;

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    int result = multiply(num1, num2);

    cout << "Product = " << result << endl;

    return 0;
}
//important this question changing from multiplication ko satta ma sum ands all
\
