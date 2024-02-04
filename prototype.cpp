#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

// Define a structure to represent a question
struct Question {
    string questionText;
    char correctOption;
    char userOption;
    vector<string> options;
};

// Function to load questions from a file
vector<Question> loadQuestions(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Question q;
            q.questionText = line;

            // Read options from the same line
            for (int i = 0; i < 4; ++i) {
                getline(file, line);
                q.options.push_back(line);
            }

            // Read correct option
            file >> q.correctOption;

            questions.push_back(q);
        }
        file.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return questions;
}

// Function to display a question and get user input
char askQuestion(const Question& q) {
    cout << q.questionText << endl;
    cout << "Options: A, B, C, D" << endl;
    
    for (int i = 0; i < q.options.size(); ++i) {
        cout << static_cast<char>('A' + i) << ". " << q.options[i] << endl;
    }

    char userOption;
    do {
        cout << "Your choice (A/B/C/D): ";
        cin >> userOption;
        userOption = toupper(userOption); // Convert to uppercase
        if (userOption < 'A' || userOption > 'D') {
            cout << "Invalid choice. Please enter A, B, C, or D." << endl;
        }
    } while (userOption < 'A' || userOption > 'D');

    return userOption;
}

// Function to conduct the test
void conductTest(const vector<Question>& questions, map<int, char>& userResponses) {
    for (int i = 0; i < questions.size(); ++i) {
        char userOption = askQuestion(questions[i]);
        userResponses[i + 1] = userOption; // Store user response for each question
    }
}

// Function to display the test results
void displayResults(const vector<Question>& questions, const map<int, char>& userResponses) {
    int score = 0;
    cout << "\nTest Results:" << endl;

    for (int i = 0; i < questions.size(); ++i) {
        cout << "\nQuestion " << (i + 1) << ":" << endl;
        cout << questions[i].questionText << endl;

        for (int j = 0; j < questions[i].options.size(); ++j) {
            cout << static_cast<char>('A' + j) << ". " << questions[i].options[j] << endl;
        }

        cout << "Correct Option: " << questions[i].correctOption << endl;
        cout << "Your Option   : " << userResponses.at(i + 1) << endl;

        if (questions[i].correctOption == userResponses.at(i + 1)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect!" << endl;
        }
    }

    cout << "\nTotal Score: " << score << " out of " << questions.size() << endl;
}

int main() {
    // Load questions from a file
    vector<Question> questions = loadQuestions("questions.txt");

    // Map to store user responses for each question
    map<int, char> userResponses;

    // Conduct the test
    conductTest(questions, userResponses);

    // Display test results
    displayResults(questions, userResponses);

    return 0;
}
