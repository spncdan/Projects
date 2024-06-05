// This a program aims to bring in contents from a data file and classify them in relation to zoo animals which may or may not need attention by a zoo.
// Language: C++
// The program will keep track of the total number of animals (whether they need attention or not)
// If a given animal needs attention (determined by there beiong less than 10 at zoo AND considered endangered) then they will be added to the amountneedsattention variable.
// Finally the name of the name, total animal count, and whether they need attention will be inputted after each loop within the file.
// When the while loop ends and there is no more data to be read into the file, we will print the total number of animals and the total number of animals which need attention.

#include <iostream>
#include <fstream> // pivotal for any program using file operation
using namespace std;

bool attention(int, char); // Function prototype for attention

int main() {

    ifstream inFile("data/animals.txt"); // reading file into program
    int totalnumofanimals = 0; // variable for numofanimals which will be calculated in main
    string needsattention;
    int amountneedsattention = 0; // variable of animals that need special attention
    int animalcount;
    string nameofanimal;
    char endangered;

    // While loop which will loop through file until all contents are covered
    while(inFile >> nameofanimal >> animalcount >> endangered){
        totalnumofanimals += animalcount; // Adding animal count to totalnumofanimals var
        if(attention(animalcount, endangered) == true){ // if statement which determines if animal needs special attention
            amountneedsattention += animalcount; // If the statement above is true, then we will add the animalcount to the amountneedsattention variable
            needsattention = "yes"; // needs attention will be inputted to "yes"
        }
        else{
            needsattention = "no"; // If the function above returns false, then we will change needsattention to no.
        }
        cout << nameofanimal << " " << animalcount << " " << needsattention << endl; // This will be inputted into the console
    };

    // Printing out determined variable values.
    cout << "There are " << totalnumofanimals << " animals in the zoo." << endl;
    cout << "There are " << amountneedsattention << " animals that need special attention." << endl;

    return 0;
}

// function which determines if there are less than 10 of the particular animal at the zoo and whether it is endangered or not, if so it will return true.
bool attention(int x, char y){
    if(x < 10 and y == 'y'){ // if statement which will return true if x is less than 10 AND they are checked off as "y" in file
        return true;
    }
    else
    return false; // returns false if the conditions above are not met
};
