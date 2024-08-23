#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include "student.h"

using std::string;

namespace zhz{
    Student::Student(const string& name, const string& major, int id, int age): name_(name), major_(major), id_(id), age_(age), cgpa_(0.0f){}


void Student::updateCGPA(){
    int totalPoint = 0;
    int totalCourses = courses_.size();

    for(const auto& course : courses_) {
        switch(course.second) {
            case'A': totalPoint += 4; break;
            case'B': totalPoint += 3; break;
            case'C': totalPoint += 2; break;
            case'D': totalPoint += 1; break;
            case'F': totalPoint += 0; break;
        }
    }

    cgpa_ = totalCourses > 0 ? static_cast<float>(totalPoint)/totalCourses : 0;

}

void Student::setName(const string& name) {name_ = name ;}
string Student::getName()const { return name_; };

void Student::setMajor(const string& major) { major_ = major; }
string Student::getMajor()const { return major_; }

void Student::setAge(int age) { age_ = age; }
int Student::getAge()const { return age_; }

void Student::setId(int id) { id_ = id; }
int Student::getId()const { return id_; }

void Student::addCourse(const string& course, char grade) {
    courses_[course] = grade;
    updateCGPA();
}

void Student::updateGrade(const string& course, char grade) {
    if(courses_.find(course) != courses_.end()) {
        courses_[course] = grade;
        updateCGPA();
    }
}

char Student::getGrade(const string& course)const {
    auto it = courses_.find(course);
    return it != courses_.end() ? it->second : 'N';  

}

double Student::getCgpa()const { return cgpa_; }

void Student::displayStudentInfo()const {

    std::cout << "Name: " << name_ << "\n";
    std::cout << "ID: " << id_ << "\n";
    std::cout << "Age: " << age_ << "\n";
    std::cout << "Major: " << major_ << "\n";
    std::cout << "Courses and Grades:\n";
    for (const auto& course : courses_) {
        std::cout << "  " << course.first << ": " << course.second << "\n";
    }
    std::cout << "CGPA: " << std::fixed << std::setprecision(2) << cgpa_ << "\n";
}


}
