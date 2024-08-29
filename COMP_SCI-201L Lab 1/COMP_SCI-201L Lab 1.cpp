#include <iostream>
using namespace std;

int main() {
    int guess = 0;
    char answer = 'y';

    srand(time(0));

    int solution = rand() % 50 + 1;

    cout << "Would you like to play? (Y/N)";
    cin >> answer;

    while (answer == 'y' || answer == 'Y') {
        cout << "Enter your guess between 0 & 50: ";
        cin >> guess;

        while (guess < 0 || guess > 50) {
            cout << "Please enter your guess between and ONLY between 0 & 50" << endl;
            cin >> guess;
        }

        if (guess > solution) {
            cout << "sorry - your guess is too big\n" << endl;
        }
        else if (guess < solution) {
            cout << "sorry - your guess is too low\n" << endl;
        }
        else {
            cout << "let's go - your guess was corrrect" << endl;
            solution = rand() % 50 + 1;
            cout << "Guess again? " << endl;
            cin >> answer;
        }
    }
}