# File: CS112_A1_T2_GameNumber( TWO )_20230295.py
# Purpose: A Number Scrabble in python. We have a list of numbers between 1 to 9 & two players
#          each of them picked number from the list and who is get sum of number's chosen = 15 Win
#          Note: Once a number has been picked, it cannot be picked again
# Author: Kirolos Adel Samir, 20230295
# Version: 3.0

# Set function of the winning
def winning(players_list):
    for i in range(len(players_list)):
        for j in range(i + 1, len(players_list)):
            for k in range(j + 1, len(players_list)):
                if players_list[i] + players_list[j] + players_list[k] == 15:
                    return True
    return False


# Set the main variable game
game_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
player1_score = 0
player2_score = 0
game = "on"
player1_list = []
player2_list = []

# Start the GAME
start_game = """
===================================
* Welcome to Number Scrabble game *
===================================
Should to pick numbers between 1 to 9 and if the summation of 
3 numbers is equal 15, the player will win.
"""
print(start_game)

# Code is always run until game = off
while game == "on":
    while True:
        # Player one
        number1 = input(f"Player one Choose number between {game_list}\n => ")
        # Check if the user inserts a number or not
        if number1 == "" or len(number1) >= 2 or number1.isspace():
            print("Error: Please enter a number between 1 to 9")
            continue
        player1_num = int(number1)
        # check the number in the list
        if player1_num in game_list:
            game_list.remove(player1_num)
            player1_list.append(player1_num)
            player1_score += player1_num
            player1_data = f"""
Player one 's:
number chosen: {player1_list}
score: {player1_score}
            """
            print(player1_data)
            break
        else:
            print("Error: Number is not in the list")

    # The func [ winning ] is checked if the player has 3 numbers it summation, is
    # equal 15 to print the player is won
    if winning(player1_list):
        print("=== Player One wins!! ===")
        game = "off"
        break
    # This code check if the main list became empty so the two players are draw
    if game_list == []:
        print("== Draw! ==")
        break

    # IF game still on => player two now is ready to play
    if game == "on":
        while True:
            # Player two
            number2 = input(f"Player two Choose number between {game_list}\n => ")
            # Check if the user insert a number or not
            if number2 == "" or len(number2) >= 2 or number2.isspace():
                print("Error: Please enter a number between 1 to 9")
                continue
            player2_num = int(number2)
            if player2_num in game_list:
                game_list.remove(player2_num)
                player2_list.append(player2_num)
                player2_score += player2_num
                player1_data = f"""
Player two:
number chosen: {player2_list}
score: {player2_score}
                            """
                print(player1_data)
                break
            else:
                print("Error: Number is not in the list")

        # The func [ winning ] is checked if the player have 3 numbers it summation is
        # equal 15 to print the player is won
        if winning(player2_list):
            print("=== Player Two wins!! ===")
            game = "off"
            break

        # This code check if the main list became empty so the two players are draw
        if game_list == []:
            print("== Draw! ==")
            break


# TEST CASES
"""
input
Player one: [ 4 , 5 , 6 ]
Player two: [ 1 , 2 , 3 ]

output
Player one wins
================================
input
Player one: [ 7 , 8 , 9 , 3 , 5]
Player two: [ 1 , 4 , 6 , 2 ]

output
Player one wins
================================
input
Player one: [ 10 ] or [ 0 ]

output
Error: Number is not in the list
================================
input
Player one: [ 5 ]
Player two: [ 5 ]

output
Error: Number is not in the list
================================
input
Player one: [ 1 , 2 , 3 , 4 , 5]
Player two: [ 7 , 8 , 9 , 6 ]

output
Draw
================================
input
Player one: kiro

output
Error: Please enter a number between 1 to 9
================================
input
Player one: ""

output
Error: Please enter a number between 1 to 9
"""