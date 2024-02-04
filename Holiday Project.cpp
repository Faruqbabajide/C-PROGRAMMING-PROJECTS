#include <iostream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct Question {
    string questionText;
    char correctOption;
    char userOption;
};


struct User {
    string username;
    string password;
};


vector<Question> loadQuestions(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);

    if (file.is_open()) {
        Question q;
        while (getline(file, q.questionText) && file >> q.correctOption) {
            q.userOption = ' ';  
            questions.push_back(q);
            file.ignore(); 
        }
        file.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return questions;
}


vector<User> loadUserDetails(const string& filename) {
    vector<User> users;
    ifstream file(filename);

    if (file.is_open()) {
        User u;
        while (file >> u.username >> u.password) {
            users.push_back(u);
        }
        file.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return users;
}


bool authenticateUser(const vector<User>& users, const string& username, const string& password) {
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

bool getUserLoginDetails(vector<User>& users) {
    string username, password;
    
    cout << "Enter the file name containing user login details: ";
    string filename;
    cin >> filename;

    users = loadUserDetails(filename);

    cout << "Enter your username: ";
    cin >> username;
    
    cout << "Enter your password: ";
    cin >> password;

    return authenticateUser(users, username, password);
}

char askQuestion(const Question& q) {
    cout << q.questionText << endl;
    cout << "Options: A, B, C, D, S (skip)" << endl;
    
    char userOption;
    do {
        cout << "Your choice (A/B/C/D/S): ";
        cin >> userOption;
        userOption = toupper(userOption); 

        if (userOption == 'S') {
            cout << "Question skipped." << endl;
            return 'S';
        }

        if (userOption < 'A' || userOption > 'D') {
            cout << "Invalid choice. Please enter A, B, C, D, or S (skip)." << endl;
        }
    } while (userOption < 'A' || userOption > 'D');

    return userOption;
}


void conductTest(vector<Question>& questions, map<int, char>& userResponses) {
    for (int i = 0; i < questions.size(); ++i) {
        char userOption;

        if (questions[i].userOption == 'S') {
            cout << "Question " << (i + 1) << " (Skipped): You previously entered option " << questions[i].userOption << ". Do you want to change it? (Y/N): ";
            char changeOption;
            cin >> changeOption;
            if (toupper(changeOption) == 'Y') {
                userOption = askQuestion(questions[i]);
            } else {
                userOption = questions[i].userOption;
            }
        } else {
            userOption = askQuestion(questions[i]);
        }

        userResponses[i + 1] = userOption;
        questions[i].userOption = userOption; 
    }


    cout << "\nRevisiting Skipped Questions:" << endl;
    for (int i = 0; i < questions.size(); ++i) {
        if (questions[i].userOption == 'S') {
            cout << "\nQuestion " << (i + 1) << " (Skipped):" << endl;
            char userOption = askQuestion(questions[i]);
            userResponses[i + 1] = userOption; 
            questions[i].userOption = userOption; 
        }
    }
}


void displayResults(const vector<Question>& questions, const map<int, char>& userResponses) {
    int score = 0;
    cout << "\nTest Results:" << endl;

    for (int i = 0; i < questions.size(); ++i) {
        cout << "\nQuestion " << (i + 1) << ":" << endl;
        cout << questions[i].questionText << endl;
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

 
    ofstream resultFile("test_results.txt");
    if (resultFile.is_open()) {
        resultFile << "Test Results:" << endl;
        for (int i = 0; i < questions.size(); ++i) {
            resultFile << "\nQuestion " << (i + 1) << ":" << endl;
            resultFile << questions[i].questionText << endl;
            resultFile << "Correct Option: " << questions[i].correctOption << endl;
            resultFile << "Your Option   : " << userResponses.at(i + 1) << endl;
            if (questions[i].correctOption == userResponses.at(i + 1)) {
                resultFile << "Correct!" << endl;
            } else {
                resultFile << "Incorrect!" << endl;
            }
        }
        resultFile << "\nTotal Score: " << score << " out of " << questions.size() << endl;
        resultFile.close();
        cout << "Test results written to testresults.txt to View your script" << endl;
    } else {
        cout << "Error writing to test_results.txt" << endl;
    }
}

int main() {
    vector<User> users;
    while (!getUserLoginDetails(users)) {
        cout << "Authentication failed. Please try to Re-login to the CBT Application t o begin test." << endl;
    }

   
    vector<Question> questions = loadQuestions("questions.txt");

    
    map<int, char> userResponses;


    conductTest(questions, userResponses);

   
    displayResults(questions, userResponses);

    return 0;
}
