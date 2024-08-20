#include <iostream>
#include <cstdlib>
#include <ctime>

void numberGuessingGame() {
    srand(time(0));  // Seed the random number generator
    int numberToGuess = rand() % 100 + 1;
    int guess;
    
    std::cout << "Guess the number (between 1 and 100): ";
    
    while (true) {
        std::cin >> guess;
        
        if (guess > numberToGuess) {
            std::cout << "Too high! Try again: ";
        } else if (guess < numberToGuess) {
            std::cout << "Too low! Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
            break;
        }
    }
}

int main() {
    numberGuessingGame();
    return 0;
}
