// Copyright (c) 2021 Brian Musembi, All rights reserved
//
// Created by Brian Musembi
// Created on May 2021
// This program is a guessing game

#include <iostream>
#include <string>
#include <random>

int main() {
    // this function compares an integer to a random number
    //      using a loop

    std::cout << "Today we will play a guessing game." << std::endl;

    // variable declarations
    const int MIN_GUESS = 0;
    const int MAX_GUESS = 9;
    int loopCounter = 0;
    int randomNumber;
    std::string userGuess;
    int userGuessInt;

    // random number generation
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(MIN_GUESS, MAX_GUESS);
    randomNumber = idist(rgen);

    // process
    while (true) {
        // input
        std::cout << "Enter a number between 0-9: ";
        std::cin >> userGuess;
        std::cout << "" << std::endl;

        // process
        try {
            userGuessInt = std::stoi(userGuess);

            if (userGuessInt >= MIN_GUESS && userGuessInt <= MAX_GUESS) {
                // process
                loopCounter = loopCounter + 1;

                if (userGuessInt == randomNumber) {
                    break;
                } else if (userGuessInt > randomNumber) {
                    std::cout << "Your guess is too high, "
                              << " please try again." << std::endl;
                } else if (userGuessInt < randomNumber) {
                    std::cout << "Your guess is too low, "
                              <<"please try again." << std::endl;
                } else {
                    std::cout << "Error, please try again." << std::endl;
                }
            } else {
                // output
                std::cout << "Your guess must be between " << MIN_GUESS
                          << " and " << MAX_GUESS << ". Try "
                          << "again." << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "That's not a number! Please try again." << std::endl;
        }
    }

    std::cout << "" << std::endl;
    std::cout << "You guessed correct! It took you "
              << loopCounter << " time(s) to guess "
              << "the number." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Thank you for playing!" << std::endl;
}
