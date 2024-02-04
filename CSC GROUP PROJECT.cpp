#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

const int MAX_STUDENTS = 1000;

struct StudentRecord {
    char name[50];
    int studentId;
    float csc201;
    float sen292;
    float cgpa;
};

char currentUsername[50];
char currentPassword[50];
StudentRecord studentRecords[MAX_STUDENTS];
int totalStudents =0;

void login();
bool authenticateUser(const char username[], const char password[]);
void updateScores();
void viewAllResults();
void searchStudentRecord();
void storeRecordInFile();
void readUserCredentials();

int main() {
	    	 std::cout << "\t**Welcome to Pan-Atlantic University Result Management System**\n ";
    readUserCredentials();
    login();

    char option;
    do {

        std::cout << "\nMain Menu:\n";
        std::cout << "A. View All Results\n";
        std::cout << "B. Search Student Record\n";
        std::cout << "C. Store Record in File\n";
        std::cout << "D. Update Scores\n";
        std::cout << "E. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        option = toupper(option);

        switch (option) {
            case 'D':
                updateScores();
                break;
            case 'A':
                viewAllResults();
                break;
            case 'B':
                searchStudentRecord();
                break;
            case 'C':
                storeRecordInFile();
                break;
            case 'E':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (option != 'E');

    return 0;
}

void login() {
    char username[50];
    char password[50];

    std::cout << "\nEnter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    if (authenticateUser(username, password)) {
        std::cout << "Login successful!\n";
        std::strcpy(currentUsername, username);
        std::strcpy(currentPassword, password);
    } else {
        std::cout << "Authentication failed. Exiting...\n";
        return login();
    }
}

bool authenticateUser(const char username[], const char password[]) {
    std::ifstream file("credentials.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening user credentials file.\n";
        std::exit(1);
    }

    char storedUsername[50];
    char storedPassword[50];

    while (file >> storedUsername >> storedPassword) {
        if (std::strcmp(username, storedUsername) == 0 && std::strcmp(password, storedPassword) == 0) {
            file.close();
            return true;  
        }
    }

    file.close();
    return false;  
}


void viewAllResults() {
    std::ifstream file("student_data.txt"); 
    if (!file.is_open()) {
        std::cerr << "Error opening student data file.\n";
        return;
    }

    int count = 0;

    std::cout << "\nAll Results:\n";
    printf("%-20s %-15s %-10s %-10s %-10s\n", "Name", "Student ID", "CSC201", "SEN292", "AVERAGE");
    printf("--------------------------------------------------------\n");

    std::string line;
    while (count < MAX_STUDENTS && std::getline(file, line)) {
        std::stringstream ss(line);

        // Parse CSV line
        ss.getline(studentRecords[count].name, sizeof(studentRecords[count].name), ',');
        ss >> studentRecords[count].studentId >> studentRecords[count].csc201
           >> studentRecords[count].sen292 >> studentRecords[count].cgpa;

        printf("%-20s %-15d %-10.2f %-10.2f %-10.2f\n",
               studentRecords[count].name, studentRecords[count].studentId,studentRecords[count].csc201, studentRecords[count].sen292, studentRecords[count].cgpa);

        count++;
    }

    file.close();
}

void updateScores() {
    int studentId;
    std::cout << "Enter student ID to update scores: ";
    std::cin >> studentId;

    bool found = false;
    std::ifstream inputFile("student_data.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening student data file for reading.\n";
        return;
    }

    std::ofstream tempFile("temp_student_data.txt");
    if (!tempFile.is_open()) {
        std::cerr << "Error opening temporary file for writing.\n";
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);

        StudentRecord tempRecord;
        ss.getline(tempRecord.name, sizeof(tempRecord.name), ',');
        ss >> tempRecord.studentId >> tempRecord.csc201 >> tempRecord.sen292 >> tempRecord.cgpa;

        if (tempRecord.studentId == studentId) {
            found = true;

            std::cout << "Current CSC201 score for " << tempRecord.name << ": " << tempRecord.csc201 << '\n';
            std::cout << "Current SEN292 score for " << tempRecord.name << ": " << tempRecord.sen292 << '\n';

            double newCSC201, newSEN292;
            std::cout << "Enter new CSC201 score for " << tempRecord.name << " (or -1 to keep current): ";
            std::cin >> newCSC201;
            tempRecord.csc201 = (newCSC201 == -1) ? tempRecord.csc201 : newCSC201;

            std::cout << "Enter new SEN292 score for " << tempRecord.name << " (or -1 to keep current): ";
            std::cin >> newSEN292;
            tempRecord.sen292 = (newSEN292 == -1) ? tempRecord.sen292 : newSEN292;

            tempRecord.cgpa = tempRecord.csc201 + tempRecord.sen292 / 2.0;

            // Write the updated record to the temporary file
            tempFile << tempRecord.name << ',' << tempRecord.studentId << ' ' << tempRecord.csc201
                      << ' ' << tempRecord.sen292 << ' ' << std::fixed << std::setprecision(2) << tempRecord.cgpa << '\n';
        } else {
            // Write the unchanged record to the temporary file
            tempFile << tempRecord.name << ',' << tempRecord.studentId << ' ' << tempRecord.csc201
                      << ' ' << tempRecord.sen292 << ' ' << std::fixed << std::setprecision(2) << tempRecord.cgpa << '\n';
        }
    }

    inputFile.close();
    tempFile.close();

    // Replace the original file with the updated temporary file
    if (found) {
        if (std::remove("student_data.txt") == 0 && std::rename("temp_student_data.txt", "student_data.txt") == 0) {
            std::cout << "Scores updated successfully.\n";
        } else {
            std::cerr << "Error updating scores.\n";
        }
    } else {
        std::cout << "Student with ID " << studentId << " not found.\n";
        std::remove("temp_student_data.txt");  // Remove the temporary file if no update was made
    }
}

