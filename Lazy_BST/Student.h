/*
Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 5: Lazy BST
Header file for the Student class - contains function and member variable declarations
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

//Student class - objects represent students and track various attributes
class Student{
    public:
        //default constructor
        Student();

        //overloaded constructor - assigns member variables to the corresponding arguments
        Student(int numID, std::string name, std::string level, std::string major, double gpa, int advisor);

        //destructor
        virtual ~Student();

        //overloaded operator - compares students based on ID number
        bool operator < (const Student& other) const;

        //overloaded operator - compares students based on ID number
        bool operator > (const Student& other) const;

        //overloaded operator - compares students based on ID number
        bool operator == (const Student& other) const;

        //overloaded operator - compares students based on ID number
        bool operator != (const Student& other) const;

        //overloaded operator - compares students based on ID number
        bool operator <= (const Student& other) const;

        //overloaded operator - compares students based on ID number
        bool operator >= (const Student& other) const;

        //accessor for the m_ID member variable
        int getID();

        //mutator for the m_ID member variable
        void setID(int newID);

        //accessor for the m_name member variable
        std::string getName();

        //mutator for the m_name member variable
        void setName(std::string newName);

        //accessor for the m_level member variable
        std::string getLevel();

        //mutator for the m_level member variable
        void setLevel(std::string newLevel);

        //accessor for the m_major member variable
        std::string getMajor();

        //mutator for the m_major member variable
        void setMajor(std::string newMajor);

        //accessor for the m_GPA member variable
        double getGPA();

        //mutator for the m_GPA member variable
        void setGPA(double newGPA);

        //accessor for the m_advisorID member variable
        int getAdvisorID();

        //mutator for the m_advisorID member variable
        void setAdvisorID(int newAdvisorID);

    private:
        int m_ID;  //represents the student's ID number
        std::string m_name;  //represents the student's name
        std::string m_level;  //represents the student's grade level
        std::string m_major;  //represents the student's major
        double m_GPA;  //represents the student's GPA
        int m_advisorID;  //represents the ID of the student's advisor (-1 if they have no advisor)
};

#endif