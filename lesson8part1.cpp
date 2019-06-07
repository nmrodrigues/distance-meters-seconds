// This program is designed to get an amount of
// seconds from the keyboard, calculates the distance with the
// distance formula and displays it to the screen.
// This is done through the use of 3 functions - one to read in the input
// another to calculate the distance, and another to display the results to the
// screen.
// 0.0 or 0 is used as a sentinel in this program

#include <iostream>
#include<cmath> // pow function
#include <iomanip> // setprecision
using namespace std;

// function protoypes for the functions used
double readseconds();
double calculateDistance(double seconds);
void displayResults(double seconds, double distance);

int main() {
    // calls the function to read the seconds in from the keyboard
    // assigns the return value to seconds
    double seconds = readseconds();
    // data validation - seconds can not be negative
    while (seconds < 0.0) {
        cout << "The time must be zero or more" << endl;
        seconds = readseconds();
    }
    // as long as seconds is positive, the loop will run
    while(seconds > 0.0) {
        // calls the calculateDistance function to
        // calculate distance and assigns the return value to
        // distance
        double distance = calculateDistance(seconds);
        displayResults(seconds, distance);
        seconds = readseconds();
    }
    // if seconds = 0, the program will quit
    // in this program, 0 is a sentinel
    if (seconds == 0.0){
        exit(EXIT_FAILURE);
    }
    return 0;
}

// funtion that prompts the user for the time and returns the value to main
double readseconds(){
    double seconds;
    cout << "Enter the time (in seconds)" << endl;
    cin >> seconds;
    return seconds;
}

// function calculates distance with the distance formula
// returns the value to main
double calculateDistance(double seconds){
    double distance;
    double gravity = 9.8;
    distance = 0.5 * gravity * pow(seconds, 2);
    return distance;
}

// function displays the input and calculation to main
// uses setprecision for the desired precision
void displayResults(double seconds, double distance){
    cout << "The object traveled " << setprecision(3) << fixed <<  distance << " meters in " ;
    cout << setprecision(2) << fixed << seconds << " seconds" << endl;
}
