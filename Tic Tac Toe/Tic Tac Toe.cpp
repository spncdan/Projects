// Reflection : This code was definitely a fun build, I did come across syntax issues with using the switches to compliment the user input of the menu but was able to over the issue with some help from AI. Furthermore this project was a great way to test my knowledge of matrixes and how I can manipulate and change the data within them.

// Sources : I used ChatGPT to help when I was going through syntax issues implementing the switch menu after completing the tic tac toe code, the AI essentially gave me advice on adding curly brackets for each case's interior in order to better organize the code and prevent confusion when viewing it from an outside perspective

// This code was created as a submittable project for my Object-Oriented Programming class and was made using knowledge and concepts explored in the class along with help with from ChatGPT for helping with syntax issues.

#include <iostream>
using namespace std;

// Function Prototypes
void printboard(char[][3], int, int);
bool checkwin(char[][3], char);
bool checkdraw(char[][3]);

// Main function
int main() {
    
    // Bool variables which help to decide the while loop which alternates between player x and y's turns (done) and a while loop which checks for invalid user inputs (proceed)
    bool proceed = true;
    bool done = false;
    int play_again = 1;
    bool menu_exit = false;
    
    while(menu_exit == false){ // This will be a while loop which will keep relooping the game and bring the user back to the menu after the game is complete
        
        cout << "************************************************* \n";
        cout << " \n";
        cout << "              Welcome to Tic Tac Toe \n";
        cout << " \n";
        cout << "Please choose a number from the following options: \n";
        cout << " \n";
        cout << "1. Play \n";
        cout << "2. Exit \n";
        cout << " \n";
        cout << "************************************************* \n";
        cout << " \n";
        
        cin >> play_again; // User will input an option where they either choose 1. to play the game or 2. to exit the game, if the user chooses anything else the switch statement below will default and tell the user their input was invalid.

        switch(play_again){ // Here is our switch statement play_again which will decide on the user input above whether to start the game of tic tac toe (if user inputs 1), or exit the program (if user inputs 2) by seeing menu_exit to true, or show an error if the user enters neither 1 or 2.
            case 1: {
                
                cout << " " << endl;
                cout << "Starting Tic Tac Toe..." << endl; // Added after screenshots were taken for better console presentation especially in case the user attempts to replay after playing once already
                cout << " " << endl;
                
                done = false; // resetting this back to false allows us to replay the game if the user chooses to play again after playing once already
                
                char board[3][3] = { // This will be the matrix which shows the board the game will use
                    
                    /* 0   1   2 */
                    /* 0 */  {'-','-','-'},
                    /* 1 */  {'-','-','-'},
                    /* 2 */  {'-','-','-'}
                    
                };
                
                // Defining variables user_input_row and user_input_col for when Player X or O inputs their move
                int user_input_row = 0, user_input_col = 0;
                
                // Printing array before game starts to show board
                cout << " " << endl;
                printboard(board, 3, 3);
                
                // Using a while loop in order to loop between Player X and O turns
                while (done == false){
                    
                    // Player X Move (Nested while loop to make sure that the input is not greater than 2 or less than 0 for both rows and columns)
                    while (proceed == true){ // While loop also makes sure inputs are not taken already
                        cout << " " << endl;
                        cout << "Player X: Enter the row and column for you move: " << endl;
                        cin >> user_input_row >> user_input_col;
                        if (board[user_input_row][user_input_col] == 'X' or board[user_input_row][user_input_col] == 'O'){ // If statement checks if spot on the matrix already has X or Y on it and will give an error message and loop back to user input.
                            cout << " " << endl;
                            cout << "Invalid input(s), please choose inputs which are not already taken" << endl;
                        }
                        else if (user_input_row >= 0 and user_input_row <= 2 and user_input_col >= 0 and user_input_col <= 2){
                            proceed = false; // If statement checks if the inputs are inside of the dimensions of matrix of the board
                        }
                        else {
                            // will run if inputs are outside of the scope of the matrix
                            cout << " " << endl;
                            cout << "Invalid input(s), please be sure that your inputs are between 0 - 2" << endl;
                        }
                    }
                    
                    // Setting the value of proceed back to true to ensure functionality for Player O's While loop
                    proceed = true;
                    
                    // Allowing user input to be replaced by 'X' on the board
                    board[user_input_row][user_input_col] = 'X';
                    
                    // Printing Array after Player X makes a move to show change.
                    cout << " " << endl;
                    printboard(board, 3, 3);
                    
                    // Checking for win conditions for player X
                    if (checkwin(board, 'X') == true){
                        cout << " " << endl;
                        cout << "Player X has won the game!" << endl;
                        cout << " " << endl;
                        done = true;
                        break;
                    }
                    // Checking for draw conditions
                    if (checkdraw(board) == true){
                        cout << " " << endl;
                        cout << "Draw!" << endl;
                        cout << " " << endl;
                        done = true;
                        break;
                    }
                    
                    // Player O Move (Nested while loop to make sure that the input is not greater than 2 or less than 0 for both rows and columns)
                    while (proceed == true){ // While loop also makes sure inputs are not taken already
                        cout << " " << endl;
                        cout << "Player O: Enter the row and column for you move: " << endl;
                        cin >> user_input_row >> user_input_col;
                        if (board[user_input_row][user_input_col] == 'X' or board[user_input_row][user_input_col] == 'O'){ // If statement checks if spot on the matrix already has X or O on it and will give an error message and loop back to user input.
                            cout << " " << endl;
                            cout << "Invalid input(s), please choose inputs which are not already taken" << endl;
                        }
                        else if (user_input_row >= 0 and user_input_row <= 2 and user_input_col >= 0 and user_input_col <= 2){
                            proceed = false; // If statement checks if the inputs are inside of the dimensions of matrix of the board
                        }
                        else {
                            // will run if inputs are outside of the scope of the matrix
                            cout << " " << endl;
                            cout << "Invalid input(s), please be sure that your inputs are between 0 - 2" << endl;
                        }
                    }
                    
                    // Setting the value of proceed back to true to ensure functionality for Player X's While loop when looped back to Player X's turn
                    proceed = true;
                    
                    // Allowing user input to be replaced by 'O' on the board
                    board[user_input_row][user_input_col] = 'O';
                    
                    // Printing Array after Player O makes a move to show change.
                    cout << " " << endl;
                    printboard(board, 3, 3);
                    
                    // Checking for win conditions for player O
                    if (checkwin(board, 'O') == true){
                        cout << " " << endl;
                        cout << "Player O has won the game!" << endl;
                        cout << " " << endl;
                        done = true;
                        break;
                    }
                    // Checking for draw conditions
                    if (checkdraw(board) == true){
                        cout << " " << endl;
                        cout << "Draw!" << endl;
                        cout << " " << endl;
                        done = true;
                        break;
                    }
                }
            break;
            }
            case 2: {
                cout << " " << endl;
                cout << "Thank you for playing!" << endl;
                cout << " " << endl;
                menu_exit = true;
                break;
            }
            default: {
                cout << " " << endl;
                cout << "Invalid option, please try again!" << endl;
                cout << " " << endl;
                break;
            }
        }
    }
    
    return 0;
}

