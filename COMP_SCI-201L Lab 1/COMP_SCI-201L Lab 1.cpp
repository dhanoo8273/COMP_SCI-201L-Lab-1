// NAME: Opjeet Dhanoa (Done IN Class)
// PGM: In class 4 Number Input (Print increasing, decreasing, largest,
// smallest, average)

#include <iostream>
using namespace std;

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the elements of the array in Ascending order
void printInAscendingOrder(int arr[], int n, bool stillGoing) {
    cout << "Printing in Ascending Order: ";
    // Iterate throught the array and print each element
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to print the elements of the array in descending order
void printInDescendingOrder(int arr[], int n, bool stillGoing) {
    // If stillGoing is false, return without printing
    if (stillGoing == false) {
        return;
    }
    cout << "Printing in Descending Order: ";
    // Iterate through the array in reverse and print each element
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to calculate and print the average of all the numbers in the Array
void Average(int arr[], int n, bool stillGoing) {
    int total = 0;
    float average = 0;

    cout << "Printing Average: ";
    // Sum up all of the elements in the array
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    average = (float)total / 4;
    cout << average;
    cout << endl;
}

void largest(int arr[]) {
    // Get the largest element in the array
    int largest = arr[3];

    cout << "Printing Largest: ";
    cout << largest << endl;
}

void smallest(int arr[]) {
    // Get the smallest element in the array
    int smallest = arr[0];

    cout << "Printing Smallest: ";
    cout << smallest << endl;
}

// Function to ask the user if they want to continue
bool askToContinue(char userInput) {
    cout << "Do you want to continue? (Y/N): ";
    cin >> userInput;

    // If the user enters 'Y' or 'y', continue
    if (userInput == 'Y' || userInput == 'y') {
        cout << "Okay, let's continue!" << endl;
        return true;
    }
    else {
        cout << "Okay, goodbye!" << endl;
        return false;
    }
}

void promptUser(int arr[], bool stillGoing) {
    cout << "Please Enter 4 Numbers: " << endl;

    // Read 4 numbers from the user and store them in the array
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    // Sorting the array using the Insertion sort
    insertionSort(arr, 4);

    // Getting the largest number and printing it
    largest(arr);

    // Getting the smallest number and printing it
    smallest(arr);

    // Calculate and print the average
    Average(arr, 4, stillGoing);

    // Print the numbers in ascending order
    printInAscendingOrder(arr, 4, stillGoing);

    // Print the numbers in Descending order
    printInDescendingOrder(arr, 4, stillGoing);
}

int main() {
    // Initalizing Variables
    int arr[4];
    bool stillGoing = true;
    char userCase = 'Y';

    //Calling PromptUser Method
    promptUser(arr, stillGoing);

    // Ask the user if they want to continue
    stillGoing = askToContinue(userCase);

    while (stillGoing == true) {
        //Calling PromptUser Method
        promptUser(arr, stillGoing);

        // Ask the user if they want to continue
        stillGoing = askToContinue(userCase);
    }
}
