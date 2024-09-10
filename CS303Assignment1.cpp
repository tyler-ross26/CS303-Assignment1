// Tyler Ross
// CS303 Assignment 1
// 9/9/2024

#include <iostream>
#include <fstream>
#include <stdexcept> // For exception handling
#include "Functions.h" // Include your header file with function declarations

using namespace std;

int main() {
    // Dynamically allocate an array to store integers
    int* numbers = new int[100];
    int size = 0; // Tracks the number of elements currently in the array
    char input = ' '; // User input for menu selection
    int userVal; // Value for finding, modifying, or adding
    int userIndex; // Index for modifying or removing elements
    int inputErr = -1; // Error code for invalid menu option

    // Open the input file
    ifstream inputFile("input.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        delete[] numbers; // Clean up dynamically allocated memory
        return 1; // Exit with an error code
    }

    // Read integers from the file and store them in the array
    while (inputFile >> numbers[size]) {
        ++size; // Increment size for each successfully read integer
    }

    inputFile.close(); // Close the file after reading

    // Main loop for user interaction
    while (input != 'q') {
        cout << "Would you like to find (f), modify (m), add (a), replace/remove (r), print (p), or quit (q)?" << endl;
        cin >> input;

        try {
            // Handle different user commands
            switch (input) {
            case 'f': // Find an integer
                cout << "What integer do you want to find?" << endl;
                cin >> userVal;
                find(numbers, size, userVal); // Call the find function
                break;

            case 'm': // Modify an element at a specific index
                cout << "Which index do you want to modify at?" << endl;
                cin >> userIndex;
                cout << "What did you want to change this integer to?" << endl;
                cin >> userVal;
                // Check if the index is valid
                if (userIndex < 0 || userIndex >= size) {
                    throw out_of_range("Index out of range"); // Throw an exception if index is invalid
                }
                modify(numbers, userIndex, userVal, numbers[userIndex]); // Call the modify function
                break;

            case 'a': // Add a new integer
                cout << "What value would you like to add?" << endl;
                cin >> userVal;
                add(numbers, size, userVal); // Call the add function
                break;

            case 'r': // Replace or remove an element at a specific index
                cout << "At what index would you like to replace/remove?" << endl;
                cin >> userIndex;
                // Check if the index is valid
                if (userIndex < 0 || userIndex >= size) {
                    throw out_of_range("Index out of range"); // Throw an exception if index is invalid
                }
                replace(numbers, userIndex); // Call the replace function
                break;

            case 'p': // Print all elements in the array
                for (int i = 0; i < size; i++) {
                    cout << numbers[i] << " ";
                }
                cout << endl;
                break;

            case 'q': // Quit the program
                cout << "Goodbye!" << endl;
                break;

            default: // Handle invalid menu options
                cout << endl;
                throw inputErr; // Throw an error code for invalid option
            }
        }
        catch (int inputErr) {
            // Handle the custom error code for invalid menu options
            cout << "Input Error\n" << endl;
            break; // Exit the loop
        }
        catch (const std::out_of_range& e) {
            // Handle out_of_range exceptions
            cerr << "Out of range error: " << e.what() << endl;
        }
    }

    // Clean up dynamically allocated memory
    delete[] numbers;
    return 0; // Exit the program
}