// Void Function to print board (void = function wont return anything)
void printboard(char matrix[][3], int rows, int cols){
    // Nested for loops will run and print out the column and row values within the matrix in a gridlike format to simulate a tic tac toe board
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }
}

// Boolean Function which will check if a player has won and return true or false depending on whether the player has won or not
bool checkwin(char matrix[][3], char player){
    for (int i = 0; i < 3; ++i){
        
        // Checking the rows and columns for the Player's Symbol (X or O)
        if (matrix[i][0] == player and matrix[i][1] == player and matrix[i][2] == player){
            return true; // checking the rows for 3 in a row of player variable
        }
        if (matrix[0][i] == player and matrix[1][i] == player and matrix[2][i] == player){
            return true; // checking the columns for 3 in a column of player variable
        }
        
        // Check diagnals of the board for Player's Symbol (X or O)
        if (matrix[0][0] == player and matrix[1][1] == player and matrix[2][2] == player){
            return true; // checking diagonals from the left to right for player variable
        }
        if (matrix[0][2] == player and matrix[1][1] == player and matrix[2][0] == player){
            return true; // checking diagonals from the right to left for player variable
        }
        
    }
    
    return false; // If none of the above is true then the function will return false as the player has not won
}

// Boolean Function which will check if a draw has occured, will return true or false depending on whether a draw has occured
bool checkdraw(char matrix[][3]){
    
    for(int i = 0; i < 3; ++i){ // going through every row
        for(int j = 0; j < 3; ++j){ // going through every column
            if(matrix[i][j] == '-'){ // as the for loop goes through every row and column possible it will check if the value '-' is still present anywhere on the board
                return false; // game is not a draw if the loop above finds that '-' is still present in any of the possible row/column combinations
            }
        }
    }
    return true; // if there are no more '-' symbols on the board then the game is a draw.
}
