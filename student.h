#pragma once

#include <iostream>
#include <string>
#include <map>
using std::string;

namespace zhz{
    class Student{
        private:
            string name_;
            string major_;
            int age_;
            int id_;
            std::map<string, char>courses_;
            double cgpa_;

            void updateCGPA(); 

        public:
            Student(const string& name, const string& major, int age, int id);

            void setName(const string& name);   
            string getName() const;

            void setMajor(const string& major);
            string getMajor() const;

            void setAge(int age);
            int getAge() const;

            void setId(int id);
            int getId() const;

            void addCourse(const string& course, char grade);
            void updateGrade(const string& course, char grade);
            char getGrade(const string& course) const;

            double getCgpa() const;

            void displayStudentInfo()const;



    };
};