/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 3
 Question No: 1
 Date: January 27, 2021
 
 -------------------------------------------------------------------------------
 
            [Objectives Overview] --> GRADE CALCULATOR!
            Ask user for the id and score
            If error happens
                Calculate grade
                Show grade table
                Program end
            Repeat asking
 
 -------------------------------------------------------------------------------
 
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void inputIdAndScore(vector<int> &studentId, vector<int> &studentScore);
void calculateGrade(vector<int> &studentScore, vector<char> &studentGrade);
void printResult(const vector<int> &studentId, const vector<int> &studentScore, const vector<char> &studentGrade);

bool processGoOn = true;

int main(int argc, char* argv[]) {
  vector<int> studentId, studentScore;
  vector<char> studentGrade;
  
  while (true) {
    inputIdAndScore(studentId, studentScore);
    if (!processGoOn) {
        calculateGrade(studentScore, studentGrade);
        printResult(studentId, studentScore, studentGrade);
        return 0;
    }
  }
}


void inputIdAndScore(vector<int> &studentId, vector<int> &studentScore) {
    
  int id, score;
  
  // Ask for student ID
  cout << "Enter a student id: ";
  cin >> id;
  if (id <= 0) {
    processGoOn = false;
    return;
  }
  studentId.push_back(id);
  
  // Ask for student score
  cout << "Enter student score: ";
  cin >> score;
  if (score <= 0) {
    studentId.pop_back();
    processGoOn = false;
    return;
  }
  studentScore.push_back(score);
}


void calculateGrade(vector<int> &studentScore, vector<char> &studentGrade) {
  for (int i = 0; i < studentScore.size(); i++) {
    if (studentScore[i] >= 90) {
      studentGrade.push_back('A');
    }
    else if (studentScore[i] >= 80) {
      studentGrade.push_back('B');
    }
    else if (studentScore[i] >= 70) {
      studentGrade.push_back('C');
    }
    else if (studentScore[i] >= 60) {
      studentGrade.push_back('D');
    }
    else {
      studentGrade.push_back('F');
    }
  }
}


void printResult(const vector<int> &studentId, const vector<int> &studentScore, const vector<char> &studentGrade) {
    
  cout << setw(10) << "Student ID" << "\t" << setw(13) << "Student Score" << "\t" << setw(13) << "Student Grade" << endl; // Show a header of a full table
    
  for (int i = 0; i < studentScore.size(); i++) {
    cout << setw(10) << studentId[i] << "\t" << setw(13) << studentScore[i] << "\t" << setw(13) << studentGrade[i] << endl;
  }
}

