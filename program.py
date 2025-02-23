import random

computer_choices = ["rock", "paper", "scissor"]
user_wins = 0
computer_wins = 0
ties = 0

total_rounds = int(input("How many rounds do you want to play? "))

for round_num in range(1, total_rounds + 1):
    computer_move = random.choice(computer_choices)
    user_move = input(f"Round {round_num}/{total_rounds} - Enter Rock, Paper, or Scissor: ").lower()

    if user_move not in computer_choices:
        print("Invalid move. Try again.")
        continue

    print(f"You chose {user_move}, Computer chose {computer_move}")

    if user_move == computer_move:
        print("It's a tie!")
        ties += 1
    elif (user_move == "rock" and computer_move == "scissor") or \
         (user_move == "paper" and computer_move == "rock") or \
         (user_move == "scissor" and computer_move == "paper"):
        print("You win!")
        user_wins += 1
    else:
        print("Computer wins!")
        computer_wins += 1

    print(f"Scoreboard - You: {user_wins}, Computer: {computer_wins}, Ties: {ties}\n")

print(f"\nFinal Scoreboard:\nYou: {user_wins}, Computer: {computer_wins}, Ties: {ties}")

if computer_wins > user_wins:
    print("You lost the game! Better luck next time.")
elif user_wins > computer_wins:
    print("Congratulations! You won the game!")
else:
    print("It's a draw!")
