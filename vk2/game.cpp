#include "Game.h"
#include <cstdlib>
#include <ctime>

Game::Game(int maxNumber)
    : maxNumber(maxNumber), playerGuess(0), numOfGuesses(0)
{
    std::cout << "GAME CONSTRUCTOR: object initialized with "
              << maxNumber << " as a maximum value" << std::endl;

    std::srand(std::time(0));
    randomNumber = std::rand() % maxNumber + 1;
}

Game::~Game() {
    std::cout << "GAME DESTRUCTOR: object cleared from stack memory" << std::endl;
}

void Game::play() {
    std::cout << "Give your guess between 1-" << maxNumber << std::endl;

    while (true) {
        std::cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess == randomNumber) {
            std::cout << "Your guess is right = " << randomNumber << std::endl;
            break;
        } else if (playerGuess < randomNumber) {
            std::cout << "Your guess is too small" << std::endl;
            std::cout << "Give your guess between 1-" << maxNumber << std::endl;
        } else {
            std::cout << "Your guess is too big" << std::endl;
            std::cout << "Give your guess between 1-" << maxNumber << std::endl;
        }
    }
}

void Game::printGameResult() {
    std::cout << "You guessed the right answer = "
              << randomNumber
              << " with "
              << numOfGuesses
              << " guesses"
              << std::endl;
}
