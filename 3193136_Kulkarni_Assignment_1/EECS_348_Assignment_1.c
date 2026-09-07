/*
Name of the program = EECS 348 Assignment 1
Description = C program where the developer sets a secret number between 1-10. User gets 3 attempts to guess the number.
Inputs= User guesses (whole numbers 1-10)
Outputs = Terminal output prompting the user and indicating win/loss.
Collaborators = None 
Other sources = ChatGPT, Gemini
Author = Aditya Kulkarni
Creation date = 9/7/2026
Revision date = 9/7/2026
Revision = selected gemini code; added min/max bounds, added checks for scanf to only accept allowed input .
*/


#include <stdio.h> //include standard I/O library for printf and scanf (Authored by Gemini)



int main() { //main entry point of program (Authored by Gemini)

    /*
Authored gemini, modified by Aditya Kulkarni.
Initialize variables needed in the code
*/
    int secretNumber = 7;// Fixed target number to guess (Authored by Gemini)
    int guess;// Variable to store the user's input (Authored by Gemini)
    int maxAttempts = 3;// Maximum allowed guesses (Authored by Gemini)
    int minGuess =1;// Minimum valid guess bound (Authored by Author)
    int maxGuess =10;// Maximum valid guess bound (Authored by Author)
    int won = 0;// Flag variable: 0 = not won yet, 1 = won (Authored by Gemini)

    // Print initial instructions using the min and max bounds (Authored by Author)
    printf("Guess a number between %d and %d.\n",minGuess,maxGuess);

    /*
     * Block: Game Loop and Logic
     * Author: Gemini, modified by Aditya Kulkarni
     * Iterates for the allowed number of attempts, processes and validates input, 
     * and evaluates win/loss conditions.
     */
    for (int i = 1; i <= maxAttempts; i++) {// Loop running from attempt 1 to maxAttempts (Authored by Gemini)
        printf("Attempt %d/%d. Enter your guess: ", i, maxAttempts);// Display current attempt (Authored by Gemini)
        
        /* 
         * Loop until scanf successfully reads 1 integer AND it is within bounds.
         * If it fails, clear the input buffer to prevent infinite loops.
         */
        while (scanf("%d",&guess) != 1 || guess < minGuess || guess > maxGuess){// Validate input type and bounds (Authored by Author)
            while (getchar() != '\n');// Clear the standard input buffer of invalid characters (Authored by Author)
            
            printf("Invalid input. Enter a whole number between %d and %d: ",minGuess, maxGuess);// Prompt the user again with the correct bounds (Authored by Author)
        }// End validation while loop (Authored by Author)

        if (guess == secretNumber) {// Check if guess exactly matches the secret (Authored by Gemini)
            printf("Correct! You win!\n");// Print winning message (Authored by Gemini)
            won = 1;// Update flag to indicate a win (Authored by Gemini)
            break; // Immediately exit the for loop (Authored by Gemini)
        } 

        else if (guess < secretNumber) {// Check if guess is lower than secret (Authored by Gemini)
            printf("Too low!");// Print low warning without newline (Authored by Gemini)
        } 
        
        else {// Fallthrough case: guess must be higher than secret (Authored by Gemini)
            printf("Too high!");// Print high warning without newline (Authored by Gemini)
        }// End of conditional checks for this attempt (Authored by Gemini)

        
        if (i < maxAttempts) {// Check if user has more attempts remaining (Authored by Gemini)
            printf(" Try again.\n");// Prompt to try again if attempts remain (Authored by Gemini)
        } else {// Case where no attempts remain (Authored by Gemini)
            printf("\n");// Print a newline to format terminal output cleanly (Authored by Gemini)
        }// End of try again logic (Authored by Gemini)
    }// End of the guessing game for loop (Authored by Gemini)

    /*
     * Block: Final Evaluation
     * Author: Gemini
     * Checks the win flag after loop termination to determine if loss message is needed.
     */
    if (!won) {// If won flag is still false/0 after exhausting attempts (Authored by Gemini)
        printf("You lose! The secret number was %d.\n", secretNumber);// Print final loss message (Authored by Gemini)
    }// End of loss check (Authored by Gemini)

    return 0;// Return zero indicating successful execution (Authored by Gemini)
}// End of main function (Authored by Gemini)