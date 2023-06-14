#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

// Function to generate a random number between min and max
int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int timer(int time = 10){
    while (time > 0)
    {
        cout << "Remaining time: " << time << endl;
        this_thread::sleep_for(chrono::seconds(1)); // 1-second delay
        usleep(1000000);
        system("clear");
        time--; // decrease time by 1 second
    }

    cout << "Time's up! The program has ended." << endl;
    return 0;
}

int main() {
    const int GOAL = 50;
    int harePosition = 0, foxPosition = 0;
    int hareMove, foxMove;
    bool hareWinner = false, foxWinner = false;
    int acceleration = 5; // Acceleration factor for the first turns

    // Random seed for generating random numbers
    srand(time(0));

    cout << "Welcome to the Hare and Fox race!" << endl;
    // Main race loop
    for (int i = 1; i <= 50; i++) {
        // Generate moves for the hare and the fox
        if (i <= acceleration) { // First turns with acceleration
            hareMove = generateRandom(1, 15);
            foxMove = generateRandom(1, 15);
        } else { // Rest of the turns with normal probability
            hareMove = generateRandom(1, 10);
            foxMove = generateRandom(1, 10);
        }

        // If the random number is even, the hare moves forward
        if (hareMove % 2 == 0) {
            harePosition += hareMove;
        }

        // If the random number is odd, the hare stays in its current position
        if (hareMove % 2 != 0) {
            harePosition -= hareMove;
        }

        // If the random number is even, the fox moves forward
        if (foxMove % 2 == 0) {
            foxPosition += foxMove;
        }

        // If the random number is odd, the fox stays in its current position
        if (foxMove % 2 != 0) {
            foxPosition -= foxMove;
        }

        // If the hare or the fox goes off the track, place them at position 0
        if (harePosition < 0) {
            harePosition = 0;
        }
        if (foxPosition < 0) {
            foxPosition = 0;
        }

        // Check if either of them has reached the goal
        if (harePosition >= GOAL) {
            hareWinner = true;
        } else if (foxPosition >= GOAL) {
            foxWinner = true;
        }

        // Print the current positions of the hare and the fox in the race
        cout << "Hare: ";
        for (int j = 0; j < GOAL; j++) {
            if (j == harePosition) {
                cout << "H";
            } else {
                cout << "-";
            }
        }
        cout << endl;

        cout << "Fox:  ";
        for (int j = 0; j < GOAL; j++) {
            if (j == foxPosition) {
                cout << "F";
            } else {
                cout << "-";
            }
        }
        cout << endl;

        // If either of them has won, exit the main loop
        if (hareWinner || foxWinner) {
            break;
        }

        // Pause to simulate real-time progress
        usleep(1000000);
        system("clear");
    }

    // Print the result of the race
    if (hareWinner) {
        cout << "The hare has won the race!" << endl;
    } else if (foxWinner) {
        cout << "The fox has won the race!" << endl;
    } else {
        cout << "The race ended in a tie." << endl;
    }

    return 0;
}
//Isanchezv
