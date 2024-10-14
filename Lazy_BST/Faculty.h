/*
Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 5: Lazy BST
Header file for the Faculty class - contains function and member variable declarations
*/
#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>

//Faculty class - objects represent faculty members that can be advisors for students
class Faculty{
    public:
        //default constructor
        Faculty();

        //overloaded constructor - assigns member variables to the corresponding arguments
        Faculty(int numID, std::string name, std::string level, std::string department);

        //destructor
        virtual ~Faculty();

        //overloaded operator - compares faculty members based on ID number
        bool operator < (const Faculty& other) const;

        //overloaded operator - compares faculty members based on ID number
        bool operator > (const Faculty& other) const;

        //overloaded operator - compares faculty members based on ID number
        bool operator == (const Faculty& other) const;

        //overloaded operator - compares faculty members based on ID number
        bool operator != (const Faculty& other) const;

        //overloaded operator - compares faculty members based on ID number
        bool operator <= (const Faculty& other) const;

        //overloaded operator - compares faculty members based on ID number
        bool operator >= (const Faculty& other) const;

        //accessor for the m_maxAdvisees member variable
        int getMaxAdvisees();

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

        //accessor for the m_department member variable
        std::string getDepartment();

        //mutator for the m_department member variable
        void setDepartment(std::string newDepartment);

        //returns a string with the values held in m_adviseeList
        std::string displayAdviseeList();

        //adds the given ID number to m_adviseeList
        void addToList(int idNumber);

        //removes the given ID number from m_adviseeList
        void removeFromList(int idNumber);

        //returns true if this faculty member has no advisees
        bool listIsEmpty();

        //removes and returns the first student ID number in m_adviseeList
        int removeFrontStudent();

    private:
        int m_ID;  //represents the faculty member's ID number
        std::string m_name;  //represents the faculty member's name
        std::string m_level;  //represents the faculty member's level
        std::string m_department;  //represents the faculty member's department
        int* m_adviseeList;  //an array of the student ID numbers of this faculty member's advisees
        int m_numAdvisees;  //the number of advisees in m_adviseeList
        int m_maxAdvisees;  //the maximum capacity of m_adviseeList before it needs to resize
};

#endif