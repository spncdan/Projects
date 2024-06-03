// This program is a Console-Based Hidden Treasure game where the treasure coordinates are randomly generated each time the player begins the program and the player has to find the treasure by either going North, South, West, or East.
// Each time the player moves, the distance between the player and the treasure is computed via the distance variable.
// There is also a visual representation of the map to show where the player has been and hasn't been.
// This was a revision of this previous lab in my object oriented programming class as I wanted to add my new found knowledge of how to print and manipulate matrixes to this program.

#include<iostream>
#include<cstdlib> // Used for the rand() function
#include<ctime>
#include<cmath> // Used for the distance formula
using namespace std;

// Function Prototypes
void printmap(char matrix[][32], int, int);

int main() {
    
    int x=15,y=15; // Explorer's coordinates
    int x1,y1; // Treasure's coordinates
    char direction; // N, S, W, E
    float distance; // Distance will be a float and have decimal values most likely
    bool treasure=false; // Boolean which will change depending on if distance = 0
    int steps; // Keeping tracks of the amount of steps the player takes to show at the end of the game

    // Randomly generating the location of the treasure
    srand(time(0)); // secretly seed the rand function
    x1=rand( ) % 30 + 1; // set X1 to random between 1 and 30
    y1=rand( ) % 30 + 1; // set X2 to random between 1 and 30
    
    // Write loop to find the treasure

    steps = 0;

    // Creation of Map

     char treasuremap[32][32] = { // Array Maximum sent to 32 to accomodate the outer lines of the map, and due to the fact that the random generation of the treasure has it's coordinates placed between 1 and 30 as shown above
                    
                     {'_' ,'_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_'},       
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'|' ,' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,' ', ' ' ,' ' ,' ' ,' ' ,'|'},
                     {'_' ,'_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_', '_' ,'_' ,'_' ,'_' ,'_'}
    };

    treasuremap[15][15] = 'X'; // Starting position of the player

    printmap(treasuremap, 32, 32); // Calling on our printmap function
    
    while (treasure == false){ // We want our loop to keep running while treasure is equal to false but we can also break the loop using break statements if needed
        
        cout << "Please enter a direction (N, S, W, E), or X to exit the program: " << endl;
        cin >> direction; // Asking user to input either N, S, W, E
        
        if (direction == 'N' and y < 31){ // Player goes North (y < 31 prevents the player from leaving the confines of the array mapped out.)
            steps += 1; // Adding to steps variable if conditions above are met
            y += 1; // North means we add to the y coordinate
            if (treasuremap[y][x] == 'X'){ // This will prevent the '.' from overriding your starting position 'X' to prevent confusion
                treasuremap[y][x] = 'X';
            }
            else{
                treasuremap[y][x] = '.'; // Changes position to '.' on array to show that the player has been here
            }
        }
        else if (direction == 'S' and y > 0){ // Player goes South (y > 0 prevents the player from leaving the confines of the array mapped out.)
            steps += 1; // Adding to steps variable if conditions above are met
            y -= 1; // South means we subtract from the y coordinate
            if (treasuremap[y][x] == 'X'){ // This will prevent the '.' from overriding your starting position 'X' to prevent confusion
                treasuremap[y][x] = 'X';
            }
            else{
                treasuremap[y][x] = '.'; // Changes position to '.' on array to show that the player has been here
            }
        }
        else if (direction == 'W' and x < 31){ // Player goes West (x < 31 prevents the player from leaving the confines of the array mapped out.)
            steps += 1; // Adding to steps variable if conditions above are met
            x += 1; // West means we add to the x coordinate
            if (treasuremap[y][x] == 'X'){ // This will prevent the '.' from overriding your starting position 'X' to prevent confusion
                treasuremap[y][x] = 'X';
            }
            else{
                treasuremap[y][x] = '.'; // Changes position to '.' on array to show that the player has been here
            }
        }
        else if (direction == 'E' and x > 0){ // Player goes East (x > 0 prevents the player from leaving the confines of the array mapped out.)
            steps += 1; // Adding to steps variable if conditions above are met
            x -= 1; // East means we subtract from the x coordinate
            if (treasuremap[y][x] == 'X'){ // This will prevent the '.' from overriding your starting position 'X' to prevent confusion
                treasuremap[y][x] = 'X';
            }
            else{
                treasuremap[y][x] = '.';  // Changes position to '.' on array to show that the player has been here
            }
        }
        else if (direction == 'X'){ // Player exits game
            cout << "Exiting program..." << endl;
            treasure = true; // This will stop the while loop and exit the program here
            break;
        }
        else { // If player inputs wrong character or attempts to move outside map
            cout << "Invalid response." << endl; // We want our loop to keep running in the case where a user may accidentally input a wrong character or attempt to move outside of the given map.
        }
        
        distance = sqrt(static_cast<double>((x-x1)*(x-x1)+(y-y1)*(y-y1))); // Distance formula given in CIS 3100 lab guidelines
        printmap(treasuremap, 32, 32); // Printing map for user to see progress and where they've been
        cout << "Your new coordinates are (" << x << "," << y << ") and your current distance from the treasure is " << distance << "." << endl; // Giving back coordinates and distance
        
        if (distance == 0){ // Distance == 0 means the player has arrived to the treasure
            cout << "Congratulations! It took you " << steps << " steps to find the treasure." << endl; // Giving the user how many steps it took to reach treasure.
            break;
        }
    }

    return 0;
}

// Function used to print the map after each loop within the while loop above.
void printmap(char matrix[][32], int rows, int cols){

    for(int i = 0; i < rows; i++){ // Cycles through every row
        for(int j = 0; j < cols; j++){ // Cycles through every col within each specific row
            cout << matrix[i][j] << " ";
        }
     cout << endl;
    }

    return;
}
