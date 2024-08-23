#include <iostream>
#include "student.h"

int main() {
    // Create a Student object
    zhz::Student student("John Doe","Computer Science", 12345, 20);

    // Add courses and grades
    student.addCourse("Mathematics", 'A');
    student.addCourse("Programming", 'B');
    student.addCourse("Physics", 'C');

    // Update a course grade
    student.updateGrade("Physics", 'B');

    // Display student information
    std::cout << "Student Information:\n";
    student.displayStudentInfo();

    // Display specific course grade
    std::cout << "Grade in Programming: " << student.getGrade("Programming") << "\n";

    // Display CGPA
    std::cout << "CGPA: " << student.getCgpa() << "\n";

    return 0;
}
