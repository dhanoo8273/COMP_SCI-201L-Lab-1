#include <iostream>
#include <cmath> 
#include <limits>   
using namespace std;

// Opjeet Dhanoa
// Some of the code was created in class

bool getUserChoice(char userChoice) {
    // Prompt user for input and get the input
    cout << "Go Again? (Y/N):";
    cin >> userChoice;

    // Check if the user entered 'Y' or 'y' to continue
    if (userChoice == 'Y' || userChoice == 'y') {
        return true;
    }
    return false;
}

bool generateNumbersOrInput(char userChoice) {
    // Prompt user for input and get the input
    cout << "Do you want to Input your OWN Numbers? (Y/N):";
    cin >> userChoice;

    // Check if the user entered 'Y' or 'y' to input their own numbers
    if (userChoice == 'Y' || userChoice == 'y') {
        return true;
    }
    return false;
}

float calculateDistance(int x1, int y1) {
    // Calculate and print the distance
    cout << "The distance to the origin (0, 0) from (" << x1 << ", " << y1 << ") is: "
        << pow(pow(x1, 2) + pow(y1, 2), 0.5) << endl;
    // Return the calculated distance
    return pow(pow(x1, 2) + pow(y1, 2), 0.5);
}

void performTask(int x1, int y1, int x2, int y2, float dist1, float dist2) {
    // Print the first point
    cout << "Point 1: (" << x1 << ", " << y1 << ")" << endl;
    // Print the second point
    cout << "Point 2: (" << x2 << ", " << y2 << ")" << endl;
    cout << "" << endl;

    // Calculate distance of the points to the origin
    dist1 = calculateDistance(x1, y1);
    dist2 = calculateDistance(x2, y2);
    cout << "" << endl;

    // Compare the distances and determine which point is closer to the origin
    if (dist1 < dist2) {
        cout << "Point 1 is closer to the origin." << endl;
    }
    else if (dist1 > dist2) {
        cout << "Point 2 is closer to the origin." << endl;
    }
    else {
        cout << "The points are the same distance from the origin." << endl;
    }
}

// Most of the code is generated by the Replit AI 
void getUserNumbers(int& x1, int& y1, int& x2, int& y2) {
    cout << "Enter x1 (From -10 to 10): " << endl;
    // Validate input for x1
    while (!(cin >> x1) || (x1 > 10 || x1 < -10)) {
        cout << "Invalid input. Please enter a number from -10 to 10 for x1." << endl;
        cin.clear();  // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
    }

    cout << "Enter y1 (From -10 to 10): " << endl;
    // Validate input for y1
    while (!(cin >> y1) || (y1 > 10 || y1 < -10)) {
        cout << "Invalid input. Please enter a number from -10 to 10 for y1." << endl;
        cin.clear();  // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
    }

    cout << "Enter x2 (From -10 to 10): " << endl;
    // Validate input for x2
    while (!(cin >> x2) || (x2 > 10 || x2 < -10)) {
        cout << "Invalid input. Please enter a number from -10 to 10 for x2." << endl;
        cin.clear();  // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
    }

    cout << "Enter y2 (From -10 to 10): " << endl;
    // Validate input for y2
    while (!(cin >> y2) || (y2 > 10 || y2 < -10)) {
        cout << "Invalid input. Please enter a number from -10 to 10 for y2." << endl;
        cin.clear();  // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
    }
}

// Main function where the program execution begins
int main() {
    // Initialize variables for coordinates, distances, and user choices
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    float dist1 = 0.0, dist2 = 0.0;
    char userChoice = 'Y';
    char userChoice2 = 'N';

    bool isStillGoing = true;
    bool isInputtingNumbers = false;

    // Ask user if they want to input their own numbers or generate random numbers
    isInputtingNumbers = generateNumbersOrInput(userChoice2);
    if (isInputtingNumbers == false) {
        srand(time(0));

        // Generate random numbers for coordinates within the range -10 to 10
        x1 = rand() % 21 - 10;
        y1 = rand() % 21 - 10;
        x2 = rand() % 21 - 10;
        y2 = rand() % 21 - 10;

        // Perform task with generated coordinates
        performTask(x1, y1, x2, y2, dist1, dist2);

        // Loop to repeat the task as long as the user wants to continue
        isStillGoing = getUserChoice(userChoice);
        while (isStillGoing == true) {
            x1 = rand() % 21 - 10;
            y1 = rand() % 21 - 10;
            x2 = rand() % 21 - 10;
            y2 = rand() % 21 - 10;

            // Perform task with generated coordinates
            performTask(x1, y1, x2, y2, dist1, dist2);

            // Ask if the user wants to continue
            isStillGoing = getUserChoice(userChoice);
            cout << "" << endl;
        }
    }
    else {
        // If the user chose to input their own numbers
        // Get user input for coordinates
        getUserNumbers(x1, y1, x2, y2);

        // Perform task with user-provided coordinates
        performTask(x1, y1, x2, y2, dist1, dist2);

        // Loop to repeat the task as long as the user wants to continue
        isStillGoing = getUserChoice(userChoice);
        while (isStillGoing == true) {
            // Get new user input for coordinates
            getUserNumbers(x1, y1, x2, y2);

            // Perform task with new user-provided coordinates
            performTask(x1, y1, x2, y2, dist1, dist2);

            isStillGoing = getUserChoice(userChoice);  // Ask if the user wants to continue
            cout << "" << endl;
        }
    }
}
