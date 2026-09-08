#include <stdio.h>

int main(void) {
    const int secret_number = 7;
    const int max_attempts = 3;
    int guess;
    int won = 0;

    printf("Guess a number between 1 and 10.\n");

    for (int attempt = 1; attempt <= max_attempts; attempt++) {
        printf("Attempt %d/%d. Enter your guess: ", attempt, max_attempts);
        scanf("%d", &guess);

        if (guess == secret_number) {
            printf("Correct! You win!\n");
            won = 1;
            break;
        } else if (guess < secret_number) {
            if (attempt < max_attempts) {
                printf("Too low! Try again.\n");
            }
        } else {
            if (attempt < max_attempts) {
                printf("Too high! Try again.\n");
            }
        }
    }

    if (!won) {
        printf("You ran out of attempts! The secret number was %d. You lose!\n", secret_number);
    }

    return 0;
}