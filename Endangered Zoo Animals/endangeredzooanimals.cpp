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
            amountneedsattention += animalcount;
            needsattention = "yes";
        }
        else{
            needsattention = "no";
        }
        cout << nameofanimal << " " << animalcount << " " << needsattention << endl;
    };

    // Printing out determined variable values.
    cout << "There are " << totalnumofanimals << " animals in the zoo." << endl;
    cout << "There are " << amountneedsattention << " animals that need special attention." << endl;

    return 0;
}

// function which determines if there are less than 10 of the particular animal at the zoo and whether it is endangered or not, if so it will return true.
bool attention(int x, char y){
    if(x < 10 and y == 'y'){
        return true;
    }
    else
    return false;
};