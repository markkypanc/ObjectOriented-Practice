/*
 
 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 9
 Question No: 1
 Date: March 18, 2021
 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//MARK: - Student Class

class Student {
    
    //MARK: - PROPERTIES
private:
    int id;
    string name;
    
    //MARK: - METHODS
public:
    
    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }
    
    void showInfo() {
        cout << "Student: " << this->id << " " << this->name << endl;
    }
    
}; //: STUDENT


//MARK: - CourseInfo Class

class CourseInfo {
    //MARK: - PROPERTIES
private:
    int id;
    string name;
    int unit;
    
    //MARK: - METHODS
public:
    
    CourseInfo(int id, string name, int unit) {
        this->id = id;
        this->name = name;
        this->unit = unit;
    }
    
    int getUnit() {
        return this->unit;
    }
    
    void showInfo() {
        cout << this->id << " " << this->name << " (" << this->unit << " credits)" << endl;
    }
    
}; //: COURSEINFO


//MARK: - StudentEnrollment Class
class StudentEnrollment {
    
    //MARK: - PROPERTIES
private:
    Student *student;
    vector<CourseInfo> courses;
    int totalCredit = 0;
    
    //MARK: - METHODS
public:
    
    StudentEnrollment(Student *student) {
        this->student = student;
    }
    
    void enrollCourse(CourseInfo *course) {
        this->courses.push_back(*course);
        this->totalCredit += course->getUnit();
    }
    
    void printStudentInfoWithCourses() {
        cout << endl;
        student->showInfo();
        for (int i = 0; i < courses.size(); i++) {
            courses[i].showInfo();
        }
        cout << "Total Units Enrolled: " << totalCredit << endl;
        cout << "---------------------------------------------" << endl;
    }
};

int main() {
    
    // INIT STUDENT
    Student too(6112345, "Uncle Too");
    Student tony(6112346, "Tony Woodsome");
    Student pom(6112347, "Pom Friendswatch");
    
    // INIT COURSE
    CourseInfo oop(12345 , "Object-Oriented Programming Concepts", 3);
    CourseInfo python(12346 , "Python Programming", 3);
    CourseInfo oopLab{12347 , "Object-Oriented Programming Lab", 2};
    
    vector<Student> students = { too, tony, pom };
    vector<CourseInfo> courses = { oop, python, oopLab };
    
    // SHOW STUDENT LIST
    cout << "Student List" << endl;
    cout << "---------------\n";
    for (int i = 0; i < students.size(); i++) {
        students[i].showInfo();
    }
    
    // SHOW COURSES LIST
    cout << "\nCourses List" << endl;
    cout << "---------------\n";
    for (int i = 0; i < courses.size(); i++) {
        courses[i].showInfo();
    }
    
    // INIT ENROLLMENT
    StudentEnrollment tooEnrollment(&too);
    StudentEnrollment tonyEnrollment(&tony);
    StudentEnrollment pomEnrollment(&pom);
    
    tooEnrollment.enrollCourse(&oop);
    tooEnrollment.enrollCourse(&oopLab);
    tooEnrollment.printStudentInfoWithCourses();
    
    tonyEnrollment.enrollCourse(&python);
    tonyEnrollment.enrollCourse(&oopLab);
    tonyEnrollment.printStudentInfoWithCourses();
    
    pomEnrollment.enrollCourse(&oop);
    pomEnrollment.enrollCourse(&python);
    pomEnrollment.printStudentInfoWithCourses();
    
    return 0;
}
