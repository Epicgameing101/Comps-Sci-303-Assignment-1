#include <iostream>
#include <iomanip>
#include <string>
#include "Functions.h"

using namespace std;


int main() {
    int array[100];       // Initialize array with size of 100
    int array_size = 0;       // Initialize variable "size" to use as reference of array size
    ifstream inputFile("A1input.txt");       // Open input file "A1input"
    if (!inputFile) {       // Check to see if file is opened, print error if not opened
        cout << "Error: Could not open the input file." << endl;
        return 1;
    }
    // Read data from file into the array
    while (inputFile >> array[array_size]) {        // Read in from "A1input" to fill array with data
        array_size++;
    }
    inputFile.close();

    int menu_command, user_value, array_index, array_oldValue;      // Initialize all variables needed to handle menu options
    cout << "Menu:" << endl;
    cout << "1: Search" << endl;
    cout << "2: Modify" << endl;
    cout << "3: Add" << endl;
    cout << "4: Remove" << endl;
    cout << "5: Exit" << endl;

    while (true) {      // Runs endlessly until user inputs '5' to exit program
        cout << "\nEnter command: ";
        cin >> menu_command;
        try {
            switch (menu_command) {
            case 1: {
                cout << "Enter a number to search for: ";
                cin >> user_value;
                if (cin.fail()) {
                    throw invalid_argument("Value must be a valid number.");
                }
                array_index = search(array, array_size, user_value);
                if (array_index != -1) {
                    cout << "Number found at index: " << array_index << endl;
                }
                else {
                    cout << "Number not found" << endl;
                }
                break;
            }
            case 2: {
                cout << "Enter the index of the value to modify: ";
                cin >> array_index;
                if (cin.fail()) {
                    throw invalid_argument("Index must be a valid number.");
                }
                cout << "Enter new value: ";
                cin >> user_value;
                if (cin.fail()) {
                    throw invalid_argument("Value must be a valid number.");
                }
                modify(array, array_size, array_index, user_value, array_oldValue);
                cout << "Modified value. Old value: " << array_oldValue << ", New value: " << user_value << endl;
                break;
            }
            case 3: {
                cout << "Enter a value to add: ";
                cin >> user_value;
                if (cin.fail()) {
                    throw invalid_argument("Value must be a valid number.");
                }
                add(array, array_size, user_value);
                cout << "Number added." << endl;
                break;
            }
            case 4: {
                cout << "Enter index to remove: ";
                cin >> array_index;
                if (cin.fail()) {
                    throw invalid_argument("Index must be a valid number.");
                }
                remove(array, array_size, array_index);
                cout << "Number removed." << endl;
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                throw invalid_argument("Invalid Command; Options are 1-5");
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}