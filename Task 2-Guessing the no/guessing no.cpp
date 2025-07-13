#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random generator

    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "=====================================" << endl;
    cout << "        NUMBER GUESSING GAME         " << endl;
    cout << "=====================================" << endl;
    cout << "Guess the number between 1 and 100!" << endl;

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try a smaller number." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try a bigger number." << endl;
        } else {
            cout << "\n🎉 Congratulations! You guessed the correct number!" << endl;
            cout << "It took you " << attempts << " attempt(s)." << endl;
        }

    } while (guess != secretNumber);

    cout << "Thank you for playing! Goodbye!" << endl;

    return 0;
}