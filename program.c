#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


void getComputerChoice(char *computer_move) {
    char *choices[] = {"rock", "paper", "scissor"};
    int randomIndex = rand() % 3;
    strcpy(computer_move, choices[randomIndex]);
}

int main() {
    char user_move[10], computer_move[10];
    int user_wins = 0, computer_wins = 0, ties = 0, total_rounds;

    srand(time(0));

    printf("How many rounds do you want to play? ");
    scanf("%d", &total_rounds);
    
    for (int round_num = 1; round_num <= total_rounds; round_num++) {
        getComputerChoice(computer_move);

        printf("Round %d/%d - Enter Rock, Paper, or Scissor: ", round_num, total_rounds);
        scanf("%s", user_move);

        // Convert to lowercase for comparison
        for (int i = 0; user_move[i]; i++) {
            user_move[i] = tolower(user_move[i]);
        }

        if (strcmp(user_move, "rock") != 0 && strcmp(user_move, "paper") != 0 && strcmp(user_move, "scissor") != 0) {
            printf("Invalid move. Try again.\n");
            round_num--; // Repeat the round
            continue;
        }

        printf("You chose %s, Computer chose %s\n", user_move, computer_move);

        if (strcmp(user_move, computer_move) == 0) {
            printf("It's a tie!\n");
            ties++;
        } else if ((strcmp(user_move, "rock") == 0 && strcmp(computer_move, "scissor") == 0) ||
                   (strcmp(user_move, "paper") == 0 && strcmp(computer_move, "rock") == 0) ||
                   (strcmp(user_move, "scissor") == 0 && strcmp(computer_move, "paper") == 0)) {
            printf("You win!\n");
            user_wins++;
        } else {
            printf("Computer wins!\n");
            computer_wins++;
        }

        printf("Scoreboard - You: %d, Computer: %d, Ties: %d\n\n", user_wins, computer_wins, ties);
    }

    printf("\nFinal Scoreboard:\nYou: %d, Computer: %d, Ties: %d\n", user_wins, computer_wins, ties);

    if (computer_wins > user_wins) {
        printf("You lost the game! Better luck next time.\n");
    } else if (user_wins > computer_wins) {
        printf("Congratulations! You won the game!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
