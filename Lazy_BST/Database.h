/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 5: Lazy BST
Header file for the Database class - contains function and member variable declarations
*/
#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "LazyBST.h"
#include <fstream>

class Database{
    public:
        //default constructor
        Database();

        //default destructor
        virtual ~Database();

        /* 
        method that executes all functions of the database
        repreatedly prompts the user to build and change the database until they exit 
        */
        void run();

    private:
        //stores all the students in the database
        LazyBST<Student>* m_studentTree;

        //stores all the faulty members in the database
        LazyBST<Faculty>* m_facultyTree;
        
        //outputs a text message with the user's options
        void prompt();

        //outputs all students in the database in text form
        void printAllStudents();

        //outputs all faculty members in the database in text form
        void printAllFaculty();

        /*
        searches the student tree for a student with an ID number that matches the parameter
        prints out the student's information if found
        */
        void findStudent(int idNumber);

        /*
        searches the faculty tree for a faculty member with an ID number that matches the parameter
        prints out the faculty member's information if found
        */
        void findFaculty(int idNumber);

        //adds a student to the student tree with attributes that correspond to the given parameters
        void addStudent(int idNumber, std::string name, std::string level, std::string major, double gpa, int advisorID);

        //deletes the student with the given ID number from the student tree, if found
        void deleteStudent(int idNumber);

        //adds a faculty member to the faculty tree with attributes that correspond to the given parameters
        void addFaculty(int idNumber, std::string name, std::string level, std::string department);

        //deletes the faculty member with the given ID number from the faculty tree, if found
        void deleteFaculty(int idNumber);

        //changes the student with the given ID number's advisor to the advisor with the corresponding faculty ID
        void changeAdvisor(int studentID, int facultyID);

        /*
        removes the student with the given ID number from the advisee list of the faculty member with the given ID number
        the student is left with no advisor until the user assigns them a new one
        */
        void removeAdvisee(int studentID, int facultyID);

        //outputs the content of the student and faculty trees to a text file (called when the program is exited)
        void outputLog();
};

#endif