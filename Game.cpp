#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

// Function to remove accents from a word
string removeAccents(const string& word) {
    string result;
    locale loc;

    for (char c : word) {
        if (isalpha(c, loc)) {
            if (isupper(c, loc)) {
                c = tolower(c, loc);
            }
            result.push_back(c);
        }
    }

    return result;
}

int main() {
    vector<string> words; // Vector to store the words from the file

    string filePath = "/Users/isacsanchezvargas/Desktop/Progra/palabras.txt"; // Absolute or relative path to the word file

    ifstream inputFile(filePath);
    if (!inputFile) {
        cout << "Unable to open the word file." << endl;
        return 1;
    }

    string word;
    while (getline(inputFile, word)) {
        words.push_back(word); // Add each word from the file to the vector
    }

    inputFile.close();

    if (words.empty()) {
        cout << "The word file is empty." << endl;
        return 1;
    }

    srand(time(nullptr));
    string selectedWord = words[rand() % words.size()]; // Select a random word from the vector

    int attempts = 7;
    string guessedLetters;
    string hiddenWord(selectedWord.length(), '_'); // Create a string with underscores to represent the hidden word

    cout << "Welcome to the Hangman game!" << endl;

    while (attempts > 0) {
        cout << "Word to guess: " << hiddenWord << endl;
        cout << "Remaining attempts: " << attempts << endl;
        cout << "Used letters: " << guessedLetters << endl;

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        guess = tolower(guess); // Convert the entered letter to lowercase

        string normalizedWord = removeAccents(selectedWord);
        string normalizedGuess = removeAccents(string(1, guess));

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You have already entered that letter. Try another one." << endl;
            continue;
        }

        guessedLetters += guess;

        bool found = false;
        for (size_t i = 0; i < normalizedWord.length(); i++) {
            if (normalizedWord[i] == normalizedGuess[0]) {
                hiddenWord[i] = selectedWord[i]; // Reveal the correctly guessed letters in the hidden word
                found = true;
            }
        }

        if (hiddenWord == selectedWord) {
            cout << endl;
            cout << "Congratulations! You have correctly guessed the word: " << selectedWord << endl;
            break;
        }

        if (!found) {
            attempts--;

            if (attempts == 0) {
                cout << endl;
                cout << "You lost! The correct word was: " << selectedWord << endl;
                break;
            }

            cout << "Incorrect letter. Try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
//Isanchezv
