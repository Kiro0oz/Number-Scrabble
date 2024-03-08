// Program: A Number Scrabble in python. We have a list of numbers between 1 to 9 & two players
//          each of them picked number from the list and who is get sum of number's chosen = 15 Win
//          Note: Once a number has been picked, it cannot be picked again
// Author: Kirollos Adel Samir, 20230295
// Version: 3.0
// Data: 2/26/2024


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// Set function of the winning
bool winning(const vector<int>& players_list) {
    for(size_t i = 0; i < players_list.size(); ++i) {
        for(size_t j = i + 1; j < players_list.size(); ++j) {
            for(size_t k = j + 1; k < players_list.size(); ++k) {
                if (players_list[i] + players_list[j]+ players_list[k] == 15) {
                    return true;
                }
            }
        }
    }
    return false;
}


// The main function
int main() {
    // Set the main variable game
    vector<int> game_list = {1,2,3,4,5,6,7,8,9};
    vector<int>::iterator it;
    auto it_begin = game_list.begin();
    auto it_end = game_list.end() - 1;
    int player1_score = 0;
    int player2_score = 0;
    vector<int> player1_list;
    vector<int> player2_list;
    bool game = true;
    cout << "====================================\n";
    cout << "* Welcome to Number Scrabble game *\n";
    cout << "====================================\n";
    // Code is always run until game = True
    while (game) {
        while (true) {
            // Player one
            int player1_number;
            // Print the main game list
            cout << "\nPlayer one enter a number between ";
            for(int num : game_list) {
                cout << "[" << num << "]" << " ";
            }
            cout << " \n=> ";
            cin >> player1_number;

            // Check if the user inserts a number or not
            if(player1_number < 1 || player1_number > 9 || cin.fail()) {
                cout << "Error: Please enter a number between 1 to 9\n Press enter to continue the game!";
                cin.ignore();
                // check if user is insert a string not a number
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            // if the number in the list
            if(find(it_begin, it_end, player1_number) != it_end) {
                game_list.erase(remove(it_begin,it_end, player1_number), it_end);
                player1_list.push_back(player1_number);
                player1_score += player1_number;
                cout << "Player one 's: \n";
                cout << "Score: " << player1_score << "\n";
                cout << "Number chosen: " ;
                for(int num : player1_list) {
                cout << "[" << num << "]";
                }
                break;
                }
            else {
                cout << "Error: Number is not in the list\n";
                continue;
                }
            }
        // The func [winning] is checked if the player has 3 numbers it summation,is equal 15 to print the player is won
        if(winning(player1_list)) {
            cout << "\n";
            cout << "\n== Player one wins! ==";
            game = false;
            break;
        }
        // This code check if the main list became empty so the two players are draw
        if(game_list.empty()) {
            cout << "== Draw ==\n";
            break;
        }
        // IF game still true => player two now is ready to play
        if(game) {
            while(true) {
                // Player two
                int player2_number;
                cout << "\nPlayer two enter a number between ";
                // Print the main game list
                for(int num : game_list) {
                    cout << "[" << num << "]" << " ";
                }
                cout << " \n=> ";
                cin >> player2_number;

                // Check if user insert a number or not
                if(player2_number < 1 || player2_number > 9 || cin.fail()) {
                    cout << "Error: Please enter a number between 1 to 9\n Press enter to continue the game!";
                    cin.ignore();
                    // check if user is insert a string not a number
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                // if the number in the list
                if(find(it_begin, it_end, player2_number) != it_end) {
                    game_list.erase(remove(it_begin,it_end, player2_number), it_end);
                    player2_list.push_back(player2_number);
                    player2_score += player2_number;
                    cout << "Player two 's: \n";
                    cout << "Score: " << player2_score << "\n";
                    cout << "Number chosen: " ;
                    for(int num : player2_list) {
                        cout << "[" << num << "]";
                    }
                    break;
                }
                else {
                    cout << "Error: Number is not in the list\n";
                    continue;
                }

            }
            if(winning(player2_list)) {
                cout << "\n";
                cout << "\n== Player Two wins! ==";
                game = false;
                break;
            }

            if(game_list.empty()) {
                cout << "== Draw ==\n";
                break;
            }
        }

        }
    return 0;
    }



