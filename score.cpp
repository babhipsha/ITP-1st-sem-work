#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "Enter your score: ";
    cin >> score;

    if (score >= 90) {
        cout << "You got an A! 🎉";
    }
    else if (score >= 80) {
        cout << "You got a B! 👏";
    }
    else if (score >= 70) {
        cout << "You got a C! 👍";
    }
    else {
        cout << "Keep practicing!";
    }

    return 0;
}
