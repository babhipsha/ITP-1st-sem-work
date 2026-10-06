#include <iostream>
using namespace std;

int main() {
    int guess;

    do {
        cout << "Guess the secret number: ";
        cin >> guess;

        if (guess == 7) {
            cout << "Correct! You guessed it!" << endl;
        } else {
            cout << "Wrong guess. Try again!" << endl;
        }

    } while (guess != 7);

    return 0;
}
