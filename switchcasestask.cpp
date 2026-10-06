#include <iostream>
using namespace std;
int main() {
    int choice;
    char cont;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Create\n";
        cout << "2. Delete\n";
        cout << "3. View\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Create task selected.\n";
                break;

            case 2:
                cout << "Delete task selected.\n";
                break;

            case 3:
                cout << "View task selected.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

        cout << "\nDo you want to continue? (y/Y): ";
        cin >> cont;

    } while(cont == 'y' || cont == 'Y');

    cout << "Program ended.\n";

    return 0;
}
