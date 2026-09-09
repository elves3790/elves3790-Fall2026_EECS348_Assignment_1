/*
 * ============================================================================
 * Program Name: Number Guessing Game
 * Author:       Anthony Raygorodetskiy
 * Description:  A simple guessing game where the player attempts to guess a
 *               predefined secret number between 1 and 10 within a maximum
 *               of 3 attempts. Provides feedback after each incorrect guess.
 * Inputs:       Integer values representing the user's guesses entered via standard input (stdin).
 * Outputs:      Prompt messages, status hints ("Too low", "Too high"), and
 *               final outcome messages ("Correct! You win!" or "You lose!") printed to standard output (stdout).
 * ============================================================================
 */

#include <stdio.h> // Include standard I/O library for console input/output functions

int main(void) { // Define the program entry point taking no arguments
    const int secret_number = 7; // Define the target value to guess as a constant integer
    const int max_attempts = 3; // Define the maximum number of allowed tries as a constant integer
    int guess; // Declare an integer variable to hold the user's numeric input

    printf("Guess a number between 1 and 10.\n"); // Print the initial instructions and valid range to the user

    for (int attempt = 1; attempt <= max_attempts; attempt++) { // Loop through guesses from attempt 1 through max_attempts
        printf("Attempt %d/%d. Enter your guess: ", attempt, max_attempts); // Display the current attempt counter and prompt for input

        if (scanf("%d", &guess) != 1) { // Read input and verify scanf successfully matched exactly one integer
            printf("Invalid input. Please enter a whole number.\n"); // Warn the user that the entered text was not a valid integer
            while (getchar() != '\n'); // Read and discard remaining characters in the input buffer until a newline
            attempt--; // Decrement attempt counter so the invalid entry does not waste a try
            continue; // Skip the rest of the loop body and start the next iteration
        } // Close the input validation if block

        if (guess == secret_number) { // Check if the valid input matches the secret number
            printf("Correct! You win!\n"); // Print the winning congratulatory message
            return 0; // Terminate the program early with a success code, bypassing the rest of the game
        } // Close the win check if block

        if (attempt < max_attempts) { // Check if there are still attempts remaining before giving a hint
            printf("%s! Try again.\n", (guess < secret_number) ? "Too low" : "Too high"); // Select and print "Too low" or "Too high" using a ternary expression
        } // Close the hint if block
    } // Close the for loop

    printf("You ran out of attempts! The secret number was %d. You lose!\n", secret_number); // Inform the player they lost and reveal the target number
} // Close the main function body