void searchStudentRecord() {
    std::ifstream file("student_data.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening student data file.\n";
        std::exit(1);
    }

    int choice;
    std::cout << "Search by:\n";
    std::cout << "1. Student ID\n";
    std::cout << "2. Student Name\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    int found = 0;

    switch (choice) {
        case 1: {
            int studentId;
            std::cout << "Enter student ID to search: ";
            std::cin >> studentId;

            std::string line;
            while (std::getline(file, line)) {
                std::stringstream ss(line);

                // Parse CSV line
                ss.getline(studentRecords[totalStudents].name, sizeof(studentRecords[totalStudents].name), ',');
                ss >> studentRecords[totalStudents].studentId >> studentRecords[totalStudents].csc201
                   >> studentRecords[totalStudents].sen292 >> studentRecords[totalStudents].cgpa;

                if (studentRecords[totalStudents].studentId == studentId) {
                    found = 1;
                    std::cout << "Record found:\n";
                    std::cout << "Name: " << studentRecords[totalStudents].name
                              << ", Student ID: " << studentRecords[totalStudents].studentId
                              << ", CSC201: " << studentRecords[totalStudents].csc201
                              << ", SEN292: " << studentRecords[totalStudents].sen292
                              << ", CGPA: " << studentRecords[totalStudents].cgpa << "\n";
                    break;
                }
            }
            break;
        }
        case 2: {
            char studentName[50];
            std::cout << "Enter student name to search: ";
            std::cin.ignore();  // Clear the input buffer
            std::cin.getline(studentName, sizeof(studentName));

            std::string line;
            while (std::getline(file, line)) {
                std::stringstream ss(line);

                // Parse CSV line
                ss.getline(studentRecords[totalStudents].name, sizeof(studentRecords[totalStudents].name), ',');
                ss >> studentRecords[totalStudents].studentId >> studentRecords[totalStudents].csc201
                   >> studentRecords[totalStudents].sen292 >> studentRecords[totalStudents].cgpa;

                if (std::strcmp(studentRecords[totalStudents].name, studentName) == 0) {
                    found = 1;
                    std::cout << "Record found:\n";
                    std::cout << "Name: " << studentRecords[totalStudents].name
                              << ", Student ID: " << studentRecords[totalStudents].studentId
                              << ", CSC201: " << studentRecords[totalStudents].csc201
                              << ", SEN292: " << studentRecords[totalStudents].sen292
                              << ", CGPA: " << studentRecords[totalStudents].cgpa << "\n";
                    break;
                }
            }
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }

    file.close();

    if (!found) {
        std::cout << "Record not found.\n";
    }
}

void storeRecordInFile() {
    int studentId;
    std::cout << "Enter student ID to store the record: ";
    std::cin >> studentId;

    
    bool found = false;
    std::ifstream inputFile("student_data.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening student data file for reading.\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);

        StudentRecord tempRecord;
        ss.getline(tempRecord.name, sizeof(tempRecord.name), ',');
        ss >> tempRecord.studentId >> tempRecord.csc201 >> tempRecord.sen292 >> tempRecord.cgpa;

        if (tempRecord.studentId == studentId) {
            found = true;

           
            std::string filename = "student_" + std::to_string(studentId) + "_record.txt";
            std::ofstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error opening file for individual student record.\n";
                inputFile.close();
                return;
            }

            // Store the individual student record in the file
            file << tempRecord.name << ','
                 << tempRecord.studentId << ','
                 << tempRecord.csc201 << ','
                 << tempRecord.sen292 << ','
                 << tempRecord.cgpa << '\n';

            file.close();

            std::cout << "Record for " << tempRecord.name << " stored in " << filename << ".\n";
            break;
        }
    }

    inputFile.close();

    if (!found) {
        std::cout << "Student with ID " << studentId << " not found in student_data.txt.\n";
    }
}

void readUserCredentials() {
    
}
