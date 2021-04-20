/*
 
 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 13
 Question No: 1
 Date: April 20, 2021
 
 */

#include <iostream>
#include <vector>
using namespace std;

template <class T>
//MARK: - STUDENT CLASS
class Student {
    //MARK: - STORED PROPERTIES
private:
    int id;
    T score;
    char grade;
    
    //MARK: - METHODS
public:
    
    Student(int id, T score) {
        this->id = id;
        this->score = score;
    }
    
    //MARK: - SETTER
    
    void setIDAndScore(int id, T score) {
        this->id = id;
        this->score = score;
    }
    
    void setGrade(char grade) {
        this->grade = grade;
    }
    
    //MARK: - GETTER
    
    int getID() {
        return this->id;
    }
    
    T getScore() {
        return this->score;
    }
    
    char getGrade() {
        return this->grade;
    }
    
};//: STUDENT

//MARK: - ERROR EXCEPTION CLASS

class FatalError: public exception {
private:
    string error = "Error: your input must be only a number.\n\n";
public:
    
    //CONSTRUCTOR
    FatalError() {
    }
    
    // CUSTOM ERROR MESSAGE
    FatalError(string error) {
        this->error = error;
    }
    
    // GETTER
    void showFatalError() {
        cout << this->error;
    }
};//: FATAL

//MARK: - GENERICS

// DECLARATION
void processStudents(int numStudents);


template <class T>
void calculateEachStudentGrade(Student<T> *aStudent) {
    int score = aStudent->getScore();
    
    if (score >= 90) {
        aStudent->setGrade('A');
    } else if (score >= 80) {
        aStudent->setGrade('B');
    } else if (score >= 70) {
        aStudent->setGrade('C');
    } else if (score >= 60) {
        aStudent->setGrade('D');
    } else {
        aStudent->setGrade('F');
    }
}

template <class T>
void calculateStudentsGrade(vector<Student<T>> &students) {
    for (int i = 0; i < students.size(); i++) {
        calculateEachStudentGrade(&students[i]);
    }
}

template <class T>
void enterEachStudentInfo(Student<T> *aStudent) {
    // PROPERTIES
    int id;
    int score;
    
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Score: ";
    cin >> score;
    
    aStudent->setIDAndScore(id, score);
}

template <class T>
void enterStudentsInfo(vector<Student<T>> &students) {
    for (int i = 0; i < students.size(); i++) {
        cout << "Student " << i + 1 << endl;
        enterEachStudentInfo(&students[i]);
    }
    
    calculateStudentsGrade(students);
    
    printStudentsInfo(students);
}

template <class T>
void printEachStudentInfo(Student<T> *aStudent) {
    cout << aStudent->getID() << "\t" << aStudent->getScore() << "\t" << aStudent->getGrade() << endl;
}

template <class T>
void printStudentsInfo(vector<Student<T>> &students) {
    cout << "Student ID\t" << "Student Score\t" << "Student Grade" << endl;
    for (int i = 0; i < students.size(); i++) {
        printEachStudentInfo(&students[i]);
    }
}



//MARK: - CORE FUNCTIONOF THE PROGRAM
void processStudents(int numStudents) {
    
    vector<Student<int>> students;
    for (int i = 0; i < numStudents; i++) {
        students.push_back(Student<int>(0, 0));
    }
    
    enterStudentsInfo(students);
};

//MARK: - GUARD NON-NUMERIC TYPES

template <class T>
T readANumber(string prompt) {
    try {
        throw FatalError();
    } catch (FatalError error) {
        error.showFatalError();
    }
    
    int inputWithNumber;
    cout << prompt;
    cin >> inputWithNumber;
    
    return inputWithNumber;
};

//MARK: - MAIN

int main() {
    int numStudents;
    string prompt = "Please enter number of students: ";
    numStudents = readANumber<int>(prompt);
    processStudents(numStudents);
    return 0;
}
